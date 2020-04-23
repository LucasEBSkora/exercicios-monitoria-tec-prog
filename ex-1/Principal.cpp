#include "Principal.hpp"

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


  Principal::Principal() : janela{new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 1")}, amigo{0, 0, "../assets/TheUndying.png"} {
    
    //janela = new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 1");
    //amigo = Personagem(0, 0, "TheUndying.png");
  }

  Principal::~Principal(){
    delete janela;
  }


  int Principal::executar(){
    while (true) {
      janela->clear();
      amigo.atualizar();
      amigo.desenhar(janela);
      janela->display();
    }
    return 0;
  }

}
