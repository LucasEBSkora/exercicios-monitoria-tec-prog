#ifndef _GERENCIADORGRAFICO_HPP_
#define _GERENCIADORGRAFICO_HPP_

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Vetor2D.hpp"
#include "Cor.hpp"

namespace exercicio {

  class GerenciadorGrafico {
    private:
      sf::RenderWindow* janela;
      sf::View camera;
      std::map<const std::string, sf::Texture*> texturas;
      sf::Texture* text;
      sf::Sprite sprite;
      sf::Font fonte;

    public:
      GerenciadorGrafico();
      ~GerenciadorGrafico();
      void mostrar() const;
      void limpar(int r = 0, int g = 0, int b = 0);
      void desenhar(const std::string& caminho, const Vetor2F posicao);
      void desenhar(const std::string& caminho, const Vetor2F posicao, const Vetor2U numeroFrames, const Vetor2U frame);
      bool carregarTextura(const std::string& caminho);
      void centralizar(const Vetor2F centro);
      const Vetor2F getTamanhoTela() const;
      sf::RenderWindow* getJanela() const;
      const Vetor2F getTamanho(const std::string& caminho) const;
      void desenharRetanguloSolido(const Vetor2F centro, const Vetor2F dimensao, const Cor cor) const;
      void desenharTexto(const std::string texto, const Vetor2F posicao, unsigned int tamanho, const bool centralizar = true) const;
      Vetor2F getPosicaoMouse() const;



  };

}

#endif