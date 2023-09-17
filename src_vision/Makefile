CC=g++ -std=c++11 #gcc -std=c99 

OPTIONS=-g -pedantic -Wall -Wextra -Wno-error -w
OBJECTS=build/utils.o build/detector.o build/yolonas.o build/vision.o build/main.o

LOPENCV =-L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_video -lopencv_imgcodecs -lopencv_dnn
IOPENCV=/usr/local/include/opencv4
# CV=`pkg-config --cflags opencv` main.cpp `pkg-config --libs opencv`

IONNXRUNTIME=/usr/local/onnxruntime-linux-x64-gpu-1.13.1/include
LONNXRUNTIME=/usr/local/onnxruntime-linux-x64-gpu-1.13.1/lib
lONNXRUNTIME=-lonnxruntime -lonnxruntime_providers_cuda -lonnxruntime_providers_tensorrt -lonnxruntime_providers_shared 

HEADERS=/home/sonic_dev/Desktop/ResearchersNight/interactive-audio-visualizer/libs/YOLO-NAS-onnxruntime/include #../include 

yolonas.bin: $(OBJECTS) #runnable
	$(CC) $(OPTIONS) $(OBJECTS) -I${HEADERS} -I$(IOPENCV) -I$(IONNXRUNTIME) -o yolonas.bin $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

build/main.o: main.cpp
	$(CC) $(OPTIONS) -c main.cpp -I/usr/include -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME) -o build/main.o $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

build/vision.o: vision.cpp vision.h
	$(CC) $(OPTIONS) -c vision.cpp -I. -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME) -I/usr/include -o build/vision.o $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

build/yolonas.o: yolonas.cpp yolonas.h
	$(CC) $(OPTIONS) -c yolonas.cpp -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME) -o build/yolonas.o $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

build/utils.o: utils.cpp # /usr/include/jack/jack.h /usr/include/jack/types.h
	$(CC) $(OPTIONS) -c utils.cpp -I$(HEADERS) -I$(IOPENCV) -o build/utils.o $(LOPENCV)

build/detector.o: detector.cpp 
	$(CC) $(OPTIONS) -c detector.cpp -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME) -I/usr/include -o build/detector.o $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

clean:
	rm -f build/*.o yolonas.bin