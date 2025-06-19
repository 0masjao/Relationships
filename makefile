CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src/university.cpp
OUT_DIR = bin
OUT = $(OUT_DIR)/university_system

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
