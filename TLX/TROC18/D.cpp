#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int ans = 4;    
    if (n == 2){
        // cout << 4 << el;
    } else if (n % 3 == 1 || (n & 1 ^ 1)){
        // cout << 3 << el;
        ans = 3;
    } else{
        // cout << 4 << el;
    }
    if (n > 3){
        n -= 3;
        if (n == 2){
            // cout << 4 << el;
        } else if (n % 3 == 1 || (n & 1 ^ 1)){
            // cout << 3 << el;
            ans = 3;
        } else{
            // cout << 4 << el;
        }
    }
    cout << ans << el;

    return 0;
}