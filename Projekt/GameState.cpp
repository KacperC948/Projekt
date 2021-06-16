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
    

    
    
    
    background.setPosition(100, 100);
    if (!font.loadFromFile(resourcePath() + "space_invaders.ttf"))
    {
        // handle error
    }
    std::string s = std::to_string(invs.getWin());
    text[0].setFont(font);
    text[0].setColor(sf::Color::White);
    text[0].setString(s);
    text[0].setCharacterSize(30);
    text[0].setPosition(130, 0);
    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Lifes: ");
    text[1].setCharacterSize(30);
    text[1].setPosition(10, 0);
    
    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Score: ");
    text[2].setCharacterSize(30);
    text[2].setPosition(780, 0);
    std::string s1 = std::to_string(invs.getScore());
    text[3].setFont(font);
    text[3].setColor(sf::Color::White);
    text[3].setString(s1);
    text[3].setCharacterSize(30);
    text[3].setPosition(910, 0);
}

void GameState::MoveUp()
{
//    if (selectedItemIndex - 1 >= 0)
//    {
//        text[selectedItemIndex].setColor(sf::Color::Green);
//        selectedItemIndex--;
//        text[selectedItemIndex].setColor(sf::Color::White);
//    }
}

void GameState::MoveDown()
{
    background.move(0, 0.5f);
}

void GameState::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->states->push(new Pause(this->window, this->states));
    }
    std::string s = std::to_string(invs.getWin());
    std::string s1 = std::to_string(invs.getScore());
    text[0].setString(s);
    text[3].setString(s1);
    player.move();
    invs.spawn();
    invs.move();
    invs.colision(player.bullets);
    if(invs.colisionWithP(player.returnPlayer()) == true){
            this->states->push(new GameOver(this->window, this->states ,this->getScore2()));
        }
        if(invs.invadersWin() == true){
            this->states->push(new GameOver(this->window, this->states,this->getScore2()));
        }
}

void GameState::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
    this->window->clear();
    this->player.draw(target);
    this->invs.draw(target);
    for(int i = 0; i < 4; i++){
        target->draw(this->text[i]);
    }
    
}

void GameState::endState(){
    
}

void GameState::keyboardInput(){
    p->move();
}

int GameState::getScore2(){
    return invs.getScore();
}
