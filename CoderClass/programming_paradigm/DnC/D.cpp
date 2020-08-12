#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n;
int ar[N];
ll ans;

void merges(int l, int r){
    if (l >= r) return;
    int m = (l + r) / 2;
    merges(l, m);
    merges(m + 1, r);
    vector<int> temp;
    int p1 = l, p2 = m + 1;
    while (p1 <= m && p2 <= r){
        if (ar[p1] < ar[p2]){
            temp.pb(ar[p1++]);
        } else{
            ans += m - p1 + 1;
            temp.pb(ar[p2++]);
        }
    }
    while (p1 <= m){
        temp.pb(ar[p1++]);
    }
    while (p2 <= r){
        temp.pb(ar[p2++]);
    }
    for (int i=l;i<=r;i++){
        ar[i] = temp[i - l];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    merges(1, n);
    cout << ans << el;

    return 0;
}