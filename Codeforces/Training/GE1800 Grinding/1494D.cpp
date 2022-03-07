#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e2 + 10;
const int MX = 5e3 + 10;

int n;
int ar[N][N];
vector<int> salary;
vector<pii> lca[MX];

int dpar[N * N]; // direct parent
int par[N * N]; // union parent
int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b, int psal){ // b becomes a's group
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (salary[a] == psal && salary[b] == psal){
        return;
    } else if (salary[a] == psal || salary[b] == psal){
        if (salary[b] == psal) swap(a, b);
        dpar[b] = a;
        par[b] = a;
    } else{
        int c = salary.size();
        salary.pb(psal);
        dpar[a] = dpar[b] = c;
        par[a] = par[b] = c;
    }
}
void init(){
    for (int i=0;i<N * N;i++){
        dpar[i] = i;
        par[i] = i;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    salary.pb(-1); // dummy
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
            if (i == j) salary.pb(ar[i][j]);
            else if (i < j) lca[ar[i][j]].pb(mp(i, j));
        }
    }
    init();
    for (int i=1;i<=5000;i++){
        for (auto& x : lca[i]){
            int a = x.fi;
            int b = x.se;
            make(a, b, i);
        }
    }
    int len = (int)salary.size() - 1;
    cout << len << el;
    for (int i=1;i<=len;i++){
        cout << salary[i] << ' ';
    }
    cout << el;
    for (int i=1;i<=len;i++){
        if (dpar[i] == i) cout << i << el;
    }
    for (int i=1;i<=len;i++){
        if (dpar[i] != i) cout << i << ' ' << dpar[i] << el;
    }

    return 0;
}