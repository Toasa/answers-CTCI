#include <iostream>
#include <set>

using std::set;

set<set<int>> createNewPowerSet(set<set<int>> src_set, int val) {
    set<set<int>> new_set = src_set;
    for (auto iter = src_set.begin(); iter != src_set.end(); iter++) {
        set<int> tmp = *iter;
        tmp.insert(val);
        new_set.insert(tmp);
    }
    return new_set;
}

set<set<int>> createPowerSet(set<int> src_set) {
    set<int> empty = {};
    set<set<int>> power_set = {empty};
    for (auto iter = src_set.begin(); iter != src_set.end(); iter++) {
        int val = *iter;
        power_set = createNewPowerSet(power_set, val);
    }
    return power_set;
}

void set_print(set<int> s) {
    std::cout << "{";
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        std::cout << *iter << ", ";
    }
    std::cout << "}" << std::endl;
}

int main() {
    set<int> s = {1, 2, 3, 4};
    
    set<set<int>> new_s = createPowerSet(s);
    for (auto iter = new_s.begin(); iter != new_s.end(); iter++) {
        set_print(*iter);
    }
}
