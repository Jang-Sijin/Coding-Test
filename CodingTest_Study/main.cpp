#define PROB 5

#if PROB == 1
////////////////////////////////////////////////////////////////////////////////////////////////////////
// 문제 설명
// 수많은 마라톤 선수들이 마라톤에 참여하였습니다.단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
// 
// 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.
// 
// 제한사항
// 마라톤 경기에 참여한 선수의 수는 1명 이상 100, 000명 이하입니다.
// completion의 길이는 participant의 길이보다 1 작습니다.
// 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
// 참가자 중에는 동명이인이 있을 수 있습니다.
// 입출력 예
// participant	completion	return
// ["leo", "kiki", "eden"]["eden", "kiki"]	"leo"
// ["marina", "josipa", "nikola", "vinko", "filipa"]["josipa", "filipa", "marina", "nikola"]	"vinko"
// ["mislav", "stanko", "mislav", "ana"]["stanko", "ana", "mislav"]	"mislav"
// 입출력 예 설명
// 예제 #1
// "leo"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.
// 
// 예제 #2
// "vinko"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.
// 
// 예제 #3
// "mislav"는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 1. 해시 테이블 : 항목 수가 많을수록 효율적, 키의 전체 개수와 동일한 크기의 버킷을 가짐.
// 2. std::map → O(logN) → binary search tree → key 정렬O
// 3. std::unordered_map → O(1) → hash table → key 정렬X
// 4. std::unordered_map 중복된 데이터를 허용X, map에 비해 데이터가 많을 시 월등히 좋은 성능.
// 5. key가 유사한 데이터가 많을 시 해시 충돌로 인해 성능저하
// 6. 결론: 해시테이블 유형 → std::unordered_map 사용하여 문제를 해결이 Best.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	unordered_map<string, int> um;

	// O(N)
	for (auto& p : participant)
	{
		um[p] += 1;
	}

	// O(N)
	for (auto& c : completion)
	{
		um[c] -= 1;
	}

	// O(N)보다 작거나 같음.
	for (auto& i : um)
	{
		if (i.second > 0)
		{
			answer = i.first;
			break;
		}
	}

	return answer;
}

int main()
{
	vector<string> participant{ "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> completion{ "josipa", "filipa", "marina", "nikola" };

	// 테스트
	cout << solution(participant, completion) << endl;;

	return 0;
}
#elif PROB == 2
// [문제]
// 스파이들은 매일 다른
// 서로 다른 옷의 조합의 수를 구하시오.
// 의상의 수는 1개 이상 ~ 30개 이하
// 같은 이름을 가진 의상은 존재 x
// 의상 이름은 모두 문자열(1이상 20이하인 자연수)
// 하루에 최소 1개의 의상을 입는다.

// 중복 의상 x
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer{ 1 };

	unordered_map<string, int> clothes_pair{};

	// 각 부위별 옷의 개수를 구한다. key: 옷의 종류, value: 옷의 개수
	for (const auto& cloth_iter : clothes)
	{
		clothes_pair[cloth_iter[1]] += 1;
	}

	for (const auto& pair_iter : clothes_pair)
	{
		// (최소 한 개의 의상(1) + 부위별 의상의 개수)
		answer *= (1 + pair_iter.second);
	}

	return answer - 1;
}

int main()
{
	vector<vector<string>> clothes{ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };

	cout << solution(clothes) << endl;

	// for (auto& iter : clothes) cout << iter[1] << endl;

	return 0;
}


#elif PROB == 3
// 탐욕법(Greedy) - 체육복
// 탐욕법 알고리즘: 알고리즘의 각 단계에서 그 순간에 최적이라고 생각되는 것을 선택
// "정해진 순서"에 따라 우선하여 빌려줄 "방향을 설정"해야 한다.

// 여벌을 가져온 학생들을 처리한다. - (reserve)길이에 비례
// 체육복을 읽어버린 학생들을 처리한다. - (lost)길이에 비례
// 체육복 빌려주기를 처리한다. - 전체 학생 수 (n)에 비례


// (reserve)여분의 체육복을 가진 학생은 체육복을 앞, 뒤 학생에게만 빌려줄 수 있다.
// 최대한 많은 학생들이 체육수업을 들을 수 있도록 한다. (체육 수업을 듣기 위해 체육복이 필요함.)

// 도난당한 학생, 여분이 있는 학생 "중복"은 없다.

