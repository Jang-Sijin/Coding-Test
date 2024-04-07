#define PROB 3

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

#elif PROB == 3
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{

	time_t timer{ time(NULL) };
	struct tm date{};
	localtime_s(&date, &timer);

	cout << date.tm_year + 1900 << "-" << setw(2) << setfill('0') << date.tm_mon + 1 << "-" << setw(2) << setfill('0') << date.tm_mday;

	return 0;
}

#endif