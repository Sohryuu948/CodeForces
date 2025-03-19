#include <iostream>
#include <vector>
#include <cmath>

void solve(std::vector<int>& results, int sumTime, int d)
{
    int maxSum = 0;
    int minSum = 0;
    int minTime, maxTime;
    int idx = 0;
    while (d--)
    {
        std::cin >> minTime >> maxTime;
        if ((sumTime < minTime) || (sumTime < maxTime))
        {
            break;
        }
        results.push_back(minTime);
        results.push_back(maxTime);

    }
    
    for (size_t i = 0; i < results.size(); i += 2)
    {
        minSum += results[i];
        if (minSum >= sumTime)
        {
            idx = i;
        }
    }
    for (size_t i = 1; i < results.size(); i += 2)
    {
        maxSum += results[i];
        if (maxSum >= sumTime)
        {
            idx = i;
        }
    }
    if (maxSum >= sumTime || minSum >= sumTime)
    {
        std::cout << "YES" << std::endl;
        //I hate this.
        std::cout << std::floor(idx / 2) << " " << results.size() << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int d, sumTime;
    std::vector<int> results;
    std::cin >> d >> sumTime;
    results.reserve(2 * d);
    solve(results, sumTime, d);
    return 0;
}