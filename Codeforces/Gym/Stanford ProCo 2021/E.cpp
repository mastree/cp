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

int n, x, y;
vector<int> ans;

bool solve(int n, int awal, int x, int y, bool tepat = false){
    if (n == 0) return true;
    if (x == 0 || y == 0) return false;
    if (x + y > n + 1 && tepat) return false;
    if (!tepat){
        int akhir = awal + n - 1;
        if (x <= y){
            y = min(y, n);
            x = min(x, n + 1 - y);
            for (int i=x - 1;i>=0;i--){
                ans.pb(akhir - i);
            }
            for (int i=y - 2;i>=0;i--){
                ans.pb(awal + i);
            }
            return solve(n - x - (y - 1), awal + y - 1, x - 1, y - 1);
        }
        x = min(x, n);
        y = min(y, n + 1 - x);
        for (int i=y - 1;i>=0;i--){
            ans.pb(awal + i);
        }
        for (int i=x - 2;i>=0;i--){
            ans.pb(akhir - i);
        }
        return solve(n - (x - 1) - y, awal + y, x - 1, y - 1);
    }
    int akhir = awal + n - 1;
    if (x <= y){
        for (int i=x - 1;i>=0;i--){
            ans.pb(akhir - i);
        }
        for (int i=y - 2;i>=0;i--){
            ans.pb(awal + i);
        }
        return solve(n - x - (y - 1), awal + y - 1, x - 1, y - 1);
    }
    for (int i=y - 1;i>=0;i--){
        ans.pb(awal + i);
    }
    for (int i=x - 2;i>=0;i--){
        ans.pb(akhir - i);
    }
    return solve(n - (x - 1) - y, awal + y, x - 1, y - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;
    bool bisa = solve(n, 1, x, y, 1);
    if (bisa){
        for (auto x : ans){
            cout << x << ' ';
        }
        cout << el;
    } else{
        cout << -1 << el;
    }

    return 0;
}