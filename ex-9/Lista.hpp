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

          TE getInfo() const;
          void setInfo(TE Info);

          ElementoLista* getAnt() const;
          void setAnt(ElementoLista* Ant);

          ElementoLista* getProx() const;
          void setProx(ElementoLista* Prox);

          void remover();
      };

      ElementoLista<TF>* inicio;
      ElementoLista<TF>* fim;
      ElementoLista<TF>* atual;

    public:

      Lista();
      ~Lista();

      void inserir(TF info);
      void esvaziar();

      TF voltarInicio(); //retorna para o início e retorna o primeiro elemento da lista
      TF irProximo(); //vai para o próximo elemento da lista e retorna o próximo
      void removerPrimeiro(TF elemento);
  };

}

#include "ListaImplementacao.hpp"

#endif