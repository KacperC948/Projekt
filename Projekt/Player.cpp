//
//  Player.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 24/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Player.hpp"

Player::Player(){
    player.setSize(sf::Vector2f(100, 100));
    //player.setFillColor(sf::Color::White);
    player.setPosition(200, 700);
    //p1.setPosition(100, 100);
    //p1.setScale(10, 10);
}

Player::~Player(){
    
}

void Player::draw(sf::RenderTarget *target){
    sf::Texture texture;
    //sf::Texture texture1;
    //texture1.loadFromFile(resourcePath() + "bullet.png");
    texture.loadFromFile(resourcePath() + "Ship.png");
    //p1.setTexture(texture);
    player.setTexture(&texture);
    
    target->draw(player);
    for(int i = 0; i < bullets.size(); i++){
        target->draw(bullets[i].bullet);
        bullets[i].bullet.move(0.f, -7.f);
    }
    //target->draw(bullet);
}

void Player::move(){
    sf::Time time1 = clock1.getElapsedTime();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        player.move(-5.f, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        player.move(5.f, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(clock1.getElapsedTime().asSeconds() > 0.3f){
        shot();
        clock1.restart();
        }
        cout << time1.asSeconds() << endl;
        
    }
}

void Player::shot(){
    Bullet b1(player.getPosition().x + player.getSize().x / 2, player.getPosition().y);
    bullets.push_back(b1);
}
