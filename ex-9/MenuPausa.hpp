#ifndef _MENU_PAUSA_HPP_
#define _MENU_PAUSA_HPP_

#include "Menu.hpp"
#include "GerenciadorGrafico.hpp"

namespace exercicio {
  class MenuPausa : public Menu {
    MenuPausa(GerenciadorGrafico& gg);
  };
}

#endif