#include "Tile.hpp"

#include <iostream>

namespace exercicio {

  Tile::Tile(const Ids::Ids ID, const char* caminhoArquivo, Vetor2F Tamanho) : id{ID}, caminho{caminhoArquivo}, tamanho{Tamanho} {
    std::cout << caminho << std::endl;
  }

  Tile::~Tile() {

  }

 void Tile::inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge) {
    std::cout << '\t' << caminho << std::endl;
    gg.carregarTextura(caminho);
  }

  void Tile::desenhar(GerenciadorGrafico& gg, const Vetor2F posicao) const {
    // std::cout << '\t' << '\t' << caminho << std::endl;
    gg.desenhar(caminho, posicao);
  }

  const Ids::Ids Tile::getId() const {
    return id;
  }

  void Tile::colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {
    
  }

}