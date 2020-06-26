#ifndef _CAMPO_TEXTO_HPP_
#define _CAMPO_TEXTO_HPP_

#include "Botao.hpp"
#include "PromessaTexto.hpp"
#include "GerenciadorEventos.hpp"
#include "GerenciadorGrafico.hpp"
#include "Vetor2D.hpp"
#include "Cor.hpp"

#include <string>

namespace exercicio {
  class CampoTexto : public Botao {
    
    private:
      PromessaTexto promessa;

    public:
      CampoTexto(GerenciadorEventos& ge, unsigned short comprimentoMaximo, Vetor2F Posicao = {0.0f, 0.0f}, Vetor2F Tamanho = {0.0f, 0.0f}, unsigned int tamTexto = 15U, Cor c = {128, 128, 128});
      ~CampoTexto();
      const std::string& getTexto() const;
      bool getTextoPronto() const;
      void desenhar(GerenciadorGrafico& gg) const override;
      void iniciarCaptura();

  };
}

#endif