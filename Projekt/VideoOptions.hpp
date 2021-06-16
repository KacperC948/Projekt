//
//  VideoMode.hpp
//  Projekt
//
//  Created by KACPER on 16/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef VideoMode_hpp
#define VideoMode_hpp

#include <stdio.h>
#include "State.hpp"
#include "GameState.hpp"
#include "Menu.hpp"


const int MAX_NUMBER_OF_ITEMS6 = 3;

using namespace std;
using namespace sf;

class VideoOptions : public State{
public:
    VideoOptions(sf::RenderWindow* window, std::stack<State*>* states);
    ~VideoOptions();
    
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
    sf::Font font;
    //sf::Text menu[MAX_NUMBER_OF_ITEMS];
    
    sf::Text text[3];
    
    
    sf::RectangleShape background;

};
#endif /* VideoMode_hpp */
