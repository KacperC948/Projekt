//
//  Player.hpp
//  Projekt
//
//  Created by Michał Wołoszyński on 24/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Player {
public:
    Player();
    ~Player();
    
    void draw(sf::RenderTarget *target);
    void move();
    
private:
    sf::RectangleShape player;
    sf::Sprite p1;
    
};

#endif /* Player_hpp */
