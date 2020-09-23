#ifndef _MODULO_H
#define _MODULO_H
#include <iostream>
#include <string>

class Modulo{
 public:
  Modulo(int modulo = 10, int value = 0, int offset = 0);
  void set_nmsd(Modulo* nmsd);
  int value();
  Modulo& operator+=(const int rhs);
  Modulo operator+(const int rhs);
  Modulo& operator++();   // pre-increment
  Modulo operator++(int ignored);    // Post-increment
  inline bool operator==(const int rhs) {return (compare(rhs) == 0); }
  inline bool operator!=(const int rhs) {return (compare(rhs) != 0); }
  inline bool operator<(const int rhs) {return (compare(rhs) < 0); }
  inline bool operator<=(const int rhs) {return (compare(rhs) <= 0); }
  inline bool operator>(const int rhs) {return (compare(rhs) > 0); }
  inline bool operator>=(const int rhs) {return (compare(rhs) >= 0); }
  friend std::ostream& operator<<(std::ostream& ost, const Modulo& m);
  friend std::istream& operator>>(std::istream& ist, Modulo& m);
 private:
  int _value;
  int _modulo;
  int _offset;
  Modulo* _nmsd;
  int compare(const int rhs);
 
};

#endif

