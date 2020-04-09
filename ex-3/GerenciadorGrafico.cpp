#include "GerenciadorGrafico.hpp"

#include <iostream>

namespace exercicio {

  GerenciadorGrafico::GerenciadorGrafico() :
    janela{new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 3")},
    camera{sf::Vector2f(400, 300), sf::Vector2f(800,600)}
  {
    janela->setView(camera);
  }

  GerenciadorGrafico::~GerenciadorGrafico() {
    delete janela;

    /*
    for (auto i = texturas.begin(); i != texturas.end(); ++i) {
      delete (*i).second;
    }
    */

    for (auto i : texturas) {
      delete i.second;
    }
  }

  void GerenciadorGrafico::mostrar() const {
    janela->display();
  }

  void GerenciadorGrafico::limpar(int r, int g, int b) {
    janela->clear(sf::Color(r, g, b));
  }

  void GerenciadorGrafico::desenhar(const std::string& caminho, const Vetor2F posicao) {
    
    if (texturas.count(caminho) == 0) {
      std::cout << texturas.size() << std::endl;
      std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
      exit(121);
    }

    sf::Texture* text = texturas[caminho];

    sf::Sprite sprite;

    //Seria possivel (aconselhável) verificar se a textura está completamente fora
    //da câmera e não desenhá-la se for o caso

    sprite.setTexture(*text);

    sprite.setPosition(posicao.x, posicao.y);

    janela->draw(sprite);


  }

  bool GerenciadorGrafico::carregarTextura(const std::string& caminho) {
      std::cout << texturas.count(caminho) << std::endl;
    
    if (texturas.count(caminho) == 1) return true;
    else {
      
      
      sf::Texture* text = new sf::Texture();

      std::cout << caminho << std::endl;
      if (!text->loadFromFile(caminho)) {
        std::cout << "Atencao! imagem em " << caminho << "nao encontrada!" << std::endl;
        exit(120);
      }

      //texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
      texturas.emplace(caminho, text); //c++11
      return true;
    }
  }

  void GerenciadorGrafico::centralizar(const Vetor2F centro) {
    camera.setCenter(sf::Vector2f(centro.x, centro.y));
  }

  sf::RenderWindow* GerenciadorGrafico::getJanela() const {
    return janela;
  }


}