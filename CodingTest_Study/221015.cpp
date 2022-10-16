#define PROB 3

#if PROB == 1
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(string source)
{
	string answer = "";

	// 중복 알파벳 1개씩 제거
	while (!source.empty())
	{
		unordered_map <char, int> alphabet_count{};
		string sort_str{};

		for (int i = 0; i < source.size();)
		{
			if (alphabet_count[source[i]] == 0)
			{
				alphabet_count[source[i]] += 1;
				sort_str += source[i];

				source.erase(i, 1);
			}
			else
				++i;
		}
		sort(sort_str.begin(), sort_str.end());

		answer += sort_str;
	}

	return answer;
}

int main()
{
	solution("execute"); // result: "cetuxee" ee excut cetux
	solution("cucumber"); // result: "bcemrucu"
	solution("bbaabd"); // result: "abdabb"
	return 0;
}
#elif PROB == 2
#include <string>
#include <vector>

using namespace std;

// 피아노 건반 최소 이동

int solution(vector<int> music) 
{
	int answer = 0;



	return answer;
}

int main()
{
	solution({ 10, 9, 4, 5, 12 }); // result: 15
	solution({ 6, 4, 2, 11 }); // result: 13

	return 0;
}
#elif PROB == 3
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 최단거리 - 다익스트라

int solution(vector<int> paper, int n) 
{
	int answer{};

	int visited = 1;

	vector<int> up{ 2,4,6,9,11 };
	vector<int> down{ 1,3,5,7,8,10,12 };

	for (int i = 0; i < paper.size(); ++i)
	{
		for (int j = 0; j < up.size(); ++j)
		{
			for (int k = 0; k < down.size(); ++k)
			{

			}

			visited = j;
		}
		
		for (int j = 0; j < down.size(); ++j)
		{

		}
	}


	return answer;
}

int main()
{
	solution({ 7, 3, 5, -2, 9 }, 2); // 19
	solution({ 10, -10 }, 1); // 10
	return 0;
}
#endif