#include "Personagem.hpp" 


#include <iostream>

namespace exercicio {

  Personagem::Personagem(float xInicial, float yInicial, const char* caminhoTextura) : x{xInicial}, y{yInicial}, text{nullptr} {
    //x = xInicial;
    //y = yInicial;
    //text = nullptr;

    if (caminhoTextura) {

      text = new sf::Texture();
      text->loadFromFile(caminhoTextura);
      
    }
    corpo.setTexture(text);
    corpo.setSize(sf::Vector2f(200.0f, 200.0f));
    corpo.setOrigin(corpo.getSize() / 2.0f);

  }

  Personagem::~Personagem() {
   if (text) delete text;
  }

  void Personagem::atualizar() {
    x *= 1.2;
    y += 0.006;

    corpo.setPosition(sf::Vector2f(x, y));
  }

  void Personagem::desenhar(sf::RenderWindow* janela) {
    
    janela->draw(corpo);

  }

}