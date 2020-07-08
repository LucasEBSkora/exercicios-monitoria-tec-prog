#include "Fase.hpp"

#include "GerenciadorTelas.hpp"

#include "Vilao.hpp"

namespace exercicio {
  
  Fase::Fase(GerenciadorGrafico& gg, GerenciadorTiles* gt, Heroi* jogador1 /*= nullptr*/) : 
    gerenciadorGrafico{gg},
    jogador1{jogador1},
    gerenciadorTiles{gt},
    IdOuvinteFecharTela{gerenciadorEventos.adicionarOuvinteOutro( [this] (const sf::Event& e) {botaoFecharTelaApertado(e);} )},
    IdOuvinteEntrarMenu{gerenciadorEventos.adicionarOuvinteTeclado( [this] (const sf::Event& e) {botaoEntrarMenuApertado(e);} )},
    codigoRetorno{continuar}
     {

    gerenciadorTiles->inicializar(gerenciadorGrafico, gerenciadorEventos);
    gerenciadorEventos.setJanela(gerenciadorGrafico.getJanela());
    gerenciadorColisoes.setGerenciadorTiles(gerenciadorTiles);
  }



  Fase::~Fase() {
    listaAmigos.removerPrimeiro(jogador1);
    listaAmigos.destruirDesenhaveis();
    delete gerenciadorTiles;
  }

  int Fase::executar() {
    codigoRetorno = continuar;
    double t = relogio.getTempo(); 

    gerenciadorEventos.tratarEventos();
    listaAmigos.atualizarDesenhaveis(t);
    gerenciadorColisoes.verificarColisoes();
    
    gerenciadorTiles->desenhar(gerenciadorGrafico);
    listaAmigos.desenharDesenhaveis(gerenciadorGrafico);
    
    return codigoRetorno;
  }

  void Fase::botaoFecharTelaApertado(const sf::Event evento) {
    if (evento.type == sf::Event::Closed) setCodigoRetorno(terminarJogo);
  }
  
  void Fase::botaoEntrarMenuApertado(const sf::Event evento) {
    if (evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Key::Escape) {
      setCodigoRetorno(irMenuPausa);
      relogio.pausar();
    }
  }

  void Fase::setCodigoRetorno(int codigo) {
    codigoRetorno = codigo;
  }
}
