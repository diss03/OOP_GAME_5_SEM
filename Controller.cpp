#include "Controller.h"
#include "iostream"
#include "windows.h"
#include <cstdio>

Controller::Controller() {}

Controller::Controller(CommandReader* comread) : comread(comread) {
    this->player = new Player();
    this->field = new Field(comread->GetHeight(), comread->GetWidth(), player);
    this->fieldw = FieldView();

    this->field = field; //---коммент из старой версии: используем коснтруктор с параметрами и конструктор копирования поля
}

// ńîçäŕĺě ýęçĺěďë˙đ ęëŕńńŕ ďîëĺ č óćĺ ń íčě đŕáîňŕĺě, čěĺ˙ ďđč ńĺáĺ ýęçĺěďë˙đ ęëŕńńŕ ęîěěŕíä-đčäĺđ čç ěýéíŕ//

void Controller::Move() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "OOP_GAME", sf::Style::Default);
    window.setFramerateLimit(10);


    std::vector<sf::Sprite> sprites;

    sf::Texture heroTex;
    sf::Sprite hero;
    if (!heroTex.loadFromFile("sprites/hero.png"))
        throw "Could not load hero.png";
    hero.setTexture(heroTex);
    hero.setScale(sf::Vector2f(0.1f, 0.1f));
    sprites.push_back(hero);

    sf::Texture grassTex;
    sf::Sprite grass;
    if (!grassTex.loadFromFile("sprites/grass.png"))
        throw "Could not load grass.png";
    grass.setTexture(grassTex);
    grass.setScale(sf::Vector2f(0.3f, 0.3f));
    sprites.push_back(grass);

    sf::Texture armorTex;
    sf::Sprite armor;
    if (!armorTex.loadFromFile("sprites/armor.png"))
        throw "Could not load armor.png";
    armor.setTexture(armorTex);
    armor.setScale(sf::Vector2f(0.1f, 0.12f));
    sprites.push_back(armor);


    sf::Texture coinTex;
    sf::Sprite coin;
    if (!coinTex.loadFromFile("sprites/coin.png"))
        throw "Could not load coin.png";
    coin.setTexture(coinTex);
    coin.setScale(sf::Vector2f(0.15f, 0.15f));
    sprites.push_back(coin);

    sf::Texture damageTex;
    sf::Sprite damage;
    if (!damageTex.loadFromFile("sprites/damage.png"))
        throw "Could not load damage.png";
    damage.setTexture(damageTex);
    damage.setScale(sf::Vector2f(0.30f, 0.35f));
    sprites.push_back(damage);

    sf::Texture hpTex;
    sf::Sprite hp;
    if (!hpTex.loadFromFile("sprites/hp.png"))
        throw "Could not load hp.png";
    hp.setTexture(hpTex);
    hp.setScale(sf::Vector2f(0.22f, 0.22f));
    sprites.push_back(hp);

    sf::Texture wallTex; //6
    sf::Sprite wall;
    if (!wallTex.loadFromFile("sprites/wall.png"))
        throw "Could not load wall.png";
    wall.setTexture(wallTex);
    wall.setScale(sf::Vector2f(0.5f, 0.5f));
    sprites.push_back(wall);

    sf::Texture winTex;//6
    sf::Sprite win;
    if (!winTex.loadFromFile("sprites/win.png"))
        throw "Could not load win.png";
    win.setTexture(winTex);
    win.setScale(sf::Vector2f(0.5f, 0.5f));
    sprites.push_back(win);

    sf::Texture teleportTex;//8
    sf::Sprite teleport;
    if (!teleportTex.loadFromFile("sprites/teleport.png"))
        throw "Could not load teleport.png";
    teleport.setTexture(teleportTex);
    teleport.setScale(sf::Vector2f(0.15f, 0.15f));
    sprites.push_back(teleport);

    sf::Texture changeFieldTex;//9
    sf::Sprite changeField;
    if (!changeFieldTex.loadFromFile("sprites/changeField.png"))
        throw "Could not load changeField.png";
    changeField.setTexture(changeFieldTex);
    changeField.setScale(sf::Vector2f(0.45f, 0.45f));
    sprites.push_back(changeField);


    fieldw.Print(field, player, &window, sprites);
    while (window.isOpen() and player->GetEnd() != true)
    {
        if (player->GetEnd() == true) {
            window.close();
        }

        comread->InputStep(&window);
        //Move(comread.GetStep());
        sf::Event event = comread->GetStep();
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
            field->MoveUp();
            fieldw.Print(field, player, &window, sprites);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
            field->MoveDown();
            fieldw.Print(field, player, &window, sprites);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
            field->MoveRight();
            fieldw.Print(field, player, &window, sprites);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
            field->MoveLeft();
            fieldw.Print(field, player, &window, sprites);
        }
        //проверка условия на проигрыш 
        if (player->GetHealth() <= 0) {
            std::cout << "U LOSE!" << std::endl;
            player->SetEnd(true);
        }
    }
    std::cout << "game over!" << std::endl;
    Sleep(5000);
}