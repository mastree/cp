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

const int N = 1e5 + 7;

int n, m, q;
int fief[N], val[N];
int par[N], sz[N], mval[N];
map <int, int> cnt[N];

int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b){
        return;
    }

    if (sz[a] < sz[b]){
        swap(a,b);
    }

    par[b] = a;
    sz[a] += sz[b];
    mval[a] = max(mval[a], mval[b]);

    for (auto x : cnt[b]){
        cnt[a][x.fi] += x.se;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> fief[i];
    }

    for (int i=1;i<=n;i++){
        cin >> val[i];
    }

    // init
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
        mval[i] = val[i];
        cnt[i][val[i]] = 1;
    }

    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;

        if (fief[a] == fief[b]){
            make(a, b);
        }
    }

    cin >> q;

    while (q--){
        int tipe;
        cin >> tipe;

        int x, y;
        if (tipe==1){
            cin >> x;
            cout << mval[find(x)] << el;
        } else{
            cin >> x >> y;
            x = find(x);

            m
        }
    }

    return 0;
}