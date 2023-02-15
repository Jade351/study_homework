#include<iostream>
using namespace std;
#define MAX 50
// û���� ���� ����
int room[MAX][MAX];
// �κ� û�ұ� ��ġ x, y �� ���� d
int p_r, p_c, p_d;
// ���� ��, �� ������
int r, c;
// û�� count
int cnt=0;
int cleaned[51][51] = {
    0,
}; //�湮 �� 2
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void rovot() 
{
    //��������, ����ȸ��
    for (int i = 0; i < 4; i++)
    {
        int n_d = (p_d + 3 - i) % 4;
        int n_r = p_r + dr[n_d];
        int n_c = p_c + dc[n_d];
        //cout <<n_d << "a" << n_r << endl;
        // ���� ���� ����, �� ���� r, c ��ġ �޾ƿ�
        if (n_r < 0 || n_r >= r || n_c < 0 || n_c >= c || room[n_r][n_c] == 1)
        {
            continue;

        } // �װ��� ���� �� ���

        //���� �ƴϰ� ���� û�� ���̶�� �� ���� û���ϰ� ȸ��
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
        //û�� �� �� ���ų� û�� �������� Back
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

    // �� ũ�� �Է� �� ����
    //room = new int* [r];
    //for (int i = 0; i < c; i += 1) {
    //    room[i] = new int[c] { 0, };
   // }

    // û���� �� �Է¹ޱ�
    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1)
            cin >> room[i][j];
    }
    cleaned[p_r][p_c] = 2;
    cnt++;
    rovot();



    return 0;
}
