#include "MenuPrincipal.hpp"

#include "GerenciadorTelas.hpp"

#include <iostream>

namespace exercicio {
  MenuPrincipal::MenuPrincipal(GerenciadorGrafico& GG) : Menu(GG), imprimiu{false},
  campoTexto{ge, 15, {400.0f, 300.0f}, {200, 50}} {
    gb.adicionarBotao(new Botao({400.0f, 200.0f}, {100, 50}, "Primeira fase", [this] {setCodigoRetorno(irPrimeiraFase);} ));
    gb.adicionarBotao(new Botao({400.0f, 400.0f}, {100, 50}, "Sair do jogo", [this] {setCodigoRetorno(terminarJogo);} ));
    gb.adicionarBotao(&campoTexto);
  }

  int MenuPrincipal::executar()  {
    int ret = Menu::executar();
    if (!imprimiu && campoTexto.getTextoPronto()) {
      imprimiu = true;
      std::cout << "o nome do seu amiguinho e " << campoTexto.getTexto() << std::endl;
    }
    return ret;
  }
}