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

int n, q;
int r[N], c[N];
int lr[N], lc[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> r[i];
        r[i] &= 1;
    }
    for (int i=1;i<=n;i++){
        cin >> c[i];
        c[i] &= 1;
    }
    lr[1] = 1;
    lc[1] = 1;
    for (int i=2;i<=n;i++){
        if (r[i] == r[i - 1]){
            lr[i] = lr[i - 1];
        } else{
            lr[i] = i;
        }
        if (c[i] == c[i - 1]){
            lc[i] = lc[i - 1];
        } else{
            lc[i] = i;
        }
    }
    while (q--){
        int ra, ca, rb, cb;
        cin >> ra >> ca >> rb >> cb;
        if (ra > rb) swap(ra, rb);
        if (ca > cb) swap(ca, cb);
        if ((r[ra] + c[ca]) & 1 || (r[rb] + c[cb]) & 1){
            cout << "NO" << el;
            continue;
        }
        if (lr[rb] <= ra && lc[cb] <= ca){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}