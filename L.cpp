#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl
const int MOD = 1e9+7;
const int MAX = 1e7;
int fatorial[MAX];
 
void pre_calc_fatorial(int n){
  fatorial[0] = 1;
  for(int i=1; i <= n; i++){
    fatorial[i] = (fatorial[i-1] * i)%MOD;
  }
}
 
int exp(int a, int b){
	if(b == 0) return 1;
	int tmp = exp(a, b/2);
	tmp = (tmp * tmp)%MOD;
	if(b%2 == 1){
		tmp = (tmp * a)%MOD;
	}
	return tmp;
}
 
int modular_inverse(int a){
	return exp(a, MOD-2);
}
 
int comb(int n, int k){
    int numerator = fatorial[n];
    int denominator = (fatorial[k] * fatorial[n-k])%MOD;
    return (numerator * modular_inverse(denominator))%MOD;
}
 
 
void solve(){
    int n;
    cin>>n;
    int resp=0;
    pre_calc_fatorial(n);
    for(int i=0;i<=n;i++){
        int sup=comb(n,i);
        if(sup%2==1)resp++;
    }
    cout<<resp<<endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solve();
}