#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;
const int M = 2e3 + 10;
const ll MOD = 1e9 + 7;

int n, m;
ll pc[N];
string s;

ll le[M][M];
ll mn = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> s;
    for (int i=1;i<=m;i++){
        if (s[i - 1] == '('){
            pc[i] = pc[i - 1] + 1;
        } else{
            pc[i] = pc[i - 1] - 1;
        }
        mn = min(mn, pc[i]);
    }

    int beda = n - m;
    if (beda == 0){
        if (mn == 0 && pc[m] == 0){
            cout << 1 << el;
        } else{
            cout << 0 << el;
        }
        return 0;
    }

    le[0][0] = 1;
    for (int i=1;i<=beda;i++){
        for (int j=0;j<=beda;j++){
            if (j > 0) le[i][j] = (le[i - 1][j - 1] + le[i - 1][j + 1]) % MOD;
            else le[i][j] = le[i - 1][j + 1];
        }
    }

    ll ans = 0;
    mn = -mn;
    for (int i=0;i<=beda;i++){
        for (int j=mn;j<=beda;j++){
            int sisa = pc[m] + j;
            if (sisa > beda - i) continue;
            ll a = le[i][j];
            ll b = le[beda - i][sisa];

            ans = (ans + a * b) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}