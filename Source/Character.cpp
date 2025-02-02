﻿#include "headers/Character.h"
#include <stdexcept>

PlayerManager* Character::createPlayer(const std::string& name) {
    if (name == "Mario") {
        return new Mario; 
    }
    else if (name == "Luigi") {
        return new Luigi; 
    }
    else {
        throw std::invalid_argument("Invalid character name: " + name); // Gestion des erreurs
    }
}
