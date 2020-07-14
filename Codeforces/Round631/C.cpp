#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = (1 << 20) + 10;

int q;
ll n, h, g;
ll ar[N * 2], res[N * 2];

vector <ll> v[N];
vector <ll> ans;

void func(ll node){
    ll le = node * 2;
    ll ri = node * 2 + 1;

    if (ar[le] == 0 && ar[ri] == 0){
        ar[node] = 0;
    } else{
        if (ar[le] > ar[ri]){
            ar[node] = ar[le];
            func(le);
        } else{
            ar[node] = ar[ri];
            func(ri);
        }
    }
}

void dfs(ll node, ll dep){
    ll le = node * 2;
    ll ri = node * 2 + 1;

    if (ar[le] == 0 && ar[ri] == 0){
        v[node].pb(ar[node]);
    } else if (dep >= g){
        dfs(le, dep + 1);
        dfs(ri, dep + 1);

        v[node].pb(ar[node]);
        int idle = 0;
        int idri = 0;
        int lenle = v[le].size();
        int lenri = v[ri].size();
        while (idle < lenle && idri < lenri){
            if (v[le][idle] > v[ri][idri]){
                v[node].pb(v[le][idle]);
                idle++;
            } else{
                v[node].pb(v[ri][idri]);
                idri++;
            }
        }
        while (idle < lenle){
            v[node].pb(v[le][idle]);
            idle++;
        }
        while (idri < lenri){
            v[node].pb(v[ri][idri]);
            idri++;
        }
    } else{
        dfs(le, dep + 1);
        dfs(ri, dep + 1);

        v[node].pb(ar[node]);
        int idle = 0;
        int idri = 0;
        int lenle = v[le].size();
        int lenri = v[ri].size();

        while (idle < lenle && idri < lenri){
            if (v[le][idle] > v[ri][idri]){
                v[node].pb(v[le][idle]);
                idle++;
            } else{
                v[node].pb(v[ri][idri]);
                idri++;
            }
        }
        v[node].pop_back();
    }

    if (dep >= g){
        v[le].pb(0);
        v[ri].pb(0);
    }
}

void dfs_ans(ll node){
    ll le = node * 2;
    ll ri = node * 2 + 1;
    while (ar[node] != res[node]){
        func(node);
        ans.pb(node);
    }
    if (ar[le] != 0){
        dfs_ans(le);
    }
    if (ar[ri] != 0){
        dfs_ans(ri);
    }
}

void sol(){
    for (ll i=1;i<=n;i++){
        v[i].clear();
    }
    dfs(1, 1);

    ll tot = 0;
    for (ll i=1;i<=n;i++){
        int len = v[i].size();
        res[i] = v[i][len - 1];
        tot += res[i];
    }
    ans.clear();
    dfs_ans(1);

    cout << tot << el;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> h >> g;
        n = (1LL << h) - 1;

        for (ll i=1;i<=n;i++){
            cin >> ar[i];
        }

        sol();
        for (ll i=1;i<=n;i++){
            ar[i] = 0;
        }
    }   

    return 0;
}