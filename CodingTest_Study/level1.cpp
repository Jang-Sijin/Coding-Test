#define PROB 58

#if PROB == 1
// [���簢�� �����]
#include <iostream>

using namespace std;

int main(void)
{
	int x;
	int y;
	cin >> x >> y;

	for (int index_y = 0; index_y < y; ++index_y)
	{
		for (int index_x = 0; index_x < x; ++index_x)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
#elif PROB == 2
// [����� ����]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<vector<int>> answer;
	answer.reserve(arr1.size());

	for (int i = 0; i < arr1.size(); ++i)
	{
		vector<int> add_value;
		answer.reserve(arr1[0].size());

		for (int j = 0; j < arr1[0].size(); ++j)
		{
			add_value.push_back(arr1[i][j] + arr2[i][j]);
		}
		answer.push_back(add_value);

		add_value.clear();
	}

	return answer;
}

int main()
{
	solution({ {1, 2 }, { 2, 3 } }, { {3, 4}, {5, 6} }); // result: {{4, 6}, {7, 9}}

	return 0;
}
#elif PROB == 3
// [�ϻ��� ��]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
	bool answer = true;

	int value{ x };
	int sum_number{ 0 };
	while (true)
	{
		sum_number += value % 10;

		if (value / 10 != 0)
			value /= 10;
		else
			break;
	}

	// cout << "sum_number: " << sum_number << endl;
	(x % sum_number == 0) ? answer = true : answer = false;

	return answer;
}

int main()
{
	cout << solution(10) << endl; // result: true
	cout << solution(12) << endl;; // result: true
	cout << solution(11) << endl;; // result: false
	cout << solution(13) << endl;; // result: false

	return 0;
}
#elif PROB == 4
// [x��ŭ ������ �ִ� n���� ����]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
	vector<long long> answer;

	int sum{ 0 };
	for (int i = 0; i < n; ++i)
	{
		sum += x;
		answer.push_back(sum);
	}

	return answer;
}

int main()
{
	solution(2, 5);

	return 0;
}
#elif PROB == 5
// [�ڵ��� ��ȣ ������]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
	string answer = "";

	const int blind_length{ 4 };

	for (int i = 0; i < phone_number.length() - blind_length; ++i)
	{
		answer += '*';
	}
	answer += phone_number.substr(phone_number.length() - blind_length, phone_number.length());

	cout << answer << endl;
	return answer;
}

int main()
{
	solution("01033334444");
	solution("027778888");

	return 0;
}
#elif PROB == 6
// [��� ���ϱ�]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr)
{
	double answer = 0;

	for (const auto iter : arr)
	{
		answer += iter;
	}
	answer /= arr.size();

	return answer;
}

int main()
{
	solution({ 1, 2, 3, 4 }); // result: 2.5
	solution({ 5, 5 }); // result: 5.0

	return 0;
}
#elif PROB == 7
// [�ݶ��� ����]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
	int answer{ 0 };

	int count{ 0 }; // ����Ƚ��
	while (num > 1 || count >= 500)
	{
		// ¦���� ��
		if (num % 2 == 0)
		{
			// 2�� �����ϴ�.
			num /= 2;
		}
		// Ȧ���� ��
		else
		{
			// 3�� ���ϰ� 1�� ���մϴ�.
			num = (num * 3) + 1;
		}

		count++;
	}
	(num == 1) ? answer = count : answer = -1;;

	return answer;
}

int main()
{
	solution(6); // result: 8
	//solution(16); // result: 4
	//solution(626331); // result: -1

	return 0;
}
#elif PROB == 8
// [¦���� Ȧ��]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num)
{
	string answer = "";

	(num % 2 == 0) ? answer = "Even" : answer = "Odd";

	return answer;
}

int main()
{
	solution(3); // result: "Odd"
	//solution(4); // result: "Even"

	return 0;
}
#elif PROB == 9
// [���� ������ �Ǻ�]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n)
{
	// �Է� n�� ���� �����̴�.
	long long answer{ 0 };

	// n�� ���� ���� x�� �������� ��
	if (sqrt(n) == static_cast<int>(sqrt(n)))
	{
		// (x+1)^2�� ��ȯ�Ѵ�.
		answer = pow(sqrt(n) + 1, 2);
	}
	// n�� ���� ���� x�� �������� �ƴ� ��
	else
	{
		// -1�� ��ȯ�Ѵ�.
		answer = -1;
	}

	return answer;
}

