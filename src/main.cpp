/*================================================*/
/* Author: jason-li-831202                        */
/* @File: main.cpp                                */
/* @Software: Visual Stidio Code                  */
/*================================================*/

#include <iostream>
// #include <opencv2/opencv.hpp>

// #include "cmdline.h"
// #include "utils.h"
// #include "detector.h"
#include "vision.h"
#include "utils.h"

structlog LOGCFG = {};

int main()
{   

    LOGCFG.headers = true; 
    LOGCFG.level = INFO;
    std::vector<int> bounding_box={0,0,0,0};

    // bool isGPU = true;
    Vision *vision = new Vision(true);
    // Vision vision();
    vision->run_detection();

    vision->~Vision();
    return 0;
}

