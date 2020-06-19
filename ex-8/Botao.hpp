#ifndef _BOTAO_HPP_
#define _BOTAO_HPP_

#include "Vetor2D.hpp"
#include "Cor.hpp"
#include "GerenciadorGrafico.hpp"

#include <string>
#include <functional>


namespace exercicio {
  class Botao {
    private:
      Vetor2F posicao;
      Vetor2F tamanho;
      Cor cor;
      std::string texto;
      unsigned int tamanhoTexto;
      std::function<void(void)> quandoApertado;

    public:
      Botao(Vetor2F Posicao = {0.0f, 0.0f}, Vetor2F Tamanho = {0.0f, 0.0f}, std::string Texto = "", std::function<void(void)> QuandoApertado = std::function<void(void)>(), unsigned int tamTexto = 15U, Cor c = {128, 128, 128});
      ~Botao();
      void desenhar(GerenciadorGrafico& gg) const;
      Vetor2F getPosicao() const;
      Vetor2F getTamanho() const;
      void apertar() const;

  };
}

#endif