int main()
{
	solution(121); // result: 144
	//solution(3); // result: -1

	return 0;
}
#elif PROB == 10
// [�ڿ��� ������ �迭�� �����]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
	vector<int> answer;

	while (n > 0)
	{
		if (n /= 10 != 0)
		{
			answer.push_back(n % 10);
			n /= 10;
		}
	}

	return answer;
}

int main()
{
	solution(12345); // result: [5, 4, 3, 2, 1]

	return 0;
}
#elif PROB == 11
// [�̻��� ���� �����]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string answer = "";

	int count{ -1 };
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
			count = -1;
		else
			count++;

		if (count % 2 == 0)
		{
			s[i] = toupper(s[i]);
		}
		else
		{
			s[i] = tolower(s[i]);
		}
	}

	answer = s;
	return answer;
}

int main()
{
	solution("try hello world"); // result: "TrY HeLlO WoRlD"

	return 0;
}
#elif PROB == 12
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
	string answer = "";

	const int alphabet_size{ 26 };
	for (int i = 0; i < s.length(); ++i)
	{
		if (isalpha(s[i]))
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				(s[i] + n <= 'z') ? s[i] += n : s[i] += n - alphabet_size;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				(s[i] + n <= 'Z') ? s[i] += n : s[i] += n - alphabet_size;
		}
	}
	answer = s;
	cout << answer << endl;
	return answer;
}

int main()
{
	solution("AB", 1); // result: "BC"
	solution("z", 1); // result: "a"
	solution("a B z", 4); // result: "e F d"

	return 0;
}
#elif PROB == 13
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
	string answer = "";

	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
			answer += "��";
		else
			answer += "��";
	}

	return answer;
}

int main()
{
	solution(3); // result: "���ڼ�"
	//solution(4); // result: "���ڼ���"

	return 0;
}
#elif PROB == 14
// [���￡�� �輭�� ã��]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul)
{
	string answer = "";

	answer = "�輭���� "
		+ to_string(find(seoul.begin(), seoul.end(), "Kim") - seoul.begin())
		+ "�� �ִ�";

	return answer;
}

int main()
{
	solution({ "Jane", "Kim" }); // result: "�輭���� 1�� �ִ�"

	return 0;
}
#elif PROB == 15
// [���ڿ� ������������ ��ġ�ϱ�]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
	string answer = "";

	sort(s.begin(), s.end(), [](const auto& first, const auto& second)
		{
			return first > second;
		});
	// ���� �� greater<char>
	answer = s;

	return answer;
}

int main()
{
	solution("Zbcdefg"); // result: "gfedcbZ"

	return 0;
}
#elif PROB == 16
// [���ڿ� �� ������� �����ϱ�]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> answer, int n)
{
	sort(answer.begin(), answer.end(), [n](const string& first, const string& second)
		{
			if (first[n] == second[n])
				return first < second;
			else
				return first[n] < second[n];
		});

	return answer;
}

int main()
{
	solution({ "sun", "bed", "car" }, 1); // result: ["car", "bed", "sun"]
	// solution({ "abce", "abcd", "cdx" }, 2); // result: ["abcd", "abce", "cdx"]

	return 0;
}
#elif PROB == 17
// [�ִ������� �ּҰ����] - �ذ� x
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m)
{
	vector<int> answer;

	int length{};
	n < m ? length = n : length = m;

	int greatest_common_factor{ 1 };
	int least_common_multiple{ 1 };

	int temp{};
	while (true)
	{
		if (n % m != 0)
		{
			temp = n % m;
			n = m;
			m = temp;
		}

		if (temp == 0 || n == 0)
		{
			n == 0 ? answer.push_back(temp) : answer.push_back(n);
			break;
		}
	}

	for (auto i : answer)
	{
		cout << i << ' ';
	}

	return answer;
}

int main()
{
	// solution(3, 12); // result: [3, 12]
	solution(2, 5); // result: [1, 10]

	return 0;
}
#elif PROB == 18
// [���� ���� �� �����ϱ�]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
	// min_element: O(n)
	auto min_value = min_element(arr.begin(), arr.end());
	arr.erase(min_value);

	if (arr.empty())
		arr.push_back(-1);

	return arr;
}

