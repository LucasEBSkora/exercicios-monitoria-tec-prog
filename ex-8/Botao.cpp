#include "Botao.hpp"

namespace exercicio {
  Botao::Botao(Vetor2F Posicao/* = {0.0f, 0.0f}*/, Vetor2F Tamanho/* = {0.0f, 0.0f}*/, std::string Texto/* = ""*/, std::function<void(void)> QuandoApertado/* = std::function<void(void)>()*/, unsigned int tamTexto/* = 15U*/, Cor c/* = {128, 128, 128}*/) :
  posicao{Posicao}, tamanho{Tamanho}, texto{Texto}, tamanhoTexto{tamTexto}, quandoApertado{QuandoApertado}, cor{c} {}

  Botao::~Botao() {

  }

  void Botao::desenhar(GerenciadorGrafico& gg) const {
    gg.desenharRetanguloSolido(posicao, tamanho, cor);
    gg.desenharTexto(texto, posicao, tamanhoTexto);
  }

  Vetor2F Botao::getPosicao() const {
    return posicao;
  }

  Vetor2F Botao::Botao::getTamanho() const {
    return tamanho;
  }

  void Botao::apertar() const {
    quandoApertado();
  }

}