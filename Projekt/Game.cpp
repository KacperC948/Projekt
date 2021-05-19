//
//  Game.cpp
//  Projekt
//
//  Created by KACPER on 10/05/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Game.hpp"

void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(600, 600), "Space Invaders");
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initStates(); 
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
    
    while(!this->states.empty()){
        delete this->states.top();
        //this->states.pop();
    }
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                if(this->ev.key.code == sf::Keyboard::Up)
                    cout << "test1231231";
//                if(this->ev.key.code == sf::Keyboard::Return)
//                    states.pop();
                break;
        }
    }
}

void Game::update()
{
    //pollEvents();
    
    if(!this->states.empty()){
        this->states.top()->update();
    }
}

void Game::render()
{
    //this->window->clear(sf::Color(255,0,0,255));
    
    if(!this->states.empty()){
        this->states.top()->render();
    }
    
    this->window->display();
}

void Game::run(){
    while(running()){
        update();
        render();
    }
}

void Game::initStates(){
    this->states.push(new Options(this->window, &this->states));
    this->states.push(new Menu(this->window, &this->states));
}
