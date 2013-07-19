// $Id: facedetector-and-id.cpp,v 1.5 2013/07/19 09:48:28 david Exp $
//
// Copyright (C) 2008-2011 INESC ID Lisboa.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// $Log: facedetector-and-id.cpp,v $
// Revision 1.5  2013/07/19 09:48:28  david
// Hackaton.
//
// Revision 1.4  2011/07/22 14:47:21  david
// Minor cleanup.
//
// Revision 1.3  2011/07/22 14:31:09  ferreira
// Added Copyright comment
//

#include <thread>
#include <FaceDetector.h>
#include <cstdlib>
#include <iostream>
#include "Database.h"

efj::Database efjdb("/afs/l2f.inesc-id.pt/home/david/robots/facedetect/scenario-2/all.dat");

FaceDetector detector0(0, "/usr/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml");
void f0() {
  detector0.StartFaceDetection(&efjdb);
}

FaceDetector detector1(1, "/usr/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml");
void f1() {
  detector1.StartFaceDetection(&efjdb);
}

//FaceDetector detector2(2, "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
//void f2() {
//  detector2.StartFaceDetection(&efjdb);
//}

int main(int argc, char** argv) {
  std::thread t0(f0);
  std::thread t1(f1);
  //std::thread t2(f2);

  t0.join();
  t1.join();
  //t2.join();

  printf("program working\n");
  return 0;
}
