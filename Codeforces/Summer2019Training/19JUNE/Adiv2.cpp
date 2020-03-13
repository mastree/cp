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

    int ar[3],d;

    for (int i=0;i<3;i++) cin >> ar[i];
    cin >> d;
    sort(ar,ar+3);

    int tot=0;
    for (int i=0;i<2;i++){
        if (ar[i+1]-ar[i]<d){
            tot+=(d-ar[i+1]+ar[i]);
        }
    }

    cout << tot << el;

    return 0;
}