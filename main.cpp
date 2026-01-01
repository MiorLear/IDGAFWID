#include "raylib.h"

int main() {
    //Initialization
    const int screenWidth = 1600;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Raylib Attemp1");

    //Define the character
    Vector2 ballPosition = {.x=(float)screenWidth/2, .y=(float)screenHeight/2};
    float ballSpeed = 1.0f;

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
        EndDrawing();
    }
    CloseWindow();
    return 0;
}