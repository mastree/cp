#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll ar[4];
ll quer;
int feed;
int urut[4] = {0, 1, 2, 3};

bool comp(int a, int b){
    return ar[a] < ar[b];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<=3;i++){
        cin >> ar[i];
    }
    cout << "First" << endl;
    sort(urut + 1, urut + 4, comp);
    quer = ar[urut[3]] - ar[urut[1]];
    cout << quer << endl;
    cin >> feed;
    if (feed == 0) return 0;

    ar[feed] += quer;
    sort(urut + 1, urut + 4, comp);
    quer = 2 * ar[urut[3]] - ar[urut[1]] - ar[urut[2]];
    cout << quer << endl;
    cin >> feed;
    if (feed == 0) return 0;

    ar[feed] += quer;
    sort(urut + 1, urut + 4, comp);
    quer = ar[urut[2]] - ar[urut[1]];
    cout << quer << endl;
    cin >> feed;
    if (feed == 0) return 0;

    return 0;
}