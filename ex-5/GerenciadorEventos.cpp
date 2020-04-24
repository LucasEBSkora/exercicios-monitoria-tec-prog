#include "GerenciadorEventos.hpp"

namespace exercicio {

  //unsigned int GerenciadorEventos::proximoID = 0; :(
  //unsigned int GerenciadorEventos::proximoID(0);  :|
  unsigned int GerenciadorEventos::proximoID{0}; // :)
  
  

  GerenciadorEventos::GerenciadorEventos() {

  }

  GerenciadorEventos::~GerenciadorEventos() {

  }

  void GerenciadorEventos::tratarEventos() {

    while (janela->pollEvent(evento)) {

      if (evento.type == sf::Event::MouseWheelScrolled 
        || evento.type == sf::Event::MouseButtonPressed
        || evento.type == sf::Event::MouseButtonReleased
        || evento.type == sf::Event::MouseMoved ) {
          
        for (auto it : ouvintesMouse) {
          it.second(evento);
        }

      } else if (evento.type == sf::Event::KeyPressed 
        || evento.type == sf::Event::KeyReleased) {
        
        for (auto it : ouvintesTeclado) {
          it.second(evento);
        }

      } else {

        for (auto it : ouvintesOutros) {
            it.second(evento);
        }
      }
    }
  }

  void GerenciadorEventos::setJanela(sf::RenderWindow* j) {
      janela = j;

      janela->setKeyRepeatEnabled(false);
  }


  unsigned int GerenciadorEventos::adicionarOuvinteMouse(std::function<void(const sf::Event&)> chamada) {

    ouvintesMouse.emplace(proximoID, chamada);

    return proximoID++;
  }

  void GerenciadorEventos::removerOuvinteMouse(int id) {
    ouvintesMouse.erase(id);

  }

  
  unsigned int GerenciadorEventos::adicionarOuvinteTeclado(std::function<void(const sf::Event&)> chamada) {

    ouvintesTeclado.emplace(proximoID, chamada);

    return proximoID++;
  }

  void GerenciadorEventos::removerOuvinteTeclado(int id) {
    ouvintesMouse.erase(id);
  }

  
  unsigned int GerenciadorEventos::adicionarOuvinteOutro(std::function<void(const sf::Event&)> chamada) {

    ouvintesOutros.emplace(proximoID, chamada);

    return proximoID++;
  }

  void GerenciadorEventos::removerOuvinteOutro(int id) {
    ouvintesMouse.erase(id);
  }

}