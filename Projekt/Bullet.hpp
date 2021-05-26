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

class Bullet {
    
    sf::RectangleShape bullet;
    
public:
    Bullet(float x, float y);
    ~Bullet();
    
    void draw(sf::RenderTarget *target);
};

#endif /* Bullet_hpp */
