#include "GerenciadorGrafico.hpp"

#include <iostream>

namespace exercicio {

  GerenciadorGrafico::GerenciadorGrafico() :
    janela{new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 3")},
    camera{sf::Vector2f(400, 300), sf::Vector2f(400,300)},
    text{nullptr}
  {
    janela->setView(camera);
  }

  GerenciadorGrafico::~GerenciadorGrafico() {
    delete janela;


    //auto é uma palavra-chave que significa, em essência "o tipo da variável que declararei em seguida é o tipo que atribuirei a ela".
    //Nesse caso, substitui o tipo std::map<const std::string, sf::Texture*>::iterator ou std::map<const std::string, sf::Texture*>::const_iterator
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
      std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
      exit(121);
    }

    text = texturas[caminho];

    //Seria possivel (aconselhável) verificar se a textura está completamente fora
    //da câmera e não desenhá-la se for o caso

    sprite.setTexture(*text, true);
    sprite.setOrigin(text->getSize().x*0.5, text->getSize().x*0.5);
    sprite.setPosition(posicao.x, posicao.y);

    janela->draw(sprite);


  }

  void GerenciadorGrafico::desenhar(const std::string& caminho, const Vetor2F posicao, const Vetor2U numeroFrames, const Vetor2U frame) {

    if (texturas.count(caminho) == 0) {
      std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
      exit(121);
    }

    text = texturas[caminho];

    //Seria possivel (aconselhável) verificar se a textura está completamente fora
    //da câmera e não desenhá-la se for o caso
    
    sprite.setTexture(*text);
    
    
    sf::Vector2i tamanho = {(int)text->getSize().x / (int)numeroFrames.y, (int)text->getSize().y / (int)numeroFrames.x };
    sf::Vector2i posicaoFrame = { (int)tamanho.x * (int)frame.y, (int)tamanho.y * (int)frame.x};

    sprite.setTextureRect({ posicaoFrame, tamanho});

    sprite.setOrigin({tamanho.x*0.5f, tamanho.y*0.5f});
    sprite.setPosition(posicao.x, posicao.y);

    janela->draw(sprite);

  }

  bool GerenciadorGrafico::carregarTextura(const std::string& caminho) {
    if (texturas.count(caminho) == 1) return true;
    else {
      
      
      sf::Texture* text = new sf::Texture();
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
    janela->setView(camera); //A RenderWindow faz uma cópia da View ao invés de usar o ponteiro, então é preciso a sobre-escrever sempre que for modificada.
  }

  sf::RenderWindow* GerenciadorGrafico::getJanela() const {
    return janela;
  }

  const Vetor2F GerenciadorGrafico::getTamanho(const std::string& caminho) const {
    
    if (texturas.count(caminho) == 0) {
      std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
      exit(121);
    }

    sf::Vector2u dimensoes = (texturas.at(caminho))->getSize();
    
    return Vetor2F(dimensoes.x, dimensoes.y);
  }

}