#pragma once
struct Color
{
    uint32_t Red;
    uint32_t Green;
    uint32_t Blue;
};
bool ConvertHexInRGBColor(std::string const& HexColor, Color & RGBColor);
