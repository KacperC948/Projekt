//
//  Invaders.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 04/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Invaders.hpp"

Invaders::Invaders(int x, int y){
    shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
    
    
}

Invaders::~Invaders(){
    
}

void Invaders::draw(sf::RenderTarget *target){
    initGui();
    target->draw(shape);
}


void Invaders::move(){
    shape.move(0.f, 1.3f);
}

void Invaders::initGui(){
    t.loadFromFile(resourcePath() + "inv.png");
    shape.setTexture(&t);
}
