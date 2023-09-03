#include "Controller.h"
#include "iostream"
#include "windows.h"
#include <cstdio>
#include <stdio.h>

//#include "Generator.h"

//Controller::Controller() {}

Controller::Controller(CommandReader* comread, InfoLog* log_info, DIFFICULTY dif){
    this->comread = comread;
    this->player = new Player();
    this->field = nullptr;

    
    new GameObserver(this);
    new StatusObserver(this);
    this->log_info = log_info;

    //this->field = new Field(comread->GetHeight(), comread->GetWidth(), player, log_info); //убрать в 5 лб
    
    /*new GameObserver(this);*/
    new ErrorObserver(this);

    this->fieldw = FieldView();

    /*this->field = field; *///---коммент из старой версии: используем коснтруктор с параметрами и конструктор копирования поля

    this->step = NOTHING;
    this->difficulty = dif;

    this->save_load_field = new SaveLoadField;
    this->save_load_player = new SaveLoadPlayer;
}

// ńîçäŕĺě ýęçĺěďë˙đ ęëŕńńŕ ďîëĺ č óćĺ ń íčě đŕáîňŕĺě, čěĺ˙ ďđč ńĺáĺ ýęçĺěďë˙đ ęëŕńńŕ ęîěěŕíä-đčäĺđ čç ěýéíŕ//
 
void Controller::FieldGanerate() {
    //Generator* generator;
    if (difficulty == EASY) {
        //FieldGenerator* generator = new ;
        FieldGenerator<FiledBase<EASY>, Armor<EASY>, Bank<EASY>, ChangeField<EASY>, Damage<EASY>, Hp<EASY>, Teleport<EASY>> generator;
        this->field = generator.generate(this->comread->GetHeight(), this->comread->GetWidth(), this->player, this->log_info);
    }
    else if (difficulty == HARD){
        //FieldGenerator* generator = new FieldGenerator<FiledBase<HARD>, Armor<HARD>, Bank<HARD>, ChangeField<HARD>, Damage<HARD>, Hp<HARD>, Teleport<HARD>>;
        FieldGenerator<FiledBase<HARD>, Armor<HARD>, Bank<HARD>, ChangeField<HARD>, Damage<HARD>, Hp<HARD>, Teleport<HARD>> generator;
        this->field = generator.generate(this->comread->GetHeight(),this->comread->GetWidth(), this->player, this->log_info);
    }
}

