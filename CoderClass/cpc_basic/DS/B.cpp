#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

deque<string> deq;
int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            string s;
            cin >> s;
            deq.push_front(s);
        } else if (tipe == 2){
            string s;
            cin >> s;
            deq.push_back(s);
        } else if (tipe == 3){
            cout << deq.front() << el;
            deq.pop_front();
        } else{
            cout << deq.back() << el;
            deq.pop_back();
        }
    }

    return 0;
}