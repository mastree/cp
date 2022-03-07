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

const int N = 1e6 + 10;

int n, q;
int bit[N];

int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (; idx < N - 2; idx = idx | (idx + 1))
        bit[idx] += delta;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        add(a, 1);
        // cout << a << el;
        // cout << sum(a) << el;
    }
    // for (int i=1;i<=n;i++){
    //     cout << sum(i) << el;
    // }
    // cout << el;

    while (q--){
        int a;
        cin >> a;
        if (a > 0){
            add(a, 1);
        } else{
            a = -a;
            int low = 1, high = N - 2;
            while (low < high){
                int mid = (low + high) / 2;

                int sm = sum(mid);
                // cout << sm << el;
                if (sm >= a){
                    high = mid;
                } else{
                    low = mid + 1;
                }
            }
            // cout << high << el;
            add(high, -1);
        }
    }
    for (int i=1;i<=n;i++){
        if (sum(i)){
            cout << i << el;
            return 0;
        }
    }
    cout << 0 << el;

    return 0;
}