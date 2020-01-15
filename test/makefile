CXX=g++
CXXFLAGS=-std=c++14
# Include and link path
INC_PATH=-I../thirdparty/SFML-2.5.1/include
LIB_PATH=-L../thirdparty/SFML-2.5.1/lib

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

EXE=test
SOURCES=main.cpp

OBJS=$(addsuffix .o, $(basename $(notdir $(SOURCES))))

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INC_PATH) $(LIB_PATH) $(LIBS) $< -o $@

all: $(EXE)
	@echo Build complete for $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC_PATH) $(LIB_PATH) $(LIBS) $^ -o $@

.PHONY: clean
clean:
	$(RM) -f $(OBJS) $(EXE)