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

int q;
int n;
string s;
int od, ev;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> s;

        vector <char> v;
        for (int i=0;i<n;i++){
            if ((s[i] - '0') & 1) v.pb(s[i]);
        }

        if (v.size() >= 2){
            cout << v[0] << v[1] << el;
        } else{
            cout << -1 << el;
        }
    }

    return 0;
}