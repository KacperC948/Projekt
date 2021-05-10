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
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
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
                break;
        }
    }
}

void Game::update()
{
    pollEvents();
}

void Game::render()
{
    this->window->clear(sf::Color(255,0,0,255));
    this->window->display();
}
