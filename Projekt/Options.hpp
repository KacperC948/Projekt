//
//  Options.hpp
//  Projekt
//
//  Created by Michał Wołoszyński on 05/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#ifndef Options_hpp
#define Options_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

const int MAX_NUMBER_OF_ITEMS2 = 3;

using namespace std;
using namespace sf;

class Options{
public:
    Options(float width, float height);
    ~Options();

    void draw(RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int getPressedItem() {return selectedItemIndex;}
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text options[MAX_NUMBER_OF_ITEMS2];
};

#endif /* Options_hpp */
