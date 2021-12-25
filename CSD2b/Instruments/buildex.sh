CXX=g++
SOURCE=cppscript.o main.o
CXXFLAGS=-wall -std=c++14
LDFLAGS=
TARGET=

cppscript: $(SOURCE)
  $(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o
  $(CXX) -c $(CXXFLAGS)
clean:
  rm -f *.o cppscript
