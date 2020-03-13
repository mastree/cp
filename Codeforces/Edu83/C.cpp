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

const int N = 50;
const ll INF = 1e16;

int q;
int n;
ll k;
ll ar[N];

ll bit[N][60];
ll res[60];
ll powk[60];

// ll lgk(ll a){
//     ll ret = 0;
//     if (a == 0) return -1;

//     while (a >= k){
//         a /= k;
//         ret++;
//     }
//     return ret;
// }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        // cout << "DEBUG" << el;
        ll temp = 1;
        int mbit;
        for (int i=0;i<60;i++){
            powk[i] = temp;
            mbit = i;
            temp *= k;
            if (temp > INF) break;
        }
        // cout << mbit << el;

        for (int i=1;i<=n;i++){
            for (int j=mbit;j>=0;j--){
                bit[i][j] = ar[i] / powk[j];
                ar[i] %= powk[j];
            }
        }

        fill(res, res + 60, 0);
        for (int i=1;i<=n;i++){
            for (int j=mbit;j>=0;j--){
                res[j] += bit[i][j];
            }
        }

        bool bisa = 1;
        for (int i=0;i<=mbit;i++){
            // cout << res[i] << " ";
            if (res[i] > 1) bisa = 0;
        }
        // cout << el;

        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }

    }

    return 0;
}