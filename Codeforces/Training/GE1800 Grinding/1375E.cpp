#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int n;
int ar[N];
vector<int> adj[N];
vector<pii> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    {
        vector<pii> temp;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            temp.pb(mp(ar[i], i));
        }
        sort(temp.begin(), temp.end());
        for (int i=0;i<n;i++){
            ar[temp[i].se] = i + 1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            if (ar[i] > ar[j]){
                adj[i].pb(j);
            }
        }
    }
    for (int i=1;i<=n;i++){
        vector<pii> urut;
        for (auto x : adj[i]){
            urut.pb(mp(ar[x], x));
        }
        sort(urut.begin(), urut.end(), greater<pii>());
        for (auto x : urut){
            ans.pb(mp(i, x.se));
            swap(ar[i], ar[x.se]);
        }
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}