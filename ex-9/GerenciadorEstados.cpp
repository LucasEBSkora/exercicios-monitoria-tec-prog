#include "GerenciadorEstados.hpp"

namespace exercicio {
  
  GerenciadorEstados::~GerenciadorEstados() {
    esvaziarPilha();
  }

  bool GerenciadorEstados::executar() {
    // Estado* estado = pilhaEstados.top();
    // int codigoRetorno = estado->executar();
    // bool terminar = processarCodigo(codigoRetorno);
    // return terminar;

    return processarCodigo((pilhaEstados.top())->executar());  
  }

  void GerenciadorEstados::push(Estado* p) {
    if (p) pilhaEstados.push(p); 
  }

  void GerenciadorEstados::pop() {
      delete pilhaEstados.top();
      pilhaEstados.pop();
  }

  Estado* GerenciadorEstados::top() {
    return pilhaEstados.top();
  }

  void GerenciadorEstados::esvaziarPilha() {
    while (pilhaEstados.size() != 0) 
      pop();
  }


}