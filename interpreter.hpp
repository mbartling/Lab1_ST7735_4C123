#ifndef __INTERPRETER_HPP__
#define __INTERPRETER_HPP__

#include "ST7735.h"
#include <stdio.h>

class Interpreter{
private:

public:
  Interpreter(){
		printf("I have created life!\n");
  }
  
	void print(void) { printf("I am in the interpreter\n"); }
};

#endif /*__INTERPRETER_HPP__ */
