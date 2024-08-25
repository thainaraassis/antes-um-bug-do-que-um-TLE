#include <bits/stdc++.h>
using namespace std;
#define int long long

int maior = 0, N;
vector<int> res, intermediario;
int vis[101][101];
int input[101][101];

void dp(int niv, int at){
    if(niv < N){
        for(int i = 0; i < N; i++){
            if(vis[niv][i] == false){
                intermediario.push_back(i);
                vis[niv][i] = true;
                    dp(niv + 1, at*input[niv][i]);
                vis[niv][i] = false;
                intermediario.pop_back();
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
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            scanf("%lld", &x);
            input[i][j] = x;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            scanf("%lld", &x);
            vis[i][j] = false;
        }
    }
    dp(-1, 1);
    for(int i = 0; i < N; i++){
        printf("%lld ", res[i]);
    }
    printf("\n");
}