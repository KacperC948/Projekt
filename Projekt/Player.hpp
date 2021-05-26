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
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Bullet.hpp"

using namespace std;

class Player {
public:
    Player();
    ~Player();
    
    void draw(sf::RenderTarget *target);
    void drawBullet(sf::RenderTarget *target);
    void move();
    void shot();
    
private:
    sf::RectangleShape player;
    sf::Sprite p1;
    sf::RectangleShape bullet;
};

#endif /* Player_hpp */
