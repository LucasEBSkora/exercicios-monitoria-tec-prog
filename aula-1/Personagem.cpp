#include <stdio.h>
#include <string.h>

class Personagem {
  private:
    float x;
    float y;
    char nome[30];
  public:
    Personagem(float X, float Y, char* Nome) {
      x = X;
      y = Y;
      strcpy(nome, Nome);
    };
    void incrementar(float dx, float dy) {
      x += dx;
      y += dy;
    };
    void desenhar() {
      printf("Ola, meu nome e %s, e estou em (%.2f, %.2f)\n", nome, x, y);
    };

};