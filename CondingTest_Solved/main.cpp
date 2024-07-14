#define PROB 2

#if PROB == 1
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	stack<int> stack{};	

	int inputSize{};
	cin >> inputSize;

	for (int i = 0; i < inputSize; ++i)
	{
		string input;
		cin >> input;

		if (input == "push")
		{
			int value{};
			cin >> value;
			
			stack.push(value);
		}
		else if (input == "pop")
		{
			bool isEmpty = stack.empty();

			if (isEmpty)
			{
				cout << -1 << endl;
			}
			else
			{				
				cout << stack.top() << endl;
				stack.pop();
			}
		}		
		else if (input == "size")
		{
			cout << stack.size() << endl;
		}
		else if (input == "empty")
		{
			bool isEmpty = stack.empty();

			if (isEmpty)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (input == "top")
		{
			bool isEmpty = stack.empty();

			if (isEmpty)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << stack.top() << endl;
			}			
		}
	}

	return 0;
}
#elif PROB == 2
// [10773] Á¦·Î

#endif