void Controller::Move() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "OOP_GAME", sf::Style::Default);
    window.setFramerateLimit(5);


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

    Message message(STATUS, "Game started!", this->log_info);
    Notify(message);

    new_game:

    fieldw.Print(this->field, this->player, &window, sprites);
    while (window.isOpen() and this->player->GetEnd() != true)
    {
        comread->SetStep(&window);
        this->step = comread->GetStep();

        if (this->player->GetEnd() == true) {
            Message message1(STATUS, "GAME OVER", this->log_info);
            Notify(message1);
            window.close();
        }
            

        if (this->step == EXIT)
            window.close();

        
        //Move(comread.GetStep());
        //sf::Event event = comread->GetStep();
        
        switch (step) {
            case ASSIGMENTS::UP: {
                system("cls");
                //std::cout << "ASSIGMENTS::UP" << std::endl;
                field->MoveUp();
                fieldw.Print(field, player, &window, sprites);
                this->step = NOTHING;
                break;
            }

            case ASSIGMENTS::DOWN: {
                system("cls");
                //std::cout << "ASSIGMENTS::DOWN" << std::endl;
                field->MoveDown();
                fieldw.Print(field, player, &window, sprites);
                this->step = NOTHING;
                break;
            }

            case ASSIGMENTS::RIGHT: {
                system("cls");
                //std::cout << "ASSIGMENTS::RIGHT" << std::endl;
                field->MoveRight();
                fieldw.Print(field, player, &window, sprites);
                this->step = NOTHING;
                break;
            }

            case ASSIGMENTS::LEFT: {
                system("cls");
                //std::cout << "ASSIGMENTS::LEFT" << std::endl;
                field->MoveLeft();
                fieldw.Print(field, player, &window, sprites);
                this->step = NOTHING;
                break;
            }

            case ASSIGMENTS::SAVE: {
                try {
                    system("cls");
                    this->save_load_player->savePlayer(player);
                    this->save_load_field->saveField(field);

                    Message message(GAME, "Data has been saved!", log_info);
                    Notify(message);
                }
                catch (SaveExeption& ex) {
                    Message message(GAME, ex.getMessage(), log_info);
                    Notify(message);
                }
                catch (FileExeption& ex) {
                    Message message(GAME, ex.getMessage(), log_info);
                    Notify(message);
                }
                catch (...) {
                    Message message(GAME, "Unknown error: game's state has not been saved", log_info);
                    Notify(message);
                }
                //this->step = NOTHING;
                break;
            }

            case ASSIGMENTS::LOAD: {
                system("cls");
                Player* copy_player = this->player;
                Field* copy_field = this->field;
                try {
                    this->player = this->save_load_player->loadPlayer(this->player);
                    this->field = this->save_load_field->loadField(this->player, this->log_info);
                    fieldw.Print(field, player, &window, sprites);

                    Message message(GAME, "Data has been uploaded!", log_info);
                    Notify(message);

                }
                catch (LoadExeption& ex) {
                    //this->player = copy(this->player, this->cplayer);
                    this->player = copy_player;
                    this->field = copy_field;
                    Message message(GAME, ex.getMessage(), log_info);
                    Notify(message);
                }
                catch (FileExeption& ex) {
                    this->player = copy_player;
                    this->field = copy_field;
                    Message message(GAME, ex.getMessage(), log_info);
                    Notify(message);
                }
                catch (...) {
                    this->player = copy_player;
                    this->field = copy_field;
                    Message message(GAME, "unknown error: game's state has not been uploaded!", log_info);
                    Notify(message);
                }
                //this->step = NOTHING;
                break;
            }

            case ASSIGMENTS::NOTHING: {
                //std::cout << "ASSIGMENTS::NOTHING" << std::endl;
                //fieldw.Print(field, player, &window, sprites);
                this->step = NOTHING;
                break;
            }

            //default:
            //    this->step = NOTHING;
            //    break;
        }

        ////проверка условия на проигрыш 
        if (player->GetHealth() <= 0) {
            //std::cout << "U LOSE!" << std::endl;
            Message message2(GAME, "player losed", this->log_info);
            Notify(message2);
            player->SetEnd(true);
        }
    }
    //std::cout << "game over!" << std::endl;


    std::cout << "Do you want to load last save and continue?" << std::endl;
    std::cout << "Y - Yes\n";
    std::cout << "N - No\n";
    char res;
    std::cin >> res;
    if (res != 'Y' and res != 'y') {
        Message message(STATUS, "OUT", this->log_info);
        Notify(message);
        return;
    }

    /*sf::RenderWindow window(sf::VideoMode(800, 800), "OOP_GAME", sf::Style::Default);*/
    player->SetEnd(false);

    Message message2(STATUS, "CONTINUE", this->log_info);
    Notify(message2);

    Player* copy_player = this->player;
    Field* copy_field = this->field;
    try {
        this->player = this->save_load_player->loadPlayer(this->player);
        this->field = this->save_load_field->loadField(this->player, this->log_info);
        fieldw.Print(field, player, &window, sprites);

        Message message(GAME, "Data has been uploaded!", log_info);
        Notify(message);

    }
    catch (LoadExeption& ex) {
        //this->player = copy(this->player, this->cplayer);
        this->player = copy_player;
        this->field = copy_field;
        Message message(GAME, ex.getMessage(), log_info);
        Notify(message);
    }
    catch (FileExeption& ex) {
        this->player = copy_player;
        this->field = copy_field;
        Message message(GAME, ex.getMessage(), log_info);
        Notify(message);
    }
    catch (...) {
        this->player = copy_player;
        this->field = copy_field;
        Message message(GAME, "unknown error: game's state has not been uploaded!", log_info);
        Notify(message);
    }

    goto new_game;

    //написать: вы хотите выйти или загрузить последнее сохранение?
    Sleep(5000);
}