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

FaceDetector detector2(2, "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
void f2() {
  detector2.StartFaceDetection();
}

int main(int argc, char** argv) {
  std::thread t0(f0);
  std::thread t1(f1);
  std::thread t2(f2);

  t0.join();
  t1.join();
  t2.join();

  printf("program working\n");
  return 0;
}
