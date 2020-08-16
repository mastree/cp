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

int q;
int n;
int ar[N];

int _cnt[20 * N];
int * cnt = _cnt + 10 * N;

void init(){
    fill(cnt - n * 10, cnt + n * 10, 0);
}

void solve(){
    string s;
    cin >> n >> s;
    init();
    for (int i=1;i<=n;i++){
        ar[i] = s[i - 1] - '0';
    }
    cnt[0] = 1;
    int cur = 0;
    ll ans = 0;
    for (int i=1;i<=n;i++){
        cur += ar[i];
        ans += (ll)cnt[cur - i];
        cnt[cur - i]++;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}