int main()
{
	solution({ 4, 3, 2, 1 }); // [4, 3, 2]

	// solution({ 10 }); // [-1]

	return 0;
}
#elif PROB == 19
// [���� ������������ ��ġ�ϱ�]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
	long long answer = 0;
	string string_number{ to_string(n) };

	sort(string_number.begin(), string_number.end(), greater<char>());
	answer = stoll(string_number); // stoll �� string to long long

	return answer;
}

int main()
{
	solution(118372); // 873211

	return 0;
}
#elif PROB == 20
// [�ڸ��� ���ϱ�]
#include <iostream>
#include <string>

using namespace std;

int solution(int n)
{
	int answer = 0;

	while (n != 0)
	{
		answer += n % 10;
		n /= 10;
	}

	return answer;
}

int main()
{
	solution(123456789);

	return 0;
}
#elif PROB == 21
// [����� ��]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (n % i == 0)
			answer += i;
	}

	cout << answer;
	return answer;
}

int main()
{
	solution(12); // result: 28
	// solution(5); // result: 6

	return 0;
}
#elif PROB == 22
// [���ڿ��� ������ �ٲٱ�]
#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
	int answer = 0;

	if (s[0] == '-' || s[0] == '+')
		answer = stoi(s.substr(1, s.length()));
	else
		answer = stoi(s.substr(0, s.length()));

	if (s[0] == '-')
		answer = ~answer + 1;

	return answer;
}

int main()
{
	solution("+1234"); // result: 1234
	// solution("-1234"); // result: -1234

	return 0;
}
#elif PROB == 23
// [�Ҽ� ã��] - �ذ� x
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	// case input n == 2 �� default answer value = 1
	int answer = 1;

	for (int i = 2; i <= n; ++i)
	{
		bool is_true{ false };
		int count{ 0 };
		for (int j = 2; j < i; ++j)
		{
			if (i % j == 0)
				break;

			if (j == i - 1)
				is_true = true;
		}

		if (is_true)
			answer++;
	}

	cout << answer;
	return answer;
}

int main()
{
	solution(10); // result: 4
	// solution(5); // result: 3

	return 0;
}
#elif PROB == 24
// [���ڿ� �ٷ�� �⺻]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	if ((s.length() != 4) && (s.length() != 6))
	{
		answer = false;
		return answer;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		if (!isdigit(s[i]))
		{
			answer = false;
			return answer;
		}
	}

	return answer;
}

int main()
{
	solution("a234"); // result: false
	solution("1234"); // result: true

	return 0;
}
#elif PROB == 25
// [���ڿ� �� p�� y�� ����]
#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
	bool answer = true;

	int y_count{ 0 };
	int p_count{ 0 };

	for (char s_index : s)
	{
		if (s_index == 'p' || s_index == 'P')
			p_count++;

		if (s_index == 'y' || s_index == 'Y')
			y_count++;
	}

	if (p_count != y_count)
		answer = false;

	return answer;
}

int main()
{
	solution("pPoooyY"); // result: true
	//solution("Pyy"); // result: false

	return 0;
}
#elif PROB == 26
// [�� ���� ������ ��]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
	long long answer = 0;

	int min_value{};
	int max_value{};

	a > b ? (max_value = a, min_value = b) : (max_value = b, min_value = a);

	for (int i = min_value; i <= max_value; ++i)
	{
		answer += i;
	}

	return answer;
}

