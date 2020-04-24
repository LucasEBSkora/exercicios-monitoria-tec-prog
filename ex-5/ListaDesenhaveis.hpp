#ifndef _LISTADESENHAVEIS_HPP_
#define _LISTADESENHAVEIS_HPP_

#include "Desenhavel.hpp"
#include "Lista.hpp"

namespace exercicio {

  class GerenciadorGrafico;
  class GerenciadorEventos;
  class GerenciadorColisoes;

  class ListaDesenhaveis {
    private:
      Lista<Desenhavel*>  lista;

    public:

      ListaDesenhaveis();
      ~ListaDesenhaveis();

      void inserir(Desenhavel* info);

      Desenhavel* voltarInicio(); //retorna para o início e retorna o primeiro elemento da lista
      Desenhavel* irProximo(); //vai para o próximo elemento da lista e retorna o próximo

      void inicializarDesenhaveis(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
      void atualizarDesenhaveis(float t);
      void desenharDesenhaveis(GerenciadorGrafico& g);
      void destruirDesenhaveis();

  };

}


#endif