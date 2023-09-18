#include "vision.h"

Vision::Vision(bool isgpu){
    isGPU=isgpu;

    _init_video();
    _init_models();
    // std::vector<int> detres();
}

Vision::~Vision(){
    image.release();
    cap.release();
    detmodel->~YoloNas();
}

void Vision::_init_video(){
    
    cap = cv::VideoCapture(0);

    if (!cap.isOpened()) {
        LOG(ERROR) << "Cannot open video.\n";
        // return -1;
    }
    cv::Size S = cv::Size((int)cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH), 
                    (int)cap.get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT));
    fps = cap.get(cv::VideoCaptureProperties::CAP_PROP_FPS);
    LOG(INFO) << "Current FPS : " << fps;
}

void Vision::_init_models(){
    const float iouThreshold = 0.4f;
    const float confThreshold = 0.3f;
    detmodel=new YoloNas(iouThreshold , confThreshold, isGPU);
}

void Vision::run_detection(){

    while (true) {
        bool ret = cap.read(image); 
        if (!ret) {
            LOG(WARN) << "Can't receive frame (stream end?). Exiting ...\n";
            break;
        }

        // detres = detmodel.inference(image);
        // std::cout<<"Vision::detres: "<<detres<<std::endl;
        
        if (!detmodel->inference(image)){
            break;
        }

        std::vector <int> dets = detmodel->postprocess();
        for(int i=0; i<dets.size(); i++){
            std::cout<<"Vision::dets: "<<dets[i]<<std::endl;
        }
        
    }
}


