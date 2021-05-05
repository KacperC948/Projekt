//
//  Options.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 05/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Options.hpp"

Options::Options(float width, float height) {
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        // handle error
    }

    options[0].setFont(font);
    options[0].setColor(sf::Color::Red);
    options[0].setString("Test123");
    options[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS2 + 1) * 1));

    options[1].setFont(font);
    options[1].setColor(sf::Color::White);
    options[1].setString("Options22");
    options[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS2 + 1) * 2));

    options[2].setFont(font);
    options[2].setColor(sf::Color::White);
    options[2].setString("Exit123");
    options[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS2 + 1) * 3));

    selectedItemIndex = 0;
}

Options::~Options(){
    
}

void Options::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS2; i++)
    {
        window.draw(options[i]);
    }
}
