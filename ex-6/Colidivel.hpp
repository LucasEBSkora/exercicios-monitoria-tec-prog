#ifndef _COLIDIVEL_HPP_
#define _COLIDIVEL_HPP_

#include "Desenhavel.hpp"
#include "IdsDesenhaveis.hpp"
#include "Vetor2D.hpp"

namespace exercicio {

  class Colidivel: public Desenhavel {
    public:
      Colidivel(Vetor2F pos, Vetor2F vel, IdsDesenhaveis::IdsDesenhaveis ID, const char* caminhoTextura = nullptr);
      virtual void colidir(IdsDesenhaveis::IdsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) = 0;
  };
}

#endif