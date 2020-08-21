#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e3 + 10, M = 26;

int n, m;
int ar[N][N];

short diag[2][N][N]; // diagonal => 0 = \, 1 = /

int hitung(pii a, pii b, int id, int pos){
    if (ar[a.fi][a.se] != pos || ar[b.fi][b.se] != pos) return 0;
    if (id == 0) return diag[0][b.fi][b.se] - diag[0][a.fi][a.se] + 1;
    return diag[1][b.fi][b.se] - diag[1][a.fi][a.se] + 1;
}

bool bisa(int r, int c, int x){
    pii kiri, atas, kanan, bawah;
    if (r - x <= 0 || r + x > n || c - x <= 0 || c + x > m) return 0;
    kiri = mp(r, c - x);
    atas = mp(r - x, c);
    kanan = mp(r, c + x);
    bawah = mp(r + x, c);

    int dig = ar[r][c];
    int temp = hitung(atas, kiri, 1, dig) + hitung(atas, kanan, 0, dig) + hitung(kiri, bawah, 0, dig) + hitung(kanan, bawah, 1, dig);
    return (temp == (x + 1) * 4);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=m;j++){
            int dig = s[j - 1] - 'a';
            ar[i][j] = dig;
            
            if (ar[i - 1][j - 1] == ar[i][j]) diag[0][i][j] = diag[0][i - 1][j - 1] + 1;
            else diag[0][i][j] = 1;
            if (ar[i - 1][j + 1] == ar[i][j]) diag[1][i][j] = diag[1][i - 1][j + 1] + 1;
            else diag[1][i][j] = 1;
        }
    }
    ll ans = 0;
    int last = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            while (bisa(i, j, last + 1)) last++;
            ans += (ll)(last + 1);
            last = max(last - 1, 0);
        }
    }
    cout << ans << el;

    return 0;
}