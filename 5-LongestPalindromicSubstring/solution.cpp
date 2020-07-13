
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief brute force solution
 * 
 * @TIMECOMPLEXITY O(n^3)
 * @SPACECOMPLEXITY O(1)
 */
class Solution {
public:
    string longestPalindrome(string s) {
        std::string result;
        const std::size_t len = s.length();
        for (std::size_t i = 0u; i < len; i++) {
            for (std::size_t j = i + 1u; j <= len; j++) {
                const std::string substr = s.substr(i, j - i);
                if (isPalindrome(substr) && substr.length() > result.length()) {
                    result = substr;
                }
            }
        }
        return result;
    }
    
private:
    bool isPalindrome(const std::string& str) const {
        const std::size_t len = str.length();
        const std::size_t half_len = len / 2;
        for (std::size_t i = 0u; i < half_len; i++) {
            if (str[i] != str[len - 1u - i]) {
                return false;
            }
        }
        return true;
    }
};

/**
 * @brief dynamic programming
 * 
 */
class Solution2 {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        std::vector<std::vector<bool> > dp(N, std::vector<bool>(N, false));

        int left = 0;
        int right = 0;


        for (int j = 0; j < N; j++)
        {
            for (int i = j; i >= 0; i--)
            {
                dp[i][j] = (s[i] == s[j]) && (j - i > 2 ? dp[i+1][j-1] : true);

                if (dp[i][j] && (j - i) > (right - left))
                {
                    right = j;
                    left = i;
                }
            }
        }

        return s.substr(left, right - left + 1u);
    }
};

int main()
{
    const std::string test = "flsuqzhtcahnyickkgtfnlyzwjuiwqiexthpzvcweqzeqpmqwkydhsfipcdrsjkefehhesubkirhalgnevjugfohwnlhbjfewiunlgmomxkafuuokesvfmcnvseixkkzekuinmcbmttzgsqeqbrtlwyqgiquyylaswlgfflrezaxtjobltcnpjsaslyviviosxorjsfncqirsjpkgajkfpoxxmvsyynbbovieoothpjgncfwcvpkvjcmrcuoronrfjcppbisqbzkgpnycqljpjlgeciaqrnqyxzedzkqpqsszovkgtcgxqgkflpmrikksaupukdvkzbltvefitdegnlmzeirotrfeaueqpzppnsjpspgomyezrlxsqlfcjrkglyvzvqakhtvfmeootbtbwfhqucbnuwznigoyatvkocqmbtqghybwrhmyvvuchjpvjckiryvjfxabezchynfxnpqaeampvaapgmvoylyutymdhvhqfmrlmzkhuhupizqiujpwzarnszrexpvgdmtoxvjygjpmiadzdcxtggwamkbwrkeplesupagievwsaaletcuxtpsxmbmeztcylsjxvhzrqizdmgjfyftpzpgxateopwvynljzffszkzzqgofdlwyknqfruhdkvmvrrjpijcjomnrjjubfccaypkpfokohvkqndptciqqiscvmpozlyyrwobeuazsawtimnawquogrohcrnmexiwvjxgwhmtpykqlcfacuadyhaotmmxevqwarppknoxthsmrrknu";

    // brute force
    Solution s1;
    std::string result = s1.longestPalindrome(test);
    std::cout << "s1 = " << result << std::endl;

    // dynamic programming
    Solution2 s2;
    result = s2.longestPalindrome(test);
    std::cout << "s2 = " << result << std::endl;
}