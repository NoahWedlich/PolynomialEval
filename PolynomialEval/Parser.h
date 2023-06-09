#pragma once
#include "Expression.h"

class Parser
{
public:
	Parser(std::string str);

	Expression* parse();
private:
	bool at_end();

	Expression* parse_addition();
	Expression* parse_subtraction();
	Expression* parse_multiplication();
	Expression* parse_division();
	Expression* parse_exponent();
	Expression* parse_scaling();
	Expression* parse_bracketed();
	Expression* parse_literal();
	Expression* parse_variable();

	char peek();
	char consume();

	std::string str_;
	int current_;
};