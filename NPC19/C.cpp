#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;
using namespace __gnu_pbds;

typedef tree<pii,null_type,less<pii>,rb_tree_tag,
    tree_order_statistics_node_update> indexed_set;

ll ans=0;
int bit[11][100010];
int n,m;
int ar[11][100010];
int cnton,mxon;
indexed_set urut;
 
void upd(int lv,int id, int val){
    while (id<100001){
        bit[lv][id]+=val;
        id=id+(id&(-id));
    }
}
 
int ask(int lv,int a, int b){
    int resa=0,resb=0;
 
    a--;
    while (a>0){
        resa+=bit[lv][a];
        a=a-(a&(-a));
    }
 
    while (b>0){
        resb+=bit[lv][b];
        b=b-(b&(-b));
    }
 
    return resb-resa;
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;mxon=n*m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> ar[i][j];
            if (ar[i][j]){
                upd(i,j,1);
                cnton++;
                urut.insert(mp(i,j));
            }
        }
    }

    int q;
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        if (s[1]=='F'){
            cout << mxon-cnton << el;
            continue;
        } 

        if (s[0]=='O'){
            cout << cnton << el;
            continue;
        }

        if (s[0]=='T'){
            int k,i;
            cin >> k >> i;
            if (ask(k,i,i)){
                upd(k,i,-1);
                urut.erase(urut.find(mp(k,i)));
                cnton--;
            }
            else{
                upd(k,i,1);
                urut.insert(mp(k,i));
                cnton++;
            }
            cout << "DONE" << el;
            continue;
        }

        if (s[0]=='C'){
            int k,i,j;
            cin >> k >> i >> j;
            cout << ask(k,i,j) << el;
            continue;
        } 

        int x;
        cin >> x;
        auto it=urut.find_by_order(x-1);
        if (it==urut.end()) cout << -1 << el;
        else {
            pii tm=*it;
            cout << tm.fi << " " << tm.se << el;
        }
    }

    return 0;
}