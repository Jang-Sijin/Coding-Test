#define PROB 4
#if PROB == 1
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

char input[100000];
int main()
{
	cin >> input;

	map<char, int> m;
	for (int i = 0; i < 100000; ++i)
	{
		if (i % 3 == 0)
		{
			m[input[i]] += 1;
			cout << input[i] << " " << m[input[i]] << endl;
		}
		else if (input[i] == 0)
			break;
		else
			continue;
	}

	int maxWins = 0;
	int winner = 0;
	for (auto const& pair : m)
	{
		if (pair.second > maxWins)
		{
			maxWins = pair.second;
			winner = pair.first;
		}
	}

	cout << winner << endl;

	return 0;
}
#elif PROB == 2
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	string commands;
	cin >> commands;

	// 접근 금지된 좌표를 저장할 set
	set<pair<int, int>> forbidden;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		forbidden.insert({ x, y });
	}

	int x = 0, y = 0; // 로봇의 초기 위치
	set<pair<int, int>> visited; // 방문한 좌표를 저장할 set

	// 로봇의 이동
	for (char c : commands)
	{
		int newX = x, newY = y;
		if (c == 'E')
		{
			newX++;
		}
		else if (c == 'W')
		{
			newX--;
		}
		else if (c == 'S')
		{
			newY--;
		}
		else if (c == 'N')
		{
			newY++;
		}

		// 이동한 좌표가 접근 금지된 좌표인지 확인
		if (forbidden.find({ newX, newY }) == forbidden.end())
		{
			visited.insert({ newX, newY });
			x = newX;
			y = newY;
		}
	}

	cout << visited.size() + 1 << endl;

	return 0;
}
#elif PROB == 4
//[4949] 균형잡힌 세상
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsBalanced(const string& input)
{
	stack<char> result_stack;

	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] == '(' || input[i] == '[')
		{
			result_stack.push(input[i]);
		}
		else if (input[i] == ')')
		{
			if (!result_stack.empty() && result_stack.top() == '(')
				result_stack.pop();
			else
				return false;
		}
		else if (input[i] == ']')
		{
			if (!result_stack.empty() && result_stack.top() == '[')
				result_stack.pop();
			else
				return false;
		}
		else if (input[i] == '.')
		{
			if (result_stack.empty())
				return true;
			else
				return false;
		}
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		string line;

		getline(cin, line);
		if (line == ".")
			break;

		stack<char> result_stack{};
		if (IsBalanced(line))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}

	return 0;
}

#endif