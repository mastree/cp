#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 100;

int q;
int n;
int ar[N];

int calc(int tot){
    int cnt[tot];
    fill(cnt, cnt + tot, 0);

    int ret = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] >= tot) continue;
        if (cnt[tot - ar[i]]){
            cnt[tot - ar[i]]--;
            ret++;
        } else cnt[ar[i]]++;
    }
    return ret;
}

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int ans = 0;
    for (int i=2;i<=N;i++){
        ans = max(ans, calc(i));
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