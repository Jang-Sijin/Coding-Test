#define PROB 11

// [DP]
// Ʈ��, ����, ���
// ū ������ ���� ������ �ɰ� �� �ִ°� ?
// ��� Ȥ�� �ݺ������� �ذ��� �� ����.

#if PROB == 1
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    return answer;
}
#elif PROB == 2
// [��� - DP]
// DP�� ū ������ ���� ������(��ȭ�� ����) �ذ��ϴ� ����� �ǹ��Ѵ�.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
   int answer = 0;

   vector<vector<int>> v;

   vector<vector<int>> puddles_list;

   cout << puddles.size() << endl;

   for (int i = 0; puddles.size(); ++i)
   {
       // puddles_list[i] = 1;
       cout << i << ", " << endl;
       //for (int j = 0; puddles[i].size(); ++j)
       //{
       //    puddles_list[i][j] = 1;
       //    cout << i << ", " << j << endl;
       //}
   }




    // �б� ���ʱ��� ���� ��� ���� + ������ �����ϴ� ��� ����
   // �ִܰ���� ������ 1, 000, 000, 007�� ���� �������� return
   return answer % 1000000007;
}

int main()
{
    solution(4, 2, { {2,2}, {3,3}, {4,4} }); // return 4

    return 0;
}
#elif PROB == 3
#include <iostream>
#include <vector>
using namespace std;
// [��ܿ����� - DP]
// ���ӹ�� �Ұ���, ù ��ܰ� �� ����� �� ��ƾ� �Ѵ�.

bool isOne{ false };
bool isDouble{ false };

int DP(int x)
{
    if (x == 1) return 1;
    else if (x == 2) return 2;
    else if (x == 3) return 3;

    if (isOne == false)
    {

    }
    else 
    {

    }
    
    if (isDouble)
    {

    }
    else
    {

    }

    return 
}

int main()
{
    int count{};
    int input{};
    vector<int> v{};

    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        cin >> input;
        v.push_back(input);
    }

    // 1. ������ ��ܿ��� 1 ���� �̵�
    for (int i = v.size() - 1; i <= 0;)
    {
        
    }
    
    // 2. ������ ��ܿ��� 2 ���� �̵�

    // 3. MAX(2���� �̵� vs 1���� �̵�)

    return 0;
}
#elif PROB == 4
// [�����ѷ� - DP]
#include <iostream>
using namespace std;

int main()
{


    return 0;
}
#elif PROB == 5
// [2021 ���� �϶� �ּ�ȭ - DP]
#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    Node(int number)
    {
        int id = number;
    }
private:
    int id;
    map<int, Node> children;
};

int main()
{
    return 0;
}
#elif PROB == 6
#include <iostream>
using namespace std;
// 1260��: DFS�� BFS, [https://www.acmicpc.net/problem/1260]
// ���� 4, ���� 5, ���� 1

// void DFS()
int main()
{
    int vertex;
    int edge;
    int start_vertex;

    cin >> vertex >> edge >> start_vertex;

    for (int i = 0; i < edge; ++i)
    {

    }
    // [�⺻�� �Ǵ� ����]
    // DFS:���, ����, BFS:ť



    return 0;
}
#elif PROB == 7
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(string start_port, vector<vector<string>> tickets, vector<string>& answer, vector<bool>& visit, int next_ticket)
{
    // ������ �Ѵٴ� ���� ������ ���� �غ� ���̶�� ������ �� �ִ�.
}

vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> answer;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());

    DFS("ICN", tickets, answer, visit, 0);

    return answer;
}

int main()
{
    solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} }); // return: ["ICN", "JFK", "HND", "IAD"]
    // solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}} ); // return: ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]

    return 0;
}
#elif PROB == 8
// [��� �̵��ϱ�]
// 16���� ���� ���ǿ� ���ؼ� ó������ �Ǵ��� �ʿ��ϴ�.
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) 
{
    int answer = 0;
    vector<vector<int>> check_board{};



    return answer;
}

int main()
{
    solution({ {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0} }); // result: 7

    return 0;
}
#elif PROB == 9
// [���̷̹�-BFS] http://210.93.60.51/problem/0033
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct position
{
    int x; // ��, �� ��ġ
    int y; // ��, �� ��ġ
    int direction; // ��, ��, ��, �� �̵��� ����
};

int solution(const int m, const int n, vector<vector<string>> board)
{
    int answer{};

    // [������ ���]
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {            
            cout << board[i][j];
        }       
        cout << endl;
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < visited.size(); ++i)
    {
        for (int j = 0; j < visited[i].size(); ++j)
        {
            cout << visited[i][j];
        }
        cout << endl;
    }

    return answer;
}

int main()
{
    solution(7, 8, { {".",".",".",".",".",".",".","."},{".","L","R","S",".","L",".","."},{".",".",".",".",".",".","L","."},
        {"G",".","L",".",".","R",".","."},{".",".","R",".","R",".",".","."},{".",".",".",".",".",".","S","."},
        {".",".",".",".",".",".",".","."}});

    return 0;
}
#elif PROB == 10
// [ī�� ¦ ���߱�]
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, int r, int c) 
{
    int answer = 0;

    // bfs, dfs
    // visited �迭�� �ʿ��� -> �湮 ���θ� �˾ƾ� �Ѵ�.

    return answer;
}

int main()
{
    solution({{1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0}}, 1, 0); // return: 14
    solution({{3, 0, 0, 2}, {0, 0, 1, 0}, {0, 1, 0, 0}, {2, 0, 0, 3}}, 0, 1); // return: 16

    return 0;
}

#elif PROB 11
#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "������ �Դϴ�." << std::endl;
    }
    MyClass(MyClass& copy)
    {
        std::cout << "���� ������ �Դϴ�." << std::endl;
    }
};

int main()
{
    std::cout << "A" << std::endl;
    MyClass A();

    std::cout << "B" << std::endl;
    MyClass B;

    std::cout << "C = B" << std::endl;
    MyClass C = B;

    std::cout << "D{ B }" << std::endl;
    MyClass D{ B };

    return 0;
}
#endif