//
//  Menu.hpp
//  Projekt
//
//  Created by KACPER on 05/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp
//#define MAX_NUMBER_OF_ITEMS = 3;

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

const int MAX_NUMBER_OF_ITEMS = 3;

using namespace std;
using namespace sf;

class Menu{
public:
    Menu(float width, float height);
    ~Menu();
    
    void draw(RenderWindow &window);
    void MoveUp();
    void MoveDown();
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif /* Menu_hpp */
