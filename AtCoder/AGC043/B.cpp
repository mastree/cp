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

const int N = 1e6 + 10;

int n;
string s;

int ar[N];
int ada[3];
int ans = 0;

int fac[N];

int comb(int n, int k){
    int atas = fac[n];
    int bawah = fac[k] + fac[n - k];

    return (atas <= bawah);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;

    fac[0] = 0;
    for (int i=1;i<=n;i++){
        int p = 0;
        int tm = i;
        while (tm % 2 == 0){
            tm /= 2;
            p++;
        }
        fac[i] = fac[i - 1] + p;
    }

    for (int i=1;i<=n;i++){
        ar[i] = s[i - 1] - '1';
        ada[ar[i]]++;
    }

    if (ada[1] && ada[2] && !ada[0]){
        for (int i=1;i<=n;i++){
            ar[i]--;
        }
        ada[0] = 1;
        ada[1] = 1;
        ada[2] = 0;
    }

    if (ada[0] && ada[1] && ada[2]){
        for (int i=1;i<=n;i++){
            ans += ar[i] * comb(n - 1, i - 1);
        }
        ans %= 2;
    } else if (ada[0] && ada[2]){
        for (int i=1;i<=n;i++){
            ar[i] /= 2;
            ans += ar[i] * comb(n - 1, i - 1);
        }
        ans %= 2;
        if (ans) ans = 2;
    } else if (ada[0] && ada[1]){
        for (int i=1;i<=n;i++){
            ans += ar[i] * comb(n - 1, i - 1);
        }
        ans %= 2;
    } else ans = 0;

    cout << ans << el;

    return 0;
}