int main()
{
	solution(3, 5); // result: 12
	solution(3, 3); // result: 3
	solution(5, 3); // result: 12

	return 0;
}
#elif PROB == 27
// [������ �������� ���� �迭]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
	vector<int> answer;

	for (const int index : arr)
	{
		if (index % divisor == 0)
			answer.push_back(index);
	}

	if (answer.empty())
	{
		answer.push_back(-1);
		return answer;
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main()
{
	solution({ 5, 9, 7, 10 }, 5); // result: [5, 10]
	solution({ 2, 36, 1, 3 }, 1); // result: [1, 2, 3, 36]
	solution({ 3, 2, 6 }, 10); // result: [-1]

	return 0;
}
#elif PROB == 28
// [1�� ��Ʈ ����]
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult)
{
	int answer = 0;

	int prev_score{};
	int score{};
	for (int i = 0; i < dartResult.length(); ++i)
	{
		switch (dartResult[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (i > 0 && dartResult[i - 1] == '1')
			{
				prev_score += 9;
			}
			else
			{
				prev_score = score;
				answer += score;
				int dartResult_value = atoi(&dartResult[i]);
				score = dartResult_value;
			}
			break;
		case 'D':
			score = pow(score, 2);
			break;
		case 'T':
			score = pow(score, 3);
			break;
		case '*':
			answer += prev_score;
			score *= 2;
			break;
		case '#':
			score *= -1;
			break;
		}
		//cout << i << "��° score: " << score << " answer: " << answer << endl;
	}
	answer += score;

	cout << "answer: " << answer << endl << endl;
	return answer;
}

int main()
{
	solution("1S2D*3T"); // result: 37
	solution("1D2S#10S"); // result: 9
	solution("1D2S0T"); // result: 3
	solution("1S*2T*3S"); // result: 23
	solution("1D#2S*3S"); // result: 5
	solution("1T2D3D#"); // result: -4
	solution("1D2S3T*"); // result: 59
	solution("10S#2S*3S"); // result: (-10 * 2) + (2 * 2) + (3) = -20 + 4 + 3 = -13

	return 0;
}
#elif PROB == 29
// [��� ���� ��������]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string answer = "";

	size_t index{ (s.length() / 2) };
	if (s.length() % 2 == 1)
		answer = s[index];
	else
		answer += s[index - 1], answer += s[index];

	cout << answer << endl;
	return answer;
}

int main()
{
	solution("abcde"); // result: "c"
	solution("qwer"); // result: "we"

	return 0;
}
#elif PROB == 30
// [������ �ݾ� ����ϱ�]
#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
	long long answer{};
	int total_price{ 0 };

	for (int i = 1; i <= count; ++i)
		total_price += (price * i);

	answer = (money - total_price) >= 0 ? 0 : (total_price - money);

	cout << answer;
	return answer;
}

int main()
{
	// solution(3, 20, 4); // result: 10
	solution(2500, 1000000000, 2500); // result: 10

	return 0;
}
#elif PROB == 31
// [�������� 1�� �Ǵ� �� ã��]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	for (int answer = 2; answer <= 1000000; ++answer)
	{
		if (n % answer == 1)
		{
			return answer;
		}
	}
}

int main()
{
	solution(10); // result: 3
	solution(12); // result: 11

	return 0;
}
#elif PROB == 32
// [2016��]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int month, int day)
{
	string answer = "";

	// ����: (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))
	const int month_day[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };

	// ������ month���� day + ���� month�� day = 2016�� 1�� 1�� ~ 2016�� month�� day�� = sum_day
	int sum_day{ 0 };
	for (int i = 1; i <= 12; ++i)
	{
		if (month == i)
		{
			for (int prev_month = 0; prev_month < i - 1; ++prev_month)
			{
				sum_day += month_day[prev_month];
			}
			sum_day += day;
			break;
		}
	}

	// 2016�� 1�� 1���� �ݿ����Դϴ�. �� case 1: "FRI"
	switch (sum_day % 7)
	{
	case 0:
		answer = "THU";
		break;
	case 1:
		answer = "FRI";
		break;
	case 2:
		answer = "SAT";
		break;
	case 3:
		answer = "SUN";
		break;
	case 4:
		answer = "MON";
		break;
	case 5:
		answer = "TUE";
		break;
	case 6:
		answer = "WED";
		break;
	}

	return answer;
}

int main()
{
	solution(5, 24); // result: "TUE"

	return 0;
}
#elif PROB == 33
// [�� �� �̾Ƽ� ���ϱ�]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers)
{
	set<int> set_numbers{};
	for (int i = 0; i < numbers.size(); ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			set_numbers.insert(numbers[i] + numbers[j]);
		}
	}

	vector<int> answer{ set_numbers.begin(), set_numbers.end() };

	return answer;
}

