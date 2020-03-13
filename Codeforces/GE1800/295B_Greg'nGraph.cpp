#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 100000000000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 505;
int n;
ll w[N][N];
vector <int> del,cur;
ll ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> w[i][j];
        }
    }

    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        del.pb(a);
    }

    reverse(del.begin(),del.end());
    int i,j,k;
    for (k = 0; k < n; k ++){
        cur.pb(del[k]);
        for (i = 0; i < n; i ++)
            for (j = 0; j < n; j ++)
                w[del[i]][del[j]]=min(w[del[i]][del[j]],w[del[i]][del[k]]+w[del[k]][del[j]]);
    
        for (auto x : cur){
            for (auto y : cur){
                ans[n-k-1]+=w[x][y];
            }
        }
    }


    for (int i=0;i<n;i++){
        cout << ans[i] << " ";
    }cout << el;

    return 0;
}