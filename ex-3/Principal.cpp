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


  Principal::Principal() : terminar{false} {
    //janela = new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 1");
    
    listaAmigos.inserir( new Personagem(Vetor2F(0.0f, 0.0f), Vetor2F(5, 5), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(Vetor2F(400.0f, 300.0f), Vetor2F(10, 0), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(Vetor2F(200.0f, 200.0f), Vetor2F(0, 5), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(Vetor2F(700.0f, 500.0f), Vetor2F(0, 0), "../assets/TheUndying.png"));
    listaAmigos.inserir( new Personagem(Vetor2F(400.0f, 0.0f), Vetor2F(5, 5), "../assets/TheUndying.png"));


    listaAmigos.inicializarPersonagens(gerenciadorGrafico);

  }

  Principal::~Principal(){
    listaAmigos.destruirPersonagens();
  }


  int Principal::executar(){
    
    relogio.restart();

    sf::Event e;

    while (!terminar) {
      sf::Time t = relogio.getElapsedTime(); 
      relogio.restart();

      
        if (gerenciadorGrafico.getJanela()->pollEvent(e)) {
          if (e.type == sf::Event::Closed) {
            terminar = true;
          }
        }



      gerenciadorGrafico.limpar();
      //janela->clear();
      
      listaAmigos.atualizarPersonagens(t.asSeconds());

  
      listaAmigos.desenharPersonagens(gerenciadorGrafico);
      
      gerenciadorGrafico.mostrar();
      //janela->display();
    
    }

    return 0;
  }

}
