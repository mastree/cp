#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e3;
// const ll M1 = 1e9 + 21, P1 = 79;
// const ll M1 = 999995959, P2 = 31;

ll M[2] = {1000000021, 999995959};
ll P[2] = {79, 31}; 
ll inv[2];

string s, stat;
int cek[30], pc[N];
int k, len;

ll ppow[2][N];

map <ll, bool> ada;

ll fpow(ll a, ll b, ll mod){
    if (b==0) return 1;
    ll tm = fpow(a, b/2, mod);
    tm = tm * tm % mod;
    if (b&1){
        tm = tm * a % mod;
    }
    return tm;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ppow[0][0] = 1;
    ppow[1][0] = 1;
    for (int i=0;i<2;i++){
        for (int j=1;j<N;j++){
            ppow[i][j] = ppow[i][j-1] * P[i] % M[i];
        }
    }
    inv[0] = fpow(P[0], M[0] - 2, M[0]);
    inv[1] = fpow(P[1], M[1] - 2, M[1]);

    cin >> s;
    len = s.length();
    s = "*" + s;
    cin >> stat;
    for (int i=0;i<26;i++){
        cek[i] = (stat[i] == '0');
    }
    cin >> k;

    for (int i=1;i<=len;i++){
        pc[i] = pc[i-1] + cek[(int)(s[i] - 'a')];
    }

    int ans = 0;
    for (int i=1;i<=len;i++){
        ll hash[2] = {0, 0};
        ll haha;

        for (int j=i;j<=len;j++){
            for (int k=0;k<2;k++){
                hash[k] = (hash[k] + ppow[k][j-i] * (s[j] - 'a' + 1)) % M[k];
            }
            if (pc[j] - pc[i-1] <= k){
                haha = (hash[0] + (hash[1] << 30));
                ada[haha]=1;
            }
        }
    }

    for (auto x : ada) ans++;
    cout << ans << el;

    return 0;
}