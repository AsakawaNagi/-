#include <stdio.h>

int arr[100][100]; // 直接申请最大可能空间
int dis[100];
int vis[100];
int pre[100]; // 记录前驱节点

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
        if (u == -1) break; // 如果没有可访问的节点，提前结束
        vis[u] = 1;// 找到每一个轮次最小的u，标记为已经访问标记u为已访问
        for (int v = 0; v < n; v++) {
            if (!vis[v] && dis[u] + arr[u][v] < dis[v]) {
                dis[v] = dis[u] + arr[u][v];
                pre[v] = u; // 记录前驱节点
            }
        }
    }
}

// 从最后一个节点开始，向前回溯
void print_path(int start, int end, int pre[]) {
    int path[100];  // 最多100个点
    int count = 0;

    int current = end;
    while (current != start) {
        path[count++] = current;  // 先加入当前点
        current = pre[current];   // 走向它的前驱
    }
    path[count++] = start;        // 最后加入起点

    // 倒着输出，得到正序路径
    for (int i = count - 1; i >= 0; i--) {
        printf("%d\n", path[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    array_input(n, arr);
    int start, end;
    scanf("%d %d", &start, &end);
    init_dijkstra(n);
//    array_output(n, arr);
    dijkstra(n);
//    result_output(n);
    print_path(start, end, pre); // 打印路径
    return 0;
}
