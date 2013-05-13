
LDFLAGS+=-lopencv_core -lopencv_imgproc -lopencv_objdetect -lopencv_highgui
CC=g++

pictionary: main.cc
	$(CC) -o $@ $^ $(LDFLAGS)
