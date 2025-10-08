#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {2,0,2,1,1,0};
    // 1:  Brute fo{ce
    //"Brute force" refers to using excessive physical or computational power to overcome a challenge, often in a direct, unrefined way.
    //  It implies a lack of subtlety or finesse, relying instead on sheer strength or effort.
    //  In computing, it's a method of trying every possible combination to solve a problem, like cracking a password.
    //  for(int i=0; i<v.size(); i++)
    //  {
    //      for(int j=i+1;j<v.size();j++)
    //      {
    //          if(v[i]>v[j])
    //          {
    //              int temp = v[j];
    //              v[j] =v[i];
    //              v[i]=temp;
    //          }
    //          else
    //          continue;
    //      }
    //  }

    // 2: Better than brute force
    // int count0 = 0, count1 = 0, count2 = 0;
    // for (int num : v) {
    //     if (num == 0) count0++;
    //     else if (num == 1) count1++;
    //     else count2++;
    // }
    // int idx = 0;
    // for (int i = 0; i < count0; ++i) v[idx++] = 0;
    // for (int i = 0; i < count1; ++i) v[idx++] = 1;
    // for (int i = 0; i < count2; ++i) v[idx++] = 2;

    // 3: Dutch Flag Algo
    //vector<int> v = {2,0,2,1,1,0};
    int n = v.size();
    int lo = 0, mid = 0, hi = n - 1;
    while (mid <= hi)
    {
        if (v[mid] == 0)
        {
            swap(v[mid], v[lo]);
            mid++;
            lo++;
        }
        else if (v[mid] == 2)
        {
            swap(v[mid], v[hi]);
            hi--;
        }
        else
        {
            mid++;
        }
    }

    for (auto num : v)
        cout << num << " ";
    cout << endl;

    return 0;
}