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
const int A = 110;
const int LEN = 15;
const int MASK = (1 << LEN);
const int INF = 1e9 + 10;

int n;
vector<pii> inp;
int cnt[A][2];

vector<int> primes;
bool is_prime[A];

void init_primes(){
    for (int i=2;i<=100;i++){
        bool ok = 1;
        for (int j=2;j<=min(i - 1, 10);j++){
            if (i % j == 0){
                ok = 0;
                break;
            }
        }
        if (ok){
            primes.pb(i);
            is_prime[i] = 1;
        }
    }
}

int sos[2][MASK];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init_primes();

    cin >> n;
    inp.resize(n);
    for (int i=0;i<n;i++){
        cin >> inp[i].fi;
    }
    for (int i=0;i<n;i++){
        cin >> inp[i].se;
    }
    for (int i=0;i<n;i++){
        cnt[inp[i].se][inp[i].fi]++;
    }
    int ans = 0;
    int mn = 0;
    for (int i=1;i<A;i++){
        if (i > 50 && is_prime[i]){
            ans += min(cnt[i][0], cnt[i][1]);
            mn += cnt[i][0] + cnt[i][1];
            continue;
        }
        int mask = 0;
        for (int j=0;j<LEN;j++){
            if (i % primes[j] == 0){
                mask += (1 << j);
            }
        }
        for (int j=0;j<2;j++){
            sos[j][mask] += cnt[i][j];
            // if (cnt[i][j]){
            //     cout << i << " " << j << " " << mask << el;
            // }
        }
    }
    for (int v=0;v<2;v++){
        for (int i=0;i<LEN;i++){
            int bit = (1 << i);
            for (int j=0;j<MASK;j++){
                if (j & bit) continue;
                sos[v][(j | bit)] += sos[v][j];
            }
        }
    }
    int tans = INF;
    for (int mask=0;mask<MASK;mask++){
        int cmask = MASK - mask - 1;
        tans = min(tans, (n - mn) - (sos[0][mask] + sos[1][cmask]));
    }
    cout << ans + tans << el;

    return 0;
}