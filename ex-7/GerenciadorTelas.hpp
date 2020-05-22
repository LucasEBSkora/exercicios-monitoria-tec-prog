#ifndef __GERENCIADOR_TELAS_HPP__
#define __GERENCIADOR_TELAS_HPP__

#include "GerenciadorEstados.hpp"

namespace exercicio {

  class GerenciadorGrafico;
  class Heroi;

  enum CodigoRetorno { 
    continuar, 
    terminarJogo
  };


  class GerenciadorTelas : public GerenciadorEstados {
    private:
      GerenciadorGrafico& gerenciadorGrafico;
      Heroi* jogador1;
    
    public:

      GerenciadorTelas(GerenciadorGrafico& gg, Heroi* jogador1);

    protected:
    
      bool processarCodigo(int codigoRetorno) override;

  };
}

#endif