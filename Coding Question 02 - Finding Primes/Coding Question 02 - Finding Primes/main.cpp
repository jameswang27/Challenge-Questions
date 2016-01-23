//Intuit Coding Question 02

/*
Find the 3rd, 58th and 10,001th prime number.
*/

/*
We will try to solve this problem quickly by taking advantage of some properties of prime numbers.
Note that the answers that the algorithm produces should be, according to Wolfram Alpha:
	-3rd: 5
	-58th: 271
	-10,001th: 104743

Important Observations:
All composite numbers can be prime factorized into prime numbers
Once we test 2 agains the prime, we no longer need to test other even numbers
If n is the number we're checking, we can check up to the floor of the square root of n. This is because it's divisor pair would have appeared
earlier if a number larger than this max is a divisor.
*/

#include <assert.h>	//For test cases
#include <iostream> //For cout
#include <math.h>	//For sqrt and floor
#include <vector>

using namespace std;

bool isPrime(int num, vector<long>& primes);

int main()
{
	vector<long> data;
	assert(!isPrime(1, data));
	assert(!isPrime(4, data));
	assert(isPrime(2, data));
	assert(isPrime(37, data));
	data.clear();
	
	int count = 1;
	while(data.size() <= 10001) //Have this second number be the prime that you want to find.
	{
		isPrime(count, data);
		count++;
	}

	for (size_t i = 0; i < data.size(); i++)
	{
		cout << data[i] << '\t';
		if (i % 5 == 4) cout << endl;
	}

	cout << endl;
	cout << "Finished" << endl;
}

/*
Purpose: Find if a number is prime.
Functionality: 
Parameters:
	-int num: integer to be checked
Return value: a boolean that indicates if the integer checked was a prime or not.
*/

bool isPrime(int num, vector<long>& primes)
{
	if (num == 1) return false;		//1 is not a prime number
	if (num == 2)					//2 is the only even prime number
	{
		primes.push_back(num);
		return true;
	}
	if (num % 2 == 0) return false;	//If the number is divisible by 2 we can immediately return false, 2 is the only prime even number
	int last = floor(sqrt(num));	//This is the last int we need to check as a divisor. It should contain the floor of the sqrt of num.

	//Begin at 3 because we definitely don't need to check 1, and we've already checked 2
	//Because we checked 2, we no longer need to check potential even divisors because those would in turn be divisible by 2
	for (size_t i = 0; i < primes.size(); i++)
	{
		//if (primes[i] > last) return false;
		if (num % primes[i] == 0) return false;
	}
	primes.push_back(num);
	return true;	//If it makes it this far, then there was no proper divisor and the number is indeed prime
}

