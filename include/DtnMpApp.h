#pragma once

// std
#include <set>
#include <map>
#include <memory>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

// graphical user interface
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>


class DtnMpApp {
private:
    GLFWwindow* window;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
public:
    DtnMpApp();
    ~DtnMpApp();

    // Gui related functions
    void NewFrame();
    void Render();
    void Close();
    void glfw_error_callback(int error, const char* description);
    
    

    bool should_close = false;
};