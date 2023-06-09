#include <iostream>
#include <math.h>
#include <string>
#include "Expression.h"
#include "Parser.h"


double evalPolynomial(std::string str, double x)
{
	Expression* expr = Parser(str).parse();
	std::cout << expr->repr() << std::endl;
	double result = expr->eval(x);
	delete expr;
	return result;
}

int main()
{
	//std::cout << evalPolynomial("8*x-3*x^2+14+2*x^5", 2) << std::endl;
	//std::cout << evalPolynomial("(2x+(-5x+2x^2)-8x^3)*5x-3", 2) << std::endl;
	//std::cout << evalPolynomial("14150108((-((2x+3(-5x+2x^2)-8x^3)*5x-6))/666)", 2);
	std::cout << evalPolynomial("x^x^x^2", 2) << std::endl;
}