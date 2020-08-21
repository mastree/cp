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

ll h;
ll tot;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h;
    ll cur = 1;
    while (h>0){
        tot+=cur;
        cur*=2;
        h/=2;
    }   
    cout << tot << el;

    return 0;
}