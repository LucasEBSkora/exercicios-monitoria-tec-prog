#include <stdio.h>
#include <string>
#include "Personagem.hpp"

  Personagem::Personagem(float X, float Y, char* Nome) {
    x = X;
    y = Y;
    strcpy(nome, Nome);
  }
  void Personagem::incrementar(float dx, float dy) {
    x += dx;
    y += dy;
  }
  void Personagem::desenhar() {
    
  }