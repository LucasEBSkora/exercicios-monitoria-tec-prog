#include <cmath>

namespace exercicio {

     
  template <typename T>
  Vetor2D<T>::Vetor2D(T X /*= 0.0*/, T Y /*= 0.0*/) : x{X}, y{Y} {

  }

  template <typename T>
  Vetor2D<T>::Vetor2D(nlohmann::json j) : x{static_cast<T>j["x"]}, y{static_cast<T>j["x"]} {
    
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
  void Vetor2D<T>::operator -=(Vetor2D<T> v) {
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
  nlohmann::json Vetor2D<T>::paraJSON() {
    return {"x" : x, "y", y};
  }

  template <typename T>
  std::ostream& operator <<(std::ostream& out, const Vetor2D<T>& v) {
    out << '(' << v.x << " , " << v.y << ')';
    return out;
  }

}