//
//  InvadersManager.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 04/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "InvadersManager.hpp"


InvadersManager::InvadersManager(){
    //spawn();
}

InvadersManager::~InvadersManager(){
    
}

void InvadersManager::spawn(){
    sf::Time time1 = clock1.getElapsedTime();
    if(invs.empty()){
        int x = rand() % 900;
        Invaders inv(x, 0);
        invs.push_back(inv);
        //std::cout << x << std::endl;
    }
    if(/*invs[0].shape.getPosition().y > 900 and */ clock1.getElapsedTime().asSeconds() > 1.f){
        int x = rand() % 1000;
        Invaders inv(x, 0);
        invs.push_back(inv);
        //std::cout << x << std::endl;
        clock1.restart();
    }
    std::cout << time1.asSeconds() << std::endl;
}

void InvadersManager::draw(sf::RenderTarget *target){
    for (int i = 0; i < invs.size(); i++) {
        invs[i].draw(target);
    }
}

void InvadersManager::move(){
    if(clock2.getElapsedTime().asSeconds() > 5){
        speed = speed + 0.3f;
        std::cout << speed << std::endl;
        clock2.restart();
    }
    for (int i = 0; i < invs.size(); i++) {
        invs[i].move(speed);
    }
}

void InvadersManager::colision(std::vector<Bullet> &b){
    for(size_t i = 0; i < b.size(); i++)
        for(size_t j = 0; j < invs.size(); j++){
            if(b[i].bullet.getGlobalBounds().intersects(invs[j].shape.getGlobalBounds())){
                score++;
                std::cout << score << std::endl;
                std::cout << "BOOM" << std::endl;
                //std::cout << i << std::endl;
                invs.erase(invs.begin()+j);
                b.pop_back();
                break;
            }
        }
}

bool InvadersManager::colisionWithP(sf::RectangleShape p){
    for (size_t i = 0; i < invs.size(); i++){
        if(p.getGlobalBounds().intersects(invs[i].shape.getGlobalBounds())){
            std::cout << "game over" << std::endl;
            return true;
        }
    }
    return false;
}


bool InvadersManager::invadersWin(){
    int win = 0;
    //test
    for(int i = 0; i < invs.size(); i++){
        if(invs[i].shape.getPosition().y > 900){
            win++;
            //std::cout << win << std::endl;
        }
    }
    if(win == 3){
        return true;
    }
    else return false;
}

int InvadersManager::getScore(){
    return score;
}
