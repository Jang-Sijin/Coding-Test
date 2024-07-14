#define PROB 3

#if PROB == 1
// [10828] ����
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
// [10773] ����
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> result_stack{};

	int input{};
	cin >> input;

	while (input--)
	{
		int value{};
		cin >> value;

		if (value == 0)
		{
			result_stack.pop();
		}
		else
		{			
			result_stack.push(value);
		}
	}

	int result{};
	while (!result_stack.empty())
	{		
		result += result_stack.top();
		result_stack.pop();
	}	

	cout << result << endl;

	return 0;
}
#elif PROB == 3
// [1874] ���� ����
#include <iostream>
#include <stack>
using namespace std;

// 1���� N������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν� �ϳ��� ������ ���� �� �ִ�.

int main()
{


	return 0;
}
#endif