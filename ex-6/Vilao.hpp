#ifndef _VILAO_H_
#define _VILAO_H_

#include "Colidivel.hpp"
#include "IdsDesenhaveis.hpp"

namespace exercicio {

  class Vilao : public Colidivel {
    private:

    public:

      Vilao(Vetor2F pos, Vetor2F vel);
      ~Vilao();
      void inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
      void colidir(IdsDesenhaveis::IdsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);

  };

}

#endif