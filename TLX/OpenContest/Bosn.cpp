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

int r,c,q;
vector <pii> v;
map <pii,bool> cek;
int ans[2][51];

void ask(int a,int b){
    cout << "? " << a << " " << b << el;
    cout << flush;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> q;

    if (r<=10 && c<=10 && q==100){
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                int tm;
                ask(i,j);
                cin >> tm;
                if (tm==0) v.pb(mp(i,j));
            }
        }

        if (v.size()==1){
            cout << "! " << v[0].fi << " " << v[0].se << " " << v[0].fi << " " << v[0].se << el;
        } else cout << "! " << v[0].fi << " " << v[0].se << " " << v[1].fi << " " << v[1].se << el;
        cout << flush;
        return 0;
    }

    if (r==1){
        int tm;
        ask(1,1);
        cin >> tm;
        int tm2;
        ask(1,c);
        cin >> tm2;
        cout << "! " << "1 " << tm+1 << " " << "1 " << c-tm2 << el;
        cout << flush;

        return 0;
        
    }

    if (r<=50 && c<=50 && q==100){
        int min1=MOD,min2=MOD;
        for (int i=1;i<=r;i++){
            ask(i,1);
            cin >> ans[0][i];
            min1=min(min1,ans[0][i]);
        }

        for (int i=1;i<=r;i++){
            ask(i,c);
            cin >> ans[1][i];
            min2=min(min2,ans[1][i]);
        }

        cout << "! ";
        for (int i=1;i<=r;i++){
            if (ans[0][i]==min1){
                cout << i << " " << min1+1 << " ";
                break; 
            }
        }
        
        for (int i=r;i>=1;i--){
            if (ans[1][i]==min2){
                cout << i << " " << c-min2 << el;
                break; 
            }
        }
        cout << flush;
        return 0;
    }
    
    int tm1,tm2;
    ask(1,1);
    cin >> tm1;
    //tm1=1+tm1/2;

 //   int mn=min(r,c);
    ask(1,c);
    cin >> tm2;
    //tm2=mn-tm2/2;

    int x,y;
    y=(tm1+tm2-c+3)/2;
    x=(tm1-tm2+1+c)/2;
    cout << "! " << y << " " << x << " " << y << " " << x << el;
    cout << flush;

    return 0;
}