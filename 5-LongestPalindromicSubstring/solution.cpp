
#include <iostream>
#include <string>

using namespace std;

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

int main()
{
    const std::string test = "flsuqzhtcahnyickkgtfnlyzwjuiwqiexthpzvcweqzeqpmqwkydhsfipcdrsjkefehhesubkirhalgnevjugfohwnlhbjfewiunlgmomxkafuuokesvfmcnvseixkkzekuinmcbmttzgsqeqbrtlwyqgiquyylaswlgfflrezaxtjobltcnpjsaslyviviosxorjsfncqirsjpkgajkfpoxxmvsyynbbovieoothpjgncfwcvpkvjcmrcuoronrfjcppbisqbzkgpnycqljpjlgeciaqrnqyxzedzkqpqsszovkgtcgxqgkflpmrikksaupukdvkzbltvefitdegnlmzeirotrfeaueqpzppnsjpspgomyezrlxsqlfcjrkglyvzvqakhtvfmeootbtbwfhqucbnuwznigoyatvkocqmbtqghybwrhmyvvuchjpvjckiryvjfxabezchynfxnpqaeampvaapgmvoylyutymdhvhqfmrlmzkhuhupizqiujpwzarnszrexpvgdmtoxvjygjpmiadzdcxtggwamkbwrkeplesupagievwsaaletcuxtpsxmbmeztcylsjxvhzrqizdmgjfyftpzpgxateopwvynljzffszkzzqgofdlwyknqfruhdkvmvrrjpijcjomnrjjubfccaypkpfokohvkqndptciqqiscvmpozlyyrwobeuazsawtimnawquogrohcrnmexiwvjxgwhmtpykqlcfacuadyhaotmmxevqwarppknoxthsmrrknu";

    Solution ss;
    const std::string result = ss.longestPalindrome(test);
    std::cout << result << std::endl;
}