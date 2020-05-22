#include <cmath>

namespace exercicio {

     
  template <typename T>
  Vetor2D<T>::Vetor2D(T X, T Y) : x{X}, y{Y} {

  }

  template <typename T>
  Vetor2D<T>::~Vetor2D() {

  }

  
  template <typename T>
  Vetor2D<T> Vetor2D<T>::operator +(Vetor2D<T> v) const {

    return Vetor2D<T>(x + v.x, y + v.y);
  }

  template <typename T>
  Vetor2D<T> Vetor2D<T>::operator -(Vetor2D<T> v) const {
    return Vetor2D<T>(x - v.x, y - v.y);
  }

  template <typename T>
  Vetor2D<T> Vetor2D<T>::operator *(int i) const {
    
    return Vetor2D<T>(x*i, y*i);

  }
  
  template <typename T>
  Vetor2D<T> Vetor2D<T>::operator *(float f) const {

    return Vetor2D(x*f, y*f);

  }

  template <typename T>
  Vetor2D<T> Vetor2D<T>::operator *(double d) const {
    
    return Vetor2D<T>(x*d, y*d);  
  }

  template <typename T>
  void Vetor2D<T>::operator +=(Vetor2D<T> v) {
    x += v.x;
    y += v.y;
  }

  
  template <typename T>
  void Vetor2D<T>::operator -=(Vetor2D v) {
    x -= v.x;
    y -= v.y;
  }

  template <typename T>
  void Vetor2D<T>::operator *=(int i) {
    x *= i;
    y *= i;
  }

  template <typename T>
  void Vetor2D<T>::operator *=(float f) {
    x *= f;
    y *= f;
  }

  template <typename T>
  void Vetor2D<T>::operator *=(double d) {
    x *= d;
    y *= d;
  }

  template <typename T>
  float Vetor2D<T>::operator *(Vetor2D<T> v) const {
    return x*v.x + y*v.y;
  }

  template <typename T>
  T Vetor2D<T>::modulo()  const {
    return sqrt(pow(x, 2) + pow(y,2));
  }
  
  template <typename T>
  Vetor2D<T> Vetor2D<T>::versor() const {
    return this->operator *(1.0/modulo());
  }

  //projeção desse vetor na direção de v
  template <typename T>
  Vetor2D<T> Vetor2D<T>::projOrtogonal(Vetor2D<T> v) const {
    return v*(this->operator*(v)/ pow(v.modulo(), 2));
  }


  template <typename T>
  std::ostream& operator <<(std::ostream& out, const Vetor2D<T>& v) {
    out << '(' << v.x << " , " << v.y << ')';
    return out;
  }

}