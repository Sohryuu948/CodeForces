#include <iostream>
#include <string>
#include <print>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::string word;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> word;
        if (word.size() > 10)
        {
            std::println("{}{}{}", word.front(), word.size() - 2, word.back());
        }
        else
        {
            std::println("{}", word);
        }
    }
    return 0;
}