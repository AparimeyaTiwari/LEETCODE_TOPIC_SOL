#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::min and std::fill
using namespace std;

/*
 Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 Example 1:

 Input: words = ["bella","label","roller"]
 Output: ["e","l","l"]

 Example 2:

 Input: words = ["cool","lock","cook"]
 Output: ["c","o"]

 Constraints:

 1 <= words.length <= 100
 1 <= words[i].length <= 100
 words[i] consists of lowercase English letters.
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int vec_size = words.size();
        vector<int> commoncharcnt(26, INT_MAX);
        vector<int> currentcharcnt(26);
        vector<string> result;

        // Initialize commoncharcnt with the first word
        for (char &ch : words[0]) {
            commoncharcnt[ch - 'a']++;
        }

        // Process the remaining words
        for (int i = 1; i < vec_size; i++) {
            fill(currentcharcnt.begin(), currentcharcnt.end(), 0);
            for (char &ch : words[i]) {
                currentcharcnt[ch - 'a']++;
            }
            for (int letter = 0; letter < 26; letter++) {
                commoncharcnt[letter] = min(currentcharcnt[letter], commoncharcnt[letter]);
            }
        }

        // Collect the result
        for (int letter = 0; letter < 26; letter++) {
            for (int common = 0; common < commoncharcnt[letter]; common++) {
                result.push_back(string(1, letter + 'a'));
            }
        }

        return result;
    }
};

void printResult(const vector<string>& result) {
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    Solution s1;
    vector<string> v1{"bella", "label", "roller"};
    vector<string> v2{"cool", "lock", "cook"};

    vector<string> result1 = s1.commonChars(v1);
    vector<string> result2 = s1.commonChars(v2);

    cout << "Common characters in v1: ";
    printResult(result1);

    cout << "Common characters in v2: ";
    printResult(result2);

    return 0;
}

