#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int INF = 1e9;

int n, m;
int ar[N];
pii quers[N];
int ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        char a;
        cin >> a;
        ar[i] = (int)(a - 'a');
    }
    for (int i=1;i<=m;i++){
        cin >> quers[i].fi >> quers[i].se;
    }
    fill(ans, ans + m + 1, INF);
    vector<int> perm = {0, 1, 2};
    do{
        vector<int> pre(n + 1, 0);
        for (int i=1;i<=n;i++){
            pre[i] = pre[i - 1] + (perm[ar[i]] != i % 3);
        }
        for (int i=1;i<=m;i++){
            ans[i] = min(ans[i], pre[quers[i].se] - pre[quers[i].fi - 1]);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    for (int i=1;i<=m;i++){
        cout << ans[i] << el;
    }

    return 0;
}