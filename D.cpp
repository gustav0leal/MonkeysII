#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 8;
const int M = int(1e4) + 10;
int dis[N];
int table[M];
int n, m, q;

void bfs(){
    memset(dis, -1, sizeof dis);

    dis[0] = 0;

    queue< int > q;

    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < m ; i++){
            if(dis[u ^ table[i]] == -1){
                dis[u ^ table[i]] = dis[u] + 1;
                q.push(u ^ table[i]);
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            char c;

            scanf("\n%c", &c);

            if(c == '1'){
                table[i] |= (1 << j);
            }
        }
    }

    bfs();

    for(int i = 0 ; i < q ; i++){
        int qu = 0;

        for(int j = 0 ; j < n ; j++){
            char c;

            scanf("\n%c", &c);

            if(c == '1'){
                qu |= (1 << j);
            }
        }

        printf("%d\n", dis[qu]);
    }

    return 0;
}