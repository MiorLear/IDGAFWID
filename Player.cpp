//
// Created by miorlear on 1/1/26.
//

#include "Player.h"
#include "imgui.h"
#include "raylib.h"


Player::Player() {
    position ={GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    speed = 0.5f;
    radius= 40.0f;
    color = MAROON;
}

void Player::Update() {
    if (IsKeyDown(KEY_RIGHT)) position.x+=speed;
    if (IsKeyDown(KEY_LEFT)) position.x-=speed;
    if (IsKeyDown(KEY_UP)) position.y-=speed;
    if (IsKeyDown(KEY_DOWN)) position.y+=speed;
}

void Player::Draw() {
    DrawCircleV(position, radius, color);
}

void Player::DrawInspector() {
    ImGui::DockSpaceOverViewport(0,ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
    ImGui::Begin("Player Inspector");
    ImGui::SliderFloat("Position X", &position.x, 0, 1600);
    ImGui::SliderFloat("Position Y", &position.y, 0, 720);
    ImGui::SliderFloat("Speed", &speed, 0, 4);
    ImGui::End();
}

