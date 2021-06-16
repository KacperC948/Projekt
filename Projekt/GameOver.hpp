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
#include "GameState.hpp"
#include "Menu.hpp"
#include "InvadersManager.hpp"

const int MAX_NUMBER_OF_ITEMS4 = 3;

using namespace std;
using namespace sf;

class GameOver : public State, public InvadersManager {
public:
    GameOver(sf::RenderWindow* window, std::stack<State*>* states, int score);
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
    int score2;
    int selectedItemIndex;
    Font font;
    Text text[5];
    RectangleShape background;
};


#endif /* GameOver_hpp */
