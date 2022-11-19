#include "PlayAudio.h"

PlayAudio::PlayAudio(const std::string& path)
{
	this->path = path;
}

auto PlayAudio::Play() -> void
{
	std::wstring wsTmp(this->path.begin(), this->path.end());
	PlaySoundW(wsTmp.c_str(), nullptr, SND_ALIAS_START);
}

auto PlayAudio::PlayAsync() -> void
{
	std::thread t([&]() { this->Play(); });
	t.detach();
}
