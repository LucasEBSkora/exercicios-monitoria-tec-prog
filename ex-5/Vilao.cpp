#include "Vilao.hpp"

#include <iostream>

namespace exercicio {
  
  Vilao::Vilao(Vetor2F pos /*= {0.0f, 0.0f}*/, Vetor2F vel /*= {0.0f, 0.0f}*/) : 
    Colidivel(pos, vel, IdsDesenhaveis::vilao, "../assets/bloodboi.png") {

  }
  
  Vilao::~Vilao() {

  }

  void Vilao::inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
    gf.carregarTextura(caminho);

    dimensoes = gf.getTamanho(caminho);

    gc.adicionarColidivel(this);
  }

  void Vilao::colidir(IdsDesenhaveis::IdsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) {

    if (idOutro == IdsDesenhaveis::heroi) {
      std::cout << "nhac nhac nham nham heroi gostoso" << std::endl;
    } else if (idOutro == IdsDesenhaveis::vilao) {

      Vetor2F distancia = posicao - posicaoOutro;

      posicao += distancia*(1/2);


      std::cout << "po desculpa ai cumpadi" << std::endl;
      v.x *= -1;
      v.y *= -1; 
    }

  }
}