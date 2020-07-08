#ifndef _RELOGIO_HPP_
#define _RELOGIO_HPP_

#include <time.h>

namespace exercicio {
  class Relogio {
    private:
      clock_t ultimo;
      clock_t atual;
      double dt;
      bool pausado;
    public:
      Relogio();
      ~Relogio();
      double getTempo();
      void reiniciar();
      void pausar();
    

  };
}
#endif