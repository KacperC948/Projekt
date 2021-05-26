//
//  Player.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 24/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Player.hpp"

Player::Player(){
    //player.setSize(sf::Vector2f(100, 100));
    //player.setFillColor(sf::Color::White);
    //player.setPosition(200, 600);
    //p1.setPosition(100, 100);
    //p1.setScale(100, 100);
}

Player::~Player(){
    
}

void Player::draw(sf::RenderTarget *target){
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "Ship.png");
    p1.setTexture(texture);
   // player.setTexture(&texture);
    //target->draw(player);
    target->draw(p1);
}

void Player::move(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        player.move(-5.f, 0);
        p1.move(-4.f, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        player.move(5.f, 0);
    }
}
