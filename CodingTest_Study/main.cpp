#define PROB 5

#if PROB == 1
////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� ����
// ������ ������ �������� �����濡 �����Ͽ����ϴ�.�� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.
// 
// �����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
// 
// ���ѻ���
// ������ ��⿡ ������ ������ ���� 1�� �̻� 100, 000�� �����Դϴ�.
// completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
// �������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
// ������ �߿��� ���������� ���� �� �ֽ��ϴ�.
// ����� ��
// participant	completion	return
// ["leo", "kiki", "eden"]["eden", "kiki"]	"leo"
// ["marina", "josipa", "nikola", "vinko", "filipa"]["josipa", "filipa", "marina", "nikola"]	"vinko"
// ["mislav", "stanko", "mislav", "ana"]["stanko", "ana", "mislav"]	"mislav"
// ����� �� ����
// ���� #1
// "leo"�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.
// 
// ���� #2
// "vinko"�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.
// 
// ���� #3
// "mislav"�� ������ ��ܿ��� �� ���� ������, ������ ��ܿ��� �� ��ۿ� ���� ������ �Ѹ��� �������� ���߽��ϴ�.
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// 1. �ؽ� ���̺� : �׸� ���� �������� ȿ����, Ű�� ��ü ������ ������ ũ���� ��Ŷ�� ����.
// 2. std::map �� O(logN) �� binary search tree �� key ����O
// 3. std::unordered_map �� O(1) �� hash table �� key ����X
// 4. std::unordered_map �ߺ��� �����͸� ���X, map�� ���� �����Ͱ� ���� �� ������ ���� ����.
// 5. key�� ������ �����Ͱ� ���� �� �ؽ� �浹�� ���� ��������
// 6. ���: �ؽ����̺� ���� �� std::unordered_map ����Ͽ� ������ �ذ��� Best.

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

	// O(N)���� �۰ų� ����.
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

	// �׽�Ʈ
	cout << solution(participant, completion) << endl;;

	return 0;
}
#elif PROB == 2
// [����]
// �����̵��� ���� �ٸ�
// ���� �ٸ� ���� ������ ���� ���Ͻÿ�.
// �ǻ��� ���� 1�� �̻� ~ 30�� ����
// ���� �̸��� ���� �ǻ��� ���� x
// �ǻ� �̸��� ��� ���ڿ�(1�̻� 20������ �ڿ���)
// �Ϸ翡 �ּ� 1���� �ǻ��� �Դ´�.

// �ߺ� �ǻ� x
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer{ 1 };

	unordered_map<string, int> clothes_pair{};

	// �� ������ ���� ������ ���Ѵ�. key: ���� ����, value: ���� ����
	for (const auto& cloth_iter : clothes)
	{
		clothes_pair[cloth_iter[1]] += 1;
	}

	for (const auto& pair_iter : clothes_pair)
	{
		// (�ּ� �� ���� �ǻ�(1) + ������ �ǻ��� ����)
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
// Ž���(Greedy) - ü����
// Ž��� �˰���: �˰����� �� �ܰ迡�� �� ������ �����̶�� �����Ǵ� ���� ����
// "������ ����"�� ���� �켱�Ͽ� ������ "������ ����"�ؾ� �Ѵ�.

// ������ ������ �л����� ó���Ѵ�. - (reserve)���̿� ���
// ü������ �о���� �л����� ó���Ѵ�. - (lost)���̿� ���
// ü���� �����ֱ⸦ ó���Ѵ�. - ��ü �л� �� (n)�� ���


// (reserve)������ ü������ ���� �л��� ü������ ��, �� �л����Ը� ������ �� �ִ�.
// �ִ��� ���� �л����� ü�������� ���� �� �ֵ��� �Ѵ�. (ü�� ������ ��� ���� ü������ �ʿ���.)

// �������� �л�, ������ �ִ� �л� "�ߺ�"�� ����.

// ü�� ������ ���� �� �ִ� �л� �� = ��ü �л� ��(n) - ü������ �������� �л�(lost)

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer{ 0 };

	// ����: ü������ �������� �л���
	unordered_set<int> lost_students{ lost.begin(), lost.end() };

	// ����: ������ ü������ ������ �ִ� �л���
	set<int> share_students{};

	// ����: ������ ü������ ������ �ִ� �л���
	for (const auto& reserve_student : reserve)
	{
		// ������ ü������ ������ �ִ� �л��� ü������ ���������� ���� ���
		if (lost_students.find(reserve_student) == lost_students.end())
		{
			// ü������ ������ �� �ִ� �л����� �з��Ѵ�.
			share_students.insert(reserve_student);
		}
		// ������ ü������ ������ �ִ� �л��� ü������ �������� ���
		else
		{
			// ü������ �������� ��Ͽ��� �����Ѵ�. �� ������ ���Ͽ����� ������ ���� �� ����
			lost_students.erase(reserve_student);
		}
	}

	// ����: ������ ������ �ʰ� ������ ü������ ������ �ִ� �����
	for (const auto& share_student : share_students)
	{
		// ������ ������ �ʰ� ������ ü������ ������ �ִ� �л��� "�� ��ȣ"�� ü������ �������� �л��� ��
		if (lost_students.find(share_student - 1) != lost_students.end())
		{
			// �� ��ȣ �л����� ü������ �����ش�. �� ������ ���� �� ����
			lost_students.erase(share_student - 1);
		}
		else if (lost_students.find(share_student + 1) != lost_students.end())
		{
			// �� ��ȣ �л����� ü������ �����ش�. �� ������ ���� �� ����
			lost_students.erase(share_student + 1);
		}
	}

	// ü�� ������ ���� �� �ִ� �л� �� = ��ü �л� ��(n) - ü������ ������ ���� �л���
	answer = n - lost_students.size();

	return answer;
}

int main()
{
	cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;

	return 0;
}

#elif PROB == 4
// �׸��� �˰��� - ū�� �����
#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k)
{
	string big_number = "";
	for (int index = 0; index < number.length(); ++index)
	{
		// 1. ������� ���� ���� ū ���� ����ִ� ���� big_number�� �����ϰ�
		// 2. ������� ���� ���� ū ���� ����ִ� ���� ���� ���������� ���� ���ڰ� number[index]���� �۰�
		// 3. ������ �� �ִ� ������ ������ 0���� Ŭ ��
		while (!big_number.empty() && big_number.back() < number[index] && k > 0)
		{
			// ������� ���� ���� ū ��(big_number)���� ���� �������� ������ ���ڸ� �����Ѵ�.
			big_number.pop_back();

			// ������ �� �ִ� ������ ������ ���ҽ�Ų��.
			k -= 1;
		}

		// ������ ���� ������ 0�̸� ������ �����Ѵ�.
		if (k == 0)
		{
			// ������� ���� ���� ū ��(big_number)�� ���� number�� ���ڸ� ���ڸ� �̾���δ�.
			big_number += number.substr(index, number.length() - index);
			break;
		}

		// number�� index�� °�� ���ڸ� ���� ���� �ڸ����� �̾���δ�.
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
// [������]
#include <iostream>
#include <vector>
using namespace std;

// N���� ����Ʈ�� �Ϸķ� �ִ�.
// �Ϻ� ����Ʈ ���󿡴� 4g �������� ��ġ�Ǿ� �ִ�.
// 4g ������ ���� ���� > 5g ������ ���� ����

int solution(int n, vector<int> stations, int w)
{
	int answer{ 0 };

	// ���� ����(����)
	const int active_length{ w * 2 };
	// ��ġ�� ��ġ�� ù ����Ʈ ��ġ
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
