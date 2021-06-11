//
//  Pause.hpp
//  Projekt
//
//  Created by KACPER on 10/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Pause_hpp
#define Pause_hpp

#include <stdio.h>
#include "State.hpp"
#include "GameState.hpp"
#include "Menu.hpp"

const int MAX_NUMBER_OF_ITEMS5 = 4;

using namespace std;
using namespace sf;


class Pause : public State {
public:
    Pause(sf::RenderWindow* window, std::stack<State*>* states);
    ~Pause();
    
    void drawText();
    void MoveUp();
    void MoveDown();
    int getPressedItem() {return selectedItemIndex;}
    
    void initGui();
    void keyboardInput();
    void update();
    void update(sf::Event ev);
    void render(sf::RenderTarget* target=nullptr);
    void endState();
    
private:
    int selectedItemIndex;
    Font font;
    Text text[4];
    RectangleShape background;
};
#endif /* Pause_hpp */


