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

const int N = 5e5 + 10;

int q;
ll n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        ll tot = 0;
        ll iter = 1;
        for (ll i=n/2;i>0;i--){
            tot += i * (n - iter) * 4LL;
            iter += 2;
        }
        cout << tot << el;
    }

    return 0;
}