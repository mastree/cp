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

const int N = 5e3 + 7;
const ll INF = 1e18;

int n;
ll ar[N];

ll sol(int l, int r){
    if (r < l) return 0;
    ll mn = r - l + 1;
    ll low = INF;
    for (int i=l;i<=r;i++){
        if (ar[i] < low){
            low = ar[i];
        }
    }

    vector <int> zero;
    zero.pb(l-1);
    for (int i=l;i<=r;i++){
        ar[i] -= low;
        if (ar[i] == 0) zero.pb(i);
    }
    zero.pb(r+1);
    ll temp = 0;
    int len = zero.size();
    for (int i=0;i<len-1;i++){
        temp += sol(zero[i] + 1, zero[i + 1] - 1);
    }

    // cout << l << ", " << r << " => " << el;
    // cout << mn << " " << low + temp << el;
    return min(mn, low + temp);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    cout << sol(1, n) << el;

    return 0;
}