int main()
{
	solution({ 2, 1, 3, 4, 1 }); // result: [2, 3, 4, 5, 6, 7]
	//solution({ 5, 0, 2, 7 }); // result: [2, 5, 7, 9, 12]

	return 0;
}
#elif PROB == 34
// [���� �����ϱ�] - SQL

/*
1. ������ �̸��� ��ȣ �������� ��ȸ
2. ���� ��ȣ�ҿ� ���� ���
3. ����� ANIMAL_ID && 4. �������� �����ּ���.
*/

// SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC;
#elif PROB == 35
// [3���� ������]
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
	int answer = 0;

	vector<int> vector_numbers{};

	// [Example]
	// 45(10) �� 1200(3)
	// (1 * 3^3) + (2 * 3^2) + (0 * 3^1) + (0 * 3^0)
	int number{ n };
	while (number > 0)
	{
		vector_numbers.push_back(number % 3);
		number /= 3;
	}

	auto number_pow{ vector_numbers.size() - 1 };
	for (int n : vector_numbers)
	{
		answer += n * pow(3, number_pow);
		--number_pow;
	}

	return answer;
}

int main()
{
	solution(45); // result: 7
	// solution(125) // result: 229

	return 0;
}
#elif PROB == 36
// [������]
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;

	map<int, double> map_stage_challenger{};

	// 1. �� �������� �� ������ �� �ʱ�ȭ
	for (int i = 1; i <= N; ++i)
		map_stage_challenger.insert({ i, 0 });

	// 2. �� �������� �� ������ ������ ����� �� ����
	for (int i = 0; i < stages.size(); ++i)
		map_stage_challenger[stages[i]]++;

	// 3. �÷��̾��� �� ����
	auto stage_challenger_count{ stages.size() };

	// 4. �� �������� �� ���� ������ ���
	for (int i = 1; i <= N; ++i)
	{
		if (map_stage_challenger[i] != 0)
		{
			// 4-1. �ش� ���������� ������ ��
			int now_satage_challenger_count = static_cast<int>(map_stage_challenger[i]);

			// 4-2. ������ ���� ���� �������� ������
			map_stage_challenger[i] /= stage_challenger_count;

			// 4-3. ���� ���������� ������ ��
			stage_challenger_count -= now_satage_challenger_count;
		}
	}

	// [@] Ȯ�� üũ
	//for (auto& map : map_stage_challenger) cout << "map.first: " << map.first << " / map.second: " << map.second << endl;

	// 5. ������ ���� ���� ����
	vector<pair<int, double>> vector_stage_challenger{};
	vector_stage_challenger.reserve(N);
	for (int i = 1; i <= N; ++i)
	{
		vector_stage_challenger.push_back({ i, map_stage_challenger[i] });
	}

	// 6. �� ���������� ������ �������� ������������ ����
	sort(vector_stage_challenger.begin(), vector_stage_challenger.end(), [](const pair<int, double>& prev, const pair<int, double>& next)
		{
			if (prev.second == next.second)
				return prev.first < next.first;

			return prev.second > next.second;
		});

	// 7. answer(��ȯ vector)�� ����� ����
	for (auto& challenger : vector_stage_challenger)
	{
		answer.push_back(challenger.first);
	}

	// [@] Ȯ�� üũ
	//cout << "result: "; for (auto& challenger : answer) cout << challenger << " ";

	return answer;
}

int main()
{
	solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 }); // result: [3, 4, 2, 1, 5]
	//solution(4, { 4, 4, 4, 4, 4 });           // result: [4, 1, 2, 3]

	return 0;
}
#elif PROB == 37
// [���� n�� ���ڵ�]
SELECT NAME FROM ANIMAL_INS ORDER BY DATETIME LIMIT 1

#elif PROB == 38
// [���� �������� �����ϱ�]
SELECT ANIMAL_ID, NAME, DATETIME FROM ANIMAL_INS ORDER BY NAME, DATETIME DESC

#elif PROB == 39
// [1�� �������]
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;

	for (int i = 0; i < n; ++i)
	{
		int i_binary{ arr1[i] | arr2[i] };

		vector<string> s_binary;
		while (i_binary > 0)
		{
			if (i_binary % 2 == 0)
			{
				s_binary.push_back(" ");
			}
			else
			{
				s_binary.push_back("#");
			}
		}

		reverse(s_binary.begin(), s_binary.end());

	}

	for (int i = 0; i < n; ++i)
		std::cout << answer[i] << "\n";

	return answer;
}

