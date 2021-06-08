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

class InvadersManager {
    sf::Clock clock1;
public:
    InvadersManager();
    ~InvadersManager();
    
    void spawn();
    void draw(sf::RenderTarget *target);
    void move();
    
    std::vector<Invaders> invs;
    bool colision(std::vector<Bullet> &b);
};

#endif /* InvadersManager_hpp */
