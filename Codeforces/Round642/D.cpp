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

const int N = 2e5 + 10;

int q;
int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        priority_queue<pair<int, pii>> pq;
        pq.push(mp(n, mp(-1, -n)));
        int id = 0;
        while (!pq.empty()){
            id++;
            auto temp = pq.top();
            pq.pop();

            int len = temp.fi;
            pii range = mp(-temp.se.fi, -temp.se.se);
            // if (id == 1) cout << range.fi << " " << range.se << " " << (range.fi + range.se) / 2 << el;
            ar[(range.fi + range.se) / 2] = id;
            if (len == 1) continue;
            int lenle = (len + 1) / 2 - 1;
            int lenri = len - lenle - 1;
            pii rangele = mp(-range.fi, -(range.fi + lenle - 1));
            pii rangeri = mp(-(range.se - lenri + 1), -range.se);

            if (lenle != 0) pq.push(mp(lenle, rangele));
            pq.push(mp(lenri, rangeri));
        }
        for (int i=1;i<=n;i++){
            cout << ar[i] << " ";
        }
        cout << el;
    }

    return 0;
}