#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const int N = 2e3 + 10;

int m, d;
string a, b;
int ppow10[N];

ll tambah(const ll& a, const ll& b){
    return (a + b + MOD) % MOD;
}

void kurang(string& s){
    if (s == "1"){
        s = "0";
        return;
    }
    int len = s.length();
    for (int i=len - 1;i>=0;i--){
        if (s[i] > '0'){
            s[i]--;
            break;
        }
        s[i] = '9';
    }
    if (s[0] == '0'){
        for (int i=0;i<len - 1;i++){
            s[i] = s[i + 1];
        }
        s.pop_back();
    }
}

ll calc(const string& s){
    if (s == "0") return 0;
    int len = s.length();
    ll dp[len + 1][m][2]; // panjang, sisa, udh bebas/masih terikat
    
    for (int i=0;i<len + 1;i++){
        for (int j=0;j<m;j++){
            for (int k=0;k<2;k++){
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 1; // masih terikat
    for (int i=0;i<len;i++){
        int dig = (int)(s[i] - '0');
        int fac = ppow10[len - i - 1];
        if (i & 1){ // nambahin digit d
            for (int j=0;j<m;j++){
                // terikat
                if (dig == d) dp[i + 1][(j + dig * fac) % m][0] = dp[i][j][0];
                for (int k=d;k<=min(dig - 1, d);k++){
                    dp[i + 1][(j + k * fac) % m][1] = tambah(dp[i + 1][(j + k * fac) % m][1], dp[i][j][0]);
                }
                // bebas
                for (int k=d;k<=d;k++){
                    dp[i + 1][(j + k * fac) % m][1] = tambah(dp[i + 1][(j + k * fac) % m][1], dp[i][j][1]);
                }
            }
        } else{
            for (int j=0;j<m;j++){
                // terikat
                if (dig != d) dp[i + 1][(j + dig * fac) % m][0] = dp[i][j][0];
                for (int k=(i == 0);k<=dig - 1;k++){
                    if (k == d) continue;
                    dp[i + 1][(j + k * fac) % m][1] = tambah(dp[i + 1][(j + k * fac) % m][1], dp[i][j][0]);
                }
                // bebas
                for (int k=(i == 0);k<=9;k++){
                    if (k == d) continue;
                    dp[i + 1][(j + k * fac) % m][1] = tambah(dp[i + 1][(j + k * fac) % m][1], dp[i][j][1]);
                }
            }
        }
    }
    ll ret = tambah(dp[len][0][1], dp[len][0][0]);
    return ret;
}

ll solve(string a, string b){
    kurang(a);
    // cout << calc(a) << " " << calc(b) << el;
    if (a.length() < b.length()) return calc(b);
    return (calc(b) - calc(a) + MOD) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> d;
    ppow10[0] = 1 % m;
    for (int i=1;i<N;i++){
        ppow10[i] = (ppow10[i - 1] * 10LL) % m;
    }
    cin >> a >> b;
    cout << solve(a, b) << el;

    return 0;
}