//
//  Menu.cpp
//  Projekt
//
//  Created by KACPER on 05/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Options.hpp"

Options::Options(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initGui();
    selectedItemIndex = 0;
}

Options::~Options()
{
    
}

void Options::drawText()
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS2; i++)
    {
        //window.draw(menu[i]);
    }
}

void Options::initGui(){
    int width = 1500;
    int height = 1000;
    
    background.setSize(Vector2f(width, height));
    background.setFillColor(sf::Color::Yellow);
    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        // handle error
    }
    text[0].setFont(font);
    text[0].setColor(sf::Color::Blue);
    text[0].setString("Difficulty");
    text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS2 + 1) * 1));
    
    text[1].setFont(font);
    text[1].setColor(sf::Color::Blue);
    text[1].setString("Video mode");
    text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS2 + 1) * 2));

    text[2].setFont(font);
    text[2].setColor(sf::Color::Blue);
    text[2].setString("Return");
    text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS2 + 1) * 3));
}

void Options::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::Blue);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Options::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS2)
    {
        text[selectedItemIndex].setColor(sf::Color::Blue);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Options::update(){
    keyboardInput();
}

void Options::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
    target->draw(this->background);
    for(int i = 0; i < 3; i++){
        target->draw(this->text[i]);
    }
}

void Options::endState(){
    
}

void Options::keyboardInput(){
    sf::Event e;
    bool test = true;
    
    while(test){
        while (this->window->pollEvent(e)){
            //if(e.type == sf::Event::KeyReleased){
//            switch (e.key.code) {
//                case sf::Keyboard::Return: {
//                    return;
//                }
//                    break;
//                case sf::Keyboard::Up:{
//                    cout << "teścik";
//                    MoveUp();
//                    return;
//                }
//                    break;
//                case sf::Keyboard::Down:{
//                    cout << "teścik2";
//                    MoveDown();
//                    return;
//                }
//                    break;
            switch (e.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
                    if(e.key.code == sf::Keyboard::Escape){
                        this->window->close();
                        cout << "test";
                    }
                    if(e.key.code == sf::Keyboard::Up){
                        MoveUp();
                        cout << "gora";
                        cout << selectedItemIndex << endl;
                    }
                    if(e.key.code == sf::Keyboard::Down){
                        MoveDown();
                        cout << "dol";
                        cout << selectedItemIndex << endl;
                    }
                    if(e.key.code == sf::Keyboard::Return){
                        cout << "enter";
                        if(selectedItemIndex == 1){
                            cout << "opcje" << endl;
                        }
                        if(selectedItemIndex == 2){
                            this->states->pop();
                            cout << "opcje" << endl;
                        }

                    }
                    //return;
                    break;
            }
            return;
        }
    }
}
