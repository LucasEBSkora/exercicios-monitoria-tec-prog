#include "GerenciadorBotoes.hpp"

#include <math.h>
namespace exercicio {
  GerenciadorBotoes::GerenciadorBotoes(GerenciadorEventos& GE, GerenciadorGrafico& GG, std::vector<Botao*> Botoes/* = {}*/) : botoes{Botoes}, ge{GE}, gg{GG} {
    
    idOuvinteMouse = ge.adicionarOuvinteMouse([this] (const sf::Event& e) {ouvinteMouse(e);});
  }

  GerenciadorBotoes::~GerenciadorBotoes() {
    ge.removerOuvinteMouse(idOuvinteMouse);
  }

  void GerenciadorBotoes::desenhar() const {
    for (Botao* b : botoes) b->desenhar(gg);
  }

  void GerenciadorBotoes::ouvinteMouse(const sf::Event& e) {
    if (e.type == sf::Event::MouseButtonReleased) { //se ocorrer um clique, verificar se foi em cima de algum botão
      Vetor2F posicaoMouse = gg.getPosicaoMouse();
      for(Botao* b : botoes) {
        Vetor2F posicaoCentroBotao = b->getPosicao();
        Vetor2F tamanhoBotao = b->getTamanho();
        Vetor2F distanciaMouseCentro = posicaoMouse - posicaoCentroBotao;
        if (fabs(distanciaMouseCentro.x) < tamanhoBotao.x/2 && fabs(distanciaMouseCentro.y) < tamanhoBotao.y/2) b->apertar();
      }

    }
  }

  void GerenciadorBotoes::adicionarBotao(Botao* b) {
    if (b) botoes.push_back(b);
  }

}