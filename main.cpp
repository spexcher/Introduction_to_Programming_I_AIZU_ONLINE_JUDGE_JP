
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    v.erase(remove(begin(v), end(v), 2), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    string s = "125464.546";
    //          0123456789
    int denom = pow(10, s.size() - 1 - (find(begin(s), end(s), '.') - begin(s)));
    s.erase(remove(begin(s), end(s), '.'), end(s));
    int num = stoi(s);
    cout << num << " " << denom;
    return 0;
}