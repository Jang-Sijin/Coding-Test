#define PROB 4

#if PROB == 1
// [�ߺ� �����ϱ�]
SELECT COUNT(DISTINCT NAME) AS count
FROM ANIMAL_INS
WHERE NAME IS NOT NULL

#elif PROB == 2
// [���� �� ���ϱ�]
SELECT count(*) as count
FROM ANIMAL_INS

#elif PROB == 3
// [�ּڰ� ���ϱ�]
SELECT DATETIME as "�ð�"
FROM ANIMAL_INS
ORDER BY DATETIME ASC
LIMIT 1

#elif PROB == 4
// [�ִ񰪰� �ּڰ�]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> GetSplit(string s)
{
    vector<string> result;
    int i = 0;
    while (s[i] > s.length())
    {
        if (s[i] == ' ')
        {
            string front = s.substr(0, i);
            result.push_back(front);
            s = s.substr(i + 1, s.length());
        }

        i++;
    }

    return result;
}

string solution(string s) 
{
    string answer = "";

    vector<string> ss = GetSplit(s);

    for (auto n : ss)
    {
        cout << n << endl;
    }

    return answer;
}

int main()
{
    solution("1 2 3 4"); // result: "1 4"
    solution("-1 -2 -3 -4"); // result: "-4 -1"
    solution("-1 -1"); // result: "-1 -1"

    return 0;
}
#endif