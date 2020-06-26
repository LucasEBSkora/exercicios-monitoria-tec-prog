#include "CampoTexto.hpp"

namespace exercicio {
  CampoTexto::CampoTexto(GerenciadorEventos& ge, unsigned short comprimentoMaximo, Vetor2F Posicao/* = {0.0f, 0.0f}*/, 
    Vetor2F Tamanho/* = {0.0f, 0.0f}*/, unsigned int tamTexto/* = 15U*/, Cor c/* = {128, 128, 128}*/) : 
    Botao{Posicao, Tamanho, "", [this] () {iniciarCaptura();}, tamTexto, c},
    promessa{ge, comprimentoMaximo} {}

  CampoTexto::~CampoTexto() {

  }

  const std::string& CampoTexto::getTexto() const {
    if (!getTextoPronto()) throw "Erro! String pedida sem ter sido terminada antes. Cheque getTextoPronto() antes de chamar esse método";
    return promessa.getTexto();
  }

  bool CampoTexto::getTextoPronto() const {
    return promessa.getTextoPronto();
  }

  void CampoTexto::desenhar(GerenciadorGrafico& gg) const {
    gg.desenharRetanguloSolido(posicao, tamanho, cor);
    gg.desenharTexto(promessa.getTexto(), posicao, tamanhoTexto, false);
  }

  void CampoTexto::iniciarCaptura() {
    promessa.comecar();
  }

}