#include "GerenciadorTiles.hpp"

namespace exercicio {
  GerenciadorTiles::GerenciadorTiles(std::vector<Tile*> Tiles, Vetor2F dimensoes, const char* caminhoArquivo) 
  : tiles {Tiles},
    dimensoesTiles {dimensoes},
    caminho {caminhoArquivo},
    tileMap {caminhoArquivo}
     {

  }

  GerenciadorTiles::~GerenciadorTiles() {
    for (Tile* t : tiles)
      delete t;
  }


  void GerenciadorTiles::inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge) {
    for (Tile* t : tiles)
      t->inicializar(gg, ge);
  }

  void GerenciadorTiles::desenhar(GerenciadorGrafico& gg) const {
    for (unsigned int i = 0; i < dimensoesTiles.y; ++i) {
      for (unsigned int j = 0; j < dimensoesTiles.x; ++j) {
        tiles[tileMap[i][j]]->desenhar(gg, converterCoordenadasMapaParaTela(Vetor2U{j, i}));
      }
    }

  }

  std::vector<IdPosicaoTamanho> GerenciadorTiles::checarColisoes(const Ids::Ids id, Vetor2F posicao, Vetor2F tamanho) {
    unsigned int cima = (unsigned int) floor((posicao.y - tamanho.y/2) / dimensoesTiles.y); 
    unsigned int baixo = (unsigned int) ceil((posicao.y + tamanho.y/2) / dimensoesTiles.y); 
    unsigned int esquerda = (unsigned int) floor((posicao.x - tamanho.x/2) / dimensoesTiles.x); 
    unsigned int direita = (unsigned int) ceil((posicao.x + tamanho.x/2) / dimensoesTiles.x); 

    std::vector<IdPosicaoTamanho> colisoes;


    for (unsigned int i = cima; i < baixo; ++i)
      for (unsigned int j = esquerda; j < direita; ++j) {
        
        short indice = tileMap[i][j] - 1; // o -1 é um offset, pois 0 no formato do tilemap indica a falta de um tile e não o tile no índice 0
        if (0 <= indice && indice < (long) tiles.size()) {
          Tile * t = tiles[indice];
          
          t->colidir(id, posicao, {j, i});

          colisoes.push_back({t->getId(), converterCoordenadasMapaParaTela({j, i}) , dimensoesTiles});

        }

      }
    return colisoes;
  }

  const Vetor2F GerenciadorTiles::converterCoordenadasMapaParaTela(const Vetor2U pos) const {
    return dimensoesTiles.operator*(0.5f) + Vetor2F(dimensoesTiles.x*pos.x, dimensoesTiles.y*pos.y);
  }
}