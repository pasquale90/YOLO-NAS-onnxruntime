CC :=g++ -std=c++11 #gcc -std=c99 

OPTIONS :=-g -pedantic -Wall -Wextra -Wno-error
OBJECTS :=build/detector.o build/utils.o build/yolonas.o build/vision.o build/main.o

LOPENCV =-L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_video -lopencv_imgcodecs -lopencv_dnn
IOPENCV=/usr/local/include/opencv4
# CV=`pkg-config --cflags opencv` main.cpp `pkg-config --libs opencv`

IONNXRUNTIME:=/usr/local/onnxruntime-linux-x64-gpu-1.13.1/include
LONNXRUNTIME:=/usr/local/onnxruntime-linux-x64-gpu-1.13.1/lib
lONNXRUNTIME:=-lonnxruntime -lonnxruntime_providers_cuda -lonnxruntime_providers_tensorrt -lonnxruntime_providers_shared 

HEADERS:=include 

yolonas.bin: $(OBJECTS) #runnable
	$(CC) $(OPTIONS) $(OBJECTS) -I$(IOPENCV) -I$(IONNXRUNTIME) -o yolonas.bin $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

build/main.o: src/main.cpp
	$(CC) $(OPTIONS) -c src/main.cpp -I/usr/include -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME) -o build/main.o $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

build/vision.o: src/vision.cpp include/vision.h
	$(CC) $(OPTIONS) -c src/vision.cpp -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME) -I/usr/include -o build/vision.o $(LOPENCV)

build/yolonas.o: src/yolonas.cpp include/yolonas.h
	$(CC) $(OPTIONS) -c src/yolonas.cpp -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME)  -o build/yolonas.o $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

build/utils.o: src/utils.cpp include/utils.h
	$(CC) $(OPTIONS) -c src/utils.cpp -I$(HEADERS) -I$(IOPENCV) -o build/utils.o $(LOPENCV)

build/detector.o: src/detector.cpp include/detector.h
	$(CC) $(OPTIONS) -c src/detector.cpp -I$(HEADERS) -I$(IOPENCV) -I$(IONNXRUNTIME) -I/usr/include -o build/detector.o $(LOPENCV) -L$(LONNXRUNTIME) $(lONNXRUNTIME)

clean:
	rm -f build/*.o yolonas.bin