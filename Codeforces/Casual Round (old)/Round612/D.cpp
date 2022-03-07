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

const int N = 2e3 + 7;

int n;
vector <int> vnode[N], child[N];
int par[N], c[N], root, val[N];
bool mungkin = 1;

void sol(int node){
    if (!mungkin) return;
    vector <int> temp;
    for (auto dest : child[node]){
        sol(dest);

        for (auto x : vnode[dest]){
            temp.pb(x);
        }
    }

    int len = temp.size();
    if (len<c[node]){
        mungkin = 0;
        return;
    }

    for (int i=0;i<len;i++){
        if (i == c[node]){
            vnode[node].pb(node);
        }
        vnode[node].pb(temp[i]);
    }
    if (c[node] == len){
        vnode[node].pb(node);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> par[i] >> c[i];
        if (par[i]==0){
            root = i;
            continue;
        }
        child[par[i]].pb(i);
    }

    sol(root);
    if (!mungkin){
        cout << "NO" << el;
        return 0;
    }

    cout << "YES" << el;
    for (int i=0;i<n;i++){
        val[vnode[root][i]] = i+1;
    }
    for (int i=1;i<=n;i++){ 
        cout << val[i] << " ";
    }
    cout << el; 

    return 0;
}