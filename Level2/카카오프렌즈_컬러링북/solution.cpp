#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    // 방문 여부를 체크할 2차원 배열 (false로 초기화)
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // 상, 하, 좌, 우 이동을 위한 방향 배열
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 그림판의 모든 칸을 하나씩 확인
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 빈 칸(0)이 아니고, 아직 방문하지 않은 칸을 발견하면 새로운 영역 시작!
            if (picture[i][j] != 0 && !visited[i][j]) {
                number_of_area++; // 영역 개수 +1
                
                int current_color = picture[i][j]; // 현재 영역의 색상
                int current_area_size = 0;         // 현재 영역의 넓이
                
                // BFS(너비 우선 탐색)를 위한 큐 생성
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                // 큐가 빌 때까지 연결된 같은 색상의 칸들을 탐색
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    current_area_size++; // 칸 하나를 확인했으므로 넓이 +1

                    // 상, 하, 좌, 우 4방향 확인
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        // 그림판 범위를 벗어나지 않는지 확인
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            // 아직 방문 안 했고 + 같은 색깔인 칸이라면
                            if (!visited[nx][ny] && picture[nx][ny] == current_color) {
                                visited[nx][ny] = true; // 방문 표시
                                q.push({nx, ny});       // 다음 탐색을 위해 큐에 넣음
                            }
                        }
                    }
                }

                // 가장 큰 영역의 넓이 갱신
                max_size_of_one_area = max(max_size_of_one_area, current_area_size);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
