#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> frequency;
        int duplicatedNumber, missingNumber;

        // Count the frequency of each number in the array
        for (int num : nums) {
            frequency[num]++;
        }

        // Find the duplicated and missing numbers
        for (int i = 1; i <= nums.size(); i++) {
            if (frequency[i] == 2) {
                duplicatedNumber = i;
            } else if (frequency[i] == 0) {
                missingNumber = i;
            }
        }

        return {duplicatedNumber, missingNumber};
    }
};

int main() {
    // Example usage
    vector<int> nums = {1, 2, 2, 4};
    
    Solution solution;
    vector<int> result = solution.findErrorNums(nums);

    // Display the result
    cout << "Duplicated Number: " << result[0] << endl;
    cout << "Missing Number: " << result[1] << endl;

    return 0;
}
