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

    int maks=((n-1)*(n-2)/2);
    if (k>maks){
        cout << -1 << el;
        return 0;
    }

    vector <pii> v;
    int cnt=maks,len=0;
    for (int i=2;i<=n;i++){
        v.pb(mp(1,i));
        len++;
    }

    vector <pii> bisa;
    for (int i=2;i<n;i++){
        for (int j=i+1;j<=n;j++){
            bisa.pb(mp(i,j));
        }
    }

    int id=0,blen=bisa.size();
    while (cnt>k && id<blen){
        v.pb(bisa[id]);
        cnt--;
        len++;
        id++;
    }

    cout << len << el;
    for (auto x : v){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}