#ifndef _LISTFA_HPP_
#define _LISTA_HPP_

namespace exercicio {

  template <typename TF>
  class Lista {
    private:
      
      template <typename TE>
      class ElementoLista {
        private:
          TE info;
          ElementoLista* ant;
          ElementoLista* prox;
        
        public:
          ElementoLista(TE Info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
          ~ElementoLista();

          TE getInfo();
          void setInfo(TE Info);

          ElementoLista* getAnt();
          void setAnt(ElementoLista* Ant);

          ElementoLista* getProx();
          void setProx(ElementoLista* Prox);
      };

      ElementoLista<TF>* inicio;
      ElementoLista<TF>* fim;
      ElementoLista<TF>* atual;

    public:

      Lista();
      ~Lista();

      void inserir(TF info);
      void esvaziar();

      //funções para iterar a lista: existe exemplo de uso nas funções atualizar, desenhar e destruirPersonagens

      TF voltarInicio(); //retorna para o início e retorna o primeiro elemento da lista
      TF irProximo(); //vai para o próximo elemento da lista e retorna o próximo
  };

}

#include "ListaImplementacao.hpp"

#endif