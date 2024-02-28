#ifndef ITF_PRINTER_HPP_
#define ITF_PRINTER_HPP_

#include <string>
#include <cstdint>

class ItfPrinter {
 public:
  virtual ~ItfPrinter();
  virtual void PrintHello() = 0;
};

#endif