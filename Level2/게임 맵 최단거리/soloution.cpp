#include<vector>
#include<queue>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int> dist(n, vector<int>(m, 0));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop()
        
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if(maps[nr][nc] == 0)
                continue;
            if(dist[nr][nc] != 0)
                continue;
            
            dist[nr][nc] = dist[r][c] + 1;
            p.push({nr, nc});
        }
    }
    
    
}
