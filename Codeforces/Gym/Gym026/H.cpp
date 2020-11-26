#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

struct Person{
    string name;
    int dd, mm, yy;

    Person(){}
    bool operator<(const Person& oth){
        if (yy != oth.yy) return (yy > oth.yy);
        if (mm != oth.mm) return (mm > oth.mm);
        return (dd > oth.dd);
    }
};
int n;
Person ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].name >> ar[i].dd >> ar[i].mm >> ar[i].yy;
    }   
    sort(ar + 1, ar + n + 1);
    cout << ar[1].name << el;
    cout << ar[n].name << el;

    return 0;
}