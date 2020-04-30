#ifndef _TILEMAP_HPP_
#define _TILEMAP_HPP_

#include "Vetor2D.hpp"

namespace exercicio {
  class TileMap {
    
    public:
    
      class LinhaTileMap {
        private:
          const unsigned short* linha;
          unsigned int comprimento;
        
        public:
          LinhaTileMap(unsigned short* p, unsigned int c);
          ~LinhaTileMap();
          unsigned short operator[](unsigned int i) const;
        
      };
    
    
    private:

      Vetor2U dimensoesMapa;
      unsigned short** mapa;
      const char* caminho;

    public:
    
      TileMap(const char* caminhoArquivo = nullptr);
      ~TileMap();
      const Vetor2U getDimensoesMapa() const;
      void imprimirMapa() const;
      void setTile(Vetor2U posicao, unsigned short novoIndice);
      const LinhaTileMap operator[](unsigned int i) const;
      
      
    private:

      void CarregarMapa();

  };
}

#endif