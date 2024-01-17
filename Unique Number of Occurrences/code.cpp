#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        // Use unordered_map for better flexibility
        std::unordered_map<int, int> frequency;

        // Count occurrences of each element in arr
        for (int i = 0; i < arr.size(); i++) {
            frequency[arr[i]]++;
        }

        // Check for unique occurrences
        std::unordered_set<int> uniqueCounts;
        for (const auto& entry : frequency) {
            if (!uniqueCounts.insert(entry.second).second) {
                // If insertion fails, it means the count is not unique
                return false;
            }
        }

        return true;
    }
};

int main() {
    // Input
    std::vector<int> arr = {1, 2, 2, 1, 1, 3};

    // Create an instance of the Solution class
    Solution solution;

    // Check if occurrences are unique
    bool result = solution.uniqueOccurrences(arr);

    // Output the result
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}
