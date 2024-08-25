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

// problema 
int n, c, t;
vector<int> p(1e5 + 1);

bool verifica(int mid) {
    int compet = 1;
    int soma = 0;

    for(int i = 0; i < n; i++) {
        if(p[i] > mid * t) return false; // um competidor não consegue comer o saco no tempo
        if(soma + p[i] <= mid * t) soma += p[i]; // competidor pode comer mais de um saco no tempo
        else {
            soma = p[i]; // vai começar a verificar quantos sacos o próximo competidor pode comer
            compet++;
        }
    }

    if(compet <= c) return true;
    return false;
}

int main(){ 

    cin >> n >> c >> t;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }

    int i = 1;
    int f = sum/t + 2;

    while (i < f) {
        int m = (i + f) / 2;
        if (verifica(m)) f = m;
        else i = m + 1;
    }

    cout << i << "\n";

    return 0;
}