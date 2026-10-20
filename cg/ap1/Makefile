CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O3 -fopenmp -Iheader
LDFLAGS = -lglfw -lGL -fopenmp

SRC = \
    main.cpp \
    src/Vector3.cpp \
    src/Ray.cpp \
    src/Color.cpp \
    src/Material.cpp \
    src/PointLight.cpp \
    src/Framebuffer.cpp \
    src/Sphere.cpp \
    src/Plane.cpp \
    src/Cylinder.cpp \
    src/Cone.cpp \
    src/Pyramid.cpp \
    src/Camera.cpp \
    src/Scene.cpp

TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET) *.ppm
