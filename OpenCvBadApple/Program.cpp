#include <iostream>
#include <Windows.h>
#include <opencv2/opencv.hpp>
#include "PlayVideo.h"
#include "PlayAudio.h"

auto main(int argc, char* argv[]) -> int
{
    // 960 x 720
    std::string audioPath = "D:\\BadApple.wav";
    std::string videoPath = "D:\\BadApple.mp4";

    // resoluntion: 2560 x 1440
    HWND console = GetConsoleWindow();
    MoveWindow(console, 1100, 100, 820, 640, TRUE); // Shrink by 10

    std::string cvName = "Video";
    cv::namedWindow(cvName);
    cv::moveWindow(cvName, 50, 100);

    auto playAudio = new PlayAudio(audioPath);
    auto playVideo = new PlayVideo(videoPath);
    playAudio->PlayAsync();
    playVideo->Play([&](cv::Mat& frame)
    {
        if (cv::getWindowProperty(cvName, cv::WND_PROP_VISIBLE) < 1)
            return false;
        cv::imshow(cvName, frame);
        playVideo->ShowInConsole(frame, 10);
        return true;
    });
    delete playAudio;
    delete playVideo;
    return 0;
}