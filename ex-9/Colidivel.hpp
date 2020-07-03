#ifndef _COLIDIVEL_HPP_
#define _COLIDIVEL_HPP_

#include "Desenhavel.hpp"
#include "Ids.hpp"
#include "Vetor2D.hpp"

namespace exercicio {

  class Colidivel: public Desenhavel {
    public:
      Colidivel(Vetor2F pos = {0.0f, 0.0f}, Vetor2F vel = {0.0f, 0.0f}, Ids::Ids ID  = Ids::semID, const char* caminhoTextura = nullptr);
      virtual void colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) = 0;
  };
}

#endif