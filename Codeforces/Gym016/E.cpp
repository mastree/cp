#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;

piii mp3(int a, int b, int c){
    return mp(mp(a, b), c);
}
bool compup(const piii& a, const piii& b){
    if (a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
    return a.se > b.se;
}
bool compdown(const piii& a, const piii& b){
    if (a.fi.fi != b.fi.fi) return a.fi.fi > b.fi.fi;
    return a.se < b.se;
}
bool is_atas(int skor1, int id1, int skor2, int id2){
    if (skor1 != skor2) return skor1 > skor2;
    return id1 < id2;
}
bool is_bawah(int skor1, int id1, int skor2, int id2){
    if (skor1 != skor2) return skor1 < skor2;
    return id1 > id2;
}

const int N = 110;

int n;
pii ar[N];
vector<piii> up, down;
int base = 0;
int ulen, dlen;

int dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        if (ar[i].se >= 0){
            up.pb(mp3(ar[i].fi, ar[i].fi + ar[i].se, i));
        } else{
            down.pb(mp3(ar[i].fi, ar[i].fi + ar[i].se, i));
        }
    }
    sort(up.begin(), up.end(), &compup);
    sort(down.begin(), down.end(), &compdown);
    ulen = up.size();
    dlen = down.size();
    for (int i=0;i<ulen - 1;i++){
        int a = up[i].fi.fi;
        int b = up[i].fi.se;
        int id = up[i].se;
        for (int j=i + 1;j<ulen;j++){
            if (up[j].fi.fi <= b){
                if (up[j].fi.fi == b){
                    if (up[j].se > id) base++;
                    else continue;
                } else base++;
                if (up[j].fi.se > b) base++;
                else if (up[j].fi.se == b){
                    if (up[j].se < id) base++;
                }
            }
        }
    }
    for (int i=0;i<dlen - 1;i++){
        int a = down[i].fi.fi;
        int b = down[i].fi.se;
        int id = down[i].se;
        for (int j=i + 1;j<dlen;j++){
            if (down[j].fi.fi >= b){
                if (down[j].fi.fi == b){
                    if (down[j].se < id) base++;
                    else continue;
                } else base++;
                if (down[j].fi.se < b) base++;
                else if (down[j].fi.se == b){
                    if (down[j].se > id) base++;
                }
            }
        }
    }
    for (int i=0;i<=ulen;i++){
        for (int j=0;j<=dlen;j++){
            int ni = i + 1, nj = j + 1;
            if (ni <= ulen){
                int tam = 0;
                for (int k=0;k<j;k++){
                    if (is_bawah(up[i].fi.fi, up[i].se, down[k].fi.se, down[k].se) && is_atas(up[i].fi.se, up[i].se, down[k].fi.se, down[k].se)){
                        tam++;
                    }
                }
                for (int k=j;k<dlen;k++){
                    if (is_bawah(up[i].fi.fi, up[i].se, down[k].fi.fi, down[k].se) && is_atas(up[i].fi.se, up[i].se, down[k].fi.fi, down[k].se)){
                        tam++;
                    }
                }
                dp[ni][j] = max(dp[ni][j], dp[i][j] + tam);
            }
            if (nj <= dlen){
                int tam = 0;
                for (int k=0;k<i;k++){
                    if (is_bawah(up[k].fi.se, up[k].se, down[j].fi.fi, down[j].se) && is_atas(up[k].fi.se, up[k].se, down[j].fi.se, down[j].se)){
                        tam++;
                    }
                }
                for (int k=i;k<ulen;k++){
                    if (is_bawah(up[k].fi.fi, up[k].se, down[j].fi.fi, down[j].se) && is_atas(up[k].fi.fi, up[k].se, down[j].fi.se, down[j].se)){
                        tam++;
                    }
                }
                dp[i][nj] = max(dp[i][nj], dp[i][j] + tam);
            }
        }
    }
    cout << base + dp[ulen][dlen] << el;

    return 0;
}