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
const int MX = 1e9;

int n, t;
int ar[N], mn[N];

unordered_map<int, int> bit;

void upd(int x, int val){
    x++;
    while (x <= t){
        bit[x] += val;
        x += (x & (-x));
    }
}
int ask(int x){
    x++;
    int ret = 0;
    while (x){
        ret += bit[x];
        x -= (x & (-x));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    t = min(t, n + MX + 10);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mn[i] = max(ar[i] - i, 0);
    }   
    int ans = 0;
    for (int i=1;i<=n;i++){
        upd(mn[i], 1);
        int mul = t - i - 1;
        if (mul >= 0){
            ans = max(ans, ask(mul));
        }
    }
    cout << ans << el;

    return 0;
}