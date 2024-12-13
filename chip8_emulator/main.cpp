#include <iostream>
#include <cstdint>  // For uint16_t

#include "Chip8.h"

int main() 
{
    {
        Chip8 chip8;
        if (!chip8.loadRom("pong.rom"))
        {
            std::cout << "error loading rom.";
        }
        else
        {
            chip8.cycle();
        }
    }
    return 0;
}