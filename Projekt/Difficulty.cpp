//
//  Difficulty.cpp
//  Projekt
//
//  Created by KACPER on 16/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Difficulty.hpp"

Difficulty::Difficulty(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initGui();
    selectedItemIndex = 0;
}

Difficulty::~Difficulty()
{
    
}

void Difficulty::drawText()
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS10; i++)
    {
        //window.draw(menu[i]);
    }
}

void Difficulty::initGui(){
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
    text[0].setString("NORMAL");
    text[0].setPosition(440,380);
    
    text[1].setFont(font);
    text[1].setColor(sf::Color::Green);
    text[1].setString("HARD");
    text[1].setPosition(460,450);

    text[2].setFont(font);
    text[2].setColor(sf::Color::Green);
    text[2].setString("RETURN");
    text[2].setPosition(440,520);
}

void Difficulty::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Difficulty::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS10)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::White);
    }
}

void Difficulty::update(){
    keyboardInput();
}

void Difficulty::render(sf::RenderTarget* target){
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

void Difficulty::endState(){
    
}

void Difficulty::keyboardInput(){
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
                        if(selectedItemIndex == 1){
                            //this->states->push(new VideoOptions(this->window, this->states));
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
