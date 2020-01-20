CXX=g++
CXXFLAGS=-std=c++14
# Include and link path
ifeq ($(OS),Windows_NT)
	INC_PATH=-I../thirdparty/SFML-2.5.1/include
	LIB_PATH=-L../thirdparty/SFML-2.5.1/lib
else
	# Other plaform
endif

D_LIB=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
S_LIB=-DSFML_STATIC -static -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s
S_LIB+=-lopengl32 -lfreetype -lwinmm -lgdi32
S_LIB+=-lopenal32 -lvorbisenc -lvorbisfile -lvorbis -lFLAC -lm -logg
LIBS=$(S_LIB)

ifeq ($(LIBS), $(S_LIB))
	DEFINE=-DSFML_STATIC
endif

EXE=input_example
SOURCES=main.cpp key.cpp

OBJS=$(addsuffix .o, $(basename $(notdir $(SOURCES))))

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INC_PATH) $(LIB_PATH) $(DEFINE) -c $< -o $@

all: $(EXE)
	@echo Build complete for $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC_PATH) $(LIB_PATH) $^ $(LIBS) -o $@

.PHONY: clean
clean:
	$(RM) -f $(OBJS) $(EXE)