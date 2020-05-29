#ifndef _VETOR2D_H_
#define _VETOR2D_H_

namespace exercicio {

  template <typename T>
  class Vetor2D {
    public:
      T x, y;

      Vetor2D(T X = 0.0, T Y = 0.0);
      ~Vetor2D();
      Vetor2D operator +(Vetor2D v);
      Vetor2D operator -(Vetor2D v);
      Vetor2D operator *(int i);
      Vetor2D operator *(float f);
      Vetor2D operator *(double d);
      
      void operator +=(Vetor2D v);
      void operator -=(Vetor2D v);
      void operator *=(int i);
      void operator *=(float f);
      void operator *=(double d);
      
      T operator *(Vetor2D v);
      T modulo();
      Vetor2D versor();
      //projeção desse vetor na direção de v
      Vetor2D projOrtogonal(Vetor2D v);

  };

  typedef Vetor2D<float> Vetor2F;
  typedef Vetor2D<unsigned> Vetor2U;
  
}

  #include "Vetor2DImplementacao.hpp"


#endif