// 체육 수업을 들을 수 있는 학생 수 = 전체 학생 수(n) - 체육복을 도난당한 학생(lost)

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer{ 0 };

	// 범위: 체육복을 도난당한 학생들
	unordered_set<int> lost_students{ lost.begin(), lost.end() };

	// 범위: 여벌의 체육복을 가지고 있는 학생들
	set<int> share_students{};

	// 범위: 여벌의 체육복을 가지고 있는 학생들
	for (const auto& reserve_student : reserve)
	{
		// 여벌의 체육복을 가지고 있는 학생이 체육복을 도난당하지 않은 경우
		if (lost_students.find(reserve_student) == lost_students.end())
		{
			// 체육복을 빌려줄 수 있는 학생으로 분류한다.
			share_students.insert(reserve_student);
		}
		// 여벌의 체육복을 가지고 있는 학생이 체육복을 도난당한 경우
		else
		{
			// 체육복을 도난당한 목록에서 제외한다. → 도난을 당하였지만 수업은 들을 수 있음
			lost_students.erase(reserve_student);
		}
	}

	// 범위: 도난을 당하지 않고 여벌의 체육복을 가지고 있는 사람들
	for (const auto& share_student : share_students)
	{
		// 도난을 당하지 않고 여벌의 체육복을 가지고 있는 학생의 "앞 번호"가 체육복을 도난당한 학생일 때
		if (lost_students.find(share_student - 1) != lost_students.end())
		{
			// 앞 번호 학생에게 체육복을 빌려준다. → 수업을 들을 수 있음
			lost_students.erase(share_student - 1);
		}
		else if (lost_students.find(share_student + 1) != lost_students.end())
		{
			// 뒷 번호 학생에게 체육복을 빌려준다. → 수업을 들을 수 있음
			lost_students.erase(share_student + 1);
		}
	}

	// 체육 수업을 들을 수 있는 학생 수 = 전체 학생 수(n) - 체육복을 빌리지 못한 학생들
	answer = n - lost_students.size();

	return answer;
}

int main()
{
	cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;

	return 0;
}

#elif PROB == 4
// 그리디 알고리즘 - 큰수 만들기
#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k)
{
	string big_number = "";
	for (int index = 0; index < number.length(); ++index)
	{
		// 1. 현재까지 계산된 가장 큰 값이 들어있는 숫자 big_number가 존재하고
		// 2. 현재까지 계산된 가장 큰 값이 들어있는 숫자 가장 마지막으로 넣은 숫자가 number[index]보다 작고
		// 3. 제거할 수 있는 숫자의 개수가 0보다 클 때
		while (!big_number.empty() && big_number.back() < number[index] && k > 0)
		{
			// 현재까지 계산된 가장 큰 값(big_number)에서 가장 마지막에 삽입한 숫자를 삭제한다.
			big_number.pop_back();

			// 제거할 수 있는 숫자의 개수를 감소시킨다.
			k -= 1;
		}

		// 제거할 수의 개수가 0이면 연산을 종료한다.
		if (k == 0)
		{
			// 현재까지 계산된 가장 큰 값(big_number)에 남은 number의 뒷자리 숫자를 이어붙인다.
			big_number += number.substr(index, number.length() - index);
			break;
		}

		// number의 index번 째의 숫자를 가장 낮은 자리수에 이어붙인다.
		big_number.push_back(number[index]);
	}

	return big_number.substr(0, big_number.length() - k);
}

int main()
{
	cout << solution("4177252841", 4) << endl;

	return 0;
}
#elif PROB == 5
// [기지국]
#include <iostream>
#include <vector>
using namespace std;

// N개의 아파트가 일렬로 있다.
// 일부 아파트 옥상에는 4g 기지국이 설치되어 있다.
// 4g 기지국 전달 길이 > 5g 기지국 전달 길이

int solution(int n, vector<int> stations, int w)
{
	int answer{ 0 };

	// 전달 범위(길이)
	const int active_length{ w * 2 };
	// 설치할 위치의 첫 아파트 위치
	int install_index{ 1 };
	// Stations Index
	int stations_index{ 0 };

	while (install_index <= n)
	{
		if (install_index >= stations[stations_index] - w &&
			install_index <= stations[stations_index] + w)
		{
			install_index = stations[stations_index] + (w + 1);
			stations_index++;
		}
		else
		{
			install_index += (active_length + 1);
			answer++;
		}
	}

	return answer;
}

int main()
{
	cout << "[case 1]: " << solution(11, { 4, 11 }, 1) << "\n";  // result: 3
	cout << "[case 2]: " << solution(16, { 9 }, 2) << "\n";		 // result: 3

	return 0;
}

#endif
