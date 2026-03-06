
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    vector<int> arr;
    deque<int> dq;
    while (getline(cin, s))
    {
        string temp;
        s.push_back(',');
        for (char x : s)
        {
            if (x == ',')
            {
                arr.push_back(stoi(temp));
                temp = "";
            }
            else
            {
                temp.push_back(x);
            }
        }
    }
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


