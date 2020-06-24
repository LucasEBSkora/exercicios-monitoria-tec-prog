#include "Menu.hpp"

#include "GerenciadorTelas.hpp"

namespace exercicio {
  Menu::Menu(GerenciadorGrafico& GG) : codigoRetorno{CodigoRetorno::continuar}, gb{ge, GG}, gg{GG} {
    ge.setJanela(gg.getJanela());
    inicializar();
  }

  int Menu::executar()  {
    codigoRetorno = CodigoRetorno::continuar;
    ge.tratarEventos();
    gb.desenhar();
    return codigoRetorno;
  }

  void Menu::setCodigoRetorno(int codigo) {
    codigoRetorno = codigo;
  }
}