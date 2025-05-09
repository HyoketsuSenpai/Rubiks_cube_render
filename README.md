# Rubik's Cube in OpenGL

This C++ project renders a 3D Rubik's Cube using OpenGL and allows interactive rotation of the cube and its individual faces. It utilizes modern OpenGL practices and libraries like GLFW and GLAD.

## 🧱 Project Highlights

* 3D Rubik's Cube rendered with OpenGL
* Uses modern OpenGL pipeline: shaders, VAOs, VBOs
* Clean and modular structure with reusable graphics code
* GLM for transformations and math

## 🎮 Features

* Automatic continuous rotation of the entire Rubik's Cube
  Full 3D rotation of the entire cube using mouse drag or keys
* Face-wise 90° rotation on valid moves (like a real Rubik's Cube)
* Visual separation of colored cubelets for realism
* Basic camera system for view manipulation

## 📁 Project Structure

```
RubiksCubeOpenGL/
├── include/                 # Header files for GLFW, GLAD, GLM
│   ├── GLFW/
│   ├── KHR/
│   ├── glad/
│   └── glm/
├── lib/                     # Static libraries
│   └── libglfw3.a
├── src/                     # Source files
│   ├── glad.c
│   ├── main.cpp
│   ├── shader_s.h
├── 3.3.shader.vs            # Vertex shader
├── 3.3.shader.fs            # Fragment shader
├── CMakeLists.txt           # Build configuration
├── build_cmake.bat          # Windows build script
```

## 🧰 Tech Stack

* C++
* OpenGL (Core Profile)
* GLFW – for window/context/input
* GLAD – for OpenGL function loading
* GLM – for linear algebra

## 📄 License

This project is created for learning and experimentation with OpenGL and 3D graphics in C++. Feel free to use, modify, and share.

---

*Turning cubes and pushing pixels – one rotation at a time 🎲✨*
