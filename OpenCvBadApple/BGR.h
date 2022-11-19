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

inline auto BGR::IsWhite(uint8_t fuzzyIndex) -> bool
{
    uint8_t value = 255 - fuzzyIndex;
    return blue >= value && green >= value && red >= value;
}

inline auto BGR::IsBlack(uint8_t fuzzyIndex) -> bool
{
    uint8_t value = 0 + fuzzyIndex;
    return blue <= value && green <= value && red <= value;
}

inline auto BGR::RepresentChar(bool reverse) -> char
{
    char cs[] = { '%', '#', '@', '$', '^', '&', '*', '"', '=', '.', ' ' };
    int index = (int)((blue + green + red) / 3 / 25);
    if (reverse)
        return cs[10 - index];
    return cs[index];
}

#endif // !BGR_H