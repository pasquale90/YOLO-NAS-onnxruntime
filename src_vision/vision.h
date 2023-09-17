#ifndef VISION_H
#define VISION_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include "yolonas.h"

class Vision {
public:
    Vision();
    Vision(bool);
    ~Vision();
    void run_detection();   

private:
    YoloNas *detmodel;
    int fps;
    cv::VideoCapture cap;
    cv::Mat image;
    cv::Size S;
    // std::vector<int> detres;
    bool isGPU;
    
    void _init_models();
    void _init_video();
    void _visualize_results(); 
};


#endif // !VISION_H