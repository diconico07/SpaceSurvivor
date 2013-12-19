#include "game.h"

Game::Game()
{
}

Game::Game(sf::RenderWindow *window){
    Window=window;
    joueur=new Vaisseau(window->getSize());
    joueurIsAlive=true;
    listeMissiles.push_back(joueur);
    music.openFromFile("ressources/music.ogg");
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
    for(unsigned int i=0;i<listeMissiles.size();i++)
    delete listeMissiles[i];
    delete back.getTexture();
    Window->setMouseCursorVisible(true);
}

void Game::playGame(){

    // Start the game loop
    while (Window->isOpen())
    {
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
                  joueur->setAccLineaire(1);
                  break;
                case sf::Keyboard::Down :
                  joueur->setAccLineaire(-1);
                  break;
                case sf::Keyboard::Left :
                  joueur->setAccAngulaire(1);
                  break;
                case sf::Keyboard::Right :
                  joueur->setAccAngulaire(-1);
                  break;
                case sf::Keyboard::Space : if(fire_delay.getElapsedTime().asMilliseconds()>shootDelay && joueurIsAlive){ //Creates a new scope in order to allow variable declaration in the switch case
                    Projectile *projectile = new Projectile(joueur->getPosition()+joueur->getVitesse()+Vecteur(joueur->getSize(),(float)joueur->getAngle()),Vecteur(Vitesse_projectiles,(float)joueur->getAngle()),joueur->getAngle(),Window->getSize());
                  listeMissiles.push_back(projectile);
                  fire_delay.restart();
                  }
                  break;
                case sf::Keyboard::Escape :
                Window->close();
                default:
                  break;
                }
        }


        // Clear screen
        Window->clear();

        // Move the sprites
        if(joueurIsAlive){
            if(asteroid_delay.getElapsedTime().asMilliseconds()>asteroidDelay){
                asteroid_delay.restart();
                spawnAsteroid();
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
            for(unsigned int i=0;i<listeMissiles.size();i++){
                for(unsigned int j=i+1;j<listeMissiles.size();j++)
                  if(listeMissiles[i]->collide(listeMissiles[j])){
                      if(listeMissiles[i]==joueur || listeMissiles[j]==joueur)
                        joueurIsAlive=false;
                      delete listeMissiles[j];
                      delete listeMissiles[i];
                      listeMissiles.erase(listeMissiles.begin()+j);
                      listeMissiles.erase(listeMissiles.begin()+i);
                    }

              }
          }
        //Draw the sprites
        Window->draw(back);
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
  do
    position->setXY(std::rand()%Window->getSize().x,std::rand()%Window->getSize().y);
  while(position->getX()<joueur->getPosition().getX()+safeZone && position->getX()>joueur->getPosition().getX()-safeZone && position->getY()<joueur->getPosition().getY()+safeZone && position->getY()<joueur->getPosition().getY()-safeZone);
  vitesse->setXY(std::rand()%6-3,std::rand()%6-3);
  size = std::rand()%5;
  Asteroid *asteroid= new Asteroid(*position,*vitesse,size,Window->getSize());
  listeMissiles.push_back(asteroid);
  delete position;
  delete vitesse;
}
