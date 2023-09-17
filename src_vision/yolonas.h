#ifndef YOLONAS_H
#define YOLONAS_H

#include <iostream>
#include <opencv2/opencv.hpp>

// #include "cmdline.h"
#include "utils.h"
#include "detector.h"

class YoloNas {
public:
    YoloNas(float iou_thres, float conf_thres, bool isGPU);
    ~YoloNas();
    bool inference(cv::Mat& image);

private:
    void init();
    void get_classess();
    void load_model(bool isGPU);
    Detection postprocess(std::vector<Detection>);
    
    YOLODetector detector {nullptr};

    // structlog LOGCFG;
    // structlog *LOGCFG;

    std::string modelPath="../models/yolo_nas_s.onnx";
    // std::string classNamesPath="../models/coco.names";

    std::vector<std::string> classNames;
    const float iouThres;
    const float confThres;

    std::vector<cv::Scalar> classColors;
    std::vector<Detection> result;
};


#endif // YOLONAS_H