#ifndef _COR_HPP_
#define _COR_HPP_

namespace exercicio {
  class Cor {
    public:
      
      unsigned char r;
      unsigned char g;
      unsigned char b;
      unsigned char a;

      Cor(unsigned char R = 0, unsigned char G = 0, unsigned char B = 0, unsigned char A = 255);
  };
}

#endif