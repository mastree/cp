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

int n,q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        cin >> n;

        string s[n];
        int totlen=0, cnt1=0;
        bool od=0;
        for (int i=0;i<n;i++){
            cin >> s[i];
            totlen+=s[i].length();
            if (s[i].length()&1) od=1;
            for (int j=0;j<s[i].length();j++){
                if (s[i][j]=='1') cnt1++;
            }
        }

        if (od) {
            cout << n << el;
        } else {
            if (cnt1&1){
                cout << n-1 << el;
            } else {
                cout << n << el;
            }
        }
    }

    return 0;
}