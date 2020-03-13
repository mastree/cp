#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

vector <pii> ver[10010],hor[10010]; // | __
ll ans=0;
int bit[10010];

void upd(int id, int val){
    while (id<10010){
        bit[id]+=val;
        id=id+(id&(-id));
    }
}

int ask(int a, int b){
    int resa=0,resb=0;

    a--;
    while (a>0){
        resa+=bit[a];
        a=a-(a&(-a));
    }

    while (b>0){
        resb+=bit[b];
        b=b-(b&(-b));
    }

    return resb-resa;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        a+=5001;
        b+=5001;
        c+=5001;
        d+=5001;

       // cerr << a << " " << b << " " << c << " " << d << el;

        if (a==c){
            if (b>d) swap(b,d);
            ver[a].pb(mp(b,d));
        } else {
            if (a>c) swap(a,c);
            hor[b].pb(mp(a,c));
        }

    }//cerr << el;


    for (int y=1;y<10010;y++){
        for (auto h : hor[y]){
        //    cerr << h.fi << " " << h.se << el;
            for (int i=1;i<10010;i++) bit[i]=0;

            vector <int> sim[10010];
            for (int x=h.fi;x<=h.se;x++){
                for (auto v : ver[x]){
                    if (v.fi<=y && v.se>y){
                //        cerr << x << el;
                        upd(x,1);
                        sim[v.se].pb(x);
                    }
                }
            }

            for (int y2=y+1;y2<10010;y2++){
                for (auto h2 : hor[y2]){
                    int cek;
                    if (h.fi>h2.se && h.se<h2.fi) continue;
                    cek=ask(max(h.fi,h2.fi),min(h.se,h2.se));

                    ans+=(ll)(cek*(cek-1)/2);
                }

                for (auto x : sim[y2]){
                    upd(x,-1);
                }
            }
        }
    }

    cout << ans << el;

    return 0;
}