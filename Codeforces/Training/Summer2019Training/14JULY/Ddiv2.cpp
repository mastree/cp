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
        int n,k;
        cin >> n >> k;

        if (k%3!=0){
            if (n%3==0) cout << "Bob" << el;
            else cout << "Alice" << el;
            continue;
        }

        n%=(k+1);

        if (n<k){
            if (n%3==0) cout << "Bob" << el;
            else cout << "Alice" << el;
        } else{
            if (n==k) cout << "Alice" << el;
            else cout << "Bob" << el;
        }
    }

    return 0;
}