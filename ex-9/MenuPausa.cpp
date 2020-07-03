#include "MenuPausa.hpp"

#include "GerenciadorTelas.hpp"

namespace exercicio {
  MenuPausa::MenuPausa(GerenciadorGrafico& gg) : Menu{gg} {
    gb.adicionarBotao(new Botao({400.0f, 200.0f}, {100, 50}, "Continuar jogo", [this] {setCodigoRetorno(sairMenuPausa);} ));
    gb.adicionarBotao(new Botao({400.0f, 300.0f}, {100, 50}, "Salvar jogo", [this] {setCodigoRetorno(salvarJogo);} ));
    gb.adicionarBotao(new Botao({400.0f, 400.0f}, {100, 50}, "Menu principal", [this] {setCodigoRetorno(irMenuPrincipal);} ));
  }
}