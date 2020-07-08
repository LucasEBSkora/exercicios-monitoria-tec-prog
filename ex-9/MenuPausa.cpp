#include "MenuPausa.hpp"

#include "GerenciadorTelas.hpp"

namespace exercicio {
  MenuPausa::MenuPausa(GerenciadorGrafico& gg) : Menu{gg} {
    gb.adicionarBotao(new Botao({200.0f, 50.0f}, {100, 50}, "Continuar jogo", [this] {setCodigoRetorno(sairMenuPausa);} ));
    gb.adicionarBotao(new Botao({200.0f, 100.0f}, {100, 50}, "Salvar jogo", [this] {setCodigoRetorno(salvarJogo);} ));
    gb.adicionarBotao(new Botao({200.0f, 150.0f}, {100, 50}, "Menu principal", [this] {setCodigoRetorno(irMenuPrincipal);} ));
  }
}