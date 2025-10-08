#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    vector<string> strs= {"flower","flow","flight"};
    string prefix = "";
    if(strs.empty())
        cout<<prefix<<endl;
    for(int i = 0; i < strs[0].size(); i++)
    {
        for(int j = 1; j < strs.size(); j++)
        {
            if(i >= strs[j].size() || strs[j][i] != strs[0][i])
            {
                cout << "strs[j][i]"<<strs[j][i]<<endl;
                cout<<"strs[0][i]"<<strs[0][i]<<endl;
                //cout<<"Rama "<<prefix<<endl;
            }
        }
        cout<<"strs[0][i]"<<strs[0][i]<<endl;
        prefix += strs[0][i];
    }
    cout << "Rama "<<prefix<<endl;
    return 0;
}