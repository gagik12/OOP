#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
 
int main() {
 
    std::string s = "AbCdEfG";
 
    std::cout << s << std::endl;
 
    // в верхний регистр
    std::transform(s.begin(), s.end(), s.begin(), toupper);
    std::cout << s << std::endl;
 
    // в нижний регистр
    std::transform(s.begin(), s.end(), s.begin(), tolower);
    std::cout << s << std::endl;
}
