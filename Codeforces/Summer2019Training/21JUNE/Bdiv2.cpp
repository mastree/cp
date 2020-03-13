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
    ll ar[n],neg=0,tot=1;
    for (ll i=0;i<n;i++){
        cin >> ar[i];
        if (ar[i]>=0){
            ar[i]=-ar[i]-(ll)1;
        }
    //    tot*=ar[i];
        neg++;
    }

    if (n==1){
        cout << max(ar[0],-ar[0]-(ll)1) << el;
        return 0;
    }

    if (neg%2==0){
        for (ll i=0;i<n;i++){
            cout << ar[i] << " ";
        }
        cout << el;
        return 0;
    }

    ll maks=-ar[0]-1,id=0;
    ar[0]=maks;
    for (ll i=1;i<n;i++){
        if ((-ar[i]-1)*(maks+1)>(-maks)*ar[i]){
            ar[i]=-ar[i]-1;
            ar[id]=-ar[id]-1;
            id=i;
            maks=ar[id];
        }
    }

//    ar[id]=-ar[id]-(ll)1;

    for (ll i=0;i<n;i++){
        cout << ar[i] << " ";
    }

    cout << el;

    return 0;
}