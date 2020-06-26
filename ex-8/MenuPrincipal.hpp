#ifndef _MENU_PRINCIPAL_HPP_
#define _MENU_PRINCIPAL_HPP_

#include "Menu.hpp"
#include "CampoTexto.hpp"

namespace exercicio {
  class MenuPrincipal : public Menu {
    bool imprimiu;
    CampoTexto campoTexto;
    public:
      MenuPrincipal(GerenciadorGrafico& GG);
      int executar() override;
  };
}

#endif