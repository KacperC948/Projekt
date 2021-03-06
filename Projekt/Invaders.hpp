//
//  Invaders.hpp
//  Projekt
//
//  Created by Michał Wołoszyński on 04/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Invaders_hpp
#define Invaders_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"


class Invaders {
public:
    Invaders(int x, int y);
    ~Invaders();
    
    void draw(sf::RenderTarget *target);
    void move(float speed);
    void initGui();
    sf::Texture t;
    sf::RectangleShape shape;
};


#endif /* Invaders_hpp */
