#pragma once
#include <vector>
#include <string>
#include <array>

namespace leetcode::strings {
template<typename StringType>
class LetterCombination {
   public:
    std::vector<std::string> letterCombinations(std::string& digits) {
        std::vector<std::string>res;
        if (digits.empty()){
            return res;
        }

        std::string buf = "";
        helper(res, digits, buf, 0);
        return res;
    }

   private:
    void helper(std::vector<std::string>&res, const std::string& digits, std::string& buf, int index){
        if (index == digits.size()){
            res.emplace_back(buf);
            return;
        }

        for (auto& c: mp[digits[index] - '2']){
            buf.push_back(c);
            helper(res, digits, buf, index + 1);
            buf.pop_back();
        }
    }
    std::array<StringType, 8> mp ={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

}  // namespace leetcode::strings
