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
vector<ll> vec;
vector<ll> ton;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ton.assign(n + 1, 0);
    for (int i=1;i<=n;i++){
        int op;
        cin >> op;
        if (op == 1){
            ll x;
            cin >> x;
            vec.pb(x);
        } else if (op == 2){
            int pos;
            ll x;
            cin >> pos >> x;
            ton[pos] += x; 
            if (pos == vec.size() && pos){
                ton[pos - 1] += ton[pos];
                vec.back() += ton[pos];
                ton[pos] = 0;
            }
        } else{
            vec.pop_back();
            int len = vec.size();
            if (len){
                vec.back() += ton[len];
                ton[len - 1] += ton[len];
                ton[len] = 0;
            }
        }
        if (vec.size()){
            cout << vec.back() << ' ';
        } else{
            cout << "EMPTY "; 
        }
    }
    cout << el;

    return 0;
}