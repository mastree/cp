#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> vec(n);
    for (int i=0;i<n;i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    deque<int> deq;
    for (auto& x : vec){
        deq.push_back(x);
    }
    vector<int> ans;
    for (int i=0;i<n;i++){
        if (i & 1){
            ans.push_back(deq.front());
            deq.pop_front();
        } else{
            ans.push_back(deq.back());
            deq.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) cout << x << ' '; cout << el;

    return 0;
}