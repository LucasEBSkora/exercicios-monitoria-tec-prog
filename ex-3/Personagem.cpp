#include "Personagem.hpp" 


#include <iostream>

namespace exercicio {

  Personagem::Personagem(Vetor2F pos /* = {0.0f, 0.0f}*/, Vetor2F vel /* = {0.0f, 0.0f}*/, const char* caminhoTextura /* = nullptr*/) : 
    posicao{pos}, v{vel}, caminho{caminhoTextura} {

  }

  Personagem::~Personagem() {
  }

  void Personagem::inicializar(GerenciadorGrafico &g) {
    g.carregarTextura(caminho);
  }

  void Personagem::atualizar(float t) {
    
    posicao += v*t;

    //corpo.move(v*t);
  }

  void Personagem::desenhar(GerenciadorGrafico &g) {
    
    g.desenhar(caminho, posicao);

  }

}