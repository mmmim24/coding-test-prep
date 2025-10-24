#include <bits/stdc++.h>
using namespace std;
class RandomizedSet
{

    vector<int> rset;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
    }

    bool search(int val)
    {
        if (mp.find(val) != mp.end())
            return true;
        else
            return false;
    }

    bool insert(int val)
    {
        if (search(val))
            return false;
        else
        {
            rset.push_back(val);
            mp[val] = rset.size() - 1;
            return true;
        }
    }

    bool remove(int val)
    {
        if (search(val))
        {
            auto it = mp.find(val);
            rset[it->second] = rset.back();
            rset.pop_back();
            mp[rset[it->second]] = it->second;
            mp.erase(val);
            return true;
        }
        else
            return false;
    }

    int getRandom()
    {
        return rset[rand() % rset.size()];
    }
};
int main()
{
    RandomizedSet *obj = new RandomizedSet();
    cout << obj->insert(1) << endl;
    cout << obj->remove(2) << endl;
    cout << obj->getRandom() << endl;
    return 0;
}