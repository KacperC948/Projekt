//
//  Bullet.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 26/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Bullet.hpp"

Bullet::Bullet(float x, float y){
    bullet.setSize(sf::Vector2f(50, 100));
    bullet.setPosition(x, y);
}

Bullet::~Bullet(){
    
}

void Bullet::draw(sf::RenderTarget *target){
    this->draw(target);
}
