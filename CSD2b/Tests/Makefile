CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS= -ljack
SOURCE=jack_module.o sine.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
