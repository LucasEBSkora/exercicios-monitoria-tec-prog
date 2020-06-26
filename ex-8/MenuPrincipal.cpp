#include "MenuPrincipal.hpp"

#include "GerenciadorTelas.hpp"

namespace exercicio {
  MenuPrincipal::MenuPrincipal(GerenciadorGrafico& GG) : Menu(GG) {
    gb.adicionarBotao(new Botao({400.0f, 200.0f}, {100, 50}, "Primeira fase", [this] {setCodigoRetorno(irPrimeiraFase);} ));
    gb.adicionarBotao(new Botao({400.0f, 400.0f}, {100, 50}, "Sair do jogo", [this] {setCodigoRetorno(terminarJogo);} ));
  }
}