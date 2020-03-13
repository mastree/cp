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
ll ar[3];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        for (int i=0;i<3;i++){
            cin >> ar[i];
        }
        sort(ar, ar + 3);
        if (ar[2] <= ar[0]+ar[1] + 1){
            cout << "Yes" << el;
        } else{
            cout << "No" << el;
        }
    }

    return 0;
}