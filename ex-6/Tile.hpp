#ifndef _TILE_HPP_
#define _TILE_HPP_

#include "Vetor2D.hpp"
#include "Ids.hpp"
#include "GerenciadorGrafico.hpp"

namespace exercicio {
  class Tile {
  
    private:
      const Ids::Ids id;
      const char* caminho;
      Vetor2F tamanho;
      GerenciadorGrafico* gg;

    public:
      Tile(const Ids::Ids ID, const char* caminhoArquivo, Vetor2F Tamanho);
      virtual ~Tile();
      virtual void inicializar(GerenciadorGrafico& GG);
      void desenhar() const;
      const Ids::Ids getId() const;
      virtual void colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2U posicao);

  };
}

#endif