CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS=
SOURCE=main.o effect.o delay.o Circbuffer.o
TARGET=EffectBaseclass

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