int main()
{
	//solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 }); // result: ["#####", "# # #", "### #", "#  ##", "#####"]
	solution(6, { 46, 33, 33, 22, 31, 50 }, { 27, 56, 19, 14, 14, 10 }); // result: ["######", "###  #", "##  ##", " #### ", " #####", "### # "]

	return 0;
}

#elif PROB == 40
// [���� ���ϱ�]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
	int answer = 0; // ���� ����� absolutes(���� ��)�� ����(��ȣ�� �ִ�)���� ��

	// signs value �� true: ���, false: ����
	for (int i = 0; i < absolutes.size(); ++i)
	{
		signs[i] ? answer += absolutes[i] : answer -= absolutes[i];
	}

	std::cout << answer << std::endl;
	return answer;
}

int main()
{
	solution({ 4,7,12 }, { true,false,true }); // result: 9
	// solution({ 1,2,3 }, { false,false,true }); // result: 0

	return 0;
}

#elif PROB == 41
// [���� ���� ���ϱ�]
#include <iostream>
#include <string>
#include <vector>
#define START_NUMBER 1
#define END_NUMBER 9

using namespace std;

int solution(vector<int> numbers)
{
	int answer{ 0 };

	for (int i = START_NUMBER; i <= END_NUMBER; ++i)
		answer += i;

	for (auto number : numbers)
		answer -= number;

	//std::cout << answer << std::endl;
	return answer;
}

int main()
{
	solution({ 1,2,3,4,6,7,8,0 }); // result: 14
	//solution({ 5,8,4,0,6,7,9 }); // result: 6

	return 0;
}

#elif PROB == 42
// [����]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
	int answer{ 0 }; // ���� ���

	for (int i = 0; i < a.size(); ++i)
	{
		answer += a[i] * b[i];
	}

	//cout << answer << endl;
	return answer;
}

int main()
{
	solution({ 1,2,3,4 }, { -3,-1,0,2 }); // result: 3
	solution({ -1,0,1 }, { 1,0,-1 }); // result: -2

	return 0;
}

#elif PROB == 43
// [����� ������ ����]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right)
{
	int answer{ 0 };

	for (int value = left; value <= right; ++value)
	{
		int count{ 0 };
		int sqrt_value = static_cast<int>(sqrt(value));
		for (int i = 1; i <= sqrt_value; ++i)
		{
			if (value % i == 0)
				count++;
		}

		if (sqrt(value) == sqrt_value)
			count = (2 * count) - 1;
		else
			count = (2 * count);

		count % 2 == 0 ? answer += value : answer -= value;
		// cout << value << ", " << count << " : ";
	}
	// cout << endl;

	// cout << answer << endl;
	return answer;
}

int main()
{
	solution(13, 17);

	return 0;
}

#elif PROB == 44
// [���� ���ڴ� �Ⱦ�]
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	answer.push_back(arr[0]);
	for (int i = 1; i < arr.size(); ++i)
	{
		if (answer.back() != arr[i])
			answer.push_back(arr[i]);
	}

	//for (auto iter : answer)
	//	cout << iter << " ";
	//cout << endl;

	return answer;
}

int main()
{
	solution({ 1,1,3,3,0,1,1 }); // result: [1,3,0,1]
	// solution({ 4,4,4,3,3 }); // result: [4,3]

	return 0;
}
#elif PROB == 45
// [����]
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
	int answer = 0;

	sort(d.begin(), d.end());

	for (auto iter = d.begin(); iter < d.end(); ++iter)
	{
		if (0 <= budget - *iter)
		{
			budget -= *iter;
			answer++;
		}
		else
			break;
	}

	return answer;
}

int main()
{
	solution({ 1, 3, 2, 5, 4 }, 9); // result: 3
	// solution({ 2, 2, 3, 3 }, 10); // result: 4

	return 0;
}

