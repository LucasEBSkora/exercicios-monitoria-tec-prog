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
    terminar{false}, 
    gerenciadorTiles{
      {
        new Tile(Ids::semID, "../assets/TileVazio.png", {32.0f, 32.0f}),
        new Tile(Ids::parede, "../assets/TempleWallTile.png", {32.0f, 32.0f}),
        new Tile(Ids::espinho, "../assets/TempleSpikeObstacle.png", {32.0f, 32.0f}),
        new Tile(Ids::fimDaFase, "../assets/LevelEndTile.png", {32.0f, 32.0f}),
        new Tile(Ids::parede, "../assets/PlayerSpawnPoint.png", {32.0f, 32.0f}),
        new Tile(Ids::buracoInfinito, "../assets/HoleObstacle.png", {32.0f, 32.0f}),
        new Tile(Ids::parede, "../assets/CavernWallTile.png", {32.0f, 32.0f}),
        new Tile(Ids::espinho, "../assets/CavernSpikeObstacle.png", {32.0f, 32.0f}),
        new Tile(Ids::armadilha, "../assets/BulletObstacle.png", {32.0f, 32.0f}),
      },
       {32.0f, 32.0f}, "../assets/tilemap.json"
    },
    IDjanelaFechada{gerenciadorEventos.adicionarOuvinteOutro( [this] (const sf::Event& e) {janelaFechada(e);} )}
     {
    
    listaAmigos.inserir( new Heroi(Vetor2F(20.0f, 20.0f)));
    listaAmigos.inserir( new Vilao(Vetor2F(40.0f, 50.0f), Vetor2F(0, 10)));
    listaAmigos.inserir( new Vilao(Vetor2F(40.0f, 100.0f), Vetor2F(0, -10)));
    listaAmigos.inserir( new Vilao(Vetor2F(80.0f, 50.0f), Vetor2F(0, -10)));
    listaAmigos.inserir( new Vilao(Vetor2F(80.0f, 100.0f), Vetor2F(0, 10)));

    listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

    gerenciadorTiles.inicializar(gerenciadorGrafico, gerenciadorEventos);

    gerenciadorEventos.setJanela(gerenciadorGrafico.getJanela());
    gerenciadorColisoes.setGerenciadorTiles(&gerenciadorTiles);
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
      //substitui janela->clear();
      
      listaAmigos.atualizarDesenhaveis(t.asSeconds());
      gerenciadorColisoes.verificarColisoes();


      gerenciadorTiles.desenhar(gerenciadorGrafico);
      listaAmigos.desenharDesenhaveis(gerenciadorGrafico);
      
      gerenciadorGrafico.mostrar();
      //substitui janela->display();
    
    }

    return 0;
  }

  void Principal::janelaFechada(const sf::Event& e) {
    if (e.type == sf::Event::Closed) terminar = true;
  }

}
