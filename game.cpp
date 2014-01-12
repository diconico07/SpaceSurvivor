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
    game_delay.restart();

    int millisec,sec;
    std::string chrono_display; // temp text to display chrono

    //loading font
    sf::Font font ;
    font.loadFromFile("ressources/CookieMonster.ttf");

    sf::Text chrono;
    sf::Text Score;

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
                default:
                  break;
                }
        }

        for(unsigned int i=0;i<listeSound.size();i++){
          if(listeSound[i].getStatus()==0){
              delete listeSound[i].getBuffer();
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
                      listeMissiles[i]->destroy(&listeCollision, &listeSound);
                      listeMissiles[j]->destroy(&listeCollision, &listeSound);
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
        Window->draw(chrono);
        Window->draw(Score);
        for(unsigned int i=0;i<listeMissiles.size();i++){
            for(int j=0;j<4;j++)
              Window->draw(listeMissiles[i]->getSprite(j));
        }

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
