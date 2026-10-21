#pragma once

#include <memory>
#include "NPC.h"

class Player
{
private:
    std::unique_ptr<NPC> currentCharacter{ nullptr }; // сам будет очищаться

public:
    void Create(std::unique_ptr<NPC> character);
    NPC* GetCharacter();
};