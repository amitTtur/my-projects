#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <stdexcept>

class SoundPlayer {
private:
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;
    SDL_AudioDeviceID deviceId;

public:
    SoundPlayer() {
        // Initialize SDL audio subsystem
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
            throw std::runtime_error(std::string("SDL audio could not initialize: ") + SDL_GetError());
        }
    }

    bool loadSound(const char* filename) {
        // Detailed logging for sound loading
        std::cout << "Attempting to load sound file: " << filename << std::endl;

        // Attempt to load WAV
        if (SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength) == NULL) {
            std::cerr << "Failed to load WAV file: " << SDL_GetError() << std::endl;
            return false;
        }

        std::cout << "WAV file loaded successfully" << std::endl;
        std::cout << "Audio Spec - Frequency: " << wavSpec.freq
            << ", Format: " << wavSpec.format
            << ", Channels: " << (int)wavSpec.channels
            << ", Samples: " << wavSpec.samples << std::endl;

        // Configure audio device
        SDL_AudioSpec desiredSpec = wavSpec;
        desiredSpec.callback = NULL;  // We're using queue method
        desiredSpec.userdata = NULL;

        // Open audio device with more detailed error checking
        deviceId = SDL_OpenAudioDevice(NULL, 0, &desiredSpec, &wavSpec, 0);
        if (deviceId == 0) {
            std::cerr << "Failed to open audio device: " << SDL_GetError() << std::endl;
            SDL_FreeWAV(wavBuffer);
            return false;
        }

        std::cout << "Audio device opened successfully" << std::endl;
        return true;
    }

    void playSound() {
        if (deviceId == 0) {
            std::cerr << "Audio device not initialized" << std::endl;
            return;
        }

        // Clear any previously queued audio
        SDL_ClearQueuedAudio(deviceId);

        // Queue the sound buffer
        if (SDL_QueueAudio(deviceId, wavBuffer, wavLength) != 0) {
            std::cerr << "Failed to queue audio: " << SDL_GetError() << std::endl;
            return;
        }

        // Unpause to play
        SDL_PauseAudioDevice(deviceId, 0);

        std::cout << "Sound played. Buffer length: " << wavLength << " bytes" << std::endl;
    }

    void stopSound() {
        if (deviceId != 0) {
            SDL_PauseAudioDevice(deviceId, 1);
        }
    }

    ~SoundPlayer() {
        // Clean up resources
        if (deviceId != 0) {
            SDL_PauseAudioDevice(deviceId, 1);
            SDL_CloseAudioDevice(deviceId);
        }

        if (wavBuffer) {
            SDL_FreeWAV(wavBuffer);
        }
    }
};