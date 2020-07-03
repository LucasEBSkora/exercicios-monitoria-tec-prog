#include "GerenciadorGrafico.hpp"

#include <iostream>

namespace exercicio {

  GerenciadorGrafico::GerenciadorGrafico() :
    janela{new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 7")},
    camera{sf::Vector2f(400, 300), sf::Vector2f(400,300)},
    text{nullptr}
  {
    janela->setView(camera);
    fonte.loadFromFile("../assets/CantoraOne-Regular.ttf");
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

  void GerenciadorGrafico::desenharRetanguloSolido(const Vetor2F centro, const Vetor2F dimensao, const Cor cor) const {
    sf::RectangleShape retangulo = sf::RectangleShape({dimensao.x, dimensao.y});
    retangulo.setFillColor({cor.r, cor.g, cor.b, cor.a});
    retangulo.setOrigin(dimensao.x/2, dimensao.y/2);
    retangulo.setPosition(centro.x, centro.y);
    janela->draw(retangulo);
  }

  void GerenciadorGrafico::desenharTexto(const std::string texto, const Vetor2F posicao, unsigned int tamanho, const bool centralizar/* = true*/) const {
    sf::Text txt = sf::Text(texto, fonte, tamanho);
    txt.setFillColor(sf::Color::White);
    if (centralizar) {
      sf::FloatRect tam = txt.getGlobalBounds();
      txt.setOrigin(tam.width/2, tam.height/2);
    }
    txt.setPosition(posicao.x, posicao.y);
    janela->draw(txt);
  }

  Vetor2F GerenciadorGrafico::getPosicaoMouse() const {
    sf::Vector2i posRelacaoJanela = sf::Mouse::getPosition(*janela);
    sf::Vector2u tamanhoJanela = janela->getSize();
    sf::Vector2f tamanhoCamera = camera.getSize();
    sf::Vector2f posicaoCamera = camera.getCenter() - tamanhoCamera/2.0f;

    return {
      (posRelacaoJanela.x/(float)tamanhoJanela.x)*tamanhoCamera.x + posicaoCamera.x, 
      (posRelacaoJanela.y/(float)tamanhoJanela.y)*tamanhoCamera.y + posicaoCamera.y
    };

  }

}