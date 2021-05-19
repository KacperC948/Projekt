//
//  Game.hpp
//  Projekt
//
//  Created by KACPER on 10/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "State.hpp"
#include "Menu.hpp"
#include "Options.hpp"

using namespace std;
using namespace sf;

class Game{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    
    std::stack<State*> states;
    
    void initVariables();
    void initWindow();
    void initStates();
    
public:
    Game();
    virtual ~Game();
    
    const bool running() const;
    
    void run();
    void pollEvents();
    void update();
    void render();
};

#endif /* Game_hpp */