#elif PROB == 46
// [�ּ����簢��]
// ���� �� �� �κа� ª�� �κ��� ��ġ�� �����ؾ� �ȴ�.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes)
{
	int answer = 0;

	// ����
	for (int i = 0; i < sizes.size(); ++i)
	{
		sort(sizes[i].begin(), sizes[i].end(), [](int first, int second)
			{
				return first > second;
			});
	}

	// min, max ����
	int max[2]{ sizes[0][0], sizes[0][1] };
	for (int i = 1; i < sizes.size(); ++i)
	{
		if (max[0] < sizes[i][0])
			max[0] = sizes[i][0];

		if (max[1] < sizes[i][1])
			max[1] = sizes[i][1];
	}

	for (int i = 0; i < sizes.size(); ++i)
	{
		for (int j = 0; j < sizes[i].size(); ++j)
		{
			cout << sizes[i][j] << ' ';
		}
		cout << endl;
	}

	answer = (max[0] * max[1]);
	cout << max[0] << ", " << max[1] << endl;
	return answer = (max[0] * max[1]);
}

int main()
{
	solution({ {60, 50 }, { 30, 70 }, { 60, 30 }, { 80, 40 } }); // result: 4000

	return 0;
}
#elif PROB == 47
// [k��°��]
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;
	answer.reserve(commands.size());

	for (int i = 0; i < commands.size(); ++i)
	{
		vector<int> sorted;
		sorted.reserve(commands[i].size());

		for (int j = commands[i][0] - 1; j < commands[i][1]; ++j)
		{
			sorted.push_back(array[j]);
		}

		sort(sorted.begin(), sorted.end());

		answer.push_back(sorted[commands[i][2] - 1]);
	}

	return answer;
}

int main()
{
	solution({ 1, 5, 2, 6, 3, 7, 4 }, { {2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } });

	return 0;
}
#elif PROB == 48
// [���� ���ڿ��� ���ܾ�]
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = 0;

	string number_str[10]
	{
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	string answer_string;
	for (int i = 0; i < s.size();)
	{
		// 1. ������ ���
		if (isdigit(s[0]))
		{
			// 1-2. ���ڸ� string ���·� answer_string�� �߰��Ѵ�.
			answer_string += s[0];

			// 1.3. ���� ���� ���ڸ� s���� �����Ѵ�.
			s = s.substr(1, s.size());
		}
		// 2. ���ڰ� ����ܾ��� ���
		else
		{
			// 2-1. number_str�� ��ȸ�ϸ鼭 s[0]���� s[number_str[j].size()]������ ���ϸ� ���� ���ڸ� ã�´�.
			for (int j = 0; j < 10; ++j)
			{
				if (number_str[j] == s.substr(0, number_str[j].size()))
				{
					// 2-2. ���ڸ� string ���·� answer_string�� �߰��Ѵ�.
					answer_string += to_string(j);

					// 2-3. ���� ���� ���ڸ� s���� �����Ѵ�.
					s = s.substr(number_str[j].size(), s.size());

					// 2-4. �ݺ� ��ŵ.
					break;
				}
			}
		}
	}

	return answer = stoi(answer_string);;
}

int main()
{
	//solution("one4seveneight");
	//solution("23four5six7");
	solution("2three45sixseven");
	//solution("123");

	return 0;
}
#elif PROB == 49
// [���ϸ�]
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;

	set<int> set_nums{ nums.begin(), nums.end() };
	auto choose_size{ nums.size() / 2 };
	cout << choose_size << " ";

	if (set_nums.size() >= choose_size)
		answer = choose_size;
	else
		answer = set_nums.size();

	return answer;
}

int main()
{
	solution({ 3, 1, 2, 3 });
	solution({ 3, 3, 3, 2, 2, 4 });
	solution({ 3, 3, 3, 2, 2, 2 });

	return 0;
}
#elif PROB == 50
// [���ǰ��]
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
	vector<int> answer;

	vector<vector<int>> students{ {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };
	vector<int> students_count{ 0,0,0 };

	for (int i = 0; i < answers.size(); ++i)
	{
		if (answers[i] == students[0][i % students[0].size()])
			students_count[0]++;

		if (answers[i] == students[1][i % students[0].size()])
			students_count[1]++;

		if (answers[i] == students[2][i % students[0].size()])
			students_count[2]++;
	}

	int max_count{ *max_element(students_count.begin(), students_count.end()) };

	for (int i = 0; i < 3; ++i)
		if (max_count == students_count[i])
			answer.push_back(i + 1);

	return answer;
}

