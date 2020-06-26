#ifndef _MENU_HPP_ 
#define _MENU_HPP_

#include "Estado.hpp"

#include "GerenciadorEventos.hpp"
#include "GerenciadorBotoes.hpp"
#include "GerenciadorGrafico.hpp"


namespace exercicio {
  class Menu : public Estado {
      
    private:
      int codigoRetorno;

    protected:
      GerenciadorEventos ge;
      GerenciadorBotoes gb;
      GerenciadorGrafico &gg;
    
    public:
      Menu(GerenciadorGrafico& GG);
      virtual ~Menu();
      int executar() override;

    protected:
      void setCodigoRetorno(int codigo);
  };
}


#endif