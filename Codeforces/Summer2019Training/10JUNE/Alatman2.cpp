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

    int n,k;
    cin >> n >> k;
    int ar[n],ans=2;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    for (int i=1;i<n;i++){
        int tm=ar[i]-ar[i-1];
        if (tm==k+k) ans++;
        else if (tm>k+k) ans+=2;
    }

    cout << ans << el;

    return 0;
}