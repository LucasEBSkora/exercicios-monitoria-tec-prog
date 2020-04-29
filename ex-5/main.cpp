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

#include <iostream>

#include <fstream>
#include "../json/single_include/nlohmann/json.hpp"

//se executar() retornar um int
int main() {

  nlohmann::json arquivo;

  std::ifstream arq("../assets/derp.json");

  arq >> arquivo;

  std::cout << arquivo << std::endl;

  // exercicio::Principal principal;

  // return principal.executar();
}