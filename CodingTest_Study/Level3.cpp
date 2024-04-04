#define PROB 11

// [DP]
// 트리, 격자, 계단
// 큰 문제를 작은 단위로 쪼갤 수 있는가 ?
// 재귀 혹은 반복문으로 해결할 수 있음.

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
// [등굣길 - DP]
// DP는 큰 문제를 작은 문제로(점화식 형태) 해결하는 방식을 의미한다.
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




    // 학교 왼쪽까지 가는 경로 개수 + 위에서 접근하는 경로 개수
   // 최단경로의 개수를 1, 000, 000, 007로 나눈 나머지를 return
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
// [계단오르기 - DP]
// 연속밟기 불가능, 첫 계단과 끝 계단은 꼭 밟아야 한다.

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

    // 1. 마지막 계단에서 1 점핑 이동
    for (int i = v.size() - 1; i <= 0;)
    {
        
    }
    
    // 2. 마지막 계단에서 2 점핑 이동

    // 3. MAX(2점핑 이동 vs 1점핑 이동)

    return 0;
}
#elif PROB == 4
// [목재총량 - DP]
#include <iostream>
using namespace std;

int main()
{


    return 0;
}
#elif PROB == 5
// [2021 매출 하락 최소화 - DP]
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
// 1260번: DFS와 BFS, [https://www.acmicpc.net/problem/1260]
// 정점 4, 간선 5, 시작 1

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
    // [기본이 되는 유형]
    // DFS:재귀, 스택, BFS:큐



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
    // 질문을 한다는 것은 생각을 많이 해본 것이라고 생각할 수 있다.
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
// [블록 이동하기]
// 16개의 방향 조건에 대해서 처리조건 판단이 필요하다.
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
// [개미미로-BFS] http://210.93.60.51/problem/0033
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct position
{
    int x; // 좌, 우 위치
    int y; // 상, 하 위치
    int direction; // 상, 하, 좌, 우 이동한 방향
};

int solution(const int m, const int n, vector<vector<string>> board)
{
    int answer{};

    // [보드판 출력]
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
// [카드 짝 맞추기]
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, int r, int c) 
{
    int answer = 0;

    // bfs, dfs
    // visited 배열이 필요함 -> 방문 여부를 알아야 한다.

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
        std::cout << "생성자 입니다." << std::endl;
    }
    MyClass(MyClass& copy)
    {
        std::cout << "복사 생성자 입니다." << std::endl;
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