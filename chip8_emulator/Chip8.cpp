#include "Chip8.h"

Chip8::Chip8()
{
    quit = false;
    dontGoToNextInstruction = false;

    keyPressed = false;

    try {
        // Use full path if needed
        if (!_soundPlayer.loadSound("beep.wav")) {
            std::cerr << "Failed to load sound file" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Sound initialization error: " << e.what() << std::endl;
    }

	V.fill(0); // all registers set to 0
    I = 0; // mem address saver (register) set to 0 (null)
    pc = 0x200; // roms are loaded in 0x200 so the var is set to start at the first instruction of the rom
    delay_timer = 0;
    sound_timer = 0;

    // load font
    const std::array<uint8_t,80> tmp = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    for (size_t i = 0; i < tmp.size() ; i++)
    {
        memory[0x050 + i] = tmp[i];
    }
    // font loaded


    // this is for the 0xC000 (which is the random function)
    // this ensures that the randomization is changing and not constant.
    srand(static_cast<unsigned int>(time(0)));

    // creating screen window
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Create an SDL window
    window = SDL_CreateWindow("Chip-8 Emulator",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH * PIXEL_LEN, HEIGHT * PIXEL_LEN, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    // Create an SDL renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Could not create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // Set the draw color to black (background)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    redrawScreen();

    // for lateness
    lastTick = SDL_GetTicks();
}

Chip8::~Chip8()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Chip8::cycle()
{
    const int INSTRUCTION_HZ = 500; // Number of instructions to execute per second
    const int TIMER_HZ = 60;       // Timer update frequency in Hz

    uint32_t lastInstructionTick = SDL_GetTicks();
    uint32_t lastTimerTick = SDL_GetTicks();

    try
    {
        while (!quit)
        {
            // key event
            while (SDL_PollEvent(&e) != 0) {
                // User requests quit
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                else if (e.type == SDL_KEYDOWN)
                {
                    keyboard.fill(false);
                    keyPressed = true;
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_1: // means button '1' pressed
                    {
                        keyboard[0x1] = true;
                        break;
                    }
                    case SDLK_2: // means button '2' pressed
                    {
                        keyboard[0x2] = true;
                        break;
                    }
                    case SDLK_3: // means button '3' pressed
                    {
                        keyboard[0x3] = true;
                        break;
                    }
                    case SDLK_4: // means button '4' pressed
                    {
                        keyboard[0xC] = true;
                        break;
                    }
                    case SDLK_q: // means button 'q' pressed
                    {
                        keyboard[0x4] = true;
                        break;
                    }
                    case SDLK_w: // means button 'w' pressed
                    {
                        keyboard[0x5] = true;
                        break;
                    }
                    case SDLK_e: // means button 'e' pressed
                    {
                        keyboard[0x6] = true;
                        break;
                    }
                    case SDLK_r: // means button 'r' pressed
                    {
                        keyboard[0xD] = true;
                        break;
                    }
                    case SDLK_a: // means button 'a' pressed
                    {
                        keyboard[0x7] = true;
                        break;
                    }
                    case SDLK_s: // means button 's' pressed
                    {
                        keyboard[0x8] = true;
                        break;
                    }
                    case SDLK_d: // means button 'd' pressed
                    {
                        keyboard[0x9] = true;
                        break;
                    }
                    case SDLK_f: // means button 'f' pressed
                    {
                        keyboard[0xE] = true;
                        break;
                    }
                    case SDLK_z: // means button 'z' pressed
                    {
                        keyboard[0xA] = true;
                        break;
                    }
                    case SDLK_x: // means button 'x' pressed
                    {
                        keyboard[0x0] = true;
                        break;
                    }
                    case SDLK_c: // means button 'c' pressed
                    {
                        keyboard[0xB] = true;
                        break;
                    }
                    case SDLK_v: // means button 'v' pressed
                    {
                        keyboard[0xF] = true;
                        break;
                    }
                    default:
                    {
                        keyPressed = false;
                        break;
                    }
                    }
                }
            }

            dontGoToNextInstruction = false;
            // Execute instructions at ~500 Hz
            uint32_t currentTick = SDL_GetTicks();
            if (currentTick - lastInstructionTick >= 1000 / INSTRUCTION_HZ)
            {
                // Fetch instruction from memory at the program counter (placeholder comment)
                uint16_t opcode = memory[pc] << 8 | memory[pc + 1];

                /*
                turns all bits except the mib (most important bit) into 0
                */
                switch (opcode & 0xF000)
                {
                case 0x0000:  // Handle opcodes starting with 0x0 and so on
                {
                    switch (opcode & 0x000F)
                    {
                    case 0x0000:
                    {
                        CLS();
                        redrawScreen();
                        break;
                    }
                    case 0x000E:
                    {
                        RET();
                        break;
                    }
                    default:
                    {
                        // there exist a SYS CALL opcode which is irrelevent...
                        break;
                    }
                    }
                    break;
                }

                case 0x1000:
                {
                    JUMP(opcode);
                    break;
                }

                case 0x2000:
                {
                    CALL(opcode);
                    break;
                }

                case 0x3000:
                {
                    JE(opcode);
                    break;
                }

                case 0x4000:
                {
                    JNE(opcode);
                    break;
                }

                case 0x5000:
                {
                    CMP(opcode);
                    break;
                }

                case 0x6000:
                {
                    MOV(opcode);
                    break;
                }

                case 0x7000:
                {
                    ADD(opcode);
                    break;
                }

                case 0x8000:
                {
                    switch (opcode & 0x000F)
                    {
                    case 0x0000:
                    {
                        MOVREG(opcode);
                        break;
                    }

                    case 0x0001:
                    {
                        ORREG(opcode);
                        break;
                    }

                    case 0x0002:
                    {
                        ANDREG(opcode);
                        break;
                    }

                    case 0x0003:
                    {
                        XORREG(opcode);
                        break;
                    }

                    case 0x0004:
                    {
                        ADDREG(opcode);
                        break;
                    }
                    case 0x0005:
                    {
                        SUBREG(opcode);
                        break;
                    }

                    case 0x0006:
                    {
                        SHRREG(opcode);
                        break;
                    }

                    case 0x0007:
                    {
                        SUBNREG(opcode);
                        break;
                    }

                    case 0x000E:
                    {
                        SHLREG(opcode);
                        break;
                    }

                    default:
                    {
                        break;
                    }

                    }

                    break;
                }

                case 0x9000:
                {
                    JNEREG(opcode);
                    break;
                }

                case 0xA000:
                {
                    SETiREG(opcode);
                    break;
                }

                case 0xB000:
                {
                    JMPIV0(opcode);
                    break;
                }

                case 0xC000:
                {
                    RND(opcode);
                    break;
                }

                case 0xD000:
                {
                    DRAW(opcode);
                    redrawScreen();
                    break;
                }

                case 0xE000:
                {
                    if ((opcode & 0x000F) == 0x000E)
                    {
                        KEYSKP(opcode);
                    }
                    else
                    {
                        KEYNSKP(opcode);
                    }
                    break;
                }

                case 0xF000:
                {
                    switch (opcode & 0x000F)
                    {
                    case 0x0007:
                    {
                        SETVTODT(opcode);
                        break;
                    }
                    case 0x000A:
                    {
                        SETKEYTOV(opcode);
                        break;
                    }
                    case 0x0005:
                    {
                        switch (opcode & 0x00F0)
                        {
                        case 0x0010:
                        {
                            SETDTTOV(opcode);
                            break;
                        }
                        case 0x0050:
                        {
                            SETVINTOMEM(opcode);
                            break;
                        }
                        case 0x0060:
                        {
                            SETMEMINTOV(opcode);
                            break;
                        }
                        }
                        break;
                    }
                    case 0x0008:
                    {
                        SETSTTOV(opcode);
                        break;
                    }
                    case 0x000E:
                    {
                        ADDVTOI(opcode);
                        break;
                    }
                    case 0x0009:
                    {
                        SETIDIGIT(opcode);
                        break;
                    }
                    case 0x0003:
                    {
                        SETDIGITI(opcode);
                        break;
                    }
                    }
                    break;
                }

                default:
                {
                    // invalid opcode
                    std::cout << "Invalid opcode had occurred... exiting.";
                    exit(1);
                }
                }

                std::cout << opcode << std::endl;

                if (!dontGoToNextInstruction)
                {
                    pc += 2; // Increment program counter by 2 bytes
                }

                lastInstructionTick = currentTick;
            }

            // Update timers at 60 Hz
            if (currentTick - lastTimerTick >= 1000 / TIMER_HZ)
            {
                updateTimers();
                redrawScreen(); // Redraw the screen (replace this with actual screen redraw logic)
                lastTimerTick = currentTick;
            }

            // Prevent high CPU usage
            SDL_Delay(1);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << " | Exiting." << std::endl;
        exit(1);
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred | Exiting." << std::endl;
        exit(1);
    }
}


bool Chip8::loadRom(const std::string& romPath)
{
    std::ifstream file(romPath,std::ios::ate | std::ios::binary);
    if (file.is_open())
    {
        int size = file.tellg();
        file.seekg(0, std::ios::beg);
        std::vector<char> buffer(size);
        if (file.read(buffer.data(), size))
        {
            for (size_t i = 0; i < size; i++)
            {
                this->memory[0x200 + i] = buffer[i];
            }
            return true;
        }
    }
    return false;
}

void Chip8::redrawScreen()
{
    // turns the screen black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black brush
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White brush
    // now drwing th ewhite pixels
    for (size_t y = 0; y < HEIGHT; y++)
    {
        for (size_t x = 0; x < WIDTH; x++)
        {
            if (screen[y][x] == 1) // if the pixel is on (white)
            {
                //                         x                  y         width     height
                SDL_Rect pixelRect = { x * PIXEL_LEN, y * PIXEL_LEN, PIXEL_LEN, PIXEL_LEN };
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White
                SDL_RenderFillRect(renderer, &pixelRect); // draw the pixel
            }
        }
    }
    // update the screen
    SDL_RenderPresent(renderer);
}

void Chip8::updateTimers()
{
    if (delay_timer > 0)
    {
        delay_timer--;
    }
    if (sound_timer > 0)
    {
        sound_timer--;
        if (sound_timer > 0)
        {
            std::cout << "sound reached";
            _soundPlayer.playSound();
        }
    }
}

int* Chip8::turn2busIntoInt(const uint16_t& opBus) const
{
    int* arr = new int[4];

    arr[0] = (opBus & 0xF000) >> 12;
    arr[1] = (opBus & 0x0F00) >> 8;
    arr[2] = (opBus & 0x00F0) >> 4;
    arr[3] = opBus & 0x000F;

    return arr;
}

uint8_t Chip8::getRightBus(const uint16_t& opBus) const
{
    return opBus & 0x00FF;
}

void Chip8::CLS()
{
    for (auto& arr : this->screen)
    {
        arr.fill(0); // 0 for black
    }
}

void Chip8::RET()
{
    if (stack.size() == 0) // means he finished his program
    {                      // like a return from main
        exit(0);
    }
    else
    {
        pc = stack.top();
        stack.pop();
        sp--;
    }
}

void Chip8::JUMP(const uint16_t& opcode)
{
    pc = opcode & 0x0FFF;
    dontGoToNextInstruction = true;
}

void Chip8::CALL(const uint16_t& opcode)
{
    if (sp >= 16)
    {
        throw MyException("Stack overflow!!!");
    }
    else
    {
        stack.push(pc);
        sp++;
        JUMP(opcode);
    }
    dontGoToNextInstruction = true;
}

void Chip8::JE(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if (V[arr[1]] == getRightBus(opcode))
    {
        pc += 2;
    }
    delete[] arr;
}

void Chip8::JNE(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if (V[arr[1]] != getRightBus(opcode))
    {
        pc += 2;
    }
    delete[] arr;
}

void Chip8::CMP(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if (arr[1] == arr[2])
    {
        pc += 2;
    }
    delete[] arr;
}

void Chip8::MOV(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    V[arr[1]] = getRightBus(opcode);
    delete[] arr;
}

void Chip8::ADD(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    V[arr[1]] += getRightBus(opcode);
    delete[] arr;
}

void Chip8::MOVREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    V[arr[1]] = V[arr[2]];
    delete[] arr;
}

void Chip8::ORREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    V[arr[1]] |= V[arr[2]];
    delete[] arr;
}

