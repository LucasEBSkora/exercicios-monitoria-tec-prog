#include "ListaPersonagens.hpp"

#include <iostream>

namespace exercicio {


        
  ListaPersonagens::ElementoLista::ElementoLista(Personagem* Info, ElementoLista* Ant, ElementoLista* Prox) :
  info{Info}, ant{Ant}, prox{Prox} {

  }

  ListaPersonagens::ElementoLista::~ElementoLista() {

  }


  Personagem* ListaPersonagens::ElementoLista::getInfo() {
    return info;
  }

  void ListaPersonagens::ElementoLista::setInfo(Personagem* Info) {
    info = Info;
  }


  ListaPersonagens::ElementoLista* ListaPersonagens::ElementoLista::getAnt() {
    return ant;
  }

  void ListaPersonagens::ElementoLista::setAnt(ElementoLista* Ant) {
    ant = Ant;
  }


  ListaPersonagens::ElementoLista* ListaPersonagens::ElementoLista::getProx() {
    return prox;
  }

  void ListaPersonagens::ElementoLista::setProx(ElementoLista* Prox) {
    prox = Prox;
  }


  ListaPersonagens::ListaPersonagens() :
    inicio{nullptr}, fim{nullptr}, atual{nullptr} {

  }

  ListaPersonagens::~ListaPersonagens() {
    esvaziar();
  }


  void ListaPersonagens::inserir(Personagem* info) {
    if (info) { //info == NULL == 0 == false
      
      ElementoLista* novo = new ElementoLista(info);

      if (!inicio) {
      
        inicio = novo;
        fim = novo;
      
      } else {
        
        fim->setProx(novo);
        novo->setAnt(fim);

        fim = novo;

      }



    }
  }

  void ListaPersonagens::esvaziar() {

    ElementoLista* paux = inicio;
    atual = inicio;
    
    while (atual != nullptr) {
      paux = atual->getProx();

      delete atual;

      atual = paux;

    }

    inicio = nullptr;
    fim = nullptr;
    atual = nullptr;


  }

  Personagem* ListaPersonagens::voltarInicio() {
    atual = inicio;

    if (atual) return atual->getInfo();
    else return nullptr;

  }

  Personagem* ListaPersonagens::irProximo() {

    atual = atual->getProx();

    return (atual) ? atual->getInfo() : nullptr;


  }


  void ListaPersonagens::atualizarPersonagens(float t) {
    
    Personagem* p = voltarInicio();


    while (p) {
      
      p->atualizar(t);

      p = irProximo();

    }

  }

  void ListaPersonagens::desenharPersonagens(sf::RenderWindow* janela) {

    
    Personagem* p = voltarInicio();

    while (p) {

      p->desenhar(janela);

      p = irProximo();

    }

  }

  void ListaPersonagens::destruirPersonagens() {
        
    Personagem* p = voltarInicio();

    while (p) {

      delete p;

      p = irProximo();

    }
    
    esvaziar();

  }


}
