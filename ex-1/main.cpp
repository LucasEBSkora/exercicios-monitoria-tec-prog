#include "Principal.hpp"

//3 maneiras diferentes mas equivalentes de usar a classe Principal

/*
int main() {
  Principal principal; //no construtor de principal você chama executar() no final

  return 0;
}
*/

/*
int main() {
  Principal principal;

  principal.executar(); //chamada explícita ao executar, mas não é chamada no construtor

  return 0;
}
*/

//se executar retornar um int
int main() {
  exercicio::Principal principal;

  return principal.executar();
}