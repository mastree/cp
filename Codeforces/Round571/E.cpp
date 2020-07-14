#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

ll n, m;
int q;
int pre[2 * N][2 * N];

ll hitung(int xa, int ya, int xb, int yb){
    if (xb == 0 || yb == 0 || xa > xb || ya > yb) return 0;
    return (ll)(pre[xb][yb] - pre[xb][ya - 1] - pre[xa - 1][yb] + pre[xa - 1][ya - 1]);
}

ll solve(ll x, ll y){
    if (x == 0 || y == 0) return 0;
    ll ret = 0;
    ll N2 = n * 2, M2 = m * 2;
    ll bagix = x / N2, bagiy = y / M2;
    ll sisax = x % N2, sisay = y % M2;
    ret += bagix * (N2 / 2LL) * y + bagiy * (M2 / 2LL) * sisax;
    bool stat = 1;
    ll tam = 0;
    // tambah
    ll curx = x - sisax + 1;
    ll cury = y - sisay + 1;
    // cout << sisax << " " << sisay << " " << curx << " " << cury << " " << ret << el;
    while (curx > 1){
        ll bit;
        for (int i=30;i>=0;i--){
            if ((1LL << i) < curx){
                bit = (1LL << i);
                break;
            }
        }
        stat ^= 1;
        curx -= bit;
    }
    while (cury > 1){
        ll bit;
        for (int i=30;i>=0;i--){
            if ((1LL << i) < cury){
                bit = (1LL << i);
                break;
            }
        }
        stat ^= 1;
        cury -= bit;
    }
    if (stat){
        tam += hitung(1, 1, max(sisax, n), max(sisay, m));
    } else{
        tam += (1LL * max(sisax, n) * max(sisay, m)) - hitung(1, 1, max(sisax, n), max(sisay, m));
    }

    if (sisax > n){
        stat = 1;
        // tambah
        curx = x - sisax + n + 1;
        cury = y - sisay + 1;
        // cout << sisax << " " << sisay << " " << curx << " " << cury << " " << ret << el;
        while (curx > 1){
            ll bit;
            for (int i=30;i>=0;i--){
                if ((1LL << i) < curx){
                    bit = (1LL << i);
                    break;
                }
            }
            stat ^= 1;
            curx -= bit;
        }
        while (cury > 1){
            ll bit;
            for (int i=30;i>=0;i--){
                if ((1LL << i) < cury){
                    bit = (1LL << i);
                    break;
                }
            }
            stat ^= 1;
            cury -= bit;
        }
        if (stat){
            tam += hitung(1, 1, max(sisax - n, n), max(sisay, m));
        } else{
            tam += (1LL * max(sisax - n, n) * max(sisay, m)) - hitung(1, 1, max(sisax - n, n), max(sisay, m));
        }
    }
    if (sisay > m){
        stat = 1;
        // tambah
        curx = x - sisax + 1;
        cury = y - sisay + m + 1;
        // cout << sisax << " " << sisay << " " << curx << " " << cury << " " << ret << el;
        while (curx > 1){
            ll bit;
            for (int i=30;i>=0;i--){
                if ((1LL << i) < curx){
                    bit = (1LL << i);
                    break;
                }
            }
            stat ^= 1;
            curx -= bit;
        }
        while (cury > 1){
            ll bit;
            for (int i=30;i>=0;i--){
                if ((1LL << i) < cury){
                    bit = (1LL << i);
                    break;
                }
            }
            stat ^= 1;
            cury -= bit;
        }
        if (stat){
            tam += hitung(1, 1, max(sisax, n), max(sisay - m, m));
        } else{
            tam += (1LL * max(sisax, n) * max(sisay - m, m)) - hitung(1, 1, max(sisax, n), max(sisay - m, m));
        }
    }
    if (sisax > n && sisay > m){
        stat = 1;
        // tambah
        curx = x - sisax + n + 1;
        cury = y - sisay + m + 1;
        // cout << sisax << " " << sisay << " " << curx << " " << cury << " " << ret << el;
        while (curx > 1){
            ll bit;
            for (int i=30;i>=0;i--){
                if ((1LL << i) < curx){
                    bit = (1LL << i);
                    break;
                }
            }
            stat ^= 1;
            curx -= bit;
        }
        while (cury > 1){
            ll bit;
            for (int i=30;i>=0;i--){
                if ((1LL << i) < cury){
                    bit = (1LL << i);
                    break;
                }
            }
            stat ^= 1;
            cury -= bit;
        }
        if (stat){
            tam += hitung(1, 1, max(sisax - n, n), max(sisay - m, m));
        } else{
            tam += (1LL * max(sisax - n, n) * max(sisay - m, m)) - hitung(1, 1, max(sisax - n, n), max(sisay - m, m));
        }
    }

    ret += tam;

    return ret;
}

ll solve(ll xa, ll ya, ll xb, ll yb){
    return solve(xb, yb) - solve(xb, ya - 1) - solve(xa - 1, yb) + solve(xa - 1, ya - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=m;j++){
            int dig = (int)(s[j - 1] - '0');
            pre[i][j] = pre[i + n][j + m] = dig;
            pre[i + n][j] = pre[i][j + n] = (dig ^ 1);
        }
    }    
    for (int i=1;i<=2 * n;i++){
        int cur = 0;
        for (int j=1;j<=2 * n;j++){
            cur += pre[i][j];
            pre[i][j] = pre[i - 1][j] + cur;
            // cout << pre[i][j] << " ";
        }
        // cout << el;
    }

    while (q--){
        ll xa, ya, xb, yb;

        cin >> xa >> ya >> xb >> yb;
        cout << solve(xa, ya, xb, yb) << el;
    }

    return 0;
}