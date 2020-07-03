#ifndef _FASE_EXEMPLO_HPP_
#define _FASE_EXEMPLO_HPP_

#include "Fase.hpp"
#include "../json/json.hpp"

namespace exercicio {
  class FaseExemplo : public Fase {
    public:
      FaseExemplo(GerenciadorGrafico& gg, Heroi* jogador1 = nullptr);
      nlohmann::json paraJSON() override;
      void carregar(const std::string& caminho) override;
      void inicializar() override;
  };
}

#endif