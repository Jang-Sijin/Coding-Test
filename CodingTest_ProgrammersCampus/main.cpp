#define PROB 1

#if PROB == 1
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;

	int pCount = 0;
	int yCount = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'p' || s[i] == 'P')
			pCount++;

		if (s[i] == 'y' || s[i] == 'Y')
			yCount++;
	}

	if (pCount == yCount)
		answer = true;
	else
		answer = false;

	return answer;
}

int main()
{
	string s{"ppyyy"};

	cout << solution(s) << endl;;

	return 0;
}
#elif PROB == 2
#include <iostream>

using namespace std;

int solution(int n)
{
	int answer = 0;

	// 10으로 나눠지지 않을 떄 까지 수행한다.
	while (true)
	{
		// 10으로 나눠질 때
		if (n / 10 != 0)
		{
			answer += (n % 10);
			n /= 10;
		}
		// 10으로 더이상 나눠지지 않을 때
		else
		{
			answer += (n % 10);
			break;
		}
	}

	return answer;
}

int main()
{
	int n{ 1234567890 };

	cout << solution(n) << endl;;

	return 0;
}
#elif PROB == 3
#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
	int answer = -1;

	// 놀이기구 총 이용료
	long long sum{ 0 };
	for (int N = 1; N <= count; ++N)
	{
		sum += (price * N);
	}

	// 소지한 금액이 부족할 경우
	if (sum > money)
	{
		return sum - money;
	}
	// 소지한 금액이 부족하지 않을 경우
	else
	{
		return 0;
	}

	return answer;
}

int main()
{
	cout << solution(2500, 10, 2500) << endl;;

	return 0;
}

#elif PROB == 4
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) 
{
	string answer = "";

	// width(x): 0,1,2
	// height(y): 0,1,2,3
	// 2차원 배열을 사용하여 키패드의 위치를 특정한다.
	char keypad[4][3]{1,2,3,4,5,6,7,8,9,'*','#'};

	// 왼손 위치
	int left_hand_x = 0;
	int left_hand_y = 3;

	// 오른손 위치
	int right_hand_x = 2;
	int right_hand_y = 3;

	for (auto& number : numbers)
	{
		// 왼손을 사용한다.
		if (number == 1 || number == 4 || number == 7)
		{
			left_hand_x = 0;
			if (number == 1)
				left_hand_y = 0;
			else if (number == 4)
				left_hand_y = 1;
			else if (number == 7)
				left_hand_y = 2;

			answer += 'L';
		}
		// 오른손을 사용한다.
		else if (number == 3 || number == 6 || number == 9)
		{
			right_hand_x = 2;
			if (number == 3)
				right_hand_y = 0;
			else if (number == 6)
				right_hand_y = 1;
			else if (number == 9)
				right_hand_y = 2;

			answer += 'R';
		}
		// 왼손 또는 오른손을 사용한다.
		else if (number == 2 || number == 5 || number == 8 || number == 0)
		{
			int find_x{};
			int find_y{};
			// number의 키패드 위치를 구한다.
			for (int y = 0; y < 4; ++y)
				for (int x = 0; x < 3; ++x)
					if (number == keypad[y][x])
					{
						find_x = x;
						find_y = y;
						break;
					}
	
			int compare_left = abs(find_x - left_hand_x) + abs(find_y - left_hand_y);
			int compare_right = abs(find_x - right_hand_x) + abs(find_y - right_hand_y);

			// 왼쪽 손이 오른쪽 손보다 먼 경우
			if (compare_left > compare_right)
			{
				//오른쪽 손을 이동한다.
				right_hand_x = find_x;
				right_hand_y = find_y;

				answer += 'R';
			}
			// 오른쪽 손이 왼쪽 손보다 먼 경우
			else if (compare_left < compare_right)
			{
				//왼쪽 손을 이동한다.
				left_hand_x = find_x;
				left_hand_y = find_y;

				answer += 'L';
			}
			// 오른쪽 손과 왼쪽 손의 거리가 같을 때
			else if (compare_left == compare_right)
			{
				// 주 손이 오른손인 경우
				if (hand == "right")
				{
					//오른쪽 손을 이동한다.
					right_hand_x = find_x;
					right_hand_y = find_y;

					answer += 'R';
				}
				// 주 손이 왼손인 경우
				else if (hand == "left")
				{
					//왼쪽 손을 이동한다.
					left_hand_x = find_x;
					left_hand_y = find_y;

					answer += 'L';
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> numbers{1,3,4,5,8,2,1,4,5,9,5};

	cout << solution(numbers, "right") << endl;

	return 0;
}
#endif