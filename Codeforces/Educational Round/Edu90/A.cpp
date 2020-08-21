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
ll a, b, c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> a >> b >> c;

        if (a < c){
            cout << 1 << " ";
        } else{
            cout << -1 << " ";
        }
        if (a * b > c){
            cout << b << el;
        } else{
            cout << -1 << el;
        }

    }

    return 0;
}