#include "game.h"

Game::Game()
{
}

Game::Game(sf::RenderWindow *window){
    Window=window;
    //Creates and add the player to the vector
    joueur=new Vaisseau(window->getSize());
    joueurIsAlive=true;
    listeMissiles.push_back(joueur);

    //Loads and play background music
    music.openFromFile("ressources/music.ogg");
    music.setLoop(true);
    music.setVolume(60);
    music.play();

    // Load a sprite to display
    sf::Texture *background=new sf::Texture;
    background->loadFromFile("ressources/back.png");
    background->setRepeated(true);
    background->setSmooth(true);
    back=sf::Sprite(*background);
    back.setColor(sf::Color::White);
    //back.scale(2,2);
    back.setScale((float)window->getSize().x/background->getSize().x,(float)window->getSize().y/background->getSize().y);
    Window->setMouseCursorVisible(false);

    //creating test asteroids field
    for(int i=0;i<Nombre_asteroids;i++){
      spawnAsteroid();
    }
}

Game::~Game(){
    music.stop();
    //Flush the vector
    for(unsigned int i=0;i<listeMissiles.size();i++)
     delete listeMissiles[i];

    delete back.getTexture();
    Window->setMouseCursorVisible(true);

}

void Game::playGame(){
    // Start the game loop
    // start game chrono
    hardcoreMode=false;
    game_delay.restart();

    int millisec,sec;
    std::string chrono_display; // temp text to display chrono

    //loading font
    sf::Font font ;
    font.loadFromFile("ressources/CookieMonster.ttf");

    sf::Text chrono;
    sf::Text Score;

    //End of Game text
    sf::Text GameOver;
    sf::Text EndGame;
    sf::RectangleShape Bar;
    Bar.setSize(sf::Vector2f(800,200));
    Bar.setPosition(Window->getSize().x/2-400,Window->getSize().y/2-100);
    Bar.setFillColor(sf::Color(207,207,207,220));
    Bar.setOutlineColor(sf::Color::Black);
    Bar.setOutlineThickness(2);
    GameOver.setString("Game Over");
    GameOver.setFont(font);
    GameOver.setPosition(Window->getSize().x/2-100,Window->getSize().y/2-80);
    GameOver.setColor(sf::Color::Blue);
    GameOver.setCharacterSize(50);
    EndGame.setString("Appuyez sur Echap pour continuer");
    EndGame.setFont(font);
    EndGame.setPosition(Window->getSize().x/2-350,Window->getSize().y/2);
    EndGame.setColor(sf::Color::Blue);
    EndGame.setCharacterSize(50);
    sf::Texture background_blur;
    background_blur.loadFromFile("ressources/backmenu.png");
    background_blur.setRepeated(true);
    background_blur.setSmooth(true);
    sf::Sprite backblur(background_blur);
    backblur.setColor(sf::Color::Transparent);
    backblur.setScale((float)Window->getSize().x/background_blur.getSize().x,(float)Window->getSize().y/background_blur.getSize().y);
    int alphablur=0;

    std::ofstream highscore;
    highscore.open("highscore",std::ios::out | std::ios::app | std::ios::binary);


    while (Window->isOpen())
    {

        if(joueurIsAlive){
            millisec=game_delay.getElapsedTime().asMilliseconds();
            sec=(int)game_delay.getElapsedTime().asSeconds();
            score=5*sec;
        }
        chrono_display=std::to_string(sec/60)+":"+std::to_string(sec%60)+":"+std::to_string((millisec%1000)/10);
        chrono=sf::Text(chrono_display,font,42);
        chrono.setPosition(sf::Vector2f(Window->getSize().x-200,10));
        chrono.setColor(sf::Color::Black);

        Score=sf::Text(std::to_string(score),font,42);
        Score.setColor(sf::Color::Black);
        Score.setPosition(sf::Vector2f(Window->getSize().x-200,50));

        // Process events
        sf::Event event;
        while (Window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                Window->close();

            if (event.type == sf::Event::KeyPressed)
              switch(event.key.code){
                case sf::Keyboard::Up :
                  if(joueurIsAlive)
                    joueur->setAccLineaire(1);
                  break;
                case sf::Keyboard::Down :
                  if(joueurIsAlive)
                    joueur->setAccLineaire(-1);
                  break;
                case sf::Keyboard::Left :
                  if(joueurIsAlive)
                    joueur->setAccAngulaire(1);
                  break;
                case sf::Keyboard::Right :
                  if(joueurIsAlive)
                    joueur->setAccAngulaire(-1);
                  break;
                case sf::Keyboard::Space : if(fire_delay.getElapsedTime().asMilliseconds()>shootDelay && joueurIsAlive){ //Creates a new scope in order to allow variable declaration in the switch case
                    Projectile *projectile = new Projectile(joueur->getPosition()+joueur->getVitesse()+Vecteur(joueur->getSize(),(float)joueur->getAngle()),Vecteur(Vitesse_projectiles,(float)joueur->getAngle()),joueur->getAngle(),Window->getSize(), &listeSound);
                  listeMissiles.push_back(projectile);
                  fire_delay.restart();
                  }
                  break;
                case sf::Keyboard::Escape :
                  return;
                  break;
                case sf::Keyboard::C :
                  hardcoreMode=hardcoreMode?false:true;
                  break;
                default:
                  break;
                }
        }

        for(unsigned int i=0;i<listeSound.size();i++){
          if(listeSound[i].getStatus()==0){
              //delete listeSound[i].getBuffer();
              listeSound.erase(listeSound.begin()+i);
            }
        }

        // Clear screen
        Window->clear();

        // Move the sprites
        if(joueurIsAlive && move_delay.getElapsedTime().asMilliseconds()>=10){
            move_delay.restart();

            if(asteroid_delay.getElapsedTime().asMilliseconds()>asteroidDelay){
                asteroid_delay.restart();
                spawnAsteroid();
                if(hardcoreMode)
                  back.setColor(sf::Color(std::rand()*255,std::rand()*255,std::rand()*255));
              }

            for(unsigned int i=0;i<listeMissiles.size();i++){
                try{
                  listeMissiles[i]->move();
                }
                catch(int e) {
                  if(e==10){
                      delete listeMissiles[i];
                      listeMissiles.erase(listeMissiles.begin()+i);
                    }
                }

              }
            for(unsigned int i=0;i<listeAnimation.size();i++){
                try{
                  listeAnimation[i].play();
                }
                catch(int e) {
                  if(e==10){
                      listeAnimation.erase(listeAnimation.begin()+i);
                    }
                }
              }
            std::vector<Missile*> listeCollision;
            for(unsigned int i=0;i<listeMissiles.size();i++){
                for(unsigned int j=i+1;j<listeMissiles.size();j++)
                  if(listeMissiles[i]->collide(listeMissiles[j])){
                      if(listeMissiles[i]==joueur || listeMissiles[j]==joueur){
                        joueurIsAlive=false;
                        if(highscore.is_open()){
                            highscore<<score<<std::endl;
                        }
                      }
                      listeMissiles[i]->destroy(&listeCollision, &listeSound, &listeAnimation);
                      listeMissiles[j]->destroy(&listeCollision, &listeSound, &listeAnimation);
                      delete listeMissiles[j];
                      delete listeMissiles[i];
                      listeMissiles.erase(listeMissiles.begin()+j);
                      listeMissiles.erase(listeMissiles.begin()+i);
                    }

              }
            listeMissiles.insert(listeMissiles.end(),listeCollision.begin(),listeCollision.end());
          }

        //Draw the sprites
        Window->draw(back);

        for(unsigned int i=0;i<listeMissiles.size();i++){
            for(int j=0;j<4;j++)
              Window->draw(listeMissiles[i]->getSprite(j));
        }

        for(unsigned int i=0;i<listeAnimation.size();i++){
            for(int j=0;j<4;j++)
              Window->draw(listeAnimation[i].getSprite(j));
        }

        if(!joueurIsAlive){//Draw end of game text
            backblur.setColor(sf::Color(255,255,255,alphablur));
            alphablur=alphablur+15>=255?255:alphablur+15;
            Window->draw(backblur);
            Window->draw(Bar);
            Window->draw(GameOver);
            Window->draw(EndGame);
        }
        Window->draw(chrono);
        Window->draw(Score);
        // Update the window
        Window->display();
    }
}

void Game::spawnAsteroid(){
    Vecteur *position = new Vecteur();
    Vecteur *vitesse = new Vecteur();
    int size;

    //Generates new position util outside the player's safe zone
    do
        position->setXY(std::rand()%Window->getSize().x,std::rand()%Window->getSize().y);
    while(position->getX()<joueur->getPosition().getX()+safeZone && position->getX()>joueur->getPosition().getX()-safeZone && position->getY()<joueur->getPosition().getY()+safeZone && position->getY()<joueur->getPosition().getY()-safeZone);

    //Generate speed and size
    vitesse->setXY(std::rand()%6-3,std::rand()%6-3);
    size = std::rand()%5;

    //Creates asteroids and add them to the vector
    Asteroid *asteroid= new Asteroid(*position,*vitesse,size,Window->getSize());
    listeMissiles.push_back(asteroid);

    //delete temp data
    delete position;
    delete vitesse;
}
