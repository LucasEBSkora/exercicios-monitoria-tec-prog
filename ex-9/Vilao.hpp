#ifndef _VILAO_H_
#define _VILAO_H_

#include "Colidivel.hpp"
#include "Ids.hpp"

namespace exercicio {

  class Vilao : public Colidivel {
    private:

    public:

      Vilao(Vetor2F pos = {0.0f, 0.0f}, Vetor2F vel = {0.0f, 0.0f});
      Vilao(nlohmann::json fonte);
      ~Vilao();
      void inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
      void colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);

  };

}

#endif