#include <iostream>


void solve(int watermelons)
{
    if (watermelons == 2)
    {
        std::cout << "NO" << '\n';
    }
    else
    {
        if (watermelons % 2 == 0)
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int w;
    std::cin >> w;
    solve(w);
    return 0;
}