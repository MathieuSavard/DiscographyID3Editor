#ifndef MATH_PRINTER_HPP_
#define MATH_PRINTER_HPP_

#include "itf_printer.hpp"

class MathPrinter : public ItfPrinter {
private:
  MathPrinter();

public:
  void PrintHello() override;
};

#endif