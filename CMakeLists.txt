cmake_minimum_required(VERSION 3.11)
project(IDGAFWID CXX)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

# 1. Raylib (Estable)
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# 2. Dear ImGui (Cambiamos a la rama 'docking' que pide rlImGui)
FetchContent_Declare(imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG docking # Esta rama es la que tiene 'GetPlatformIO'
)
FetchContent_MakeAvailable(imgui)

# 3. rlImGui
FetchContent_Declare(rlimgui GIT_REPOSITORY https://github.com/raylib-extras/rlImGui.git GIT_TAG main)
FetchContent_MakeAvailable(rlimgui)

# Definimos los fuentes de ImGui
set(IMGUI_SOURCES
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
)

add_executable(IDGAFWID
        main.cpp
        ${IMGUI_SOURCES}
        ${rlimgui_SOURCE_DIR}/rlImGui.cpp
)

# Agregamos ${imgui_SOURCE_DIR} para que rlImGui encuentre imgui.h
target_include_directories(IDGAFWID PRIVATE
        ${raylib_SOURCE_DIR}/src
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends # Por si acaso
        ${rlimgui_SOURCE_DIR}
)

target_link_libraries(IDGAFWID raylib GL m pthread dl rt X11)