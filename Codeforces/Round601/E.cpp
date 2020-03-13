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

const int N = 1e5 + 10;

int n;
int ar[N], arin[N];
int tot=0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arin[i];
        if (arin[i]) tot++;
    }

    if (tot==1){
        cout << -1 << el;
        return 0; 
    }
    int ans = n-1;
    vector <int> v;
    for (int i=2;i*i<=tot;i++){
        if (tot%i==0){
            v.pb(i);
            if (i*i!=tot) v.pb(tot/i);
        }
    }

    v.pb(tot);

    for (auto fac : v){
        int tm=0;
        for (int i=0;i<n;i++){
            ar[i]=arin[i];
        }
        for (int i=0;i<n-1;i++){
            if (ar[i]%fac!=0){
                ar[i+1]+=ar[i];
                tm++;
                // cout << i << " ";
            }
        }//cout << el;
        // cout << fac << " " << tm << el;
        if (ar[n-1]%fac==0) ans = min(ans,tm);
    }
    // cout << fac << el;

    cout << ans << el;

    return 0;
}