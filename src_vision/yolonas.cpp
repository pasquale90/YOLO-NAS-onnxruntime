
#include "yolonas.h"


YoloNas::YoloNas(const float iou_thres,const float conf_thres,bool isGPU):iouThres(iou_thres),confThres(conf_thres){
    
    // LOGCFG= new structlog{}; 
    
    // LOGCFG->headers = true; 
    // LOGCFG->level = INFO;

    get_classess();
    load_model(isGPU);    
}

YoloNas::~YoloNas(){
    // delete LOGCFG;
}

void YoloNas::get_classess(){
    // classNames = utils::loadNames(this->classNamesPath);
    const std::string temp_classNamesPath="/home/sonic_dev/Desktop/ResearchersNight/interactive-audio-visualizer/libs/YOLO-NAS-onnxruntime/models/coco.names";
    
    std::vector<std::string> temp = utils::loadNames(temp_classNamesPath);
    // // =temp;
    for (std::string name : temp)
    {
        classNames.push_back(name);
        // std::cout<<"name: "<<name<<std::endl;
    }
    

    // for (std::string name : classNames)
    // {
    //     // classNames.push_back(name);
    //     std::cout<<"name: "<<name<<std::endl;
    // }

    // classNames = temp;
    

    if (classNames.empty())
    {
        LOG(ERROR) << "Error: Empty class names file.";
        // return -1;
    }
}

void YoloNas::load_model(bool isGPU){
    
    try
    {
        const std::string temp_modelPath="/home/sonic_dev/Desktop/ResearchersNight/interactive-audio-visualizer/libs/YOLO-NAS-onnxruntime/models/yolo_nas_s.onnx";
        detector = YOLODetector(temp_modelPath, isGPU);
        // detector = YOLODetector(this->modelPath, isGPU);
        LOG(INFO) << "Model was initialized.";
    }
    catch(const std::exception& e)
    {
        LOG(ERROR) << e.what();
        // return -1;
    }
    classColors = utils::colorVectorScalar(detector.num_class);

}

bool YoloNas::inference(cv::Mat& image){

    // for (std::string name : classNames)
    // {
    //     // classNames.push_back(name);
    //     std::cout<<"name: "<<name<<std::endl;
    // }

    result = detector.detectFrame(image, this->confThres, this->iouThres);
    utils::drawDetectOnFrame(image, result, this->classNames, this->classColors);

    cv::imshow("result", image);
    if (cv::waitKey(33) == 'q') {
        return false;
    }
    return true;
}

void YoloNas::postprocess(){
}
