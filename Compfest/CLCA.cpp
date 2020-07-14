#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define el '\n'
#define MOD 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fr front

int ar[1001];
pair <int,int> path[2002], stree[10000];

void constree(int l, int r, int pos){
    if (l==r) stree[pos]=mp(path[l].se,l);
    else {
        int mid=(l+r)/2;
        constree(l,mid,pos*2+1);
        constree(mid+1,r,pos*2+2);

        stree[pos]=min(stree[pos*2+1],stree[pos*2+2]);
    }
}

pair<int,int> cari(int ql, int qr, int l, int r, int pos){
    if (l>=ql && r<=qr) return stree[pos];
    if (r<ql || l>qr) return {MOD,0};

    int mid=(l+r)/2;
    return min(cari(ql,qr,l,mid,pos*2+1),cari(ql,qr,mid+1,r,pos*2+2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    int cas=0;

    while (tc--){
        cas++;
        int n;
        cin >> n;

        queue <int> adlist[n];
        for (int i=0;i<n;i++){
            int b;
            cin >> b;
            for (int j=0;j<b;j++){
                int tm;
                cin >> tm;
                adlist[i].push(tm-1);
            }
        }

        stack <int> st;
        st.push(0);
        int firstap[n],depth=0,itt=0;

        for (int i=0;i<n;i++) firstap[i]=MOD;
        firstap[0]=0;

        while (!st.empty()){
            path[itt]=mp(st.top(),depth);
            int x=st.top();

            if (!adlist[x].empty()) {
                itt++;
                depth++;
                st.push(adlist[x].fr());
                path[itt]=mp(adlist[x].fr(),depth);
                firstap[adlist[x].fr()]=min(firstap[adlist[x].fr()],itt);
                adlist[x].pop();
            }
            else {
                st.pop();
                depth--;
                itt++;
            }

        }
        constree(0,itt-1,0);

        int q;
        cin >> q;
        cout << "Case " << cas << ":\n";
        while (q--){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            int p1=firstap[a],p2=firstap[b];

            pair <int,int> sim=cari(min(p1,p2),max(p1,p2),0,itt-1,0);
            cout << path[sim.se].fi+1 << el;
        }

    }
}