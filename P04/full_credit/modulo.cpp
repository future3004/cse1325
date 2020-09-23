#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset): _modulo{modulo}, _value{value % modulo}, _offset{offset}, _nmsd{nullptr}{
  _value = (_value - _offset) % _modulo;
}

void Modulo::set_nmsd(Modulo* nmsd){_nmsd = nmsd;}
int Modulo::value(){ return _value + _offset; }

// input / output
std::ostream& operator<<(std::ostream& ost, const Modulo& m){
  ost << (m._value + m._offset);
  //ost << m._value;
  return ost;
}

std::istream& operator>>(std::istream& ist, Modulo& m){
  ist >> m._value;
  m._value = (m._value - m._offset) % m._modulo;
  return ist;
}

int Modulo::compare(const int rhs){
  int i = _value + _offset;
  if(i < rhs) return -1;
  else if(i > rhs) return 1;
  else return 0;
}

Modulo& Modulo::operator+=(const int rhs){
  int sum = _value + rhs;
  if((sum >= _modulo) && _nmsd){
    (*_nmsd) += (sum / _modulo);
  }
  _value = sum % _modulo;

  return *this;
}
Modulo Modulo::operator+(const int rhs){
 Modulo m{*this};
 m += rhs;
 return m;
}

Modulo& Modulo::operator++(){
  // pre-increment
  *this += 1;
  return *this;
}

Modulo Modulo::operator++(int ignored){ 
   // this is post increment, the parameter is ignored
   Modulo m{*this};
   ++*this;
   return m;
}
