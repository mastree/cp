#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e3 + 10;
const int INF = 1e9;

int n;
int ar[N];

int solve(int l, int r){
    if (r < l) return 0;
    int ans = r - l + 1;

    int mn = INF;
    for (int i=l;i<=r;i++){
        mn = min(mn, ar[i]);
    }
    vector<int> pos;
    pos.pb(l - 1);
    for (int i=l;i<=r;i++){
        ar[i] -= mn;
        if (ar[i] == 0) pos.pb(i);
    }
    pos.pb(r + 1);
    int ans2 = mn;
    int len = pos.size();
    for (int i=0;i<len - 1;i++){
        ans2 += solve(pos[i] + 1, pos[i + 1] - 1);
    }
    return min(ans, ans2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    cout << solve(1, n) << el;

    return 0;
}