#include <SFML/Graphics.hpp>
#include "Personagem.h"



class Principal {
    private:
      sf::RenderWindow* window;
      Personagem p;
    public:
      Principal();
      ~Principal();
      void executar();
};