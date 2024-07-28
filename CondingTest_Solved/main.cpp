#define PROB 6

#if PROB == 1
// [10828] 스택
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
// [10773] 제로
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
// [1874] 스택 수열
#include <iostream>
#include <stack>
using namespace std;

// 1부터 N까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써 하나의 수열을 만들 수 있다.
int main()
{
	// 입력 개수
	int input{};
	cin >> input;

	string result_operator{};
	stack<int> result_stack{};
	int pos_value{ 1 };
	while (input--)
	{
		int input_number;
		cin >> input_number;

		while (pos_value <= input_number)
		{
			result_stack.push(pos_value++);
			result_operator += "+\n";
		}

		// 출력 결과 비교
		if (result_stack.top() != input_number)
		{
			cout << "NO" << endl;
			return 0;
		}

		result_stack.pop();
		result_operator += "-\n";
	}

	cout << result_operator;
}
#elif PROB == 4
// [10845] 큐
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int input{};
	cin >> input;

	queue<int> queue{};
	for (int i = 0; i < input; ++i)
	{
		string input_command{};
		cin >> input_command;
		if (input_command == "push")
		{
			int input_value{};
			cin >> input_value;
			queue.push(input_value);
		}
		else if (input_command == "pop")
		{
			if (queue.empty())
				cout << -1 << "\n";
			else
			{
				cout << queue.front() << "\n";
				queue.pop();
			}
		}
		else if (input_command == "size")
		{
			cout << queue.size() << "\n";
		}
		else if (input_command == "empty")
		{
			cout << queue.empty() << "\n";
		}
		else if (input_command == "front")
		{
			if (queue.empty())
				cout << -1 << "\n";
			else
			{
				cout << queue.front() << "\n";
			}
		}
		else if (input_command == "back")
		{
			if (queue.empty())
				cout << -1 << "\n";
			else
			{
				cout << queue.back() << "\n";
			}
		}

	}

	return 0;
}
#elif PROB == 5
// [2164] 카드2
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int input{};
	cin >> input;

	queue<int> queue;

	// 1. 입력 조건 세팅
	for (int i = 1; i <= input; ++i)
		queue.push(i);

	// 2. 로직 수행
	while (queue.size() > 1)
	{
		queue.pop();

		int save_value = queue.front();
		queue.push(save_value);

		queue.pop();
	}

	// 3. 결과 값 출력
	cout << queue.front();
}
#elif PROB == 6

#endif