// only work in Windows
#pragma once
#ifdef _WIN32
#ifndef PLAYAUDIO_H
#define PLAYAUDIO_H

#include <iostream>
#include <thread>
#include <Windows.h>

class PlayAudio
{
private:
	std::string path;
public:
	PlayAudio(const std::string& path);
	auto Play() -> void;
	auto PlayAsync() -> void;
};

#endif // _WIN32
#endif // !PLAYAUDIO_H

