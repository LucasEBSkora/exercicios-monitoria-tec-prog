#include "Desenhavel.hpp" 

#include <iostream>

namespace exercicio {

  Desenhavel::Desenhavel(Vetor2F pos /* = {0.0f, 0.0f}*/, Vetor2F vel/* = {0.0f, 0.0f}*/, IdsDesenhaveis::IdsDesenhaveis ID  /*= IdsDesenhaveis::semID*/, const char* caminhoTextura /* = nullptr*/) : 
    posicao{pos}, v{vel}, caminho{caminhoTextura}, id{ID} {

  }

  Desenhavel::~Desenhavel() {
  }

  void Desenhavel::inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
    gf.carregarTextura(caminho);
  }

  void Desenhavel::atualizar(float t) {
    
    posicao += v*t;

  }

  void Desenhavel::desenhar(GerenciadorGrafico &g) {
    
    g.desenhar(caminho, posicao);

  }
  
  const Vetor2F Desenhavel::getPosicao() const {
    return posicao;
  }

  const Vetor2F Desenhavel::getDimensoes() const {
    return dimensoes;
  }

  const IdsDesenhaveis::IdsDesenhaveis Desenhavel::getId() const {
    return id;
  }

}