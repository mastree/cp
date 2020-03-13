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

const int N = 1e3 + 1;
int n;
int mat[N][N];
pair<pii, pii> dp[N][N]; // min2, min5;
pair<bool, bool> par[N][N]; // 0 = kiri, 1 = atas;
int ans2, ans5;
pii nol;

pii hitung(int a){
    if (a==0){
        return mp(MOD, MOD);
    }
    int c2=0, c5=0;
    while (a%2==0){
        a/=2;
        c2++;
    }
    while (a%5==0){
        a/=5;
        c5++;
    }

    return mp(c2, c5);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            // int a;
            // cin >> a;

            // while (a%2==0){
            //     a/=2;
            //     mat[i][j].fi++;
            // }
            // while (a%5==0){
            //     a/=5;
            //     mat[i][j].se++;
            // }
            cin >> mat[i][j];
            if (mat[i][j]==0){
                // mat[i][j] = mp(MOD, MOD);
                nol = mp(i, j);
            } 
        }
    }

    for (int i=0;i<=n;i++){
        pii mx = mp(MOD, MOD);
        dp[i][0] = mp(mx, mx);
        dp[0][i] = mp(mx, mx);
    }

    pii c25 = hitung(mat[1][1]);
    dp[1][1] = mp(c25, c25);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==1 && j==1){
                continue;
            }

            pii a = hitung(mat[i][j]), b = hitung(mat[i][j]);
            pii atas = dp[i-1][j].fi;
            pii kiri = dp[i][j-1].fi;
            if (atas.fi < kiri.fi){
                a.fi += atas.fi;
                a.se += atas.se;
                par[i][j].fi = 1;
            } else {
                if (atas.fi==kiri.fi){
                    a.fi += atas.fi;
                    a.se += min(atas.se, kiri.se);
                    if (atas.se <= kiri.se){
                        par[i][j].fi = 1;
                    } else{
                        par[i][j].fi = 0;
                    }
                } else{
                    a.fi += kiri.fi;
                    a.se += kiri.se;
                    par[i][j].fi = 0;
                }
            }
            atas = dp[i-1][j].se;
            kiri = dp[i][j-1].se;
            if (atas.se < kiri.se){
                b.fi += atas.fi;
                b.se += atas.se;
                par[i][j].se = 1;
            } else{
                if (atas.se == kiri.se){
                    b.se += atas.se;
                    b.fi += min(atas.fi, kiri.fi);
                    if (atas.fi <= kiri.fi){
                        par[i][j].se = 1;
                    } else{
                        par[i][j].se = 0;
                    }
                } else{
                    b.fi += kiri.fi;
                    b.se += kiri.se;
                    par[i][j].se = 0;
                }
            }

            dp[i][j] = mp(a, b);
        }
    }

    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         cout << dp[i][j].se.fi << " " << dp[i][j].se.se << " || ";
    //     }
    //     cout << el;
    // }
    ans2 = min(dp[n][n].fi.fi, dp[n][n].fi.se);
    ans5 = min(dp[n][n].se.fi, dp[n][n].se.se);
    // cout << ans2 << " " << ans5 << el;
    if (nol != mp(0, 0) && ans2 > 1 && ans5 > 1){
        pii cur = mp(1,1);
        cout << 1 << el;
        while (cur.fi < nol.fi){
            cout << "D";
            cur.fi++;
        }
        while (cur.se < nol.se){
            cout << "R";
            cur.se++;
        }
        while (cur.fi < n){
            cout << "D";
            cur.fi++;
        }
        while (cur.se < n){
            cout << "R";
            cur.se++;
        }
        cout << el;
    } else{
        if (ans2<=ans5){
            cout << ans2 << el;
            string str = "";
            pii cur = mp(n,n);
            while (cur != mp(1,1)){
                bool atas = par[cur.fi][cur.se].fi;
                if (atas){
                    str.pb('D');
                    cur.fi--;
                } else{
                    str.pb('R');
                    cur.se--;
                }
            }
            reverse(str.begin(), str.end());
            cout << str << el;
        } else{
            cout << ans5 << el;
            string str = "";
            pii cur = mp(n,n);
            while (cur != mp(1,1)){
                bool atas = par[cur.fi][cur.se].se;
                if (atas){
                    str.pb('D');
                    cur.fi--;
                } else{
                    str.pb('R');
                    cur.se--;
                }
            }
            reverse(str.begin(), str.end());
            cout << str << el;
        }
    }

    return 0;
}