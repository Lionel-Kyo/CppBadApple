#pragma once

#ifndef PLAYVIDEO_H
#define PLAYVIDEO_H

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "BGR.h"
#include "ColourPrint.h"


class PlayVideo
{
private:
	std::string path;
	auto PixelByType(cv::Mat& mat, int type, int x, int y) -> BGR;
public:
	PlayVideo(const std::string& path);
	auto Play(std::function<bool(cv::Mat&)> frameHandler) -> void;
	auto ShowInConsole(cv::Mat& frame, uint32_t frameShrink = 15) -> bool;
};


#endif // !PLAYVIDEO_H

