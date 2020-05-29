#include "Colidivel.hpp"

namespace exercicio {

  Colidivel::Colidivel(Vetor2F pos /* = {0.0f, 0.0f}*/, Vetor2F vel/* = {0.0f, 0.0f}*/, IdsDesenhaveis::IdsDesenhaveis ID  /*= IdsDesenhaveis::semID*/, const char* caminhoTextura /* = nullptr*/) : 
    Desenhavel{pos, vel, ID, caminhoTextura} {

  }

}