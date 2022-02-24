CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS= -ljack
SOURCE=main.o effect.o tremolo.o sine.o sqr.o oscillator.o jack_module.o
TARGET=tremolo

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
