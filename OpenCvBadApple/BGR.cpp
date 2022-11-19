#include "BGR.h"

auto BGR::IsWhite(uint8_t fuzzyIndex) -> bool
{
    uint8_t value = 255 - fuzzyIndex;
    return blue >= value && green >= value && red >= value;
}

auto BGR::IsBlack(uint8_t fuzzyIndex) -> bool
{
    uint8_t value = 0 + fuzzyIndex;
    return blue <= value && green <= value && red <= value;
}

auto BGR::RepresentChar(bool reverse) -> char
{
    char cs[] = { '%', '#', '@', '$', '^', '&', '*', '"', '=', '.', ' ' };
    int index = (int)((blue + green + red) / 3 / 25);
    if (reverse)
        return cs[10 - index];
    return cs[index];
}