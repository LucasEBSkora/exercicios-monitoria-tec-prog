#include "Heroi.hpp"

#include <iostream>

namespace exercicio {

  Heroi::Heroi(Vetor2F pos): Desenhavel(pos, Vetor2F(), "../assets/TheUndying.png") {

  }

  Heroi::~Heroi() {


  }

  void Heroi::inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge) {
    gf.carregarTextura(caminho);

    chaveOuvinte = ge.adicionarOuvinteTeclado([this] (const sf::Event& e) {tratarEvento(e);});


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
          v.x += 10;
          /* code */
          break;
        case sf::Keyboard::Key::Left:
          v.x -= 10;
          /* code */
          break;
        case sf::Keyboard::Key::Up:
          v.y -= 10;
          /* code */
          break;
        case sf::Keyboard::Key::Down:
          v.y += 10;
          /* code */
          break;
        default:
          break;
      }
    } else if (e.type == sf::Event::KeyReleased) {
        switch (e.key.code) {
          case sf::Keyboard::Key::Right:
            v.x -= 10;
            break;
          case sf::Keyboard::Key::Left:
            v.x += 10;
            break;
          case sf::Keyboard::Key::Up:
            v.y += 10;
            break;
          case sf::Keyboard::Key::Down:
            v.y -= 10;
            break;
          default:
            break;
      }
    }





  }


}