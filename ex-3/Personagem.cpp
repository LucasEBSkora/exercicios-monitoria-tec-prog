#include "Personagem.hpp" 


#include <iostream>

namespace exercicio {

  Personagem::Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura) : 
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