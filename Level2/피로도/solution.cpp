#include <vector>
using namespace std;

int answer = 0;    // 최고 기록 넣어둘 전역 변수
bool visited[8];    // 던전 방문 표시를 위한 배열

void dfs(int k, vector<vector<int>>& dungeons, int count)
{
    if(count > answer)    //지금까지 돈 던전의 수가 최고기록 보다 많으면 경신
        answer = count;
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(!visited[i] && k >= dungeons[i][0])  // 아직 방문하지 않은 던전이고, 현재 피로도와 작거나 같은 던전이면 true
        {
            visited[i] = true;                  // 던전 방문 표시
            dfs(k - dungeons[i][1], dungeons, count + 1);  // dfs함수에 매개변수 넘겨주면서 호출(남은 피로도, 던전 목록, 기록)
            visited[i] = false;  //dfs 함수 종료 시 다음 경우의 수 확인을 위해 다시 false로 방문 표시 지우기
                                // 그대로 두면 다른 경우의 수 진행 시 진행이 안 됨
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    dfs(k, dungeons, 0);    // 처음 출발 할 때 돈 던전의 개수는 0개니까 0
    return answer;
}
