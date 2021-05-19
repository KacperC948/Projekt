//
//  State.cpp
//  Projekt
//
//  Created by KACPER on 10/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "State.hpp"

State::State(sf::RenderWindow* window, std::stack<State*> *states){
    this->window = window;
    this->states = states;
}

State::~State(){
    
}
