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
    texture.loadFromFile(resourcePath() + "Ship.png");
    player.setTexture(&texture);
    target->draw(player);
    for(int i = 0; i < bullets.size(); i++){
        bullets[i].initGui();
        target->draw(bullets[i].bullet);
        bullets[i].bullet.move(0.f, -3.f);
        if(bullets[i].bullet.getPosition().y < 0){
            bullets.erase(bullets.begin()+i);
        }
    }
}

void Player::move(){
    sf::Time time1 = clock1.getElapsedTime();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(player.getPosition().x >= 0){
            player.move(-5.f, 0);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(player.getPosition().x + player.getSize().x < 1000){
            player.move(5.f, 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(clock1.getElapsedTime().asSeconds() > 0.1f){
            shot();
            clock1.restart();
        }
        //cout << time1.asSeconds() << endl;
    }
}

void Player::shot(){
    Bullet b1(player.getPosition().x + player.getSize().x / 2, player.getPosition().y);
    bullets.push_back(b1);
}

sf::RectangleShape Player::returnPlayer(){
    return player;
}
