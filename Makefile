FACEDETECTOR_DIR = ${HOME}/workspace/facedetector 

LIB = -L$(FACEDETECTOR_DIR) -lfacedetector -L/usr/lib64 -lopencv_core -lopencv_highgui -lopencv_objdetect
INC=-I. -I$(FACEDETECTOR_DIR) -I/usr/include/opencv
CXXFLAGS = -fPIC -fpic -std=c++0x

all: facedetector-standalone facedetector

facedetector: facedetector.o
	g++ -o $@ $^ $(LIB)

facedetector-standalone: facedetector-standalone.o
	g++ -o $@ $^ $(LIB)

%.o: %.cpp
	g++ $(INC) $(CXXFLAGS) -c $< -o $@

clean:
	-rm facedetector.o facedetector facedetector-standalone.o facedetector-standalone
