#include "Desenhavel.hpp" 

#include <iostream>

namespace exercicio {

  Desenhavel::Desenhavel(Vetor2F pos, Vetor2F vel, const char* caminhoTextura) : 
    posicao{pos}, v{vel}, caminho{caminhoTextura} {

  }

  Desenhavel::~Desenhavel() {
  }

  void Desenhavel::inicializar(GerenciadorGrafico &gf, GerenciadorEventos &ge) {
    gf.carregarTextura(caminho);
  }

  void Desenhavel::atualizar(float t) {
    
    posicao += v*t;

  }

  void Desenhavel::desenhar(GerenciadorGrafico &g) {
    
    g.desenhar(caminho, posicao);

  }

}