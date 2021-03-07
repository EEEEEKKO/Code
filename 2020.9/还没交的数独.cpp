#include<bits/stdc++.h>

using namespace std;

char map_m[18][18], map_copy[18][18];
int square[4][4], check[16];
char temp[4][4], lie[16];
int flag = 0;

int check_r(int r) {
    memset(check, 0, sizeof(check));
    for (int i = 0; i < 16; i++) {
        char ch = map_m[r][i];
        if (ch == '0') check[0]++; if (ch == '1') check[1]++;
        if (ch == '2') check[2]++; if (ch == '3') check[3]++;
        if (ch == '4') check[4]++; if (ch == '5') check[5]++;
        if (ch == '6') check[6]++; if (ch == '7') check[7]++;
        if (ch == '8') check[8]++; if (ch == '9') check[9]++;
        if (ch == 'A') check[10]++; if (ch == 'B') check[11]++;
        if (ch == 'C') check[12]++; if (ch == 'D') check[13]++;
        if (ch == 'E') check[14]++; if (ch == 'F') check[15]++;
    }
    for (int i = 0; i < 16; i++) {
        if (check[i] == 0 || check[i] > 1) return 0;
    }
    return 1;
}

int check_l() {
    memset(check, 0, sizeof(check));
    for (int i = 0; i < 16; i++) {
        char ch = lie[i];
        if (ch == '0') check[0]++; if (ch == '1') check[1]++;
        if (ch == '2') check[2]++; if (ch == '3') check[3]++;
        if (ch == '4') check[4]++; if (ch == '5') check[5]++;
        if (ch == '6') check[6]++; if (ch == '7') check[7]++;
        if (ch == '8') check[8]++; if (ch == '9') check[9]++;
        if (ch == 'A') check[10]++; if (ch == 'B') check[11]++;
        if (ch == 'C') check[12]++; if (ch == 'D') check[13]++;
        if (ch == 'E') check[14]++; if (ch == 'F') check[15]++;
    }
    for (int i = 0; i < 16; i++) {
        if (check[i] == 0 || check[i] > 1) return 0;
    }
    return 1;
}

int rotation(int t, int r, int n) {
    for (int i = 0; i < t; i++) {
        for (int j = 3; j >= 0; j--) {
            for (int k = 0; k < 4; k++) {
                temp[3 - j][k] = map_m[k + (r - 1) * 4][j + (n - 1) * 4];
            }
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                map_m[j + (r - 1) * 4][k + (n - 1) * 4] = temp[j][k];
            }
        }
    }
    square[r - 1][n - 1] = t;
    return 0;
}

int reverse(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            map_m[(x - 1) * 4 + i][(y - 1) * 4 + j] = map_copy[(x - 1) * 4 + i][(y - 1) * 4 + j];
        }
    }
    return 0;
}

int dfs(int r, int n) {
    if (flag == 1)
        return 0;
    if (n == 4) {
        for (int i = 0; i < 4; i++) {
            rotation(i, r, n);
            if (check_r((r - 1) * 4) == 1) {
                flag = 1;
                return 0;
            }
            else {
                reverse(r, n);
                square[r - 1][n - 1] = 0;
            }
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            rotation(i, r, n);
            dfs(r, n + 1);
            if (check_r((r - 1) * 4) == 1) {
                flag = 1;
                return 0;
            }
            else {
                reverse(r, n);
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        flag = 0;
        for (int i = 0; i < 16; i++) {
            scanf("%s", &map_m[i]);
            for (int j = 0; j < 16; j++) {
                map_copy[i][j] = map_m[i][j];
            }
        }
        for (int i = 1; i < 5; i++) {
            flag = 0;
            dfs(i, 1);
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int m = 0; m < 2; m++) {
                        lie[0] = map_m[0][0 + i * 3]; lie[1] = map_m[1][0 + i * 3];
                        lie[2] = map_m[2][0 + i * 3]; lie[3] = map_m[3][0 + i * 3];
                        lie[4] = map_m[4][0 + j * 3]; lie[5] = map_m[5][0 + j * 3];
                        lie[6] = map_m[6][0 + j * 3]; lie[7] = map_m[7][0 + j * 3];
                        lie[8] = map_m[8][0 + k * 3]; lie[9] = map_m[9][0 + k * 3];
                        lie[10] = map_m[10][0 + k * 3]; lie[11] = map_m[11][0 + k * 3];
                        lie[12] = map_m[12][0 + m * 3]; lie[13] = map_m[13][0 + m * 3];
                        lie[14] = map_m[14][0 + m * 3]; lie[15] = map_m[15][0 + m * 3];
                        if (check_l() == 1)
                            goto k;
                        for (int m = 0; m < 4; m++) {
                            square[3][m] = (square[3][m] + 2) % 4;
                        }
                    }
                    for (int m = 0; m < 4; m++) {
                        square[2][m] = (square[2][m] + 2) % 4;
                    }
                }
                for (int m = 0; m < 4; m++) {
                    square[1][m] = (square[1][m] + 2) % 4;
                }
            }
            for (int m = 0; m < 4; m++) {
                square[0][m] = (square[0][m] + 2) % 4;
            }
        }

    k:
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                sum1 = square[i][j] + sum1;
                sum2 = (square[i][j] + 2) % 4 + sum2;
            }
        if (sum1 < sum2) {
            printf("%d\n", sum1);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < square[i][j]; k++) {
                        printf("%d %d\n", i + 1, j + 1);
                    }
                }
            }
        }
        else {
            printf("%d\n", sum2);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < (square[i][j] + 2) % 4; k++) {
                        printf("%d %d\n", i + 1, j + 1);
                    }
                }
            }
        }
    }
}
