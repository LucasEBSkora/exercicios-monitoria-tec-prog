#include "Salvavel.hpp"

#include "../json/json.hpp"
#include <fstream>


namespace exercicio {
  bool Salvavel::salvar(const std::string& caminho) const {
    std::ofstream arquivo(caminho);
    if (arquivo.fail()) return false;
    arquivo << paraJSON();
    arquivo.close();
    return true;
  }
}