//
// Created by miorlear on 1/1/26.
//

#ifndef IDGAFWID_GAMEEDITOR_H
#define IDGAFWID_GAMEEDITOR_H

#include "Player.h"

class GameEditor {
public:
    bool isOpen = false;

    GameEditor();
    void Draw(Player& player);
};


#endif //IDGAFWID_GAMEEDITOR_H