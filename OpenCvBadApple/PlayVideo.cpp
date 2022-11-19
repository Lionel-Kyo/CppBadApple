#include "PlayVideo.h"

// private
auto PlayVideo::PixelByType(cv::Mat& mat, int type, int x, int y) -> BGR
{
	switch (type)
	{
	case CV_8UC1:
	case CV_8UC2:
	{
		auto pixel = mat.at<cv::Vec2b>(y, x);
		return { pixel[0], pixel[0], pixel[0] };
	}
	case CV_8UC3:
	{
		auto pixel = mat.at<cv::Vec3b>(y, x);
		return { pixel[0], pixel[1], pixel[2] };
	}
	case CV_8UC4:
	{
		auto pixel = mat.at<cv::Vec4b>(y, x);
		return { pixel[0], pixel[1], pixel[2] };
	}
	}
	return BGR();
}


// public
PlayVideo::PlayVideo(const std::string& path)
{
	this->path = path;
}

auto PlayVideo::Play(std::function<bool(cv::Mat&)> frameHandler) -> void
{
	cv::VideoCapture videoCapture;
	videoCapture.open(this->path);
	double fps = videoCapture.get(cv::CAP_PROP_FPS);
	double frameWait = 1000.0 / fps;

	if (!videoCapture.isOpened())
	{
		std::cout << "Fail to open video" << std::endl;
		return;
	}

	cv::Mat frame;
	auto start = std::chrono::high_resolution_clock::now();
	while (videoCapture.read(frame))
	{
		if (!frameHandler(frame))
			break;
		auto end = std::chrono::high_resolution_clock::now();
		double duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0;
		int waitTime = (int)(frameWait - duration);
		cv::waitKey(waitTime <= 0 ? 1 : waitTime);
		start = std::chrono::high_resolution_clock::now();
	}
	videoCapture.release();
	std::cout << "Video is end" << std::endl;
}
auto PlayVideo::ShowInConsole(cv::Mat& frame, uint32_t frameShrink) -> bool
{
	cv::Mat newFrame;
	cv::resize(frame, newFrame, cv::Size((int)frame.cols / frameShrink, (int)frame.rows / frameShrink));

	// system("cls"); // bad performance
	auto type = newFrame.type();
	auto size = newFrame.size();
	std::string str = "";
	for (int y = 0; y < size.height; y++)
	{
		if (y & 1)continue;
		for (int x = 0; x < size.width; x++)
		{
			auto pixel = PixelByType(newFrame, type, x, y);
			str += pixel.RepresentChar(true);
		}
		str += '\n';
	}
	std::cout << str;
	return true;
}
