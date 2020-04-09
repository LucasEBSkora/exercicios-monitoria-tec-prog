#ifndef _GERENCIADORGRAFICO_HPP_
#define _GERENCIADORGRAFICO_HPP_

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Vetor2D.hpp"

namespace exercicio {

  class GerenciadorGrafico {
    private:
      sf::RenderWindow* janela;
      sf::View camera;
      std::map<const std::string, sf::Texture*> texturas;

    public:
      GerenciadorGrafico();
      ~GerenciadorGrafico();
      void mostrar() const;
      void limpar(int r = 0, int g = 0, int b = 0);
      void desenhar(const std::string& caminho, const Vetor2F posicao);
      bool carregarTextura(const std::string& caminho);
      void centralizar(const Vetor2F centro);
      sf::RenderWindow* getJanela() const;

  };

}

#endif