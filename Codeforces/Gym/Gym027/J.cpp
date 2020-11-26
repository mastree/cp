#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 100;

int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int tot = 0;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        tot += a + i;
    }
    if (tot % 7 == 0){
        cout << "yes" << el;
        return 0;
    }
    cout << "no" << el;

    return 0;
}