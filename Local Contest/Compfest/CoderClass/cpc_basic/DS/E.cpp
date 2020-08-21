#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using namespace __gnu_pbds; 
using ll = long long;
using pii = pair<int, int>;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    ordset;

int q;
ordset ar; 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        int a;
        cin >> a;
        ar.insert(mp(a, i));
        if (i & 1){
            cout << ar.find_by_order(i / 2)->fi << el;
        } else{
            int temp = (ar.find_by_order(i / 2)->fi + ar.find_by_order((i - 1) / 2)->fi);
            if (temp & 1){
                cout << temp / 2 << ".5" << el;
            } else cout << temp / 2 << el;
        }
    }

    return 0;
}