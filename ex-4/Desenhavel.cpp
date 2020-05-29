#include "Desenhavel.hpp" 

#include <iostream>

namespace exercicio {

  Desenhavel::Desenhavel(Vetor2F pos /* = {0.0f, 0.0f}*/, Vetor2F vel/* = {0.0f, 0.0f}*/, const char* caminhoTextura /* = nullptr*/) : 
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