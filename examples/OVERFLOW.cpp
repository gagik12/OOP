#include <iostream>

enum MathErr
{
	ME_OVERFLOW_ADD,
	ME_OVERFLOW_MULTIPLICATION,
	ME_UNDERFLOW_ADD,
	ME_UNDERFLOW_MULTIPLICATION
};


int Add(int multiplication, int number)
{
	if ((multiplication > 0) &&  (multiplication > INT_MAX - number))
	{
		throw ME_OVERFLOW_ADD;
	}
	if((multiplication < 0) && (multiplication < INT_MIN - number))
	{
		throw ME_UNDERFLOW_ADD;
	}
	return multiplication + number;
}

int Multiplication(int pow, int digit)
{
	if ((pow >= 0) && (digit >= 0) && (pow > INT_MAX / digit))
	{
		throw ME_OVERFLOW_MULTIPLICATION;
	}
	if (pow < INT_MAX / digit)
	{
		throw ME_UNDERFLOW_MULTIPLICATION;
	}
	return digit * pow;
}


void PrintMathErr(MathErr& mathErr)
{
	switch (mathErr)
	{
	case 0:
		std::cout << "ME_OVERFLOW_ADD\n";
		break;
	case 1:
		std::cout << "ME_OVERFLOW_MULTIPLICATION\n";
		break;
	case 2:
		std::cout << "ME_UNDERFLOW_ADD\n";
		break;
	case 3:
		std::cout << "ME_UNDERFLOW_MULTIPLICATION\n";
		break;
	}
}

int main()
{
	int  multiplication;
	int  sum;
	try 
	{
		multiplication = Multiplication(INT_MAX, 1);
		std::cout << "Multiplication = " << multiplication << std::endl;
		sum = Add(multiplication, 0);
		std::cout << "Add = " << sum << std::endl;
	}

	catch (MathErr& mathErr)
	{
		PrintMathErr(mathErr);
		return 1;
	}
	//std::cout << sum << std::endl;
	return 0;
}