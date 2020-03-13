#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    ll tot=1,plus=0;
    for (int i=1;i<n;i++){
        plus+=4;
        tot+=plus;
    }

    cout << tot << el;

    return 0;
}