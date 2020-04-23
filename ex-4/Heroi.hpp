#ifndef _HEROI_HPP_
#define _HEROI_HPP_

#include "Desenhavel.hpp"
#include "Vetor2D.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"



namespace exercicio {

  class Heroi : public Desenhavel {
    private:
      unsigned int chaveOuvinte;
    public:
      
      Heroi(Vetor2F pos);
      ~Heroi();
      void inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge);
      void atualizar(float t);
      void desenhar(GerenciadorGrafico &g);
      void tratarEvento(const sf::Event &e);
  };

}

#endif