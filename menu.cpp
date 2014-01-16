#include "menu.h"

Menu::Menu()
{
}

Menu::Menu(sf::RenderWindow *window){
    Window=window;
    // Load a sprite to display
    sf::Texture *background=new sf::Texture;
    background->loadFromFile("ressources/backmenu.png");
    background->setRepeated(true);
    background->setSmooth(true);
    back=sf::Sprite(*background);
    back.setColor(sf::Color::White);
    //back.scale(2,2);
    back.setScale((float)window->getSize().x/background->getSize().x,(float)window->getSize().y/background->getSize().y);
    Window->setMouseCursorVisible(true);



}
enum choix Menu::playMenu(){
    sf::Clock delay;


    sf::RectangleShape cadre=sf::RectangleShape(sf::Vector2f(Window->getSize().x-200,4*(80+10)+10));
    cadre.setPosition(sf::Vector2f(100,Window->getSize().y/3));
    cadre.setFillColor(sf::Color::Transparent);
    cadre.setOutlineThickness(5);
    cadre.setOutlineColor(sf::Color::Black);
    cadre.setFillColor(sf::Color(207,207,207,220));

    sf::RectangleShape selector= sf::RectangleShape(sf::Vector2f(Window->getSize().x-220,80));
    selector.setPosition(sf::Vector2f(cadre.getPosition().x+10,cadre.getPosition().y+10));
    selector.setFillColor(sf::Color(252,220,18,150));
    selector.setOutlineThickness(3);
    selector.setOutlineColor(sf::Color::Blue);
    unsigned int selectorPosition =1;

    sf::Text Title=sf::Text("COOKIE SURVIVOR",Ressources::getFont(),90);
    Title.setPosition(sf::Vector2f(cadre.getSize().x/2-190,cadre.getPosition().y-200));
    Title.setColor(sf::Color::Yellow);
    Title.setStyle(sf::Text::Bold);

    sf::Sprite Monster1, Monster2;
    Monster1.setTexture(Ressources::getVessel());
    Monster2.setTexture(Ressources::getVessel());
    Monster1.setPosition(sf::Vector2f(cadre.getSize().x/2-330,cadre.getPosition().y-200));
    Monster1.setScale(2,2);
    Monster2.setPosition(sf::Vector2f(cadre.getSize().x/2+460,cadre.getPosition().y-200));
    Monster2.setScale(2,2);

    sf::Text jouer=sf::Text("# Jouer #",Ressources::getFont(),42);
    jouer.setPosition(sf::Vector2f(cadre.getSize().x/2,cadre.getPosition().y+10));
    jouer.setColor(sf::Color::Blue);
    jouer.setStyle(sf::Text::Bold);

    sf::Text HS=sf::Text("* HighScores *",Ressources::getFont(),42);
    HS.setPosition(sf::Vector2f(cadre.getSize().x/2,cadre.getPosition().y+10+spacementSelector));
    HS.setColor(sf::Color::Blue);
    HS.setStyle(sf::Text::Bold);

    sf::Text credits=sf::Text("+ Credits +",Ressources::getFont(),42);
    credits.setPosition(sf::Vector2f(cadre.getSize().x/2,cadre.getPosition().y+10+2*spacementSelector));
    credits.setColor(sf::Color::Blue);
    credits.setStyle(sf::Text::Bold);

    sf::Text quit=sf::Text("?! Quitter !?",Ressources::getFont(),42);
    quit.setPosition(sf::Vector2f(cadre.getSize().x/2,cadre.getPosition().y+10+3*spacementSelector));
    quit.setColor(sf::Color::Blue);
    quit.setStyle(sf::Text::Bold);


