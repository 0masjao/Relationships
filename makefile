CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src/main.cpp
DEPS = src/Person.h src/Student.h src/Professor.h src/Course.h src/Department.h
OBJ = $(SRC)
OUT = bin/university_system

all: $(OUT)

$(OUT): $(OBJ)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(OUT)

clean:
	rm -f $(OUT)
