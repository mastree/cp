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

int n,len;
int ar[500];
int tot,cnt0;

vector <int> pos,neg;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    len=2*n-1;

    for (int i=0;i<len;i++){
        cin >> ar[i];
        tot+=abs(ar[i]);

        if (ar[i]>0) pos.pb(ar[i]);
        else if (ar[i]<0) neg.pb(ar[i]);
        else cnt0++;
    }

    if ((n%2) || (cnt0>0) || neg.empty() || (neg.size()%2==0)){
        cout << tot << el;
        return 0;
    }

    sort(neg.begin(),neg.end());
    int lastn=neg.size();
    if (pos.empty()){
        cout << tot+2*neg[lastn-1] << el;
        return 0;
    }

    
    sort(pos.begin(),pos.end());

    cout << max(tot+2*neg[lastn-1],tot-2*pos[0]) << el;

    return 0;
}