void Chip8::ANDREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    V[arr[1]] &= V[arr[2]];
    delete[] arr;
}

void Chip8::XORREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    V[arr[1]] ^= V[arr[2]];
    delete[] arr;
}

void Chip8::ADDREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if ((V[arr[1]] + V[arr[2]]) > 255)
    {
        V[15] = 1;
    }
    else
    {
        V[15] = 0;
    }

    V[arr[1]] += V[arr[2]];
    delete[] arr;
}

void Chip8::SUBREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if ((V[arr[1]] - V[arr[2]]) >= 0)
    {
        V[15] = 1;
    }
    else
    {
        V[15] = 0;
    }

    V[arr[1]] -= V[arr[2]];
    delete[] arr;
}

void Chip8::SHRREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if (V[arr[1]] & 0x0001)
    {
        V[15] = 1;
    }
    else
    {
        V[15] = 0;
    }

    V[arr[1]] = V[arr[1]] >> 1;
    delete[] arr;
}

void Chip8::SUBNREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if ((V[arr[2]] - V[arr[1]]) >= 0)
    {
        V[15] = 1;
    }
    else
    {
        V[15] = 0;
    }

    V[arr[1]] = V[arr[2]] - V[arr[1]];
    delete[] arr;
}

void Chip8::SHLREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    uint8_t registerIndex = arr[1]; // X register index

    // Check the MSB of the register before shifting
    if (V[registerIndex] & 0x80)
    {
        V[0xF] = 1; // Set VF to 1 if MSB was 1
    }
    else
    {
        V[0xF] = 0; // Set VF to 0 if MSB was 0
    }

    // Shift the register value left by 1 bit
    V[registerIndex] <<= 1;

    delete[] arr;
}

