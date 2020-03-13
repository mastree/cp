#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll cal[2005][2005];

int main() {
    ll n, k;
    cin >> n >> k;
    cal[0][0] = cal[1][0] = cal[1][1] = 1;
    for (int i = 1; i <= 2000; i++) {
        cal[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            cal[i][j] = cal[i - 1][j - 1] + cal[i - 1][j];
            cal[i][j] %= mod; 
        }
    }
    for (int i = 1; i <= k; i++) {
        ll a = cal[k - 1][i - 1];
        ll b = 0;
        if (n - k + 1 >= i) b = cal[n - k + 1][i];
        cout << a * b % mod << '\n';
    }

    return 0;
} 