//
//  Game.hpp
//  Projekt
//
//  Created by KACPER on 10/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    
    void initVariables();
    void initWindow();
public:
    Game();
    virtual ~Game();
    
    const bool running() const;
    
    void pollEvents();
    void update();
    void render();
};

#endif /* Game_hpp */
