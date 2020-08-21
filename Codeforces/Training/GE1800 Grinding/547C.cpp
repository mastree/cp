#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10, MX = 5e5 + 10, M = 6;

int n, q;
int ar[N];

vector<int> fac[MX];
bool avail[N];

int bitCnt[(1 << M)];
int cnt[MX];
int shelf;
ll ans;

void init(){
    for (int i=2;i<MX;i++){
        if (fac[i].size()) continue;
        for (int j=i;j<MX;j+=i){
            fac[j].pb(i);
        }
    }
    for (int i=1;i<(1 << M);i++){
        bitCnt[i] = __builtin_popcount(i);
    }
}
void upd(int a){
    int len = fac[ar[a]].size();
    ll res = 0;
    if (avail[a]){
        for (int i=1;i<(1 << len);i++){
            int cur = 1;
            for (int j=0;j<len;j++){
                if (i & (1 << j)){
                    cur *= fac[ar[a]][j];
                }
            }
            if (bitCnt[i] & 1) res += cnt[cur];
            else res -= cnt[cur];
            cnt[cur]++;
        }
        ans += (shelf - res);
        shelf++;
    } else{
        for (int i=1;i<(1 << len);i++){
            int cur = 1;
            for (int j=0;j<len;j++){
                if (i & (1 << j)){
                    cur *= fac[ar[a]][j];
                }
            }
            cnt[cur]--;
            if (bitCnt[i] & 1) res += cnt[cur];
            else res -= cnt[cur];
        }
        shelf--;
        ans -= (shelf - res);
    }
    avail[a] ^= 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        avail[i] = 1;
    }
    while (q--){
        int a;
        cin >> a;
        upd(a);
        cout << ans << el;
    }

    return 0;
}