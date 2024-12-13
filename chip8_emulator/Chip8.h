#ifndef CHIP8_H
#define CHIP8_H

#include <iostream>
#include <cstdint>
#include <array>
#include <stack>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>

#define SDL_MAIN_HANDLED
#include "SoundPlayer.h"



#define HEIGHT 32
#define WIDTH 64
#define PIXEL_LEN 10

#include "MyException.h"

class Chip8
{
public:
    // Add public members and methods here
    Chip8();
    ~Chip8();

    bool cycle();

    /// <summary>
    /// reads the rom and copies it into 0x200 forward.
    /// </summary>
    /// <param name="romPath"> the memory path of the rom file in the computer.
    /// <returns> whether rom was loaded successfully s(1), or not (0).
    bool loadRom(const std::string& romPath);



private:
    bool dontGoToNextInstruction;
    bool quit;
    SDL_Event e;

    std::array<bool, 16> keyboard;
    bool keyPressed;

    // sound (ai used)
    SoundPlayer _soundPlayer;

    // for screen
    SDL_Window* window;
    SDL_Renderer* renderer;
    void redrawScreen();

    // Add private members and methods here
    std::array<std::array<uint8_t, WIDTH >, HEIGHT> screen;

    /******** MEMORY **********/
    uint8_t memory[4096];

    /*
    when a "call" opcode is called the calling address is saved on top of the stack
    a total of 16 calls are possible in the chip 8.

    i used STL stack for comfort, and STL array for a max size of 16 :)
    */
    std::stack<uint16_t> stack;
    uint8_t sp; // indicates the level of the stack 0 - 16

    std::array<uint8_t, 16> V; // registers from v0 to vf
    uint16_t I;     // 16-bit index register
    uint16_t pc;    // program counter

    uint8_t delay_timer;       // 8-bit delay timer
    uint8_t sound_timer;       // 8-bit sound timer
    void updateTimers();
    uint32_t lastTick;
    
    /// <summary>
    /// Gets a 2bus (16 bits, 2 bytes) and return the int equivalent of each 4 bits.
    /// for example:
    /// for the 2bus 0xABCD it will return a array consisting of {10,11,12,13}
    /// </summary>
    /// <param name="opBus"></param> the 2bus
    /// <returns></returns> the int array, Note that the receiver needs to delete the array because its a dynamic array. 
    int* turn2busIntoInt(const uint16_t& opBus) const;

    uint8_t getRightBus(const uint16_t& opBus) const;

    void CLS();

    void RET();

    void JUMP(const uint16_t& opcode);

    void CALL(const uint16_t& opcode);

    // compares second chunk of the 4 bits as Vx register, and the second bus
    void JE(const uint16_t& opcode);

    void JNE(const uint16_t& opcode);

    void CMP(const uint16_t& opcode);

    void MOV(const uint16_t& opcode);

    void ADD(const uint16_t& opcode);

    /* 0x800~ */
    void MOVREG(const uint16_t& opcode);

    void ORREG(const uint16_t& opcode);

    void ANDREG(const uint16_t& opcode);

    void XORREG(const uint16_t& opcode);

    void ADDREG(const uint16_t& opcode);

    void SUBREG(const uint16_t& opcode);

    void SHRREG(const uint16_t& opcode);

    void SUBNREG(const uint16_t& opcode);

    void SHLREG(const uint16_t& opcode);

    // 0x9000
    void JNEREG(const uint16_t& opcode);

    // 0xA000
    void SETiREG(const uint16_t& opcode);

    // 0xB000
    void JMPIV0(const uint16_t& opcode);

    // 0xC000
    void RND(const uint16_t& opcode);

    // 0xD000
    void DRAW(const uint16_t& opcode);

    // 0xEx9E
    void KEYSKP(const uint16_t& opcode);

    // 0xExA1
    void KEYNSKP(const uint16_t& opcode);

    //0xF007
    void SETVTODT(const uint16_t& opcode);

    //0xFx0A
    void SETKEYTOV(const uint16_t& opcode);

    // 0xFx15
    void SETDTTOV(const uint16_t& opcode);

    // 0xFx18
    void SETSTTOV(const uint16_t& opcode);

    // 0xFx1E
    void ADDVTOI(const uint16_t& opcode);

    // 0xFx29
    void SETIDIGIT(const uint16_t& opcode);

    // 0xFx33
    void SETDIGITI(const uint16_t& opcode);

    // 0xFx55
    void SETVINTOMEM(const uint16_t& opcode);

    // 0xFx65
    void SETMEMINTOV(const uint16_t& opcode);
};

#endif // CHIP8_H