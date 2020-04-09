#ifndef _LISTAPERSONAGENS_HPP_
#define _LISTAPERSONAGENS_HPP_

#include "Personagem.hpp"

namespace exercicio {

  class GerenciadorGrafico;

  class ListaPersonagens {
    private:

      class ElementoLista {
        private:
          Personagem* info;
          ElementoLista* ant;
          ElementoLista* prox;
        
        public:
          ElementoLista(Personagem* Info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
          ~ElementoLista();

          Personagem* getInfo();
          void setInfo(Personagem* Info);

          ElementoLista* getAnt();
          void setAnt(ElementoLista* Ant);

          ElementoLista* getProx();
          void setProx(ElementoLista* Prox);
      };

      ElementoLista* inicio;
      ElementoLista* fim;
      ElementoLista* atual;

    public:

      ListaPersonagens();
      ~ListaPersonagens();

      void inserir(Personagem* info);
      void esvaziar();


      //funções para iterar a lista: existe exemplo de uso nas funções atualizar, desenhar e destruirPersonagens

      Personagem* voltarInicio(); //retorna para o início e retorna o primeiro elemento da lista
      Personagem* irProximo(); //vai para o próximo elemento da lista e retorna o próximo

      void inicializarPersonagens(GerenciadorGrafico &g);
      void atualizarPersonagens(float t);
      void desenharPersonagens(GerenciadorGrafico &g);
      void destruirPersonagens();

  };

}


#endif