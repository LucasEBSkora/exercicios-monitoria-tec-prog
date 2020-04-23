#include "Principal.hpp"

#include "Heroi.hpp"
#include "Vilao.hpp"

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


  Principal::Principal() : 
    terminar{false}, 
    IDjanelaFechada{gerenciadorEventos.adicionarOuvinteOutro( [this] (const sf::Event& e) {janelaFechada(e);} )} {
    
    listaAmigos.inserir( new Heroi(Vetor2F(0.0f, 0.0f)));
    listaAmigos.inserir( new Vilao(Vetor2F(400.0f, 300.0f), Vetor2F(10, 0)));
    listaAmigos.inserir( new Vilao(Vetor2F(200.0f, 200.0f), Vetor2F(0, 5)));
    listaAmigos.inserir( new Vilao(Vetor2F(700.0f, 500.0f), Vetor2F(0, 0)));
    listaAmigos.inserir( new Vilao(Vetor2F(20.0f, 0.0f), Vetor2F(5, 5)));


    listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos);

    gerenciadorEventos.setJanela(gerenciadorGrafico.getJanela());

  }

  Principal::~Principal(){
    listaAmigos.destruirDesenhaveis();
  }


  int Principal::executar(){
    
    relogio.restart();
    
    while (!terminar) {
      sf::Time t = relogio.getElapsedTime(); 
      relogio.restart();

      gerenciadorEventos.tratarEventos();

      gerenciadorGrafico.limpar();
      //janela->clear();
      
      listaAmigos.atualizarDesenhaveis(t.asSeconds());

  
      listaAmigos.desenharDesenhaveis(gerenciadorGrafico);
      
      gerenciadorGrafico.mostrar();
      //janela->display();
    
    }

    return 0;
  }

  void Principal::janelaFechada(const sf::Event& e) {
    if (e.type == sf::Event::Closed) terminar = true;
  }

}
