FACEDETECTOR_DIR = ${HOME}/workspace/facedetector 
LIBEFJDIR = ${HOME}/workspace/efj
EIGEN=/afs/l2f.inesc-id.pt/home/ferreira/face-recognition/eigen
QTDIR=/usr/lib64/qt4

LDFLAGS = -L$(FACEDETECTOR_DIR) -lfacedetector -L/usr/lib64 -lopencv_core -lopencv_highgui -lopencv_objdetect \
	-L$(LIBEFJDIR) -lefj -lboost_filesystem -lQtGui -lgomp

INC=-I. -I$(FACEDETECTOR_DIR) -I$(LIBEFJDIR) -I/usr/include/opencv -I$(EIGEN) -I$(QTDIR)/include/QtCore -I$(QTDIR)/include/QtGui
CXXFLAGS = -fPIC -fpic -std=c++0x

all: facedetector-standalone facedetector facedetector-and-id

facedetector: facedetector.o
	g++ -o $@ $^ $(LDFLAGS)

facedetector-standalone: facedetector-standalone.o
	g++ -o $@ $^ $(LDFLAGS)

facedetector-and-id: facedetector-and-id.o
	g++ -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	g++ $(INC) $(CXXFLAGS) -c $< -o $@

clean:
	-rm facedetector.o facedetector facedetector-standalone.o facedetector-standalone facedetector-and-id.o facedetector-and-id
