#include <stdio.h>

int arr[100][100]; // 直接申请最大可能空间
int dis[100];
int vis[100];

void array_input(int n, int arr[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}
void array_output(int n, int arr[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void result_output(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", dis[i]);
    }
}

// 矩阵必须要初始化
void init_dijkstra(int n) {
    for (int i = 0; i < n; i++) {
        dis[i] = arr[0][i];
        vis[i] = 0;
    }
    dis[0] = 0;
    vis[0] = 1;
}

void dijkstra(int n) {
    for(int count=0;count<n;count++){
        int min_num = 10000;
        int u = -1;
        for(int i=0;i<n;i++){
            if(vis[i]==0 && dis[i]<min_num){
                min_num = dis[i];
                u = i;
            }
        }
        vis[u] = 1;// 找到每一个轮次最小的u，标记为已经访问标记u为已访问
        for (int v = 0; v < n; v++) {
            if (!vis[v] && dis[u] + arr[u][v] < dis[v]) {
                dis[v] = dis[u] + arr[u][v];
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    array_input(n, arr);
    init_dijkstra(n);
//    array_output(n, arr);
    dijkstra(n);
    result_output(n);
    return 0;
}
