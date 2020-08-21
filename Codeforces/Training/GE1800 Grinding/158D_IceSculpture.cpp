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
    int tot=0;
    int ar[n];
    for (int i=0;i<n;i++){
        cin >> ar[i];
        tot+=ar[i];
    }

    vector <int> fac;
    for (int i=2;i*i<=n;i++){
        if (n%i==0){
            fac.pb(i);
            if (i!=n/i) fac.pb(n/i);
        }
    }

    for (auto x : fac){
    //    cout << x << el;
        int tm;
        if (n/x<3) continue;
        for (int awal=0;awal<x;awal++){
            tm=0;
        //    cout << awal << el;
            for (int i=0;i<n;i+=x){
                tm+=ar[i+awal];
        //        cout << ar[i+awal] << " ";
            }
        //    cout << el << tm << el;
            tot=max(tot,tm);
        }
    }

    cout << tot << el;

    return 0;
}