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

int a[100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,x,y;
    cin >> n >> x >> y;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        bool p=1;
        for (int j=i-x;j<i;j++) {
            if (j>=1&&j<=n) {
                if (a[j]<a[i]) p=0;
            }
        }
        for (int j=i+1;j<=i+y;j++) {
            if (j>=1&&j<=n) {
                if (a[j]<a[i]) p=0;
            }
        }
        if (p) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}   