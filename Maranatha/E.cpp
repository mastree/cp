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

    int q;
    cin >> q;

    while (q--){
        int n,tot=0;
        cin >> n;
        int ar[n];
        for (int i=0;i<n;i++) {
            cin >> ar[i];
            tot+=ar[i];    
        }

        bool bisa=1;
        for (int i=0;i<n;i++){
            if (ar[i]>tot-ar[i]){
                bisa=0;
                break;
            }
        }

        if (bisa) cout << "true" << el;
        else cout << "false" << el; 
    }

    return 0;
}