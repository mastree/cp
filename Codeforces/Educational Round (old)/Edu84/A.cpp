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

const int N = 2000;
const ll mx = 1e7 + 10;

int q;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        ll a, b;
        cin >> a >> b;
        bool bisa = 1;

        if (a % 2 != b % 2){
            cout << "NO" << el;
            continue;
        }

        ll i;
        ll cur = 0;
        for (i=1;i<mx;i+=2){
            if (b == 1 || cur > a) break;
            cur += i;
            b--;
        }

        if (cur > a) cout << "NO" << el;
        else {
            if (a - cur >= i){
                cout << "YES" << el;
            } else{
                cout << "NO" << el;
            }
        }
    }

    return 0;
}