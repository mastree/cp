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

int n;
int ar[200005],pc[200010];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int tm;
        cin >> tm;
        if (tm>0) ar[i]=0;
        else ar[i]=1;
    }

    for (int i=1;i<=n;i++){
        pc[i]=pc[i-1]+ar[i];
    }

    ll od=0,ev=0;
    for (int i=0;i<=n;i++){
        if (pc[i]%2) od++;
        else ev++;
    }

    ll pos=0,neg=0;
    pos+=ev*(ev-1)/2;
    pos+=od*(od-1)/2;
    neg+=od*ev;

    cout << neg << " " << pos << el;

    return 0;
}