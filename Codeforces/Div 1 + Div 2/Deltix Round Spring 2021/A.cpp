#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int q;
int n, iter;
int ar[N], le[N], ri[N];

void solve(){
    cin >> n >> iter;
    for (int i=1;i<=n;i++){
        char temp;
        cin >> temp;
        ar[i] = (temp == '1');
    }
    fill(le, le + n + 2, -1);
    fill(ri, ri + n + 2, -1);
    for (int i=1;i<=n;i++){
        if (ar[i]) le[i] = i;
        else le[i] = le[i - 1];
    }
    for (int i=n;i>=1;i--){
        if (ar[i]) ri[i] = i;
        else ri[i] = ri[i + 1];
    }
    for (int i=1;i<=n;i++){
        if (ar[i]) cout << 1;
        else if (le[i] == -1 && ri[i] == -1) cout << 0;
        else if (le[i] == -1) cout << (iter >= ri[i] - i);
        else if (ri[i] == -1) cout << (iter >= i - le[i]);
        else{
            if (i - le[i] == ri[i] - i) cout << 0;
            else cout << (iter >= min(i - le[i], ri[i] - i));
        }
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}