#include <stdio.h>

int arr[100][100]; // 邻接矩阵，直接用作 Floyd 的 dist 矩阵

void array_input(int n, int arr[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void floyd(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 防止溢出：避免两个无穷相加变成负数
                if (arr[i][k] != 10000 && arr[k][j] != 10000 && arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    array_input(n, arr);

    floyd(n);

    int m;
    scanf("%d", &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", arr[u][v]);
    }

    return 0;
}
