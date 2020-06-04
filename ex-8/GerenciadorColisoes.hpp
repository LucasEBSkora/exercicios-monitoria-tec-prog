#ifndef _GERENCIADOR_COLISOES_HPP_
#define _GERENCIADOR_COLISOES_HPP_

#include "GerenciadorTiles.hpp"

#include <set>

namespace exercicio {

  class Colidivel;

  class GerenciadorColisoes {
    private:
      std::set<Colidivel*> colidiveis;
      bool estaoColidindo(Colidivel* p1, Colidivel* p2);
      GerenciadorTiles* gt;

    public:
      GerenciadorColisoes();
      ~GerenciadorColisoes();
      void adicionarColidivel(Colidivel* p);
      void removerColidivel(Colidivel* p);
      void removerTodos();
      void verificarColisoes();
      void setGerenciadorTiles(GerenciadorTiles* Gt);
  };
}

#endif