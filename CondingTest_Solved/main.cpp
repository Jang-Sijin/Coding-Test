#define PROB 1

#if PROB == 1
// [1000] A+B
#include <iostream>
using namespace std;

int main()
{
	int input[2];
	cin >> input[0] >> input[1];

	cout << input[0] + input[1];
}
#endif