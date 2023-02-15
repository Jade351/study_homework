#include<iostream>
using namespace std;
#define MAX 50
// 청소할 방의 상태
int room[MAX][MAX];
// 로봇 청소기 위치 x, y 와 방향 d
int p_r, p_c, p_d;
// 방의 행, 열 사이즈
int r, c;
// 청소 count
int cnt=0;
int cleaned[51][51] = {
    0,
}; //방문 시 2
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void rovot() 
{
    //동서남북, 왼쪽회전
    for (int i = 0; i < 4; i++)
    {
        int n_d = (p_d + 3 - i) % 4;
        int n_r = p_r + dr[n_d];
        int n_c = p_c + dc[n_d];
        //cout <<n_d << "a" << n_r << endl;
        // 다음 방향 지정, 그 방향 r, c 위치 받아옴
        if (n_r < 0 || n_r >= r || n_c < 0 || n_c >= c || room[n_r][n_c] == 1)
        {
            continue;

        } // 그곳이 벽일 때 계속

        //벽이 아니고 아직 청소 전이라면 그 공간 청소하고 회전
        if (room[n_r][n_c] == 0 && cleaned[n_r][n_c] == 0)
        {
            cleaned[n_r][n_c] = 2;
            p_r = n_r;
            p_c = n_c;
            p_d = n_d;
            cnt++;
            rovot();
        }
    }
        //청소 할 곳 없거나 청소 다했으면 Back
    int back_i = p_d>1 ? p_d-2 : p_d +2;
    int b_r = p_r + dr[back_i];
    int b_c = p_c + dc[back_i];
    //cout <<back_i << "a" << b_r << endl;
    if (b_r >= 0 && b_r <= r || b_c >= 0 || b_c <= c) 
    {
        if (room[b_r][b_c] == 0) 
        {
            p_r = b_r;
            p_c = b_c;
            rovot();
        }

        else
        {
            //for (int i = 0; i < r; i += 1)
            //{
             //   for (int j = 0; j < c; j += 1)
             //       cout << cleaned[i][j] << " ";
            //    cout << endl;
            //}
            cout << cnt << endl;
            exit(0);
        }
    }
        
}

int main(void) {
    cin >> r >> c;
    cin >> p_r >> p_c >> p_d;

    // 방 크기 입력 및 생성
    //room = new int* [r];
    //for (int i = 0; i < c; i += 1) {
    //    room[i] = new int[c] { 0, };
   // }

    // 청소할 방 입력받기
    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1)
            cin >> room[i][j];
    }
    cleaned[p_r][p_c] = 2;
    cnt++;
    rovot();



    return 0;
}
