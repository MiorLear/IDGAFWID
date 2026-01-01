#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"
#include "Player.h"
#include "GameEditor.h"
int main() {

    InitWindow(1920, 1080, "IGAFWID - Modular");
    SetTargetFPS(60);

    rlImGuiSetup(true);
    ImGuiIO& io = ImGui::GetIO();
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.FontGlobalScale = 2.0f;

    Player myPlayer;
    GameEditor editor;

    while (!WindowShouldClose()) {
        //Update
        myPlayer.Update();
        if (IsKeyPressed(KEY_F1)) editor.isOpen = !editor.isOpen;

        //Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            myPlayer.Draw();
            editor.Draw(myPlayer);
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}