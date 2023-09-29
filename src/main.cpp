#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(512, 512), "MinecraftCave");
    RectangleShape pickaxe(Vector2f(130.0f, 128.0f));
    RectangleShape creeper(Vector2f(128.0f, 256.0f));
    RectangleShape background(Vector2f(512.0f, 512.0f));
    Texture pickaxeTexture;
    Texture creeperTexture;
    Texture backgroundTexture;
    pickaxeTexture.loadFromFile("textures/iron_pickaxe.png");
    creeperTexture.loadFromFile("textures/creeper.png");
    backgroundTexture.loadFromFile("textures/background.png");
    pickaxe.setTexture(&pickaxeTexture);
    creeper.setTexture(&creeperTexture);
    background.setTexture(&backgroundTexture);
    pickaxe.setOrigin(50.0f, 50.0f);
    creeper.setPosition(315.0f, 150.0f);
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == e.Closed){
                window.close();
            }
        }
        if(Mouse::isButtonPressed(Mouse::Button::Left)){
            Vector2i mousePos = Mouse::getPosition(window);
            pickaxe.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
        window.clear();
        window.draw(background);
        window.draw(creeper);
        window.draw(pickaxe);
        window.display();
    }
    return 0;
}