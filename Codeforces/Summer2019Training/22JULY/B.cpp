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

    int ar[n],sar[n],mak=0;
    for (int i=0;i<n;i++){
        cin >> ar[i];
        sar[i]=ar[i];
        mak=max(mak,ar[i]);
    }

    for (int i=0;i<n;i++){
        if (ar[i]==mak){
            sort(sar,sar+i);
            sort(sar+i+1,sar+n,greater<int>());
            break;
        }
    }

    bool beda=0;
    for (int i=0;i<n;i++){
        if (sar[i]!=ar[i]){
            beda=1;
            break;
        }
    }

    if (beda) cout << "NO" << el;
    else cout << "YES" << el;

    return 0;
}