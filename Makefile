IMGUI_DIR = ./vendor/imgui
VENDOR_DIR = ./vendor
SRC_DIR = ./src
TEST_DIR = ./src/tests

INCLUDES = -I/usr/local/include -I$(VENDOR_DIR) -I${SRC_DIR} -I${TEST_DIR}

LIBS = -L/usr/local/lib -lglfw  -lGLEW -lassimp -framework OpenGL


CXXFLAGS = -std=c++17 -DIMGUI_IMPL_OPENGL_LOADER_GLAD -g
#CXXFLAGS += -DIMGUI_IMPL_OPENGL_LOADER_GL3W

SOURCES = $(wildcard src/*.cpp)
SOURCES += $(wildcard src/LightCaster/*.cpp)
SOURCES += $(wildcard src/Mapping/*.cpp)
SOURCES += $(wildcard src/Material/*.cpp)
SOURCES += $(wildcard src/Model/*.cpp)
SOURCES += $(wildcard src/tests/*.cpp)
SOURCES += src/glad.c
SOURCES += $(wildcard $(IMGUI_DIR)/*.cpp)
SOURCES += $(wildcard vendor/stb_image/*.cpp)
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

%.o:src/%.c
	$(CC) $(CXXFLAGS) -c -o $@ $<

%.o:src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<
%.o:src/LightCaster/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<
%.o:src/Mapping/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<
%.o:src/Material/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<
%.o:src/Model/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<
%.o:src/tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

%.o:$(IMGUI_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<
%.o:vendor/stb_image/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

demo: $(OBJS)
	g++ -o $@.exe $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -rf *.exe
	rm -rf *.o

.PHONY: demo
