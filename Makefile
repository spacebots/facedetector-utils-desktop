# $Id: Makefile,v 1.4 2011/07/22 14:47:21 david Exp $
#
# Copyright (C) 2008-2011 INESC ID Lisboa.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#
# $Log: Makefile,v $
# Revision 1.4  2011/07/22 14:47:21  david
# Minor cleanup.
#
#
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
