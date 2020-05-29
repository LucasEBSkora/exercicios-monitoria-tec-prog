#ifndef __FASE_EXEMPLO_HPP__
#define __FASE_EXEMPLO_HPP__

#include "Estado.hpp"

#include "GerenciadorGrafico.hpp"
#include "Heroi.hpp"


#include "GerenciadorEventos.hpp"

#include "GerenciadorColisoes.hpp"

#include "GerenciadorTiles.hpp"


#include "Desenhavel.hpp"

#include "ListaDesenhaveis.hpp"

namespace exercicio {
  class FaseExemplo : public Estado {
    private: 
      GerenciadorGrafico& gerenciadorGrafico;
      Heroi* jogador1;

      GerenciadorEventos gerenciadorEventos;
      GerenciadorColisoes gerenciadorColisoes;
      GerenciadorTiles gerenciadorTiles;
      sf::Clock relogio; //vide cola
      ListaDesenhaveis listaAmigos;

      bool terminar;
      unsigned int IdOuvinteFecharTela;

    public: 
      FaseExemplo(GerenciadorGrafico& gg, Heroi* jogador1 /*= nullptr*/);
      //Construtor sem parâmetros não é necessário pois ele não existe em classes com atributos que são referências

      ~FaseExemplo();
      int executar() override;
    
    private:
      void botaoFecharTelaApertado(const sf::Event evento);
  };
}

#endif