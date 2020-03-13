#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define el '\n'

using namespace std;

int s,b;
pll ar[100006];
ll pc[100006];

int binser(ll tar){
    int low=0,high=b-1;

    while (low<high){
        int mid=(low+high+1)/2;

        if (ar[mid].fi<=tar){
            low=mid;
        }else{
            high=mid-1;
        }
    }

    return low;

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> s >> b;

    ll at[s];
    for (int i=0;i<s;i++){
        cin >> at[i];
    }

    for (int i=0;i<b;i++){
        cin >> ar[i].fi >> ar[i].se;
    }

    sort(ar,ar+b);
    for (int i=0;i<b;i++){
        pc[i+1]+=pc[i]+ar[i].se;
    }

    for (int i=0;i<s;i++){
        if (ar[0].fi>at[i]){
            cout << 0 << " ";
            continue;
        }
        int tm=binser(at[i]);
        cout << pc[tm+1] << " ";
    }
    cout << el;

    return 0;
}