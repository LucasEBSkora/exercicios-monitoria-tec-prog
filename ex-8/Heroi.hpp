#ifndef _HEROI_HPP_
#define _HEROI_HPP_

#include "Colidivel.hpp"
#include "Vetor2D.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"



namespace exercicio {

  class Heroi : public Colidivel {
    private:
      unsigned int chaveOuvinte;
    public:
      
      Heroi(Vetor2F pos = {0.0f , 0.0f});
      ~Heroi();
      void inicializar(GerenciadorGrafico &gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
      void atualizar(float t);
      void desenhar(GerenciadorGrafico &g);
      void tratarEvento(const sf::Event &e);
      void colidir(Ids::Ids idOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);
  };

}

#endif