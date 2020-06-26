#include "PromessaTexto.hpp"

namespace exercicio {
  PromessaTexto::PromessaTexto(GerenciadorEventos& GE, unsigned short comprimentoMax) :
    idOuvinteTeclado{0},
    capturaIniciada{false}, 
    textoPronto{false},
    ge{GE},
    comprimentoMaximo{comprimentoMax} {}

  PromessaTexto::~PromessaTexto() {
    ge.removerOuvinteTeclado(idOuvinteTeclado);
  }

  void PromessaTexto::comecar() {
    if (capturaIniciada) return;
    capturaIniciada = true;
    
    texto.clear(); //Tira os conteúdos antigos da string

    idOuvinteTeclado = ge.adicionarOuvinteTeclado([this] (const sf::Event& e) {adquirir(e);});
  }

  bool PromessaTexto::getTextoPronto() const {
    return textoPronto;
  }

  const std::string& PromessaTexto::getTexto() const {
    return texto;
  }

  void PromessaTexto::adquirir(const sf::Event& e) {
    
    if (e.type == sf::Event::EventType::TextEntered) {
      
      if (texto.size() <= comprimentoMaximo) {
        // char c;
        // if (e.text.unicode < 128) c = static_cast<char>(e.text.unicode);
        // else c = '\0';
        char c = (e.text.unicode < 128) ? static_cast<char>(e.text.unicode) : '\0';
        
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '_')
          texto += c;   
      }
    } else if (e.type == sf::Event::EventType::KeyReleased) {
      if (e.key.code == sf::Keyboard::Key::Backspace) {
        if (texto.size() > 0) texto.pop_back();
      } else if (e.key.code == sf::Keyboard::Key::Enter) {
        textoPronto = true;
        capturaIniciada = false;
        ge.removerOuvinteTeclado(idOuvinteTeclado);
        idOuvinteTeclado = 0;
      }
    }
  }

}