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
        int x = rand() % 1000;
        Invaders inv(x, 0);
        invs.push_back(inv);
        std::cout << x << std::endl;
    }
    if(invs[0].shape.getPosition().y > 900 and clock1.getElapsedTime().asSeconds() > 2.3f){
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
    for (int i = 0; i < invs.size(); i++) {
        invs[i].move();
    }
}
