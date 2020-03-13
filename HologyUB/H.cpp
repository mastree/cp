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
ll ar[100100];
ll ans=0;
vector <ll> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    sort(ar,ar+n);

    for (int i=n-1;i>0;i-=2){
        while ((ar[i]-ar[i-1]>1) && i>0) i--;
   //     cerr << ar[i] << " " << ar[i-1] << el;
        if (i==0) break;
        v.pb(ar[i-1]);
    }

    int len=v.size();
    for (int i=0;i<len;i+=2){// cerr << v[i] << " " << v[i-1] << el;
        ans+=v[i]*v[i+1];
    }

    cout << ans << el;

    return 0;
}