#ifndef __GERENCIADOR_ESTADOS_HPP__
#define __GERENCIADOR_ESTADOS_HPP__

#include "Estado.hpp"

#include <stack>

namespace exercicio {
  class GerenciadorEstados {
    private:
      std::stack<Estado*> pilhaEstados;
    public: 
      virtual ~GerenciadorEstados();
      bool executar();
    protected:
      void pushEstado(Estado* p);
      void popEstado();
      void esvaziarPilha();
      virtual bool processarCodigo(int codigoRetorno) = 0;

  };
}

#endif 