void Chip8::JNEREG(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    if (V[arr[1]] != V[arr[2]])
    {
        pc += 2;
    }
    delete[] arr;
}

void Chip8::SETiREG(const uint16_t& opcode)
{
    I = opcode & 0x0FFF;
}

void Chip8::JMPIV0(const uint16_t& opcode)
{
    I = opcode & 0x0FFF + V[0];
}

void Chip8::RND(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    
    V[arr[1]] = (rand() % 256) & getRightBus(opcode);

    delete[] arr;
}

void Chip8::DRAW(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    int x = V[arr[1]];  // X-coordinate
    int y = V[arr[2]];  // Y-coordinate 
    int n = arr[3];     // Number of sprite rows to draw

    V[0xF] = 0; // Clear the collision flag

    for (int i = 0; i < n; i++) // y adder
    {
        // Fetch the sprite row from memory
        uint8_t spriteByte = memory[I + i];

        for (int j = 0; j < 8; j++) // x adder
        {
            // Calculate the current pixel's position on the screen
            int pixelX = (x + j) % 64;
            int pixelY = (y + i) % 32;

            // Extract the bit (0 or 1) from the sprite byte
            uint8_t spritePixel = (spriteByte >> (7 - j)) & 0x01;

            // XOR the sprite pixel with the screen pixel
            if (spritePixel == 1)
            {
                if (screen[pixelY][pixelX] == 1)
                {
                    V[0xF] = 1; // Set VF to 1 if there's a collision
                }
                screen[pixelY][pixelX] ^= 1; // XOR operation
            }
        }
    }
    delete[] arr; 
}


