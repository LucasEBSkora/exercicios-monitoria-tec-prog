#include "Principal.hpp"

#include <iostream>

namespace exercicio {

  /*

  listas de inicialização

  no construtor de uma classe, depois da lista de parâmetros mas antes do abre chaves, escreva um dois pontos.
  depois disso, coloque o nome de cada variável com os parâmetros que você passaria para inicializá-la (ou o valor de inicialização) entre chaves, separados
  por vírgulas, na ordem de sua declaração na classe.

  Também funcionaria com parenteses 

  amigo(0, 0, "TheUndying.png")

  mas as chaves são mais estritas, impedindo que você faça conversões não explícitas, o que é mais eficiente e te dá um controle mais exato sobre o que está acontecendo



  */


  Principal::Principal() : terminar{false}, janela{new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 1")} {
    //janela = new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 1");
    
    listaAmigos.inserir( new Personagem(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(5, 5), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(sf::Vector2f(400.0f, 300.0f), sf::Vector2f(10, 0), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(0, 5), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(sf::Vector2f(800.0f, 600.0f), sf::Vector2f(0, 0), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(sf::Vector2f(400.0f, 0.0f), sf::Vector2f(5, 5), "../assets/TheUndying.png"));



  }

  Principal::~Principal(){
    delete janela;

    listaAmigos.destruirPersonagens();
  }


  int Principal::executar(){
    
    relogio.restart();

    sf::Event e;

    while (!terminar) {
      sf::Time t = relogio.getElapsedTime(); 
      relogio.restart();

      
        if (janela->pollEvent(e)) {
          if (e.type == sf::Event::Closed) {
            terminar = true;
          }
        }



    
      janela->clear();
      
      listaAmigos.atualizarPersonagens(t.asSeconds());

  
      listaAmigos.desenharPersonagens(janela);
      janela->display();
    
    }

    return 0;
  }

}
