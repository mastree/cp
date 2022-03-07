#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e4 + 10;

int q;
ll n, d, c, m;
string s;

void solve(){
    cin >> n >> d >> c >> m;
    cin >> s;
    int dog = 0;
    for (auto& x : s) if (x == 'D') dog++;
    for (auto& x : s){
        if (x == 'D'){
            if (d){
                d--;
                c += m;
                dog--;
            } else{
                break;
            }
        } else{
            if (c){
                c--;
            } else{
                break;
            }
        }
    }
    if (dog == 0){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}