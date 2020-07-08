#include "GerenciadorTelas.hpp"

#include "FaseExemplo.hpp"

namespace exercicio {

  GerenciadorTelas::GerenciadorTelas(GerenciadorGrafico& gg, Heroi* jogador1 /*= nullptr*/) : 
    gerenciadorGrafico{gg}, jogador1{jogador1} {
    push(new FaseExemplo(gg, jogador1));
  }

  bool GerenciadorTelas::processarCodigo(int codigoRetorno) {
    switch (codigoRetorno) {
      case terminarJogo: 
        return true;
      default:
        return false;
    }
  }
}