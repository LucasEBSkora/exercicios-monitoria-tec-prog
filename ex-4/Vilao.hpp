#ifndef _VILAO_H_
#define _VILAO_H_

#include "Desenhavel.hpp"

namespace exercicio {

  class Vilao : public Desenhavel {
    private:

    public:

      Vilao(Vetor2F pos, Vetor2F vel);
      ~Vilao();
      

  };

}

#endif