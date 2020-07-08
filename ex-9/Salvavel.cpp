#include "Salvavel.hpp"

#include "../json/json.hpp"
#include <fstream>


namespace exercicio {

  Salvavel::~Salvavel() {

  }

  bool Salvavel::salvar(const std::string& caminho) {
    std::ofstream arquivo(caminho);
    if (arquivo.fail()) return false;
    arquivo << paraJSON();
    arquivo.close();
    return true;
  }
}