#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 26;

int q;
int n, m, k;
string a, b;

bool bisa[M][M];

void init(){
    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            bisa[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    cin >> a >> b;

    init();
    for (int i=0;i + k - 1<n;i++){
        int dig1 = (int)(a[i] - 'a');
        int dig2 = (int)(a[i + k - 1] - 'a');
        bisa[dig1][dig2] = 1;
    }
    int cnt[M];
    fill(cnt, cnt + M, 0);
    for (auto x : b){
        int dig = (int)(x - 'a');
        cnt[dig]++;
    }
    ll ans = 0;
    for (int i=0;i<m;i++){
        int dig = (int)(b[i] - 'a');
        for (int j=0;j<M;j++){
            if (bisa[dig][j]){
                ans += (ll)cnt[j];
            }
        }
        cnt[dig]--;
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