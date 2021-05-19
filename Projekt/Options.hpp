//
//  Menu.hpp
//  Projekt
//
//  Created by KACPER on 05/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Options_hpp
#define Options_hpp
//#define MAX_NUMBER_OF_ITEMS = 3;

#include "State.hpp"

const int MAX_NUMBER_OF_ITEMS2 = 3;

using namespace std;
using namespace sf;

class Options : public State{
public:
    Options(sf::RenderWindow* window);
    ~Options();
    
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

#endif /* Menu_hpp */
