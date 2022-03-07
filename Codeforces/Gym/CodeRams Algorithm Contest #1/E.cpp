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

int n, m;
ll k;
ll ar[N];
vector<ll> vec[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char a;
            cin >> a;
            if (a != '1') continue;
            vec[j].pb(ar[i]);
        }
    }
    for (int i=1;i<=m;i++){
        sort(vec[i].begin(), vec[i].end(), greater<ll>());
        int len = vec[i].size();
        for (int j=1;j<len;j++){
            vec[i][j] += vec[i][j - 1];
        }
    }
    int ans = -1;
    for (int take=1;take<=n;take++){
        ll tot = 0;
        for (int i=1;i<=m;i++){
            if (vec[i].empty()) continue;
            int id = min(take, (int)vec[i].size());
            tot += vec[i][id - 1];
        }
        if (tot >= k){
            ans = take;
            break;
        }
    }
    cout << ans << el;

    return 0;
}