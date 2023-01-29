#define PROB 6

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
#endif