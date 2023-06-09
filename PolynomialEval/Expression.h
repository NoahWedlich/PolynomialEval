#pragma once
#include <string>
#include <cmath>

class Expression
{
public:
	virtual double eval(double x) = 0;
	virtual std::string repr() = 0;
};

class Variable : public Expression
{
public:
	Variable(std::string name);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	std::string name_;
};;

class Literal : public Expression
{
public:
	Literal(double value);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	double value_;
};

class ScalingExpression : public Expression
{
public:
	ScalingExpression(Expression* expr, Expression* scale);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* scale_;
	Expression* expr_;
};

class BracketedExpression : public Expression
{
public:
	BracketedExpression(Expression* expr);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* expr_;
};

class InvertExpression : public Expression
{
public:
	InvertExpression(Expression* expr);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* expr_;
};

class ExponentExpression : public Expression
{
public:
	ExponentExpression(Expression* exponent, Expression* expr);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* exponent_;
	Expression* expr_;
};

class DivisionExpression : public Expression
{
public:
	DivisionExpression(Expression* numerator, Expression* denominator);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* numerator_;
	Expression* denominator_;
};

class MultiplicationExpression : public Expression
{
public:
	MultiplicationExpression(Expression* left, Expression* right);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* left_;
	Expression* right_;
};

class SubtractionExpression : public Expression
{
public:
	SubtractionExpression(Expression* left, Expression* right);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* left_;
	Expression* right_;
};

class AdditionExpression : public Expression
{
public:
	AdditionExpression(Expression* left, Expression* right);

	virtual double eval(double x) override;
	virtual std::string repr() override;
private:
	Expression* left_;
	Expression* right_;
};