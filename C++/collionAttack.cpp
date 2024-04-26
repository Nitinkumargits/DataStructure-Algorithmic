#include <bits/stdc++.h>
using namespace std;

struct gfg_custom_hash
{
    static uint64_t splitmix64(uint64_t key)
    {
        key += 0x9e3779b97f4a7c15;
        key = (key ^ (key >> 30)) * 0xbf58476d1ce4e5b9;
        key = (key ^ (key >> 27)) * 0x94d049bb133111eb;
        return key ^ (key >> 31);
    }

    // function to make the hash function non-deterministic
    size_t operator()(uint64_t x) const
    {
        static const uint64_t RANDOM = chrono::steady_clock::now()
                                           .time_since_epoch()
                                           .count();
        return splitmix64(x + RANDOM);
    }
};

int main()
{
    // Passing the custom hash function for the
    // unordered map
    unordered_map<long long, int, gfg_custom_hash> mp;
    mp[1] = 10;
    mp[2] = 20;
    for (auto ele : mp)
    {
        cout << ele.first << " " << ele.second << "\n";
    }

    // Passing the custom hash function for the
    // unordered set
    unordered_set<long long, gfg_custom_hash> st;
    st.insert(1);
    st.insert(2);
    for (auto ele : st)
        cout << ele << " ";
    cout << "\n";

    return 0;
}
