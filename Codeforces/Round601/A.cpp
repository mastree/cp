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

int a, b, q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){

        cin >> a >> b;

        int tm = abs(a-b);
        if (tm%5==0){
            cout << tm/5 << el;
        } else if (tm%5<=2){
            cout << tm/5 + 1 << el;
        } else{
            cout << tm/5 + 2 << el;
        }
    }
    return 0;
}