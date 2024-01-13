#include <iostream>
#include <vector>
#include <cmath>

int minStepsToAnagram(const std::string& s, const std::string& t) {
    if (s.length() != t.length()) {
        return -1; // Strings should have the same length
    }

    // Count the occurrences of each character in both strings
    std::vector<int> count_s(26, 0); // Assuming lowercase English letters only
    std::vector<int> count_t(26, 0);

    for (char c : s) {
        count_s[c - 'a']++;
    }

    for (char c : t) {
        count_t[c - 'a']++;
    }

    // Calculate the difference in counts for each character
    int steps = 0;
    for (int i = 0; i < 26; ++i) {
        steps += std::abs(count_s[i] - count_t[i]);
    }

    // Return half of the total steps, as each step affects two characters
    return steps / 2;
}

int main() {
    // Test cases
    std::cout << minStepsToAnagram("bab", "aba") << std::endl;  // Output: 1
    std::cout << minStepsToAnagram("leetcode", "practice") << std::endl;  // Output: 5
    std::cout << minStepsToAnagram("anagram", "mangaar") << std::endl;  // Output: 0

    return 0;
}
