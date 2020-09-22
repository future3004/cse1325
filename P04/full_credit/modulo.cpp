#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset): _modulo{modulo}, _value{value}, _offset{offset}{}
Modulo::Modulo(): Modulo(10, 0, 0){}
Modulo::Modulo(int modulo, int value): _modulo{modulo}, _value{value}, _offset{0}{}
Modulo::Modulo(int modulo):_modulo{modulo}, _value{0}, _offset{0}{}


void Modulo::set_nmsd(Modulo* nmsd){_nmsd = nmsd;}
int Modulo::value(){ return _value; }

std::ostream& operator<<(std::ostream& ost, const Modulo& m){
  //ost << m._value + m._offset;
  ost << m._value;
  return ost;
}

std::ostream& operator>>(std::ostream& ost, Modulo& m){
  ost >> m;
  //m._value = (m._value - m._offset) % m._modulo;
  return ost;
}

int Modulo::compare(const int rhs){
  if(_modulo < rhs) return -1;
  if(_modulo > rhs) return 1;
  return 0;
}

Modulo& Modulo::operator+=(int rhs){
  this->_value = this->_value + rhs;
  if(this->_value > 60){
    int left = this->_value - 60;
    this->_value = left;
    //this->_nmsd->_value = this->_nmsd->_value + 1;
}
 //if(this->_nmsd->_value = 13){ this->_nmsd->_value = 1; }

  return *this;
}
Modulo Modulo::operator+(int rhs){
 Modulo m{*this};
m._value = m._value + rhs;
  if(m._value > 60){
    int left = m._value - 60;
    //_nmsd->_value = _nmsd->_value + 1;
    m._value = left;
}
 return m;
}

Modulo& Modulo::operator++(){
  // pre-increment
   this->_value = this->_value + 1;
  if(this->_value > 60){
    int left = this->_value - 60;
    //_nmsd->_value = _nmsd->_value + 1;
    this->_value = left;
}
  return *this;
}

Modulo Modulo::operator++(int ignored){ 
   // this is post increment, the parameter is ignored
   Modulo m{*this};
   ++*this;
    this->_value = this->_value + 1;
  if(this->_value > 60){
    int left = this->_value - 60;
    //_nmsd->_value = _nmsd->_value + 1;
    this->_value = left;
}
   return m;
}
