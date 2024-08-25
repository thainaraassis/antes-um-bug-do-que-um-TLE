#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int N, V;
    scanf("%lld%lld", &N, &V);
    int res = N * V;
    for(int i = 1; i <= 9; i++){
        printf("%lld ", (int) ceil(res * i * 0.1));
    }
    printf("\n");
}