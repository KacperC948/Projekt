//
//  Menu.cpp
//  Projekt
//
//  Created by KACPER on 05/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Menu.hpp"


Menu::Menu(sf::RenderWindow* window) : State(window)
{
    this->initGui();
//    int width = 400;
//    int height = 400;
//    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
//    {
//        // handle error
//    }
//
//    menu[0].setFont(font);
//    menu[0].setColor(sf::Color::Red);
//    menu[0].setString("Test");
//    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
//
//    menu[1].setFont(font);
//    menu[1].setColor(sf::Color::White);
//    menu[1].setString("Options");
//    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
//
//    menu[2].setFont(font);
//    menu[2].setColor(sf::Color::White);
//    menu[2].setString("Exit");
//    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
//
    selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::drawText()
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        //window.draw(menu[i]);
    }
}

void Menu::initGui(){
    int width = 400;
    int height = 400;
    
    background.setSize(Vector2f(width, height));
    background.setFillColor(sf::Color::Red);
    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        // handle error
    }
    text[0].setFont(font);
    text[0].setColor(sf::Color::Blue);
    text[0].setString("Test");
    text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    
    text[1].setFont(font);
    text[1].setColor(sf::Color::Blue);
    text[1].setString("Test2");
    text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    text[2].setFont(font);
    text[2].setColor(sf::Color::Blue);
    text[2].setString("Test3");
    text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::Blue);
    }
}
//
void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::Blue);
    }
}

void Menu::update(){
    keyboardInput();
    
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        MoveUp();
//        cout << "test1" << endl;
//        cout << selectedItemIndex;
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
//        this->MoveDown();
//        cout << "test2" << endl;
//        cout << selectedItemIndex;
//    }
}

void Menu::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
    //draw(this->target);
    target->draw(this->background);
    for(int i = 0; i < 3; i++){
        target->draw(this->text[i]);
    }
    //target->draw(this->text);
}

void Menu::endState(){
    
}

void Menu::keyboardInput(){
    sf::Event e;
    
    while (this->window->pollEvent(e)) {
        cout << "tesasdad";
        switch (e.type) {
            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::Up){
                    cout << "gówno";
                    MoveUp();
                }
                if(e.key.code == sf::Keyboard::Down){
                    cout << "Dupa";
                    MoveDown();
                }
                break;
        }
    }
}
