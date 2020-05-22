#ifndef __ESTADO_HPP__
#define __ESTADO_HPP__

namespace exercicio {
  class Estado {
    
    public: 
      virtual ~Estado();
      virtual int executar() = 0;

  };
}

#endif