    while(Window->isOpen()){
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window->close();
            if (event.type == sf::Event::KeyPressed){
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    if(selectorPosition==1){
                        selector.setPosition(sf::Vector2f(selector.getPosition().x,selector.getPosition().y+(4-1)*spacementSelector));
                        selectorPosition=4;
                    }
                    else{
                        selector.setPosition(sf::Vector2f(selector.getPosition().x,selector.getPosition().y-spacementSelector));
                        selectorPosition--;
                    }
                    break;
                case sf::Keyboard::Down:
                    if(selectorPosition==4){
                        selector.setPosition(sf::Vector2f(selector.getPosition().x,selector.getPosition().y-(4-1)*spacementSelector));
                        selectorPosition=1;
                    }
                    else{
                        selector.setPosition(sf::Vector2f(selector.getPosition().x,selector.getPosition().y+spacementSelector));
                        selectorPosition++;
                    }
                    break;
                case sf::Keyboard::Return:
                    switch (selectorPosition) {
                    case 1:
                        return JOUER;
                        break;
                    case 2:
                        return HIGHSCORES;
                        break;
                    case 3:
                        return CREDITS;
                        break;
                    case 4:
                        return QUITTER;
                        break;
                    default:
                        break;
                    }
                default:
                    break;
                } 
            }
//            if(event.type == sf::Event::MouseMoved){
//                int y =event.mouseMove.y;
//                if(y>>110 && y<<190){
//                    selector->setPosition(sf::Vector2f(selector->getPosition().x,110));
//                    selectorPosition=1;
//                }
//                else if(y>>200 && y<<280){
//                    selector->setPosition(sf::Vector2f(selector->getPosition().x,200));
//                    selectorPosition=2;
//                }
//                else if(y>>290 && y<<270){
//                    selector->setPosition(sf::Vector2f(selector->getPosition().x,290));
//                    selectorPosition=3;
//                }

//            }

        }
        switch (selectorPosition) {
        case 1:
            jouer.setColor(sf::Color::Green);
            jouer.setScale(1.2,1.2);
            jouer.setPosition(sf::Vector2f(cadre.getSize().x/2-10,cadre.getPosition().y+20));
            HS.setColor(sf::Color::Blue);
            HS.setScale(1,1);
            HS.setPosition(sf::Vector2f(cadre.getSize().x/2-35,cadre.getPosition().y+15+spacementSelector));
            credits.setColor(sf::Color::Blue);
            credits.setScale(1,1);
            credits.setPosition(sf::Vector2f(cadre.getSize().x/2-22,cadre.getPosition().y+15+2*spacementSelector));
            quit.setColor(sf::Color::Blue);
            quit.setScale(1,1);
            quit.setPosition(sf::Vector2f(cadre.getSize().x/2-30,cadre.getPosition().y+15+3*spacementSelector));
            break;
        case 2:
            jouer.setColor(sf::Color::Blue);
            jouer.setScale(1,1);
            jouer.setPosition(sf::Vector2f(cadre.getSize().x/2,cadre.getPosition().y+15));
            HS.setColor(sf::Color::Green);
            HS.setScale(1.2,1.2);
            HS.setPosition(sf::Vector2f(cadre.getSize().x/2-20-35,cadre.getPosition().y+20+spacementSelector));
            credits.setColor(sf::Color::Blue);
            credits.setScale(1,1);
            credits.setPosition(sf::Vector2f(cadre.getSize().x/2-22,cadre.getPosition().y+15+2*spacementSelector));
            quit.setColor(sf::Color::Blue);
            quit.setScale(1,1);
            quit.setPosition(sf::Vector2f(cadre.getSize().x/2-30,cadre.getPosition().y+15+3*spacementSelector));
            break;
        case 3:
            jouer.setColor(sf::Color::Blue);
            jouer.setScale(1,1);
            jouer.setPosition(sf::Vector2f(cadre.getSize().x/2,cadre.getPosition().y+15));
            HS.setColor(sf::Color::Blue);
            HS.setScale(1,1);
            HS.setPosition(sf::Vector2f(cadre.getSize().x/2-35,cadre.getPosition().y+15+spacementSelector));
            credits.setColor(sf::Color::Green);
            credits.setScale(1.2,1.2);
            credits.setPosition(sf::Vector2f(cadre.getSize().x/2-15-22,cadre.getPosition().y+20+2*spacementSelector));
            quit.setColor(sf::Color::Blue);
            quit.setScale(1,1);
            quit.setPosition(sf::Vector2f(cadre.getSize().x/2-30,cadre.getPosition().y+15+3*spacementSelector));
            break;
        case 4:
            jouer.setColor(sf::Color::Blue);
            jouer.setScale(1,1);
            jouer.setPosition(sf::Vector2f(cadre.getSize().x/2,cadre.getPosition().y+15));
            HS.setColor(sf::Color::Blue);
            HS.setScale(1,1);
            HS.setPosition(sf::Vector2f(cadre.getSize().x/2-35,cadre.getPosition().y+15+spacementSelector));
            credits.setColor(sf::Color::Blue);
            credits.setScale(1,1);
            credits.setPosition(sf::Vector2f(cadre.getSize().x/2-22,cadre.getPosition().y+15+2*spacementSelector));
            quit.setColor(sf::Color::Green);
            quit.setScale(1.2,1.2);
            quit.setPosition(sf::Vector2f(cadre.getSize().x/2-18-30,cadre.getPosition().y+20+3*spacementSelector));
            break;
        default:
            break;
        }

        if(delay.getElapsedTime().asMilliseconds()>=500){
            delay.restart();
            cadre.setOutlineColor(sf::Color(std::rand()%255,std::rand()%255,std::rand()%255));
            selector.setOutlineColor(sf::Color(std::rand()%255,std::rand()%255,std::rand()%255));
            Title.setColor(sf::Color(std::rand()%255,std::rand()%255,std::rand()%255));
        }

        //clear window
        Window->clear();

        //Draw the sprites
        Window->draw(back);
        Window->draw(Title);
        Window->draw(cadre);
        Window->draw(selector);
        Window->draw(Monster1);
        Window->draw(Monster2);
        Window->draw(jouer);
        Window->draw(HS);
        Window->draw(credits);
        Window->draw(quit);
        // Update the window
        Window->display();

    }
    return QUITTER;
}

