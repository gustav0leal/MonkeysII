#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int field[N][N];
int vis[N];
int match[N];
int n, m;

int aug(int x){
    if(vis[x]){
        return 0;
    }

    vis[x] = 1;

    for(int i = 0 ; i < m ; i++){
        if(field[x][i]){
            if(match[i] == -1 || aug(match[i])){
                match[i] = x;
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    scanf("%d %d", &n, &m);

    int easter_cnt = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            char c;

            scanf("\n%c", &c);

            field[i][j] = c - '0';

            easter_cnt += field[i][j];
        }
    }

    memset(match, -1, sizeof match);

    int mcbm = 0;

    for(int i = 0 ; i < n ; i++){
        memset(vis, 0, sizeof vis);

        if(aug(i)){
            mcbm++;
        }
    }

    printf("%d\n", easter_cnt - mcbm);

    return 0;
}