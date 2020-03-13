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

int t;
int n, x, y;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n >> x >> y;
        if (x < y) swap(x, y);
        int mn = n, mx = 0;
        pii kiri = mp(x-1, n-x);
        pii kanan = mp(y-1, n-y);
        pii ambil = mp(min(kiri.fi, kanan.se), min(kiri.se, kanan.fi));
        mx = ambil.fi + ambil.se;
        if (kiri.fi - ambil.fi){
            mx += kiri.fi - ambil.fi;
        }
        ambil = mp(max(min(kiri.fi, kanan.se-1), 0), max(min(kiri.se-1, kanan.fi), 0));
        mn -= ambil.fi + ambil.se;
        mn -= min(kanan.se - ambil.fi, kiri.se - ambil.se);

        cout << mn << " " << mx+1 << el;
    }

    return 0;
}