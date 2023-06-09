#include "Expression.h"

Variable::Variable(std::string name)
    : name_(name)
{
}

double Variable::eval(double x)
{
    return x;
}

std::string Variable::repr()
{
    return name_;
}

Literal::Literal(double value)
	: value_(value)
{
}

double Literal::eval(double x)
{
    return value_;
}

std::string Literal::repr()
{
    std::string val = std::to_string(value_);
    val.erase(val.find_last_not_of('0') + 1, std::string::npos);
    val.erase(val.find_last_not_of('.') + 1, std::string::npos);
    return val;
}

ScalingExpression::ScalingExpression(Expression* expr, Expression* scale)
	: expr_(expr), scale_(scale)
{
}

double ScalingExpression::eval(double x)
{
    return scale_->eval(x) * expr_->eval(x);
}

std::string ScalingExpression::repr()
{
    return scale_->repr() + expr_->repr();
}

BracketedExpression::BracketedExpression(Expression* expr)
    : expr_(expr)
{
}

double BracketedExpression::eval(double x)
{
    return expr_->eval(x);
}

std::string BracketedExpression::repr()
{
    return "(" + expr_->repr() + ")";
}

InvertExpression::InvertExpression(Expression* expr)
    : expr_(expr)
{
}

double InvertExpression::eval(double x)
{
    return -expr_->eval(x);
}

std::string InvertExpression::repr()
{
    return "-" + expr_->repr();
}

ExponentExpression::ExponentExpression(Expression* exponent, Expression* expr)
	: exponent_(exponent), expr_(expr)
{
}

double ExponentExpression::eval(double x)
{
    return std::pow(expr_->eval(x), exponent_->eval(x));
}

std::string ExponentExpression::repr()
{
    return expr_->repr() + "^" + exponent_->repr();
}

DivisionExpression::DivisionExpression(Expression* numerator, Expression* denominator)
    : numerator_(numerator), denominator_(denominator)
{
}

double DivisionExpression::eval(double x)
{
    return numerator_->eval(x) / denominator_->eval(x);
}

std::string DivisionExpression::repr()
{
    return numerator_->repr() + "/" + denominator_->repr();
}

MultiplicationExpression::MultiplicationExpression(Expression* left, Expression* right)
	: left_(left), right_(right)
{
}

double MultiplicationExpression::eval(double x)
{
    return left_->eval(x) * right_->eval(x);
}

std::string MultiplicationExpression::repr()
{
    return left_->repr() + "*" + right_->repr();
}

SubtractionExpression::SubtractionExpression(Expression* left, Expression* right)
	: left_(left), right_(right)
{
}

double SubtractionExpression::eval(double x)
{
    return left_->eval(x) - right_->eval(x);
}

std::string SubtractionExpression::repr()
{
    return left_->repr() + "-" + right_->repr();
}

AdditionExpression::AdditionExpression(Expression* left, Expression* right)
    : left_(left), right_(right)
{
}

double AdditionExpression::eval(double x)
{
    return left_->eval(x) + right_->eval(x);
}

std::string AdditionExpression::repr()
{
    return left_->repr() + "+" + right_->repr();
}
