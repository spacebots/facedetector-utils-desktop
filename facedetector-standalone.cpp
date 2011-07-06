#include <thread>
#include <FaceDetector.h>

FaceDetector detector0(0, "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
void f0() {
  detector0.StartFaceDetection();
}

FaceDetector detector1(1, "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
void f1() {
  detector1.StartFaceDetection();
}

int main(int argc, char** argv) {
  f0();
  printf("program working\n");
  return 0;
}
