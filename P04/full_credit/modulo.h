#ifndef _MODULO_H
#define _MODULO_H
#include <iostream>
#include <string>

class Modulo{
 public:
  Modulo(int modulo, int value, int offset);
  Modulo();
  Modulo(int modulo, int value);
  Modulo(int modulo);
  void set_nmsd(Modulo* nmsd);
  int value();
  Modulo& operator+=(int rhs);
  Modulo operator+(int rhs);
  Modulo& operator++();   // pre-increment
  Modulo operator++(int ignored);    // Post-increment
  inline bool operator==(int rhs) {return (compare(rhs) == 0); }
  inline bool operator!=(int rhs) {return (compare(rhs) != 0); }
  inline bool operator<(int rhs) {return (compare(rhs) < 0); }
  inline bool operator<=(int rhs) {return (compare(rhs) <= 0); }
  inline bool operator>(int rhs) {return (compare(rhs) > 0); }
  inline bool operator>=(int rhs) {return (compare(rhs) >= 0); }
  friend std::ostream& operator<<(std::ostream& ost, const Modulo& m);
  friend std::ostream& operator>>(std::ostream& ost, Modulo& m);
 private:
  int _value;
  int _modulo;
  int _offset;
  Modulo* _nmsd;
  int compare(const int rhs);
 
};

#endif

