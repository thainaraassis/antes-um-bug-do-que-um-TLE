#include <bits/stdc++.h> 
using namespace std;  

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ 
    int n;
    int max = 0;
    cin >> n;
    vector<int> v(n+1);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] >= max) max = v[i];
    }

    if(v[0] == max) cout << 'S' << "\n";
    else cout << "N" << "\n";

    return 0;
}