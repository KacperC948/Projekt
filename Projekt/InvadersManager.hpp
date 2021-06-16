//
//  InvadersManager.hpp
//  Projekt
//
//  Created by Michał Wołoszyński on 04/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef InvadersManager_hpp
#define InvadersManager_hpp

#include <stdio.h>
#include "Invaders.hpp"
#include <stdlib.h>
#include "Bullet.hpp"
#include <iostream>
#include <string>

class InvadersManager {
    sf::Clock clock1;
    
    sf::Clock clock2;
    sf::Time time2 = clock2.getElapsedTime();
    float speed = 1.f;
    int win = 3;
    int score = 0;
public:
    InvadersManager();
    ~InvadersManager();
    
    void spawn();
    void draw(sf::RenderTarget *target);
    void move();
    
    std::vector<Invaders> invs;
    void colision(std::vector<Bullet> &b);
    
    bool invadersWin();
    bool colisionWithP(sf::RectangleShape p);
    
    int getScore();
    int getWin();
    
    std::string scoreToString();
};

#endif /* InvadersManager_hpp */
