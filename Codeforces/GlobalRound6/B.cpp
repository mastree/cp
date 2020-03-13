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
        ll n;
        cin >> n;
        
        if (n<15){
            cout << "NO" << el;
            continue;
        }
        ll M = 14;
        ll sisa = n%M;
        // cout << sisa << el;
        if (1<=sisa && sisa<=6){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}