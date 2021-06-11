//
//  Pause.cpp
//  Projekt
//
//  Created by KACPER on 10/06/2021.
//  Copyright © 2021 KACPER. All rights reserved.
//

#include "Pause.hpp"

Pause::Pause(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this->initGui();
    selectedItemIndex = 2;
}

Pause::~Pause()
{
    
}

void Pause::drawText()
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS5; i++)
    {
        //window.draw(menu[i]);
    }
}

void Pause::initGui(){
    //int width = 600;
    //int height = 648;
    sf::Vector2f vector2f(450.f, 300.f);
    //background.setSize(Vector2f(width, height));
    background.setFillColor(sf::Color::Yellow);
    background.setPosition(vector2f);
    if (!font.loadFromFile(resourcePath() + "space_invaders.ttf"))
    {
        // handle error
    }
    
    text[0].setFont(font);
    text[0].setColor(sf::Color::White);
    text[0].setString("PAUSE");
    text[0].setCharacterSize(120);
    text[0].setPosition(300,300);
    
    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Do you want to continue?");
    text[1].setCharacterSize(25);
    text[1].setPosition(320,450);
    
    text[2].setFont(font);
    text[2].setColor(sf::Color::Green);
    text[2].setString("Yes");
    text[2].setCharacterSize(25);
    text[2].setPosition(480,500);
    
    text[3].setFont(font);
    text[3].setColor(sf::Color::White);
    text[3].setString("No");
    text[3].setCharacterSize(25);
    text[3].setPosition(490,550);
    
    

}

void Pause::MoveUp()
{
    if (selectedItemIndex - 3 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void Pause::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS5)
    {
        text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void Pause::update(){
    keyboardInput();
}

void Pause::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    
    //sf::Texture texture;
    //texture.loadFromFile(resourcePath() + "pause.png");

    sf::Sprite sprite;
    //sprite.setTexture(texture);
    sprite.setPosition(255,200);
    
    this->window->draw(sprite);
    for(int i = 0; i < 4; i++){
        target->draw(this->text[i]);
    }
}

void Pause::endState(){
    
}

void Pause::keyboardInput(){
    sf::Event e;
    bool test = true;
    
    while(test){
        while (this->window->pollEvent(e)){
            switch (e.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
//                    if(e.key.code == sf::Keyboard::Escape){
//                        this->states->pop();
//                        cout << "test";
//                    }
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
                        if(selectedItemIndex == 2){
                            this->states->pop();
                            cout << "opcje" << endl;
                        }
                        if(selectedItemIndex == 3){
                            this->states->pop();
                            this->states->pop();
                            this->states->pop();
                            this->states->push(new Menu(this->window,this->states));
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
