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

ll n,m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    if (n>m) swap(n,m);
    if (n==1){
        cout << (m+1)/3 << el;
        return 0;
    }
    else if(n==2){
        cout << (m+1)/2 << el;
        return 0;
    }

    if (m%2>0 && n%2==0) swap(n,m);
    ll tot=0;
    
    
    if ((n+1)%3!=2){
        tot+=(n+1)/3*2;
        m-=2;
    } else {
        tot+=(n+1)/3*2;
    }
    if (m<=0){
        cout << tot << el;
        return 0;
    }
  //  cerr << tot << el;
    if ((n+1)%3!=2){
        tot+=(m-1)/3*2;
        n-=2;
    } else {
        tot+=(m+1)/3;
        n-=1;
        m-=2;
    }
  //  cerr << tot << el;
    ll tm1=0,tm2=0;
    tm1+=(n/3)*(m/4);
    tm2+=(n/4)*(m/3);
    tm1+=((m%4)/3)*(n/4);
    tm2+=((n%4)/3)*(m/4);
    tot+=max(tm1,tm2);
    cout << tot << el;

    return 0;
}