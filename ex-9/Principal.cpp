#include "Principal.hpp"

#include "Heroi.hpp"
#include "Vilao.hpp"
#include "Tile.hpp"

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
      jogador1{Heroi(Vetor2F(20.0f, 20.0f))},
      gerenciadorTelas{gerenciadorGrafico, &jogador1},
      terminar{false}
     {
    

  }

  Principal::~Principal(){
    
  }


  int Principal::executar(){
    

    while (!terminar) {

      gerenciadorGrafico.limpar();
      //substitui janela->clear();
      
      terminar = gerenciadorTelas.executar();
      
      gerenciadorGrafico.mostrar();
      //substitui janela->display();
    
    }

    return 0;
  }

}
