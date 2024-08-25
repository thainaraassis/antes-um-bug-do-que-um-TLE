#include <bits/stdc++.h>
using namespace std;
#define int long long

int maior = 0, N;
vector<int> res, intermediario;
int vis[101];
int input[101][101];

void dp(int niv, int at){
    if(niv < N){
        for(int i = 0; i < N; i++){
            if(vis[i] == false){
                intermediario[i] = niv + 1;
                vis[i] = true;
                    dp(niv + 1, at*input[niv][i]);
                vis[i] = false;
            }
        }
    }
    else{
        if(at > maior){
            maior = at;
            for(int i = 0; i < N; i++){
                res[i] = intermediario[i];
            }
        }
    }
}

signed main(){
    scanf("%lld", &N);
    res.resize(N);
    intermediario.resize(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            scanf("%lld", &x);
            input[i][j] = x;
        }
    }
    for(int i = 0; i < N; i++){
        vis[i] = false;
    }
    dp(0, 1);
    for(int i = 0; i < N; i++){
        printf("%lld ", res[i]);
    }
    printf("\n");
}