void Menu::play_HS(){

    sf::RectangleShape cadre=sf::RectangleShape(sf::Vector2f(Window->getSize().x-200,4*(80+10)+10));
    cadre.setPosition(sf::Vector2f(100,Window->getSize().y/3));
    cadre.setFillColor(sf::Color::Transparent);
    cadre.setOutlineThickness(3);
    cadre.setOutlineColor(sf::Color::Yellow);
    cadre.setFillColor(sf::Color(207,207,207,220));

    sf::Text Title=sf::Text("* HighScores *",Ressources::getFont(),90);
    Title.setPosition(sf::Vector2f(cadre.getSize().x/2-150,cadre.getPosition().y-150));
    Title.setColor(sf::Color::Yellow);
    Title.setStyle(sf::Text::Bold);

    std::vector <sf::Text> listeHS;

    std::ifstream highscore ("highscore");
    std::ofstream HS;
    HS.open("hs");
    std::string line;
    std::vector <int> hs;
    if(highscore.is_open()){
        while (std::getline(highscore,line)){
            hs.push_back(std::atoi(line.c_str()));
            line.clear();
        }
        std::sort(hs.begin(),hs.end());
        std::reverse(hs.begin(),hs.end());

    }

    if(hs.size()>=1){
        sf::Text hs1=sf::Text(std::to_string(hs[0]),Ressources::getFont(),70);
        hs1.setPosition(sf::Vector2f(cadre.getSize().x/2+50,cadre.getPosition().y+10));
        hs1.setColor(sf::Color::Yellow);
        hs1.setStyle(sf::Text::Bold);
        listeHS.push_back(hs1);
    }
    if(hs.size()>=2){
        sf::Text hs2=sf::Text(std::to_string(hs[1]),Ressources::getFont(),42);
        hs2.setPosition(sf::Vector2f(cadre.getSize().x/2+60,cadre.getPosition().y+10+spacementSelector));
        hs2.setColor(sf::Color::Blue);
        hs2.setStyle(sf::Text::Bold);
        listeHS.push_back(hs2);
    }
    if(hs.size()>=3){
        sf::Text hs3=sf::Text(std::to_string(hs[2]),Ressources::getFont(),42);
        hs3.setPosition(sf::Vector2f(cadre.getSize().x/2+60,cadre.getPosition().y+10+2*spacementSelector));
        hs3.setColor(sf::Color::Blue);
        hs3.setStyle(sf::Text::Bold);
        listeHS.push_back(hs3);
    }
    if(hs.size()>=4){
        sf::Text hs4=sf::Text(std::to_string(hs[3]),Ressources::getFont(),42);
        hs4.setPosition(sf::Vector2f(cadre.getSize().x/2+60,cadre.getPosition().y+10+3*spacementSelector));
        hs4.setColor(sf::Color::Blue);
        hs4.setStyle(sf::Text::Bold);
        listeHS.push_back(hs4);
    }

    while(Window->isOpen()){
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window->close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Escape) {
                return;
                }
            }
        }

        //clear window
        Window->clear();

        Window->draw(back);
        Window->draw(cadre);
        Window->draw(Title);
        for(unsigned int i=0;i<listeHS.size();i++){
            Window->draw(listeHS[i]);
        }

        Window->display();
    }



}

void Menu::play_Credits(){

    sf::Clock delay;
    //Loads and play background music
    sf::Music music;
    music.openFromFile("ressources/music.ogg");
    music.setLoop(true);
    music.setVolume(60);
    music.play();


    sf::Text Title=sf::Text("+ Credits +",Ressources::getFont(),90);
    Title.setPosition(sf::Vector2f(Window->getSize().x/2-260,Window->getSize().y/2-300));
    Title.setColor(sf::Color::Black);
    Title.setStyle(sf::Text::Bold);



    sf::Text credits=sf::Text("DicoNico07 & Tiritchi",Ressources::getFont(),70);
    credits.setPosition(sf::Vector2f(Window->getSize().x/2-330,Window->getSize().y/2));
    credits.setColor(sf::Color::Yellow);
    credits.setStyle(sf::Text::Bold);


    while(Window->isOpen()){
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window->close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code==sf::Keyboard::Escape) {
                    back.setColor(sf::Color(255,255,255));
                    return;
                }
            }
        }

        if(delay.getElapsedTime().asMilliseconds()>=200){
            delay.restart();
            credits.setColor(sf::Color(std::rand()%255,std::rand()%255,std::rand()%255));
            back.setColor(sf::Color(std::rand()%255,std::rand()%255,std::rand()%255));
            Title.setColor(sf::Color(std::rand()%255,std::rand()%255,std::rand()%255));

        }

        //clear window
        Window->clear();

        Window->draw(back);
        Window->draw(Title);
        Window->draw(credits);

        Window->display();
    }



}
