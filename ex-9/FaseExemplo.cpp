#include "FaseExemplo.hpp"

#include "Tile.hpp"
#include "Vilao.hpp"

#include <fstream>

namespace exercicio {
  FaseExemplo::FaseExemplo(GerenciadorGrafico& gg, Heroi* jogador1/* = nullptr*/) : Fase{gg,
  new GerenciadorTiles{
    {
      new Tile(Ids::semID, "../assets/TileVazio.png"),
      new Tile(Ids::parede, "../assets/TempleWallTile.png"),
      new Tile(Ids::espinho, "../assets/TempleSpikeObstacle.png"),
      new Tile(Ids::fimDaFase, "../assets/LevelEndTile.png"),
      new Tile(Ids::parede, "../assets/PlayerSpawnPoint.png"),
      new Tile(Ids::buracoInfinito, "../assets/HoleObstacle.png"),
      new Tile(Ids::parede, "../assets/CavernWallTile.png"),
      new Tile(Ids::espinho, "../assets/CavernSpikeObstacle.png"),
      new Tile(Ids::armadilha, "../assets/BulletObstacle.png"),
    },
    {32.0f, 32.0f}, "../assets/tilemap.json"
  }
  , jogador1} {

  }

  nlohmann::json FaseExemplo::paraJSON() {
    nlohmann::json json;

    json["amigos"] = listaAmigos.paraJSON();

    return json;
    
  }

  void FaseExemplo::carregar(const std::string& caminho) {
    std::ifstream arquivo(caminho);
    if (arquivo.fail()) throw "arquivo nao encontrado!";
    nlohmann::json j;
    arquivo >> j;

    for (nlohmann::json amigo : j["amigos"]) {
      switch (static_cast<int> (amigo["id"]))
      {
      case Ids::heroi:
        if (jogador1) {
          jogador1->inicializarComJSON(amigo);
          listaAmigos.inserir(jogador1);
        }
        break;
      case Ids::vilao: 
        listaAmigos.inserir(new Vilao(amigo));
        break;
      default:
        break;
      }
    }

    listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
  }

  void FaseExemplo::inicializar() {
    if (jogador1) listaAmigos.inserir(jogador1);

    listaAmigos.inserir( new Vilao(Vetor2F(40.0f, 50.0f), Vetor2F(0, 10)));
    listaAmigos.inserir( new Vilao(Vetor2F(40.0f, 100.0f), Vetor2F(0, -10)));
    listaAmigos.inserir( new Vilao(Vetor2F(80.0f, 50.0f), Vetor2F(0, -10)));
    listaAmigos.inserir( new Vilao(Vetor2F(80.0f, 100.0f), Vetor2F(0, 10)));

    listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

  }

}