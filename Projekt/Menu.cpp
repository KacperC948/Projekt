//
//  Menu.cpp
//  Projekt
//
//  Created by KACPER on 05/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Menu.hpp"

Menu::Menu(sf::RenderWindow* window, std::stack<State*> *states) : State(window, states)
{
    this->initGui();
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
    int width = 600;
    int height = 648;
    
    //sf::Texture texture;
    //texture.loadFromFile(resourcePath() + "menu.png");
    
    background.setSize(Vector2f(width, height));
    //background.setTexture(&texture);
    //background.setTextureRect(sf::IntRect(0,0,1500,100));
    //background.setFillColor(sf::Color(255,255,255,64));
    //background.setFillColor(sf::Color::Red);
    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    //this->window->draw(sprite);
    if (!font.loadFromFile(resourcePath() + "space_invaders.ttf"))
    {
        // handle error
    }
    text[0].setFont(font);
    text[0].setColor(sf::Color::White);
    text[0].setString("Start");
    text[0].setPosition(245, 300);
    //text[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    
    text[1].setFont(font);
    text[1].setColor(sf::Color::Green);
    text[1].setString("Options");
    text[1].setPosition(230, 400);
    //text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    text[2].setFont(font);
    text[2].setColor(sf::Color::Green);
    text[2].setString("Exit");
    text[2].setPosition(260, 500);
    //text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Menu::update(){
    keyboardInput();
}

void Menu::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "menu.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    this->window->draw(sprite);
    //target->draw(this->background);
    for(int i = 0; i < 3; i++){
        target->draw(this->text[i]);
    }
}

void Menu::endState(){
    
}

void Menu::keyboardInput(){
    sf::Event e;
    bool test = true;
    
    while(test){
        while (this->window->pollEvent(e)){
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
                        if(selectedItemIndex == 0){
                            this->states->push(new GameState(this->window, this->states));
                        }
                        if(selectedItemIndex == 1){
                            this->states->push(new Options(this->window, this->states));
                        }
                        if(selectedItemIndex == 2){
                            this->window->close();
                        }
                    }
                    //return;
                    break;
            }
            return;
        }
    }
}
