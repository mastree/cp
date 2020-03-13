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

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll a, b;
        cin >> a >> b;
        if (a == b){
            cout << 0 << el;
            continue;
        }
        ll beda = abs(a - b);
        if (a < b){
            if (beda & 1){
                cout << 1 << el;
                continue;
            } else{
                cout << 2 << el;
                continue;
            }
        } else{
            if (beda & 1){
                cout << 2 << el;
                continue;
            } else{
                cout << 1 << el;
                continue;
            }
        }
    }

    return 0;
}