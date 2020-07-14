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

ll a, b, c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    if (a + b >= c){
        cout << "No" << el;
        return 0;
    }
    c = c - a - b;
    if (c * c > 4 * a * b){
        cout << "Yes" << el;
    } else{
        cout << "No" << el;
    }

    return 0;
}