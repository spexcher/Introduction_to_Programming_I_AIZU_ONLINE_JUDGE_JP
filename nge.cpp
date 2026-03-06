
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    // for (int x : v)
    // {
    //     cout << x << " ";
    // }
    cout << endl;
    
    stack<int> mdec;
    vector<int> pse(n);
    pse[0] = -1;
    mdec.push(*begin(v));
    for (int i = 1; i <=n-1; i++)
    {
        while (!mdec.empty() and v[i] <= mdec.top())
        {
            mdec.pop();
        }
        if (mdec.empty())
            pse[i] = -1;
        else
            pse[i] = mdec.top();
        mdec.push(v[i]);
    }
    for (int x : pse)
    {
        cout << x << " ";
    }

    return 0;
}