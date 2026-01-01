#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"
int main() {
    //Initialization
    const int screenWidth = 1600;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Raylib Attemp1");

    //Define the character
    Vector2 ballPosition = {(float)screenWidth/2, (float)screenHeight/2};
    float ballSpeed = 1.0f;

    rlImGuiSetup(true);
    ImGuiIO& io = ImGui::GetIO();
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.FontGlobalScale = 2.0f;

    //Main Loop
    while (!WindowShouldClose()) {
        //Module 1 - (movement)
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x +=ballSpeed;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= ballSpeed;
        if (IsKeyDown(KEY_UP)) ballPosition.y -=ballSpeed;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += ballSpeed;

        //Module 2 - Drawing
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Move the ball with the keys!", 10, 10, 20, DARKGRAY);
            DrawCircleV(ballPosition, 40, MAROON);

            // ToolKit
            rlImGuiBegin();
                ImGui::DockSpaceOverViewport(0,ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
                ImGui::Begin("Inspector");
                ImGui::SliderFloat("Position X", &ballPosition.x, 0, 1600);
                ImGui::SliderFloat("Position Y", &ballPosition.y, 0, 720);
                ImGui::SliderFloat("Speed", &ballSpeed, 0, 4);
                ImGui::Text("FPS: %i", GetFPS());
                ImGui::End();
            rlImGuiEnd();
        EndDrawing();

        //Render Toolkit Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}