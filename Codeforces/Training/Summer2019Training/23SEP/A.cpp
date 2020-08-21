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

    int ar[4];
    for (int i=0;i<4;i++){
        cin >> ar[i];
    }

    sort(ar,ar+4);
    int tot=0;
    for (int i=0;i<4;i++){
        tot+=ar[i];
    }

    int cur=0;
    for (int i=0;i<4;i++){
        cur=0;
        for (int j=i;j<4;j++){
            cur+=ar[j];
            if (cur==tot-cur){
                cout << "YES" << el;
                return 0;
            }
        }
    }

    cout << "NO" << el;


    return 0;
}