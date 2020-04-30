#ifndef _GERENCIADOR_COLISOES_HPP_
#define _GERENCIADOR_COLISOES_HPP_

#include <set>

namespace exercicio {

  class Colidivel;

  class GerenciadorColisoes {
    private:
      std::set<Colidivel*> colidiveis;
      bool estaoColidindo(Colidivel* p1, Colidivel* p2);

    public:
      GerenciadorColisoes();
      ~GerenciadorColisoes();
      void adicionarColidivel(Colidivel* p);
      void removerColidivel(Colidivel* p);
      void removerTodos();
      void verificarColisoes();
  };
}

#endif