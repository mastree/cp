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

const int N = 1e5 + 10;

int q;
int n;
ll l, r;

void solve(int c1, int c2, int byk, int col, bool akhir){
    while (byk > 0){
        if (byk && col){
            cout << c1 << " ";
            byk--;
            col = 0;
        }
        if (byk && !col){
            // cout << c2 << " ";
            byk--;
            if (c2 == n){
                int temp = c1;
                c1 = n;
                c2 = temp + 1;
                if (c2 == n) c2 = 1;
            } else{
                if (c1 < c2){
                    swap(c1, c2);
                } else{
                    swap(c1, c2);
                    if (c2 == n){
                        c2 = c1 + 1;
                    } else{
                        c2++;
                    }
                }
            }
            col = 1;
        }
    }
    if (akhir) cout << 1;
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> l >> r;
        bool akhir = (r == n * (n - 1) + 1);
        if (akhir) r--;
        l = (l - 1) * 2 + 1;
        r = (r - 1) * 2 + 1;
        ll row = (l + 1) / 2;
        ll col = l & 1;
        ll rs, cur = 0;

        ll lebihr;
        for (ll i=1;i<=n;i++){
            ll cnt = (n - i) * 2;
            cur += cnt;
            if (cur >= row){
                rs = i;
                lebihr = row - (cur - cnt);
                break;
            }
        }
        ll cs[2];
        if (lebihr&1){
            cs[0] = rs;
            cs[1] = rs + 1 + lebihr / 2;
        } else{
            cs[0] = rs + lebihr / 2;
            cs[1] = rs;
            if (cs[0] == n) cs[1]++;
        }
        // cout << l << " " << r << el;
        // cout << cs[0] << " " << cs[1] << el;
        // cout << rs << " " << cs[0] << " " << cs[1] << " " << col << el;
        solve((int)cs[0], (int)cs[1], (int)(r - l + 1LL), (int)col, akhir);
    }

    return 0;
}