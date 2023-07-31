#define PROB 15

#if PROB == 1
// [중복 제거하기]
SELECT COUNT(DISTINCT NAME) AS count
FROM ANIMAL_INS
WHERE NAME IS NOT NULL

#elif PROB == 2
// [동물 수 구하기]
SELECT count(*) as count
FROM ANIMAL_INS

#elif PROB == 3
// [최솟값 구하기]
SELECT DATETIME as "시간"
FROM ANIMAL_INS
ORDER BY DATETIME ASC
LIMIT 1

#elif PROB == 4
// [최댓값과 최솟값]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetSplit(string input, string delimiter)
{
	vector<int> result;
	int index = 0;
	while ((index = input.find(delimiter)) != string::npos)
	{
		string token = input.substr(0, index);
		result.push_back(stoi(token));
		input.erase(0, index + delimiter.length());
	}
	result.push_back(stoi(input));

	return result;
}

string solution(string s)
{
	string answer{ "" };
	string delimiter{ " " };

	vector<int> result = GetSplit(s, delimiter);
	sort(result.begin(), result.end());

	answer = to_string(result.front()) + delimiter + to_string(result.back());	
	return answer;
}

int main()
{
	solution("1 2 3 4"); // result: "1 4"
	solution("-1 -2 -3 -4"); // result: "-4 -1"
	solution("-1 -1"); // result: "-1 -1"

	return 0;
}

#elif PROB == 5
// [JadenCase 문자열 만들기]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) 
{
	string answer = "";

	transform(s.begin(), s.end(), s.begin(), ::tolower);

	if (isalpha(s[0]))
		s[0] = toupper(s[0]);

	for (int i = 0; i < s.length(); ++i)
	{
		if ((s[i] == ' ') && isalpha(s[i + 1]))
			s[i + 1] = toupper(s[i + 1]);
	}	

	return answer = s;
}

int main()
{
	solution("3people  unFollowed me"); // result: "3people Unfollowed Me"
	solution("for the last week"); // result: "For The Last Week"

	return 0;
}

#elif PROB == 6
// [이름에 el이 들어가는 동물 찾기]
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE NAME LIKE CONCAT('%EL%') AND ANIMAL_TYPE LIKE 'Dog'
ORDER BY NAME ASC

#elif PROB == 7
// [최솟값 만들기]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < A.size(); ++i)
	{
		answer += (A[i] * B[i]);
	}

	cout << answer << "\n";
	return answer;
}

int main()
{
	solution({ 1, 4, 2 }, { 5, 4, 4 }); // result: 29
	solution({ 1, 2 }, { 3, 4 }); // result: 10

	return 0;
}
#elif PROB == 8
// [올바른 괄호]
#include <iostream>
#include <string>

using namespace std;

bool solution(string s) 
{
	bool answer{ true };
	int s_count{ 0 };

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			++s_count;
		else if (s[i] == ')')
			--s_count;

		if (s_count < 0)
		{
			break;
		}		
	}
	
	return (s_count == 0) ? answer = true : answer = false;
}

int main()
{
	solution("()()"); // true
	solution("(())()"); // true
	solution(")()("); // false
	solution("(()("); // false

	return 0;
}
#elif PROB == 9
// [이진 변환 반복하기]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

#define MAX_BIT_SIZE 150000

using namespace std;

vector<int> solution(string s) 
{
	vector<int> answer;

	int turn{ 0 };
	int sum_earase_zero_count{ 0 };

	while (true)
	{
		++turn;
		
		s.erase(remove_if(s.begin(), s.end(), [&sum_earase_zero_count](char ch)
			{
				if (ch == '0')
				{
					sum_earase_zero_count++;
					return true;
				}
				else
					return false;
			}), s.end());

		auto s_value{ s.length() };
		int bit_size{ 0 };

		while (s_value != 0)
		{
			++bit_size;
			s_value >>= 1;
		}

		s = bitset<MAX_BIT_SIZE>(s.size()).to_string().substr(MAX_BIT_SIZE - bit_size);
	
		if (s == "1")
			break;
	}

	answer.push_back(turn);
	answer.push_back(sum_earase_zero_count);

	return answer;
}

int main()
{
	solution("110010101001"); // [3,8]
	solution("01110"); // [3,3]
	solution("1111111"); // [4,1]

	return 0;
}
#elif PROB == 10
// [숫자의 표현]
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) 
{
	int answer{ 0 };
	int loop_value{ 1 };

	while (loop_value <= n)
	{
		int sum{ 0 };
		for (int i = loop_value; i <= n; ++i)
		{
			sum += i;

			if (sum == n)
			{							
				++answer;				
				break;
			}
			else if (sum > n)
			{				
				break;
			}
		}
		++loop_value;
	}

	return answer;
}

