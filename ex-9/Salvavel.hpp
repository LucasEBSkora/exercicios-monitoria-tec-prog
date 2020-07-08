#ifndef _SALVAVEL_HPP_
#define _SALVAVEL_HPP_

#include "Serializavel.hpp"

namespace exercicio {
  class Salvavel : public Serializavel {
    public:
      virtual ~Salvavel();
      bool salvar(const std::string& caminho); 
      virtual void carregar(const std::string& caminho) = 0; 
  };
}

#endif