#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class LRUCache
{

private:
    int capacity;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> um;

public:
    LRUCache(int c)
    {
        this->capacity = c;
    }
    int get(int key)
    {
        if (um.find(key) == um.end())
            return -1;

        l.splice(l.begin(), l, um[key]);
        return um[key]->second;
    }
    void put(int key, int value)
    {
        if (get(key) != -1)
        {
            um[key]->second = value;
            return;
        }
        if(l.size() ==capacity)
        {
            int lastKey = l.back().first;
            l.pop_back();
            um.erase(lastKey);
        }
        //l.push_front({key,value});
        l.emplace_front(key,value);
        um[key] =l.begin();
    }
};

int main()
{
    LRUCache obj(3);
    obj.put(1,10);
    obj.put(2,20);
    obj.put(3,30);
    obj.get(2);
    obj.put(4,40);
    obj.put(5,50);

    return 0;
}
