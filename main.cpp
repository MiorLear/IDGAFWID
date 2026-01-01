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

            rlImGuiBegin();
                // ToolKit
                ImGui::Begin("Control de Experimento");
                ImGui::SliderFloat("Posicion X", &ballPosition.x, 0, 1600);
                ImGui::SliderFloat("Velocidad", &ballSpeed, 0, 4);
                ImGui::Text("FPS: %i", GetFPS());
                ImGui::End();
            rlImGuiEnd();
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}