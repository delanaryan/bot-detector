CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = src/main.cpp src/tokenizer.cpp src/naive_bayes.cpp
OUT = detector

all: 
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
	