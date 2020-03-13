#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>

class Principal;

class Personagem {
  private:
    float x;
    float y;
    sf::Texture* tex;
  public:
    Personagem(float X, float Y, const char* caminho);
    ~Personagem();
    void atualizar();
    void desenhar();

};