/**
 * @brief summary
 *
 * @details don't think too much, simply loop over it and check
 *
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> codebook;
        constructCodebook(codebook);

        int result = 0;
        for (size_t i = 0; i < s.length(); i++) {
            int sign = 1;
            if (i < s.length() - 1 &&
                codebook.at(s.at(i)) < codebook.at(s.at(i + 1))) {
                sign = -1;
            }
            result += sign * codebook.at(s.at(i));
        }

        return result;
    }

private:
    void constructCodebook(unordered_map<char, int>& codebook) const {
        codebook['I'] = 1;
        codebook['V'] = 5;
        codebook['X'] = 10;
        codebook['L'] = 50;
        codebook['C'] = 100;
        codebook['D'] = 500;
        codebook['M'] = 1000;
    }
};

int main() { return 0; }