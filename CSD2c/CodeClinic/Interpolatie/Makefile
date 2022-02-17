CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS=
SOURCE=Inpol.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
