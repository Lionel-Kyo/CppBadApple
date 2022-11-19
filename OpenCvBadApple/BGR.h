#pragma once
#ifndef BGR_H
#define BGR_H

#include <iostream>

class BGR
{
public:
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    auto IsWhite(uint8_t fuzzyIndex = 0) -> bool;
    auto IsBlack(uint8_t fuzzyIndex = 0) -> bool;
    auto RepresentChar(bool reverse = false) -> char;
};

#endif // !BGR_H