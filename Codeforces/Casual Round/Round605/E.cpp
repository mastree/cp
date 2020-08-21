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

const int N = 2e5 + 7;

int n;
int ar[N];
vector <int> in[N], out[N];
queue <pii> qu; // src, cnt
int ans[N];
bool vis[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (i-ar[i]>=1){
            in[i-ar[i]].pb(i);
            out[i].pb(i-ar[i]);
        }
        if (i+ar[i]<=n){
            in[i+ar[i]].pb(i);
            out[i].pb(i+ar[i]);
        } 
    }

    for (int i=1;i<=n;i++){
        for (auto x : out[i]){
            if (ar[i]%2 != ar[x]%2){
                qu.push(mp(i,1));
                break;
            }
        }
    }

    while (!qu.empty()){
        int id = qu.front().fi;
        int cnt = qu.front().se;

        qu.pop();
        if (vis[id]) continue;
        vis[id] = 1;
        ans[id] = cnt;

        for (auto x : in[id]){
            if (!vis[x]) qu.push(mp(x, cnt+1));
        }
    }

    for (int i=1;i<=n;i++){
        if (ans[i]){
            cout << ans[i] << " ";
        } else{
            cout << -1 << " ";
        }
    }
    cout << el;

    return 0;
}