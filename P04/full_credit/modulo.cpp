#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset): _modulo{modulo}, _value{value}, _offset{offset}{}
Modulo::Modulo(): Modulo(10, 0, 0){}
Modulo::Modulo(int modulo, int value): _modulo{modulo}, _value{value}, _offset{0}{}



void Modulo::set_nmsd(Modulo* nmsd){_nmsd = nmsd;}
int Modulo::value(){ return _value; }

std::ostream& operator<<(std::ostream& ost, Modulo& m){
  ost << m._value;
  return ost;
}

std::ostream& operator>>(std::ostream& ost, Modulo& m){
  ost >> m;
  return ost;
}

int Modulo::compare(const int rhs){
  if(_modulo < rhs) return -1;
  if(_modulo > rhs) return 1;
  if(_value < rhs) return -1;
  if(_value > rhs) return 1;
  if(_offset < rhs) return -1;
  if(_offset > rhs) return 1;
  return 0;
}

Modulo& Modulo::operator+=(int rhs){

  return *this;
}
Modulo Modulo::operator+(int rhs){
 Modulo m{*this};
 return m;
}

Modulo& Modulo::operator++(){
  // pre-increment
  return *this;
}

Modulo Modulo::operator++(int ignored){ 
   // this is post increment, the parameter is ignored
   Modulo m{*this};
   ++*this;
   return m;
}
