#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib> // For rand() function
using namespace std;

class RandomizedSet {
private:
    vector<int> a; // array vector
    unordered_map<int, int> m; // Unordered Map for quick search, insert, and delete
public:
    RandomizedSet() {
        // No need to initialize a & m as they are automatically initialized to default values.
    }

    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        else {
            a.push_back(val);
            m[val] = a.size() - 1;
            return true;
        }
    }

    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        else {
            int last = a.back();
            a[m[val]] = last;
            a.pop_back();
            m[last] = m[val];
            m.erase(val);
            return true;
        }
    }

    int getRandom() {
        return a[rand() % a.size()];
    }
};

int main() {
    RandomizedSet randomizedSet;

    randomizedSet.insert(1);
    randomizedSet.insert(2);
    randomizedSet.insert(3);

    cout << randomizedSet.getRandom() << endl;  // Get a random element

    randomizedSet.remove(2);

    cout << randomizedSet.getRandom() << endl;  // Get a random element after removal

    return 0;
}
