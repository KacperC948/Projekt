//
//  GameOver.hpp
//  Projekt
//
//  Created by KACPER on 09/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef GameOver_hpp
#define GameOver_hpp

#include <stdio.h>
#include "State.hpp"

const int MAX_NUMBER_OF_ITEMS3 = 3;

using namespace std;
using namespace sf;

class GameOver : public State {
public:
    GameOver(sf::RenderWindow* window, std::stack<State*>* states);
    ~GameOver();
    
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
    int selectedItemIndex = 1;
    Font font;
    Text text[2];
    RectangleShape background;
};


#endif /* GameOver_hpp */
