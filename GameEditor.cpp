//
// Created by miorlear on 1/1/26.
//

#include "GameEditor.h"
#include "rlImGui.h"
#include "imgui.h"
#include "imgui_internal.h"

GameEditor::GameEditor() {}

void GameEditor::Draw(Player& player) {
    if (!isOpen) return;
    rlImGuiBegin();
    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;
    ImGui::DockSpaceOverViewport(dockspace_id, ImGui::GetMainViewport(), dockspace_flags);

    //Player Inspector
    ImGui::Begin("Inspector");
    //ImGui::SetWindowFontScale(2.0f);

    if (ImGui::CollapsingHeader("Player", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::SliderFloat("Pos X", &player.position.x, 0, 1600);
        ImGui::SliderFloat("Pos Y", &player.position.y, 0, 720);
        ImGui::SliderFloat("Speed", &player.speed, 0, 10);

        Color col = player.color;
        float visualColor[4] = {
            col.r / 255.0f,
            col.g / 255.0f,
            col.b / 255.0f,
            col.a / 255.0f
        };

        if (ImGui::ColorEdit4("Color del Personaje", visualColor)) {
            player.color.r = (unsigned char)(visualColor[0] * 255);
            player.color.g = (unsigned char)(visualColor[1] * 255);
            player.color.b = (unsigned char)(visualColor[2] * 255);
            player.color.a = (unsigned char)(visualColor[3] * 255);
        }
    }

    //Future other features

    ImGui::Separator();
    ImGui::Text("Rendimiento %.1f FPS", ImGui::GetIO().Framerate);
    ImGui::End();
    rlImGuiEnd();


}