CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS=
SOURCE=Circbuffer.o sqr.o oscillator.o main.o writeToFile.o
TARGET=circbuffer

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
