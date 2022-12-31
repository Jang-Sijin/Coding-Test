#define PROB 2

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
#elif PROB == 2
#include <iostream>
using namespace std;

int main()
{
	int input[2];
	cin >> input[0] >> input[1];

	cout << input[0] + input[1];

	return 0;
}
#endif