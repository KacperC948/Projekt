//
//  State.hpp
//  Projekt
//
//  Created by KACPER on 10/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include <iostream>
#include <stack>
#include "ResourcePath.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class State{
protected:
    std::vector<sf::Texture> textures;
    std::stack<State*> *states;
    sf::RenderWindow* window;
    
public:
    State(sf::RenderWindow* window, std::stack<State*> *states);
    virtual ~State();
    
    virtual void update() = 0;
    virtual void render(sf::RenderTarget* target=nullptr) = 0;
    virtual void endState() = 0;
};

#endif /* State_hpp */
