#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 5e3 + 10;
const ll MOD = 1e9 + 7;

int n;
int ar[N];
ll base;
ll out[N];

int par[N], sz[N];
vector<int> v;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    base++;
}

void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
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
        if (ar[i] != -1) make(i, ar[i]);
        else{
            v.pb(i);
        }
    }
    ll ans = 0;
    ll tot = 1LL * n;
    ll min1 = 0;
    for (auto x : v){
        out[par[x]]++;
        min1++;
    }
    ans = base * fpow(tot - 1, min1);
    cout << ans << el; 

    return 0;
}