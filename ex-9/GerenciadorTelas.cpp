#include "GerenciadorTelas.hpp"

#include "FaseExemplo.hpp"
#include "MenuPrincipal.hpp"
#include "MenuPausa.hpp"

#include <iostream>

namespace exercicio {

  GerenciadorTelas::GerenciadorTelas(GerenciadorGrafico& gg, Heroi* jogador1 /*= nullptr*/) : 
    gerenciadorGrafico{gg}, jogador1{jogador1} {
    push(new MenuPrincipal(gerenciadorGrafico));
  }

  bool GerenciadorTelas::processarCodigo(int codigoRetorno) {
    switch (codigoRetorno) {
      case terminarJogo: 
        return true;

      case comecarPrimeiraFase:
      {
        FaseExemplo* fase = new FaseExemplo(gerenciadorGrafico, jogador1);
        fase->inicializar();
        push(fase);
        return false;
      }
      case salvarJogo:
      {
        pop();
        Fase* fase = dynamic_cast<Fase*>(top());
        if (!fase)  
          std::cout << "Erro! Não há fase a ser salva." << std::endl;
        else if (!fase->salvar("../jogos-salvos/jogo_salvo.json")) 
          std::cout << "Erro! O jogo não pôde ser salvo." << std::endl;
        return false;
      }
      case carregarJogo:
      {
        std::cout << "como";
        FaseExemplo* fase = new FaseExemplo(gerenciadorGrafico, jogador1);
        std::cout << " onde" << std::endl;
        try {
          fase->carregar("../jogos-salvos/jogo_salvo.json");
          push(fase);
        } catch (char const* s) {
          std::cout << s << std::endl;
          delete fase;
        }
        return false;
      }
      case irMenuPausa:
        push(new MenuPausa(gerenciadorGrafico));
        return false;
      
      case sairMenuPausa:
        pop();
        return false;
      
      case irMenuPrincipal:
        esvaziarPilha();
        push(new MenuPrincipal(gerenciadorGrafico));

      case continuar:
      default:
        return false;
    }
  }
}


