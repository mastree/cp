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

ll fpb(ll a,ll b){
    while (a%b!=0){
        ll c=b;
        b=a%b;
        a=c;
    }

    return b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    a--;

    ll cc=b/c-a/c,dd=b/d-a/d,ee=b/(c*d/fpb(c,d))-a/(c*d/fpb(c,d));

  //  cerr << cc << " " << dd << el;
    cout << b-a-cc-dd+ee << el;

    return 0;
}