#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MapSum {
    unordered_map<string, int> dict;
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        if (dict.count(key) == 0)
            dict[key] = val;
        else dict[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for (auto& kvp : dict)
        {
            if (kvp.first.find(prefix) != string::npos && kvp.first.find(prefix) == 0) /* 需要是前缀, 而不仅仅是子串 */
                sum += kvp.second;
        }
        return sum;
    }
};

// Test
int main()
{
    MapSum* map = new MapSum();
    map->insert("apple",3);
    int sum1 = map->sum("ap");
    cout << sum1 << endl;    
    map->insert("app",2);    
    sum1 = map->sum("ap");    
    cout << sum1 << endl;

    return 0;
}