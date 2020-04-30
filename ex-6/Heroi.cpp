#include "Heroi.hpp"

#include <iostream>

namespace exercicio {

  Heroi::Heroi(Vetor2F pos): Colidivel(pos, Vetor2F(), Ids::heroi, "../assets/TheUndying.png") {

  }

  Heroi::~Heroi() {


  }

  void Heroi::inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
    gf.carregarTextura(caminho);
    
    dimensoes = gf.getTamanho(caminho); 

    chaveOuvinte = ge.adicionarOuvinteTeclado([this] (const sf::Event& e) {tratarEvento(e);});

    gc.adicionarColidivel(this);

  }

  void Heroi::atualizar(float t) {    
    posicao += v*t;
  }

  void Heroi::desenhar(GerenciadorGrafico &g) {
        
    g.desenhar(caminho, posicao);
    g.centralizar(posicao);
  }



  void Heroi::tratarEvento(const sf::Event& e) {

    
    if (e.type == sf::Event::KeyPressed) {


      switch (e.key.code) {
        case sf::Keyboard::Key::Right:
          v.x += 30;
          /* code */
          break;
        case sf::Keyboard::Key::Left:
          v.x -= 30;
          /* code */
          break;
        case sf::Keyboard::Key::Up:
          v.y -= 30;
          /* code */
          break;
        case sf::Keyboard::Key::Down:
          v.y += 30;
          /* code */
          break;
        default:
          break;
      }
    } else if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
          case sf::Keyboard::Key::Right:
            v.x -= 30;
            break;
          case sf::Keyboard::Key::Left:
            v.x += 30;
            break;
          case sf::Keyboard::Key::Up:
            v.y += 30;
            break;
          case sf::Keyboard::Key::Down:
            v.y -= 30;
            break;
          default:
            break;
      }
    }
  }

  void Heroi::colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) {
    std::cout << "ai " << std::endl;
  }

}