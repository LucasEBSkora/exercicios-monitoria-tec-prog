#include "Personagem.cpp"

int main () {
  Personagem amigo(0, 0, "amiguinho");

  for (int i = 0; i < 11; ++i) {
    amigo.incrementar(i,-i);
    amigo.desenhar();
  }
  return 0;
}