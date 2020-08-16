#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;
const int M = 41;

int n;
ll ar[N], beda[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll tot = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=2;i<=n;i++){
        beda[i] = ar[i] - ar[i - 1];
    }
    bool masih = 1;
    while(masih){
        bool ok = 0;
        for (int j=M - 1;j>0;j--){
            for (int i=n;i>=2;i--){
                ll bit = (1LL << j);
                if (beda[i] & bit){
                    beda[i] -= bit;
                    beda[i + 1] += (bit >> 1);
                    beda[i - 1] += (bit >> 1);

                    ar[i] -= (bit >> 1);
                    ar[i - 1] += (bit >> 1);
                    ok = 1;
                }
            }
        }
        if (!ok) masih = 0;
    }
    for (int i=1;i<=n;i++){
        cout << ar[i] << " ";
    }
    cout << el;

    return 0;
}