#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1){
        cout << "a" << el;
        return 0;
    } else if (n == 2){
        cout << "aa" << el;
        return 0;
    } else if (n == 3){
        cout << "aba" << el;
        return 0;
    }
    for (int i=0;i<n;i++){
        cout << char((i % 3) + 'a');
    }
    cout << el;

    return 0;
}