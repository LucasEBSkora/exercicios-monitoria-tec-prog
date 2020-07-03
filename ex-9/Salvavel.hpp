#ifndef _SALVAVEL_HPP_
#define _SALVAVEL_HPP_

#include "Serializavel.hpp"

namespace exercicio {
  class Salvavel : public Serializavel {
    bool salvar(const std::string& caminho) const; 
    virtual void carregar(const std::string& caminho) = 0; 
  };
}

#endif