#include "FaseExemplo.hpp"

#include "GerenciadorTelas.hpp"

#include "Vilao.hpp"

namespace exercicio {
  
  FaseExemplo::FaseExemplo(GerenciadorGrafico& gg, Heroi* jogador1) : 
    gerenciadorGrafico{gg}, 
    jogador1{jogador1},
    gerenciadorTiles{
      {
        new Tile(Ids::errado, "../assets/TileVazio.png", {32.0f, 32.0f}),
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
    terminar{false},
    IdOuvinteFecharTela{gerenciadorEventos.adicionarOuvinteOutro( [this] (const sf::Event& e) {botaoFecharTelaApertado(e);} )} {

    listaAmigos.inserir(jogador1);
    listaAmigos.inserir( new Vilao(Vetor2F(40.0f, 50.0f), Vetor2F(0, 10)));
    listaAmigos.inserir( new Vilao(Vetor2F(40.0f, 100.0f), Vetor2F(0, -10)));
    listaAmigos.inserir( new Vilao(Vetor2F(80.0f, 50.0f), Vetor2F(0, -10)));
    listaAmigos.inserir( new Vilao(Vetor2F(80.0f, 100.0f), Vetor2F(0, 10)));

    listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

    gerenciadorTiles.inicializar(gerenciadorGrafico, gerenciadorEventos);

    gerenciadorEventos.setJanela(gerenciadorGrafico.getJanela());
    gerenciadorColisoes.setGerenciadorTiles(&gerenciadorTiles);
  }

  FaseExemplo::~FaseExemplo() {
    listaAmigos.removerPrimeiro(jogador1);
    listaAmigos.destruirDesenhaveis();
  }

  int FaseExemplo::executar() {

     sf::Time t = relogio.getElapsedTime(); 
    relogio.restart();

    gerenciadorEventos.tratarEventos();
    listaAmigos.atualizarDesenhaveis(t.asSeconds());
    gerenciadorColisoes.verificarColisoes();
    
    gerenciadorTiles.desenhar(gerenciadorGrafico);
    listaAmigos.desenharDesenhaveis(gerenciadorGrafico);
      
    if (terminar) return terminarJogo;
    else return continuar;
  }

  void FaseExemplo::botaoFecharTelaApertado(const sf::Event evento) {
    if (evento.type == sf::Event::Closed) terminar = true;
  }

}