void Chip8::KEYSKP(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);

    if (keyboard[V[arr[1]]]-1)
    {
        pc += 2;
    }
    delete[] arr;
}

void Chip8::KEYNSKP(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);

    if (!keyboard[V[arr[1]]])
    {
        pc += 2;
    }
    delete[] arr;
}

void Chip8::SETVTODT(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);

    V[arr[1]] = delay_timer;
    delete[] arr;
}

void Chip8::SETKEYTOV(const uint16_t& opcode)
{
    if (!keyPressed)
    {
        dontGoToNextInstruction = true;
    }
    else
    {
        int* arr = turn2busIntoInt(opcode);
        for (size_t i = 0; i < keyboard.size(); i++)
        {
            if (keyboard[i])
            {
                V[arr[1]] = i;
            }
        }
        delete[] arr;
    }
}

void Chip8::SETDTTOV(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    delay_timer = V[arr[1]];
    delete[] arr;
}

void Chip8::SETSTTOV(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    sound_timer = V[arr[1]];
    delete[] arr;
}

void Chip8::ADDVTOI(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    I += V[arr[1]];
    delete[] arr;
}

void Chip8::SETIDIGIT(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    I = 0x050 + (V[arr[1]] * 5);
    delete[] arr;
}

void Chip8::SETDIGITI(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    int value = V[arr[1]];
    memory[I] = (value / 100) % 10;
    memory[I+1] = (value / 10) % 10;
    memory[I+2] = value % 10;
    delete[] arr;
}

void Chip8::SETVINTOMEM(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    for (size_t i = 0; i <= arr[1]; i++)
    {
        memory[I + i] = V[i];
    }
    delete[] arr;
}

void Chip8::SETMEMINTOV(const uint16_t& opcode)
{
    int* arr = turn2busIntoInt(opcode);
    for (size_t i = 0; i <= arr[1]; i++)
    {
        V[i] = memory[I + i];
    }
    delete[] arr;
}

