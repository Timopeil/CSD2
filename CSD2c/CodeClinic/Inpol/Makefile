CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS=
SOURCE=linInp.o
TARGET=NNMap

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
