//
// Created by miorlear on 1/1/26.
//

#ifndef IDGAFWID_PLAYER_H
#define IDGAFWID_PLAYER_H
#include "raylib.h"

class Player {
public:
    //Variables
    Vector2 position;
    float speed;
    float radius;
    Color color;

    //Constructor
    Player();

    //Voids
    void Update();
    void Draw();
    void DrawInspector();
};


#endif //IDGAFWID_PLAYER_H