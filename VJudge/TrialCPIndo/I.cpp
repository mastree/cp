#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 3e2 + 10;

int n;
int ar[N];
bool bisa[N][N];

int par[N], sz[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}
void solve(int p){
    vector<int> v;
    for (int i=1;i<=n;i++){
        if (find(i) == p){
            v.pb(ar[i]);
        }
    }
    sort(v.begin(), v.end());
    int cur = 0;
    for (int i=1;i<=n;i++){
        if (find(i) == p){
            ar[i] = v[cur++];
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    init();
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }    
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=n;j++){
            bisa[i][j] = (s[j - 1] == '1');
            if (bisa[i][j]) make(i, j);
        }
    }
    for (int i=1;i<=n;i++){
        if (par[i] == i) solve(i);
    }
    for (int i=1;i<=n;i++) cout << ar[i] << " "; cout << el;

    return 0;
}