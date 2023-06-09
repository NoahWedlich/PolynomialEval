#include "Parser.h"

Parser::Parser(std::string str)
    : str_(str), current_(0)
{
}

Expression* Parser::parse()
{
    return parse_addition();
}

bool Parser::at_end()
{
    return current_ == str_.size();
}

Expression* Parser::parse_addition()
{
    Expression* left = parse_subtraction();
    if (peek() != '+')
    { return left; }
    consume();
    Expression* right = parse_addition();
    return new AdditionExpression(left, right);
}

Expression* Parser::parse_subtraction()
{
    Expression* left = parse_multiplication();
    if (peek() != '-')
	{ return left; }
    consume();
	Expression* right = parse_subtraction();
	return new SubtractionExpression(left, right);
}

Expression* Parser::parse_multiplication()
{
    Expression* left = parse_division();
    if (peek() != '*')
	{ return left; }
    consume();
	Expression* right = parse_multiplication();
	return new MultiplicationExpression(left, right);
}

Expression* Parser::parse_division()
{
    Expression* left = parse_exponent();
    if (peek() != '/')
    { return left; }
    consume();
    Expression* right = parse_division();
    return new DivisionExpression(left, right);
}

Expression* Parser::parse_exponent()
{
    Expression* base = parse_scaling();
    if (peek() != '^')
	{ return base; }
    consume();
    Expression* exp = parse_exponent();
    return new ExponentExpression(exp, base);
}

Expression* Parser::parse_scaling()
{
    bool invert = false;
    if (peek() == '-')
    {
        consume();
        invert = true;
    }
    Expression* scale = parse_bracketed();
    if (invert)
    { scale = new InvertExpression(scale); }
    //TODO: Named variables
    if (peek() != 'x' && peek() != '(')
    { return scale; }
    Expression* expr = parse_exponent();
    return new ScalingExpression(expr, scale);
}

Expression* Parser::parse_bracketed()
{
    if (peek() != '(')
	{ return parse_literal(); }
    consume();
	Expression* expr = parse_addition();
	if (peek() != ')')
	{ throw std::exception("Expected ')'"); }
	consume();
	return new BracketedExpression(expr);
}

Expression* Parser::parse_literal()
{
    std::string num = "";
    while (!at_end() && (peek() >= '0' && peek() <= '9'))
    { num += consume(); }
    if (peek() == '.')
    {
		num += consume();
		while (!at_end() && (peek() >= '0' && peek() <= '9'))
		{ num += consume(); }
	}
    if (num == "")
    { return parse_variable(); }
    return new Literal(std::stof(num));
}

Expression* Parser::parse_variable()
{
    //TODO: Named variables
    if (peek() != 'x')
	{ throw std::exception("Expected Expression"); }
    consume();
	return new Variable("x");
}

char Parser::peek()
{
    return str_[current_];
}

char Parser::consume()
{
    return str_[current_++];
}
