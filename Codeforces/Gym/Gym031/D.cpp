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

const int N = 1e5 + 10;

int q;
int n;
vector<int> fac[N];
int cnt[N];
bool udh[N];

void init(){
    for (int i=1;i<N;i++){
        for (int j=i + i;j<N;j+=i){
            fac[j].pb(i);
        }
    }
}

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
        for (auto& x : fac[a]){
            cnt[x]++;
        }
    }
    bool dapet = 0;
    ll ans = 0;
    for (int i=N - 1;i>=1;i--){
        if (!dapet && cnt[i]){
            cnt[i]--;
            udh[i] = 1;
            for (auto& x : fac[i]){
                udh[x] = 1;
            }
        }
        if (udh[i] && cnt[i]){
            ans += 1LL * (cnt[i]) * i;
            for (auto& x : fac[i]){
                cnt[x] -= cnt[i];
            }
        } else if (cnt[i] > 1){
            ans += 1LL * (cnt[i] - 1) * i;
            for (auto& x : fac[i]){
                cnt[x] += 1 - cnt[i];
                udh[x] = 1;
            }
        }
        cnt[i] = 0;
        udh[i] = 0;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("dream.in", "r", stdin); 

    init();
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case " << i << ": ";
        solve(); 
    }

    return 0;
}