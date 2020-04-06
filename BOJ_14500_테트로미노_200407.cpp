/* 14500. 테트로미노 Gold V
 https://www.acmicpc.net/problem/14500
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    int paper[N][M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> paper[i][j];
        }
    }
    
    int dir[19][3][2] = {
        {{0, 1}, {0, 2}, {0, 3}}, //가로 4칸
        {{1, 0}, {2, 0}, {3, 0}}, //세로 4칸
        {{0, 1}, {1, 0}, {1, 1}}, //네모
        {{0, 1}, {0, 2}, {1, 1}}, //가운데 돌출 아래로
        {{0, 1}, {0, 2}, {-1, 1}}, //가운데 돌출 위로
        {{1, 0}, {2, 0}, {1, -1}}, //가운데 돌출 왼쪽
        {{1, 0}, {2, 0}, {1, 1}}, //가운데 돌출 오른쪽
        {{1, 0}, {2, 0}, {2, 1}}, //세로 끝 돌출 오른쪽 아래
        {{1, 0}, {2, 0}, {2, -1}}, //세로 끝 돌출 왼쪽 아래
        {{1, 0}, {2, 0}, {0, 1}}, //세로 끝 돌출 오른쪽 위
        {{1, 0}, {2, 0}, {0, -1}}, //세로 끝 돌출 왼쪽 위
        {{0, 1}, {0, 2}, {1, 2}}, //가로 끝 돌출 오른쪽 아래
        {{0, 1}, {0, 2}, {-1, 2}}, //가로 끝 돌출 오른쪽 위
        {{0, 1}, {0, 2}, {1, 0}}, //가로 끝 돌출 왼쪽 아래
        {{0, 1}, {0, 2}, {-1, 0}}, //가로 끝 돌출 왼쪽 위
        {{1, 0}, {1, 1}, {2, 1}}, //지그재그 기본형
        {{1, 0}, {1, -1}, {2, -1}}, //지그재그 세로 대칭
        {{0, 1}, {-1, 1}, {-1, 2}}, //지그재그 가로
        {{0, 1}, {1, 1}, {1, 2}}, //지그재그 가로 대칭
    };
    int answer = 0, tmp;
    bool flag;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) { //각 칸에서 시작
            for (int d = 0; d<19; d++) { //가능한 모든 모양 테스트
                tmp = paper[i][j];
                flag = true;
                for (int k=0; k<3; k++) {
                    int ni =i+dir[d][k][0], nj =j+dir[d][k][1];
                    if (ni < 0 || nj < 0 || ni >= N || nj >= M) { //범위 초과
                        flag = false;
                        break;
                    }
                    tmp += paper[ni][nj];
                }
                if (flag && answer < tmp) { //갱신 : 테트로미노 놓을 수 있어야 함
                    answer = tmp;
                }
            } //모양 테스트 끝
        }
    }
    cout << answer;
}
