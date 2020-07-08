#ifndef __FASE_HPP__
#define __FASE_HPP__

#include "Estado.hpp"
#include "Salvavel.hpp"

#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "GerenciadorColisoes.hpp"
#include "GerenciadorTiles.hpp"

#include "ListaDesenhaveis.hpp"
#include "Desenhavel.hpp"
#include "Heroi.hpp"

#include "Relogio.hpp"

namespace exercicio {
  class Fase : public Estado, public Salvavel {
    protected: 
      GerenciadorGrafico& gerenciadorGrafico;
      Heroi* jogador1;
      GerenciadorEventos gerenciadorEventos;
      GerenciadorColisoes gerenciadorColisoes;
      GerenciadorTiles* gerenciadorTiles;
      Relogio relogio; //vide cola
      ListaDesenhaveis listaAmigos;

    public: 
      Fase(GerenciadorGrafico& gg, GerenciadorTiles* gt, Heroi* jogador1 = nullptr);
      //Construtor sem parâmetros não é necessário pois ele não existe em classes com atributos que são referências
      ~Fase();
      int executar() override;
      virtual void inicializar() = 0;
    
    private:
      unsigned int IdOuvinteFecharTela;
      unsigned int IdOuvinteEntrarMenu;
      void botaoFecharTelaApertado(const sf::Event evento);
      void botaoEntrarMenuApertado(const sf::Event evento);

    protected:
      void setCodigoRetorno(int codigo);
      int codigoRetorno;
  };
}

#endif