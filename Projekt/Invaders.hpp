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


class Invaders {
    
public:
    Invaders(int x, int y);
    ~Invaders();
    
    void draw(sf::RenderTarget *target);
    void move();
    
    sf::RectangleShape shape;
};


#endif /* Invaders_hpp */
