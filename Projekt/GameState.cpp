//
//  GameState.cpp
//  Projekt
//
//  Created by Michał Wołoszyński on 23/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "GameState.hpp"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initGui();
    selectedItemIndex = 0;
}

GameState::~GameState()
{
    
}

void GameState::drawText()
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS3; i++)
    {
        //window.draw(menu[i]);
    }
}

void GameState::initGui(){
    int width = 200;
    int height = 200;
    
    background.setSize(Vector2f(width, height));
    background.setFillColor(sf::Color::Yellow);
    
    background.setPosition(100, 100);
    if (!font.loadFromFile(resourcePath() + "space_invaders.ttf"))
    {
        // handle error
    }
    
}

void GameState::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void GameState::MoveDown()
{
    background.move(0, 0.5f);
}

void GameState::update(){
    keyboardInput();
}

void GameState::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
//    sf::Texture texture;
//    texture.loadFromFile(resourcePath() + "menu.png");

//    sf::Sprite sprite;
//    sprite.setTexture(texture);
    this->window->clear();
    this->window->draw(background);

}

void GameState::endState(){
    
}

void GameState::keyboardInput(){
    sf::Event e;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        background.move(0, -0.5f);
            cout << "test1" << endl;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            background.move(0, 0.5f);
            cout << "test2" << endl;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            background.move(-0.5f, 0);
            cout << "test2" << endl;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            background.move(0.5f, 0);
            cout << "test2" << endl;
        }
}
