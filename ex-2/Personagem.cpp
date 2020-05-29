#include "Personagem.hpp" 


#include <iostream>

namespace exercicio {

  Personagem::Personagem(sf::Vector2f pos /* = sf::Vector2f(0.0f, 0.0f)*/, sf::Vector2f vel /* = sf::Vector2f(0.0f, 0.0f)*/, const char* caminhoTextura /* = nullptr*/) : 
    posicao{pos}, v{vel}, text{nullptr} {
    //a lista de inicialização acima (depois do :) é a maneira correta de inicializar variáveis em um construtor.
    //posicao = pos;
    //v = vel;
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

  void Personagem::atualizar(float t) {
    
    posicao += v*t;

    corpo.setPosition(posicao);

    //corpo.move(v*t);
  }

  void Personagem::desenhar(sf::RenderWindow* janela) {
    
    janela->draw(corpo);

  }

}