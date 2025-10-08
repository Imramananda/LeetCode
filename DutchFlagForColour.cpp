#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> v = {"blue","red", "black", "red", "blue", "black", "red", "black", "blue"};
    int lo = 0, mid = 0, hi = v.size() - 1;
    while (mid <= hi)
    {
        if (v[mid] == "blue")
        {
            swap(v[mid], v[lo]);
            mid++;
            lo++;
        }
        else if (v[mid] == "red")
        {
            swap(v[mid], v[hi]);
            hi--;
        }
        else
            mid++;
    }
    for (auto num : v)
        cout << num << " ";
    cout << endl;
    return 0;
}