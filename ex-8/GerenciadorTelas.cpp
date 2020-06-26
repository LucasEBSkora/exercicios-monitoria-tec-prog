#include "GerenciadorTelas.hpp"

#include "FaseExemplo.hpp"
#include "MenuPrincipal.hpp"

namespace exercicio {

  GerenciadorTelas::GerenciadorTelas(GerenciadorGrafico& gg, Heroi* jogador1 /*= nullptr*/) : 
    gerenciadorGrafico{gg}, jogador1{jogador1} {
    pushEstado(new MenuPrincipal(gerenciadorGrafico));
  }

  bool GerenciadorTelas::processarCodigo(int codigoRetorno) {
    switch (codigoRetorno) {
      case terminarJogo: 
        return true;
      case irPrimeiraFase:
        pushEstado(new FaseExemplo(gerenciadorGrafico, jogador1));
        return false;
        break;

      default:
        return false;
    }
  }
}