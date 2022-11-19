#pragma once
#ifndef COLOURPRINT_H
#define COLOURPRINT_H

#include <iostream>
#include <string>

namespace clrout
{
	enum class Colour
	{
		Black = 0,
		Red = 1,
		Green = 2,
		Yellow = 3,
		Blue = 4,
		Magenta = 5,
		Cyan = 6,
		White = 7,

		BrightBlack = 100,
		BrightRed = 101,
		BrightGreen = 102,
		BrightYellow = 103,
		BrightBlue = 104,
		BrightMagenta = 105,
		BrightCyan = 106,
		BrightWhite = 107,
	};

	class ColourGet
	{
	public:
		auto static Text(Colour colour) -> int;
		auto static Background(Colour colour) -> int;
	};

	inline auto clrout::ColourGet::Text(Colour colour) -> int
	{
		switch (colour)
		{
		case Colour::Black:
			return 30;
		case Colour::Red:
			return 31;
		case Colour::Green:
			return 32;
		case Colour::Yellow:
			return 33;
		case Colour::Blue:
			return 34;
		case Colour::Magenta:
			return 35;
		case Colour::Cyan:
			return 36;
		case Colour::White:
			return 37;

		case Colour::BrightBlack:
			return 90;
		case Colour::BrightRed:
			return 91;
		case Colour::BrightGreen:
			return 92;
		case Colour::BrightYellow:
			return 93;
		case Colour::BrightBlue:
			return 94;
		case Colour::BrightMagenta:
			return 95;
		case Colour::BrightCyan:
			return 96;
		case Colour::BrightWhite:
			return 97;
		}
		return 30;
	}

	inline auto clrout::ColourGet::Background(Colour colour) -> int
	{
		switch (colour)
		{
		case Colour::Black:
			return 40;
		case Colour::Red:
			return 41;
		case Colour::Green:
			return 42;
		case Colour::Yellow:
			return 43;
		case Colour::Blue:
			return 44;
		case Colour::Magenta:
			return 45;
		case Colour::Cyan:
			return 46;
		case Colour::White:
			return 47;

		case Colour::BrightBlack:
			return 100;
		case Colour::BrightRed:
			return 101;
		case Colour::BrightGreen:
			return 102;
		case Colour::BrightYellow:
			return 103;
		case Colour::BrightBlue:
			return 104;
		case Colour::BrightMagenta:
			return 105;
		case Colour::BrightCyan:
			return 106;
		case Colour::BrightWhite:
			return 107;
		}
		return 30;
	}

	inline auto GetPrintString(std::string& text, Colour textColour = Colour::White, Colour backgroundColour = Colour::Black) -> std::string
	{
		return "\033[3;" + std::to_string(ColourGet::Background(backgroundColour))
			+ ";" + std::to_string(ColourGet::Text(textColour)) + "m" + text + "\033[0m";
	}

	inline auto GetPrintString(std::string&& text, Colour textColour = Colour::White, Colour backgroundColour = Colour::Black) -> std::string
	{
		return GetPrintString(text, textColour, backgroundColour);
	}

	inline auto Print(std::string& text, Colour textColour = Colour::White, Colour backgroundColour = Colour::Black) -> void
	{
		std::cout << GetPrintString(text, textColour, backgroundColour);
	}

	inline auto PrintLine(std::string& text, Colour textColour = Colour::White, Colour backgroundColour = Colour::Black) -> void
	{
		Print(text, textColour, backgroundColour);
		std::cout << std::endl;
	}

	inline auto Print(std::string&& text, Colour textColour = Colour::White, Colour backgroundColour = Colour::Black) -> void
	{
		Print(text, textColour, backgroundColour);
	}

	inline auto PrintLine(std::string&& text, Colour textColour = Colour::White, Colour backgroundColour = Colour::Black) -> void
	{
		PrintLine(text, textColour, backgroundColour);
	}
}

#endif //!COLOURPRINT_H