int main()
{
	solution(15); // result: 4

	return 0;
}
#elif PROB == 11
// [다음 큰 숫자]
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

#define MAX_VALUE_SIZE 32

using namespace std;

int solution(int n) 
{
	int answer = n + 1;

	auto n_string = bitset<MAX_VALUE_SIZE>(n).to_string();
	auto count_n = count(n_string.begin(), n_string.end(), '1');

	while (true)
	{
		auto answer_string = bitset<MAX_VALUE_SIZE>(answer).to_string();
		auto count_answer = count(answer_string.begin(), answer_string.end(), '1');
		//cout << "n_string: " << n_string << "answer_string: " << answer_string << endl;
		//cout << "count_n: " << count_n << "count_answer: " << count_answer << endl;

		if (count_n == count_answer)
		{
			break;
		}
		else
			answer += 1;
	}
	cout << answer << endl;

	return answer;
}

int main()
{
	solution(78); // result: 83
	solution(15); // result: 23

	return 0;
}
#elif PROB == 12
// [피보나치 수]
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n)
{
	int answer{ 0 };

	int f_0{ 0 }; // 0
	int f_1{ 1 }; // 1
	answer += (f_0 + f_1);

	for (int i = 2; i <= n; ++i)
	{		
		int f_2 = (f_0 + f_1) % 1234567;
		answer = f_2;
		f_0 = f_1;
		f_1 = f_2;
	}

	return answer;
}

int main()
{
	cout << solution(3) << endl; // result: 2
	cout << solution(5) << endl; // result: 5

	return 0;
}
#elif PROB == 13
#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
	int answer = -1;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}

int main()
{
	cout << solution("baabaa") << endl; // result: 2
	cout << solution("cdcd") << endl; // result: 5

	return 0;
}
#elif PROB == 14
// [타겟 넘버]
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 재귀적으로 최대 깊이까지 탐색하는 알고리즘, 가장 깊은 거리까지 탐색하는 알고리즘
// is_sign == true -> '+', is_sign == false -> '-'
void DFS(const vector<int>& numbers, const int& target, int index, int sum, bool is_sign, int& answer)
{
	// +, - 조건 판별 후 결과 값 연산
	if (is_sign)
		sum += numbers[index++];
	else
		sum -= numbers[index++];

	// 탐색 완료? 미완료?
	if (numbers.size() != index) // 더 탐색 가능 (모든 정점 방문 미완료)
	{
		DFS(numbers, target, index, sum, true, answer);
		DFS(numbers, target, index, sum, false, answer);
	}
	else // 더 이상 탐색 불가능 (모든 정점 방문 완료)
	{
		if (sum == target) // 원하는 결과 값이 완성됨
			answer++;
		
		return;
	}
}


int solution(vector<int> numbers, int target) 
{
	int answer{ 0 };
	int sum_value{ 0 };

	DFS(numbers, target, 0, sum_value, true, answer);
	DFS(numbers, target, 0, sum_value, false, answer);

	cout << answer << endl;
	return answer;
}

int main()
{
	solution({ 1, 1, 1, 1, 1 }, 3); // result: 5
	solution({ 4, 1, 2, 1 }, 4); // result: 2

	return 0;
}
#elif PROB == 15
// [네트워크]
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n, vector<vector<int>> computers)
{
	vector<bitset<200>> graphs;

	bool isFirst = true;
	for (const auto& computer : computers)
	{
		string temp;
		for (int node : computer)
		{
			temp += to_string(node);
		}

		auto b = bitset<200>(temp.c_str());

		if (isFirst)
		{
			graphs.push_back(b);
			isFirst = false;
			continue;
		}

		for (const auto& bit : graphs)
		{
			//cout << (bit & b) << endl;
			if ((bit & b) == bitset<200>(0))
			{
				graphs.push_back(b);
				break;
			}
		}
	}

	return  graphs.size();
}

int solution(int n, vector<vector<int>> computers) 
{
	int answer{ 0 };

	DFS(n, computers, answer, 0);
	cout << answer << endl;

	return answer;
}

int main()
{
	solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} }); // result: 2
	solution(3, { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} }); // result: 1

	return 0;
}
#endif