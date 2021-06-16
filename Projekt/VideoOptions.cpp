//
//  VideoMode.cpp
//  Projekt
//
//  Created by KACPER on 16/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "VideoOptions.hpp"

VideoOptions::VideoOptions(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initGui();
    selectedItemIndex = 0;
}

VideoOptions::~VideoOptions()
{
    
}

void VideoOptions::drawText()
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS2; i++)
    {
        //window.draw(menu[i]);
    }
}

void VideoOptions::initGui(){
    int width = 600;
    int height = 648;
    
    background.setSize(Vector2f(width, height));
    background.setFillColor(sf::Color::Yellow);
    if (!font.loadFromFile(resourcePath() + "space_invaders.ttf"))
    {
        // handle error
    }
    text[0].setFont(font);
    text[0].setColor(sf::Color::White);
    text[0].setString("Full screen");
    text[0].setPosition(390,380);
    
    text[1].setFont(font);
    text[1].setColor(sf::Color::Green);
    text[1].setString("Small");
    text[1].setPosition(450,450);

    text[2].setFont(font);
    text[2].setColor(sf::Color::Green);
    text[2].setString("Return");
    text[2].setPosition(440,520);
}

void VideoOptions::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void VideoOptions::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS2)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void VideoOptions::update(){
    keyboardInput();
}

void VideoOptions::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
    sf::Texture texture;
    texture.loadFromFile(resourcePath() + "menu.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    this->window->draw(sprite);
    for(int i = 0; i < 3; i++){
        target->draw(this->text[i]);
    }
}

void VideoOptions::endState(){
    
}

void VideoOptions::keyboardInput(){
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
                        if(selectedItemIndex == 0){ //FULSCREEN
                            cout << "videoOptions fullscreen" << endl;
                        }
                        if(selectedItemIndex == 1){ //SMALL
                            cout << "videoOptions small" << endl;
                        }
                        if(selectedItemIndex == 2){
                            this->states->pop();
                            cout << "videoOptions return" << endl;
                        }

                    }
                    //return;
                    break;
            }
            return;
        }
    }
}
