#ifndef _GERENCIADOR_BOTOES_HPP_
#define _GERENCIADOR_BOTOES_HPP_ 

#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"
#include "Botao.hpp"

#include <vector>

namespace exercicio {
  class GerenciadorBotoes {
    
    private:
      std::vector<Botao*> botoes;
      GerenciadorEventos& ge;
      GerenciadorGrafico& gg;
      unsigned int idOuvinteMouse;

    public:
      //Construtor sem parâmetros não é necessário pois ele não existe em classes com atributos que são referências
      GerenciadorBotoes(GerenciadorEventos& GE, GerenciadorGrafico& gg, std::vector<Botao*> Botoes = {});
      ~GerenciadorBotoes();
      void desenhar() const;
      void ouvinteMouse(const sf::Event& e);
      void adicionarBotao(Botao* b);
  };
}

#endif