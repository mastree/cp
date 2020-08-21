#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 1e9 + 1;

int n, c, t; // bags, competitors, max pop/sec
int pre[N];

int coba(int mx){
    int ret = 0, last = 0;
    for (int i=1;i<=n;i++){
        if ((pre[i] - pre[last] + t - 1) / t > mx) return INF;
        if ((pre[i + 1] - pre[last] + t - 1) / t <= mx) continue;
        ret++;
        last = i;
    }
    ret++;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c >> t;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        pre[i] = pre[i - 1] + a;
    }
    int l = 1, r = INF;
    while (l < r){
        int m = (l + r) / 2;
        if (coba(m) <= c){
            r = m;
        } else{
            l = m + 1;
        }
    }
    cout << l << el;

    return 0;
}