int main()
{
	solution({ 1,2,3,4,5 }); // result: [1]
	// solution({ 1,3,2,4,2 }); // result: [1,2,3]

	return 0;
}
#elif PROB == 51
// [���ѻ�]
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> number)
{
	int answer = 0;

	// ����� ��
	for (int i = 0; i < number.size() - 2; ++i)
	{
		for (int j = i + 1; j < number.size() - 1; ++j)
		{
			for (int k = j + 1; k < number.size(); ++k)
			{
				if (number[i] + number[j] + number[k] == 0)
					++answer;
			}
		}
	}

	cout << answer << endl;
	return answer;
}

int main()
{
	solution({ -2, 3, 0, 2, -5 }); // result: 2
	solution({ -3, -2, -1, 0, 1, 2, 3 }); // result: 5
	solution({ -1, 1, -1, 1 }); // result: 0

	return 0;
}
#elif PROB == 52
// [�ζ��� �ְ� ������ ���� ����]
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
	vector<int> answer;

	// [Best Rank]
	answer.push_back(count(lottos.begin(), lottos.end(), 0));
	// [Worst Rank]
	answer.push_back(0);

	for (int i = 0; i < win_nums.size(); ++i)
	{
		// match lottos numbers
		if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
		{
			answer[0] += 1;
			answer[1] += 1;
		}
	}

	// i == 0 �� Best Rank
	// i == 1 �� Worst Rank
	for (int i = 0; i < 2; ++i)
	{
		switch (answer[i])
		{
		case 6:
			answer[i] = 1;
			break;
		case 5:
			answer[i] = 2;
			break;
		case 4:
			answer[i] = 3;
			break;
		case 3:
			answer[i] = 4;
			break;
		case 2:
			answer[i] = 5;
			break;
		default:
			answer[i] = 6;
			break;
		}
	}

	return answer;
}

int main()
{
	solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 }); // result: [3, 5]
	solution({ 0, 0, 0, 0, 0, 0 }, { 38, 19, 20, 40, 15, 25 });  // result: [1, 6]
	solution({ 45, 4, 35, 20, 3, 9 }, { 20, 9, 3, 45, 4, 35 });  // result: [1, 1]

	return 0;
}
#elif PROB == 53
// [�������� ��ġ�� ������� ��� ����ϱ�]
SELECT FACTORY_ID, FACTORY_NAME, ADDRESS 
FROM FOOD_FACTORY 
WHERE ADDRESS LIKE '������%' 
ORDER BY FACTORY_ID ASC

#elif PROB == 54
// [���� ������ ���� ȸ�� �� ���ϱ�]
SELECT COUNT(*) AS 'USERS' 
FROM USER_INFO 
WHERE AGE IS NULL

#elif PROB == 55
// [��⵵�� ��ġ�� ��ǰâ�� ��� ����ϱ�]
SELECT WAREHOUSE_ID, WAREHOUSE_NAME, ADDRESS, IF(FREEZER_YN IS NULL, 'N', FREEZER_YN) 
FROM FOOD_WAREHOUSE 
WHERE ADDRESS LIKE '��⵵%' 
ORDER BY WAREHOUSE_ID ASC

#elif PROB == 56
// [���ǿ� �´� ȸ���� ���ϱ�]
SELECT COUNT(*) AS 'USERS' 
FROM USER_INFO 
WHERE YEAR(JOINED) = 2021 AND AGE >= 20 AND AGE <= 29

#elif PROB == 57
// [���� ��� ��ǰ ���ϱ�]
SELECT MAX(PRICE) AS 'MAX_PRICE' 
FROM PRODUCT

#elif PROB == 58
// [��οܰ� �Ǵ� �Ϲݿܰ� �ǻ� ��� ����ϱ�]
SELECT DR_NAME, DR_ID, MCDP_CD, DATE_FORMAT(HIRE_YMD, '%Y-%m-%d')
FROM DOCTOR
WHERE MCDP_CD = 'CS' OR MCDP_CD = 'GS'
ORDER BY HIRE_YMD DESC, DR_NAME ASC

#endif