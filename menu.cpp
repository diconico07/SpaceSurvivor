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
    //reinitialisation
    if(listeMenu.size()>0)
      for(unsigned int i=0;i<listeMenu.size();i++)
        delete listeMenu[i];
    listeMenu.clear();

    sf::RectangleShape *cadre= new sf::RectangleShape(sf::Vector2f(Window->getSize().x-200,4*(80+10)+10));
    cadre->setPosition(sf::Vector2f(100,Window->getSize().y/3));
    cadre->setFillColor(sf::Color::Transparent);
    cadre->setOutlineThickness(3);
    cadre->setOutlineColor(sf::Color::Black);
    cadre->setFillColor(sf::Color(207,207,207,220));

    sf::RectangleShape *selector= new sf::RectangleShape(sf::Vector2f(Window->getSize().x-220,80));
    selector->setPosition(sf::Vector2f(cadre->getPosition().x+10,cadre->getPosition().y+10));
    selector->setFillColor(sf::Color(252,220,18,150));
    selector->setOutlineThickness(2);
    selector->setOutlineColor(sf::Color::Blue);
    unsigned int selectorPosition =1;

    sf::Text *Title=new sf::Text("SPACE SURVIVOR",Ressources::getFont(),90);
    Title->setPosition(sf::Vector2f(cadre->getSize().x/2-160,cadre->getPosition().y-200));
    Title->setColor(sf::Color::Yellow);
    Title->setStyle(sf::Text::Bold);

    sf::Text *jouer=new sf::Text("# Jouer #",Ressources::getFont(),42);
    jouer->setPosition(sf::Vector2f(cadre->getSize().x/2,cadre->getPosition().y+10));
    jouer->setColor(sf::Color::Blue);
    jouer->setStyle(sf::Text::Bold);

    sf::Text *HS=new sf::Text("* HighScores *",Ressources::getFont(),42);
    HS->setPosition(sf::Vector2f(cadre->getSize().x/2,cadre->getPosition().y+10+spacementSelector));
    HS->setColor(sf::Color::Blue);
    HS->setStyle(sf::Text::Bold);

    sf::Text *credits=new sf::Text("+ Credits +",Ressources::getFont(),42);
    credits->setPosition(sf::Vector2f(cadre->getSize().x/2,cadre->getPosition().y+10+2*spacementSelector));
    credits->setColor(sf::Color::Blue);
    credits->setStyle(sf::Text::Bold);

    sf::Text *quit=new sf::Text("?! Quitter !?",Ressources::getFont(),42);
    quit->setPosition(sf::Vector2f(cadre->getSize().x/2,cadre->getPosition().y+10+3*spacementSelector));
    quit->setColor(sf::Color::Red);
    quit->setStyle(sf::Text::Bold);

    listeMenu.push_back(jouer);
    listeMenu.push_back(HS);
    listeMenu.push_back(credits);
    listeMenu.push_back(quit);

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
                        selector->setPosition(sf::Vector2f(selector->getPosition().x,selector->getPosition().y+(listeMenu.size()-1)*spacementSelector));
                        selectorPosition=listeMenu.size();
                    }
                    else{
                        selector->setPosition(sf::Vector2f(selector->getPosition().x,selector->getPosition().y-spacementSelector));
                        selectorPosition--;
                    }
                    break;
                case sf::Keyboard::Down:
                    if(selectorPosition==listeMenu.size()){
                        selector->setPosition(sf::Vector2f(selector->getPosition().x,selector->getPosition().y-(listeMenu.size()-1)*spacementSelector));
                        selectorPosition=1;
                    }
                    else{
                        selector->setPosition(sf::Vector2f(selector->getPosition().x,selector->getPosition().y+spacementSelector));
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
            jouer->setColor(sf::Color::Green);
            jouer->setScale(1.2,1.2);
            jouer->setPosition(sf::Vector2f(cadre->getSize().x/2-10,cadre->getPosition().y+10));
            HS->setColor(sf::Color::Blue);
            HS->setScale(1,1);
            HS->setPosition(sf::Vector2f(cadre->getSize().x/2-35,cadre->getPosition().y+10+spacementSelector));
            credits->setColor(sf::Color::Blue);
            credits->setScale(1,1);
            credits->setPosition(sf::Vector2f(cadre->getSize().x/2-22,cadre->getPosition().y+10+2*spacementSelector));
            quit->setColor(sf::Color::Blue);
            quit->setScale(1,1);
            quit->setPosition(sf::Vector2f(cadre->getSize().x/2-30,cadre->getPosition().y+10+3*spacementSelector));
            break;
        case 2:
            jouer->setColor(sf::Color::Blue);
            jouer->setScale(1,1);
            jouer->setPosition(sf::Vector2f(cadre->getSize().x/2,cadre->getPosition().y+10));
            HS->setColor(sf::Color::Green);
            HS->setScale(1.2,1.2);
            HS->setPosition(sf::Vector2f(cadre->getSize().x/2-20-35,cadre->getPosition().y+10+spacementSelector));
            credits->setColor(sf::Color::Blue);
            credits->setScale(1,1);
            credits->setPosition(sf::Vector2f(cadre->getSize().x/2-22,cadre->getPosition().y+10+2*spacementSelector));
            quit->setColor(sf::Color::Blue);
            quit->setScale(1,1);
            quit->setPosition(sf::Vector2f(cadre->getSize().x/2-30,cadre->getPosition().y+10+3*spacementSelector));
            break;
        case 3:
            jouer->setColor(sf::Color::Blue);
            jouer->setScale(1,1);
            jouer->setPosition(sf::Vector2f(cadre->getSize().x/2,cadre->getPosition().y+10));
            HS->setColor(sf::Color::Blue);
            HS->setScale(1,1);
            HS->setPosition(sf::Vector2f(cadre->getSize().x/2-35,cadre->getPosition().y+10+spacementSelector));
            credits->setColor(sf::Color::Green);
            credits->setScale(1.2,1.2);
            credits->setPosition(sf::Vector2f(cadre->getSize().x/2-15-22,cadre->getPosition().y+10+2*spacementSelector));
            quit->setColor(sf::Color::Blue);
            quit->setScale(1,1);
            quit->setPosition(sf::Vector2f(cadre->getSize().x/2-30,cadre->getPosition().y+10+3*spacementSelector));
            break;
        case 4:
            jouer->setColor(sf::Color::Blue);
            jouer->setScale(1,1);
            jouer->setPosition(sf::Vector2f(cadre->getSize().x/2,cadre->getPosition().y+10));
            HS->setColor(sf::Color::Blue);
            HS->setScale(1,1);
            HS->setPosition(sf::Vector2f(cadre->getSize().x/2-35,cadre->getPosition().y+10+spacementSelector));
            credits->setColor(sf::Color::Blue);
            credits->setScale(1,1);
            credits->setPosition(sf::Vector2f(cadre->getSize().x/2-22,cadre->getPosition().y+10+2*spacementSelector));
            quit->setColor(sf::Color::Green);
            quit->setScale(1.2,1.2);
            quit->setPosition(sf::Vector2f(cadre->getSize().x/2-18-30,cadre->getPosition().y+10+3*spacementSelector));
            break;
        default:
            break;
        }

        //clear window
        Window->clear();

        //Draw the sprites
        Window->draw(back);
        Window->draw(*Title);
        Window->draw(*cadre);
        Window->draw(*selector);
        for(unsigned int i=0;i<listeMenu.size();i++){
            Window->draw(*listeMenu[i]);
          }
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
                return;
                }
            }
        }

        if(delay.getElapsedTime().asMilliseconds()>=200){
            delay.restart();
            credits.setColor(sf::Color(std::rand()%255,std::rand()%255,std::rand()%255));

        }

        //clear window
        Window->clear();

        Window->draw(back);
        Window->draw(Title);
        Window->draw(credits);

        Window->display();
    }



}
