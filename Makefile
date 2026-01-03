CXX = g++
CXXFLAGS = -Wall -g
TARGET = main.exe
SRC = main.cpp InstanceReader.cpp Params.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)