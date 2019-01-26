#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long input)
{
	for (long long i = 2; i <= sqrt(input); ++i)
	{
		if (input % i == 0)
			return false;
	}

	return true;
}


vector<int> digitVector(int input)
{
	vector<int> v;

	while (input)
	{
		v.push_back(input % 10);
		input /= 10;
	}

	return v;
}

bool isPalindrome(int input)
{
	vector<int> v = digitVector(input);

	for (int i = 0; i < v.size()/2; ++i)
	{
		if (v[i] != v[v.size()-i-1])
			return false;
	}

	return true;
}


int problem1()
{
	int counter = 0;
	for (int i = 3; i < 1000; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			counter += i;
		}
	}

	return counter;
}

int problem2()
{
	int sum = 0, oldValue = 1, aux;

	for (int i = 2; i <= 4000000; )
	{
		if (i % 2 == 0)
		{
			sum += i;
		}

		aux = i;

		i += oldValue;
		oldValue = aux;

	}

	return sum;
}

long long problem3()
{
	long long max = 600851475143;
	vector<long long> lowerDivisors;

	for (long long i = 2; i <= sqrt(max); ++i)
	{
		if (max % i == 0)
		{
			lowerDivisors.push_back(i);
			long long num = max/i;

			if (isPrime(num))
				return num;
		}
	}

	for (int i = lowerDivisors.size()-1; i >= 0; --i)
	{
		if (isPrime(lowerDivisors[i]))
			return lowerDivisors[i];
	}

	return -1;
}

int problem4()
{
	int mult;
	int max = 0;

	for (int i = 999; i > 99; --i)
	{
		for (int j = i; j > 99; --j)
		{
			mult = i*j;

			if (mult > max && isPalindrome(mult))
				max = mult;
		}
	}

	return max;
}


int run(int (*probFunction)())
{
	cout << "Problem: " << probFunction() << "\n";
}



int main(int argc, char** argv)
{

	run(problem4);

	return 0;
}