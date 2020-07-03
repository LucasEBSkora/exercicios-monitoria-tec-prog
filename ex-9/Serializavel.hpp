#ifndef _SERIALIZAVEL_HPP_
#define _SERIALIZAVEL_HPP_ 


#include "../json/json.hpp"

namespace exercicio {
  class Serializavel {
    public:
      virtual nlohmann::json paraJSON() =0 ;
  };
}

#endif