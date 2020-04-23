#include "ListaDesenhaveis.hpp"

#include <iostream>

namespace exercicio {


  ListaDesenhaveis::ListaDesenhaveis() {

  }

  ListaDesenhaveis::~ListaDesenhaveis() {
    destruirDesenhaveis();
  }

  void ListaDesenhaveis::inserir(Desenhavel* info) {
    lista.inserir(info);
  }

  void ListaDesenhaveis::inicializarDesenhaveis(GerenciadorGrafico &ge, GerenciadorEventos &gf) {

    Desenhavel* p = lista.voltarInicio();

    while (p) {
      
      p->inicializar(ge, gf);

      p = lista.irProximo();

    }

  }

  void ListaDesenhaveis::atualizarDesenhaveis(float t) {
    
    Desenhavel* p = lista.voltarInicio();


    while (p) {
      
      p->atualizar(t);

      p = lista.irProximo();

    }

  }

  void ListaDesenhaveis::desenharDesenhaveis(GerenciadorGrafico &g) {

    
    Desenhavel* p = lista.voltarInicio();

    while (p) {

      p->desenhar(g);

      p = lista.irProximo();

    }

  }

  void ListaDesenhaveis::destruirDesenhaveis() {
        
    Desenhavel* p = lista.voltarInicio();

    while (p) {

      delete p;

      p = lista.irProximo();

    }
    
    lista.esvaziar();

  }


}
