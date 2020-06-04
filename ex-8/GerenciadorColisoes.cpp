#include "GerenciadorColisoes.hpp"
#include "Colidivel.hpp"

#include "Vetor2D.hpp"

#include <math.h>

#include <iostream>

namespace exercicio {


  GerenciadorColisoes::GerenciadorColisoes() : gt{nullptr} {

  }

  GerenciadorColisoes::~GerenciadorColisoes() {

  }

  bool GerenciadorColisoes::estaoColidindo(Colidivel* p1, Colidivel* p2) {
    
    Vetor2F posicao1 = p1->getPosicao();
    Vetor2F dimensoes1 = p1->getDimensoes();

    Vetor2F posicao2 = p2->getPosicao();
    Vetor2F dimensoes2 = p2->getDimensoes();

    Vetor2F distancia = posicao1 - posicao2;

    // if (p1->getId() == Ids::vilao) {

    //  std::cout << '(' << posicao1.x << ',' << posicao1.y << ')' << '(' << posicao2.x << ',' << posicao2.y << ')'<< '(' << distancia.x << ',' << distancia.y << ')'<< (dimensoes1.x + dimensoes2.x)/2.0 << ' ' << (dimensoes1.y + dimensoes2.y)/2. << '\n';

    // }
    
    if (p1 == p2) return false;

    return (fabs(distancia.x) < (dimensoes1.x + dimensoes2.x)/2.) && (fabs(distancia.y) < (dimensoes1.y + dimensoes2.y)/2.);


  }

  void GerenciadorColisoes::adicionarColidivel(Colidivel* p) {
    colidiveis.insert(p);
  }

  void GerenciadorColisoes::removerColidivel(Colidivel* p) {
    colidiveis.erase(p);
  }

  void GerenciadorColisoes::removerTodos() {
    colidiveis.clear();
  }

  void GerenciadorColisoes::verificarColisoes() {
    
    for (auto primeiro = colidiveis.begin(); primeiro != colidiveis.end(); primeiro++) {
      
      Colidivel *p1 = *primeiro;
      
      auto tilesColidindo = gt->checarColisoes(p1->getId(), p1->getPosicao(), p1->getDimensoes());

      for (auto colisao : tilesColidindo) 
        p1->colidir(colisao.id, colisao.posicao, colisao.tamanho);
      
      auto segundo = primeiro;
      segundo++;  

      for (; segundo != colidiveis.end(); segundo++) {
        Colidivel *p2 = *segundo;
        
        
        
        if (estaoColidindo(p1, p2)) {
          p1->colidir(p2->getId(), p2->getPosicao(), p2->getDimensoes());
          p2->colidir(p1->getId(), p1->getPosicao(), p1->getDimensoes());  
            
        }

      }

      //std::cout << '\n' << std::endl;
    }

  }

  void GerenciadorColisoes::setGerenciadorTiles(GerenciadorTiles* Gt) {
    gt = Gt;
  }

}