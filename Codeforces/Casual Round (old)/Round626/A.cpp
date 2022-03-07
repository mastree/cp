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

const int N = 1e2 + 10;

int q;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;

        vector <int> od, ev;
        for (int i=1;i<=n;i++){
            int a;
            cin >> a;
            if (a & 1) od.pb(i);
            else ev.pb(i);
        }

        int lenod = od.size();
        int lenev = ev.size();
        if (lenev){
            cout << 1 << el;
            cout << ev[0] << el;
            continue;
        } else if (lenod >= 2){
            cout << 2 << el;
            cout << od[0] << " " << od[1] << el;
            continue;
        } else{
            cout << -1 << el;
        }
    }

    return 0;
}