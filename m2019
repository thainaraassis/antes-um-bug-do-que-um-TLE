#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl

int q[(int)2e5+7];
int popcorn[(int )2e5+7];
int n,c,t;

bool check(int mid){
    int comp=1;
    int pop=0;
    for(int i=0;i<n;i++){
        if(q[i]>mid) return false;
        else if(pop+q[i]>mid){
            pop=0;
            comp++;
            pop=q[i];

        }
        else{
            pop+=q[i];
        }
    }
    if(comp>c)return false;
    // dbg(mid);
    return true;
}

int buscabinaria(int lo, int hi){
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid))hi=mid-1;
        else lo=mid+1;
    }
    // dbg(lo,hi);
    if(check(lo))return lo;
    else return lo+1;
}



void solve(){
    cin>>n>>c>>t;
    int quantidade=0;
    for(int i=0;i<n;i++){
        cin>>popcorn[i];
        if(popcorn[i]%t==0)q[i]=popcorn[i]/t;
        else q[i]=popcorn[i]/t +1;
        // cout<<q[i]<<endl;
    }
    quantidade=buscabinaria(0,(int)1e10);
    cout<<quantidade<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solve();
}
