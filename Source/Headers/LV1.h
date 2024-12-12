#pragma
#ifndef LV1_H
#define LV1_H

#include "LevelManager.h"
#include "Goomba.h"
#include "Koopa.h"

class LV1 : public LevelManager {
public:
    LV1(PlayerManager* player, sf::RenderWindow *window);
    ~LV1();
};

#endif // LV1_H

