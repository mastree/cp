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

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        int n,x;
        cin >> n >> x;

        int mk=0,md=0;
        for (int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            md=max(md,a-b);
            mk=max(mk,a);
        }

        if (x<=mk){
            cout << 1 << el;
            continue;
        }
        if (md<=0){
            cout << -1 << el;
            continue;
        }
        
        cout << (x-mk+md-1)/md+1 << el;
    }

    return 0;
}