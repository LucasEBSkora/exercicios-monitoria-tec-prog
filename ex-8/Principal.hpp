#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_


#include "GerenciadorGrafico.hpp"

#include "Heroi.hpp"

#include "GerenciadorTelas.hpp"

//using namespace sf

/*

namespaces: conjuntos de classes, variáveis, funções, etc.

um namespace pode ser declarado dividido entre vários arquivos, e todos entenderão que estão no mesmo namespace


para usar algo de um namespace fora do namespace, se usa o operador de resolução de escopo (::)

std::list -> dentro do namespace std, quero a classe list

O operador de resolução de escopo também é usado com classes

Principal::Principal() -> procurando a função Principal() dentro da classe Principal

classes e namespaces são escopos


o comando "using namespace std" significa que se o compilador não achar algo no escopo local, deve procurar no namespace std

namespace nome_do_namespace {




}



*/

namespace exercicio {

  class Principal {
    private:
      
      GerenciadorGrafico gerenciadorGrafico;
      Heroi jogador1;
      GerenciadorTelas gerenciadorTelas;
      bool terminar;
    public:
      Principal();
      ~Principal();
      int executar();
      void janelaFechada(const sf::Event& e);

  };

}


#endif