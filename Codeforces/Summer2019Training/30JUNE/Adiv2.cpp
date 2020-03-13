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

    int q;
    cin >> q;
    while (q--){
        int n,s,t;
        cin >> n >> s >> t;

        int both=s+t-n;
        s-=both;
        t-=both;

        cout << max(s,t)+1 << el;
    }

    return 0;
}