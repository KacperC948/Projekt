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
    background.move(0, -10);
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
    
    this->window->draw(background);
    //target->draw(this->background);
    for(int i = 0; i < 3; i++){
        target->draw(this->text[i]);
    }
}

void GameState::endState(){
    
}

void GameState::keyboardInput(){
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
                        //MoveDown();
                        //background.move(0.f, -10.f);
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
