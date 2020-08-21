#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;
const ll INF = 2e18;

int q;
int n, m, k;
ll s;
ll P[N], Q[N];
ll PR[5], QR[5]; 

void init(){
    for (int i=k + 1;i<=n;i++){
        P[i] = (PR[1] * P[i - 2] % PR[4] + PR[2] * P[i - 1] % PR[4] + PR[3]) % PR[4] + 1LL;
    }
    for (int i=k + 1;i<=m;i++){
        Q[i] = (QR[1] * Q[i - 2] % QR[4] + QR[2] * Q[i - 1] % QR[4] + QR[3]) % QR[4] + 1LL;  
    }
}
void debug(){
    cout << el;
    for (int i=1;i<=n;i++){
        cout << P[i] << " ";
    }
    cout << el;
    for (int i=1;i<=m;i++){
        cout << Q[i] << " ";
    }
    cout << el;
}
bool bisa(ll t){
    int i = 1, j = 1;

    while (i <= n && j <= m){
        int j1 = j, j2 = j;

        if (1){
            ll cur = 0;

            ll pos = P[i];
            if (Q[j1] < P[i]){
                cur += P[i] - Q[j1];
                pos = Q[j1];
            }
            if (cur > t) cur = INF;
            else{
                while (j1 <= m && Q[j1] - pos + cur + s <= t){
                    cur += s;
                    j1++;
                }
            }
        }
        if (1){
            ll cur = 0;

            while (j2 <= m && max(Q[j2] - P[i], P[i] - Q[j2]) + Q[j2] - Q[j] + ((ll)(j2 - j + 1)) * s <= t){
                j2++;
            }
            cur = max(Q[j2] - P[i], P[i] - Q[j2]) + Q[j2] - Q[j] + ((ll)(j2 - j + 1)) * s;
        }
        j = max(j1, j2);
        i++;
    }
    if (j <= m) return 0;
    return 1;
}

void solve(){
    cin >> n >> m >> k >> s;
    for (int i=1;i<=k;i++){
        cin >> P[i];
    }
    for (int i=1;i<=4;i++){
        cin >> PR[i];
    }
    for (int i=1;i<=k;i++){
        cin >> Q[i];
    }
    for (int i=1;i<=4;i++){
        cin >> QR[i];
    }
    init();
    sort(P + 1, P + 1 + n);
    sort(Q + 1, Q + 1 + m);

    ll l = 0, r = INF - 100LL;
    while (l < r){
        ll m = (l + r) / 2LL;
        if (bisa(m)){
            r = m;
        } else{
            l = m + 1;
        }
    }
    cout << r << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("dislodging_logs_input.txt", "r", stdin);
    freopen("B.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}