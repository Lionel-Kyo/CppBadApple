// only work in Windows

#pragma once
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

#endif // !PLAYAUDIO_H

