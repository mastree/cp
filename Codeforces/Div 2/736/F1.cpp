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

const int N = 6e3 + 10;

int n;
pii ar[N];
ll cnt[2][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        ar[i].fi /= 2;
        ar[i].se /= 2;
        ar[i].fi &= 1;
        ar[i].se &= 1;
        cnt[ar[i].fi][ar[i].se]++;
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        cnt[ar[i].fi][ar[i].se]--;
        for (int j=i + 1;j<=n;j++){
            cnt[ar[j].fi][ar[j].se]--;
            int cur = (ar[i].fi != ar[j].fi || ar[i].se != ar[j].se);
            cur %= 2;
            for (int ii=0;ii<2;ii++){
                for (int jj=0;jj<2;jj++){
                    int cur2 = (ar[i].fi != ii || ar[i].se != jj) + (ar[j].fi != ii || ar[j].se != jj);
                    if ((cur + cur2) & 1 ^ 1){
                        ans += cnt[ii][jj];
                    }
                }
            }
        }
        for (int j=i + 1;j<=n;j++){
            cnt[ar[j].fi][ar[j].se]++;
        }
    }
    cout << ans << el;

    return 0;
}