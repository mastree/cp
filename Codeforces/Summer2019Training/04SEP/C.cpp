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

    int ar[2*n+1];

    int cur=0;
    for (int i=1;i<=n;i++){
        cur++;
        if (i%2){
            ar[i]=cur;
            cur++;
            ar[i+n]=cur;
        } else{
            ar[i+n]=cur;
            cur++;
            ar[i]=cur;
        }
    }

    ll pc[2*n+1],mn=100000000000,mx=0;
    pc[0]=0;
    for (int i=1;i<=2*n;i++){
        pc[i]=pc[i-1]+ar[i];
    }

    for (int i=1;i<=2*n;i++){
        int j=i+n-1;
        if (j<=2*n){
            ll tm=pc[j]-pc[i-1];
            mn=min(mn,tm);
            mx=max(mx,tm);
        } else{
            j%=2*n;
            ll tm=pc[2*n]-pc[i-1]+pc[j];
            mn=min(mn,tm);
            mx=max(mx,tm);
        }
    }

  //  cout << mx << " " << mn << el;
    if (mx-mn<=1){
        cout << "YES" << el;
        for (int i=1;i<=2*n;i++) cout << ar[i] << " ";
        cout << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}