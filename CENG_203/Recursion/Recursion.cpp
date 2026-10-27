#include "Recursion.h"
#include <iostream>
#include <stdexcept> // std::invalid_argument
using namespace std;
// ============================ Q1 / Q2 ============================
void countdown(int n)
{
	cout << "Entering countdown(" << n << "), stack level " << n << endl;
	if (n <= 0) {
		cout << "Base case reached!" << endl;
		return; // base case: no further call
	}
	cout << n << " "; // work BEFORE the recursive call
	countdown(n - 1); // recursive call: one level deeper
	cout << "Exiting countdown(" << n << ")" << endl; // work AFTER
}
void buggyCountdown(int n)
{
	cout << n << " ";
	buggyCountdown(n - 1); // no base case: never stops
}
void fixedCountdown(int n)
{
	if (n <= 0) {
		return;
	}
	cout << n << " ";
	return fixedCountdown(n - 1);

}
// ============================ Q3 / Q4 ============================
void tailPrint(int n)
{
	if (n <= 0) {        //base case
		return;
	}
	cout << n << endl;    //work before call -> 3 2 1
	tailPrint(n - 1);
}
void nonTailPrint(int n)
{
	if (n <= 0) {       //base case
		return;
	}
	nonTailPrint(n - 1);      //recursive call
	cout << n << " ";         // work after -> 1 2 3
}
int tailSum(int n, int accumulator)
{
	if (n <= 0) return accumulator;
	tailSum(n - 1, accumulator + n);
}
int nonTailSum(int n)
{
	if (n <= 0) {
		return 0;
	}
	return n + nonTailSum(n - 1);

}
// ============================ Q5 ============================
long long factorial(int n)
{
	if (n < 0) {
		throw std::invalid_argument("factorial: n must no be negative");
	}
	if (n <= 1) {       //base case 0!=1!=1  :)
		return 1;
	}
	return n * factorial(n - 1);
}
long long factorialTail(int n, long long acc)
{
	if (n <= 1) {
		return acc;
	}
	factorialTail(n - 1, acc * n);

}
// ============================ Q6 ============================
double power(double base, int exponent, int& calls)
{
	calls++;
	if (exponent == 0) return 1.0;                          // base case
	if (exponent < 0) return 1.0 / power(base, -exponent, calls);
	return base * power(base, exponent - 1, calls);         // doğrusal: n çağrı
}

double fastPower(double base, int exponent, int& calls)
{
	calls++;
	if (exponent == 0) return 1;
	if (exponent < 0) return 1 / fastPower(base, -exponent, calls);
	double half = fastPower(base, exponent / 2, calls);
	if (exponent % 2 == 0) {
		return half * half;
	}
	return base * half * half;
}
// ============================ Q7 ============================
bool isEven(int n)
{
	if (n < 0) return isEven(-n);      // negative sayılar
	if (n == 0) return true;          // base case
	return isOdd(n - 1);
}
bool isOdd(int n)
{
	if (n < 0) return isOdd(-n);
	if (n == 0) return false;
	return isEven(n - 1);
}
// ============================ Q9 ============================
void parseExpression(const string& expr, int& index)
{
	cout << "Entering parseExpression at index " << index << endl;
	while (index < (int)expr.length() && expr[index] != ')') {
		if (isdigit(expr[index])) {
			parseOperand(expr, index);
		}
		else if (expr[index] == '+' || expr[index] == '*' ||
			expr[index] == '-') {
			cout << "Operator: " << expr[index] << endl;
			index++;
		}
		else if (expr[index] == '(') {
			parseOperand(expr, index); // indirect recursion
		}
		else {
			index++; // skip spaces etc.
		}
	}
	if (index < (int)expr.length() && expr[index] == ')') {
		cout << "Closing parenthesis at index " << index << endl;
		index++; // move past ')'
	}
	cout << "Exiting parseExpression at index " << index << endl;
}
void parseOperand(const string& expr, int& index)
{
	if (isdigit(expr[index])) {
		cout << "Operand: " << expr[index] << endl;
		index++;
	}
	else if (expr[index] == '(') {
		cout << "Opening parenthesis at index " << index << endl;
		index++; // skip '('
		parseExpression(expr, index); // indirect recursion
	}
}
// ============================ Q10 ============================
long long fib(int n, long long& calls)
{
	calls++; // keep this line
	return 0; // TODO: two recursive calls
}
long long fibIter(int n)
{
	return 0; // TODO: a loop, no recursion
}