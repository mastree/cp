#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define double long double

const double pi = atan(1)*4;
const double EPS = 1e-9;
int ans;
struct point
{
    double x1,y1,x2,y2;
    double sudut()
    {
        if(x2-x1 == 0){
            if(y2>y1) return 90;
            else return 270;
        }
        double ret = atan((y2-y1)/(x2-x1)) * 180 / pi;
        //cout << ret << '\n';
        if(ret < 0) ret += 360;
        if(x2 > x1){
            //<90 atau >270
            if(90 < ret && ret < 180) return ret+180;
            if(180<ret && ret < 270) return ret-180;
            return ret;
        }
        else{
            //90<x<270
            if(90 > ret) return ret+180;
            if(270 < ret) return ret-180;
            return ret;
        }
    }
    double len()
    {
        return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }
    bool cross(point o,double l,double u)
    {
        double penyebut = (x2-x1)*(o.y2-o.y1) - (y2-y1)*(o.x2-o.x1);
        double pembilang1 = (o.x1-x1)*(o.y2-o.y1) - (o.y1-y1)*(o.x2-o.x1);
        double pembilang2 = (o.x1-x1)*(y2-y1) - (o.y1-y1)*(x2-x1);
        //cout << pembilang << ' ' << penyebut << '\n';
        if(penyebut == 0) return 0;
        if(pembilang1/penyebut + EPS < l || u < pembilang1/penyebut - EPS) return 0;
        if(pembilang2/penyebut + EPS < l || u < pembilang2/penyebut - EPS) return 0;
        return 1;
    }
    void print()
    {
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }
};

void inputpoint(point &s)
{
    cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;
}

void solvekombin(point s1,point s2,point s3)
{
    //s1 s2 common endpoint
    if(s1.x1 != s2.x1 || s1.y1 != s2.y1) return;
    //s1 s2 sudut
    if(!(0 < s2.sudut() - s1.sudut() + EPS && s2.sudut() - s1.sudut() - EPS < 90)) return;
    //s1 >= 2*s2
    if(s1.len() < 2*s2.len()) return;
    //s3 berpotongan dengan s1
    if(!(s3.cross(s1,((double)1)/((double)3),0.75))) return;
    // if (s3.cross(s1, ))
    //s3 tidak berpotongan dengan s2
    if(s3.cross(s2,0,1)) return;
    //sudut s1 s3
    //cout << s1.sudut() << ' ' << s3.sudut() << '\n';
    //s1.print(); s3.print();
    if(s1.sudut() - s3.sudut() - EPS >= 120 || s1.sudut() - s3.sudut() + EPS <= 60) return;

    ans = 1;
}

void solve()
{
    ans = 0;
    point s1,s2,s3;
    inputpoint(s1);
    inputpoint(s2);
    inputpoint(s3);
    //cout << s1.sudut() << ' ' << s2.sudut() << ' ' << s3.sudut() << ' ' << pi << '\n';

    forn(i,8){
        //cout << "KOMBINASI : " << i << '\n';
        if(i&1) swap(s1.x1,s1.x2) , swap(s1.y1,s1.y2);
        if(i&2) swap(s2.x1,s2.x2) , swap(s2.y1,s2.y2);
        if(i&4) swap(s3.x1,s3.x2) , swap(s3.y1,s3.y2);
        //cout << 'a';
        solvekombin(s1,s2,s3);
        //cout << 'b';
        solvekombin(s1,s3,s2);
        //cout << 'c';
        solvekombin(s2,s1,s3);
        //cout << 'd';
        solvekombin(s2,s3,s1);
        //cout << 'e';
        solvekombin(s3,s1,s2);
        //cout << 'f';
        solvekombin(s3,s2,s1);
        if(i&1) swap(s1.x1,s1.x2) , swap(s1.y1,s1.y2);
        if(i&2) swap(s2.x1,s2.x2) , swap(s2.y1,s2.y2);
        if(i&4) swap(s3.x1,s3.x2) , swap(s3.y1,s3.y2);
        if (ans) break;
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main()
{
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
/*
1
0 0 4 0
4 0 4 -1
2 2 2 -4
*/
