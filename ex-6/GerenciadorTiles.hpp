#ifndef _GERENCIADORTILES_HPP_
#define _GERENCIADORTILES_HPP_

#include "Tile.hpp"
#include "TileMap.hpp"
#include "Vetor2D.hpp"
#include "Ids.hpp"
#include "Desenhavel.hpp"

#include <vector>

namespace exercicio {

  class GerenciadorTiles : public Desenhavel {
    
    public:
      typedef struct idpostam {
        const Ids::Ids id;
        const Vetor2F posicao;
        const Vetor2F tamanho;
      } IdPosicaoTamanho;
    

    private:
      TileMap tileMap;
      Vetor2F DimensoesTiles;
      const char* caminho;
      std::vector<Tile> tiles;

    public: 
      GerenciadorTiles(std::vector<Tile> Tiles, Vetor2F dimensoes, const char* caminhoArquivo);
      ~GerenciadorTiles();
      void atualizar(float t);
      void inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge, GerenciadorColisoes& gc);
      void desenhar(GerenciadorGrafico& g) const;
      std::vector<IdPosicaoTamanho> checarColisoes(const Ids::Ids id, Vetor2F posicao, Vetor2F tamanho);      

  };

  using IdPosicaoTamanho = GerenciadorTiles::IdPosicaoTamanho;
}

#endif