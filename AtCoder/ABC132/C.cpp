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

    int n;
    cin >> n;

    int ar[n+1];
    for (int i=0;i<n;i++) cin >> ar[i];
    sort(ar,ar+n);

    if (n&1){
        cout << 0 << el;
        return 0;
    }

    cout << ar[n/2]-ar[n/2-1] << el;

    return 0;
}