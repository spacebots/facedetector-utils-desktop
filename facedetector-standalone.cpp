// $Id: facedetector-standalone.cpp,v 1.4 2011/07/22 14:47:21 david Exp $
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
// $Log: facedetector-standalone.cpp,v $
// Revision 1.4  2011/07/22 14:47:21  david
// Minor cleanup.
//
// Revision 1.3  2011/07/22 14:31:09  ferreira
// Added Copyright comment
//

#include <thread>
#include <FaceDetector.h>

FaceDetector detector0(0, "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
void f0() {
  detector0.StartFaceDetection();
}

int main(int argc, char** argv) {
  f0();
  printf("program working\n");
  return 0;
}
