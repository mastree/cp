#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 30;

int n;
int q;
ll mat[N][N];

void init(){
    for (int i=1;i<=25;i++){
        for (int j=1;j<=25;j++){
            ll p = (49 - i - j + 2);
            mat[i][j] = (1LL << p);
            if (i & 1) mat[i][j] += (1LL << (p - 1));
        }
    }
    mat[1][1] = 0;
}

void solve(ll cur){
    pii pos = mp(1 + 25 - n, 1 + 25 - n);
    while (pos != mp(25, 25) && pos.fi <= 25 && pos.se <= 25){
        cout << pos.fi - (25 - n) << " " << pos.se - (25 - n) << endl;
        cur -= mat[pos.fi][pos.se];
        ll mxp = (49 - pos.fi - pos.se + 2);
        ll mx = (1LL << mxp);
        if (pos.fi == 25){
            pos.se++;
            continue;
        } else if (pos.se == 25){
            pos.fi++;
            continue;
        }
        if ((cur - mx + 1LL) >= (1LL << (mxp - 2))){
            if (pos.fi & 1){
                pos = mp(pos.fi, pos.se + 1);
            } else{
                pos = mp(pos.fi + 1, pos.se);
            }
        } else{
            if (pos.fi & 1 ^ 1){
                pos = mp(pos.fi, pos.se + 1);
            } else{
                pos = mp(pos.fi + 1, pos.se);
            }
        }
    }
    cout << pos.fi - (25 - n) << " " << pos.se - (25 - n) << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout << mat[i + (25 - n)][j + (25 - n)] << " ";
        }
        cout << endl;
    }
    cin >> q;
    while (q--){
        ll quer;
        cin >> quer;
        solve(quer);
        cout << endl;
    }

    return 0;
}