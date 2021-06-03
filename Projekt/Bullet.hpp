//
//  Bullet.hpp
//  Projekt
//
//  Created by Michał Wołoszyński on 26/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>

class Bullet {
    
public:
    Bullet(float x, float y);
    ~Bullet();
    sf::RectangleShape bullet;
    void initGui();
    

    sf::Texture t1;
    
};

#endif /* Bullet_hpp */
