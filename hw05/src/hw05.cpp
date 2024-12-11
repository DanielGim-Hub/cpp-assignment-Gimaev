#include <hw05.h>
#include <vector>
#include <string>
using VecOfStr = std::vector<std::string>;

VecOfStr hw05(const VecOfStr& strings){
    VecOfStr result;

    auto isPalindrome = [](const std::string& str) -> bool {
        std::string filtered;
        
        // Удаляем все не-буквенно-цифровые символы и приводим к нижнему регистру
        for (const auto& c : str) {
            if (std::isalnum(static_cast<unsigned char>(c))) {
                filtered.push_back(std::tolower(static_cast<unsigned char>(c)));
            }
        }

        // Сравниваем строку с её реверсивной версией
        auto it1 = filtered.begin();
        auto it2 = filtered.rbegin();
        while (it1 != filtered.end() && it2 != filtered.rend()) {
            if (*it1 != *it2) {
                return false;
            }
            ++it1;
            ++it2;
        }
        return true;
    };

    for (const auto& str : strings) {
        if (isPalindrome(str)) {
            result.push_back(str);
        }
    }

    return result;
}
