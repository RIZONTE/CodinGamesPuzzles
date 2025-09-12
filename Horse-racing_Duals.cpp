#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<int> p(n);
    for (int i = 0; i < n; i++){
        std::cin >> p[i];
        std::cin.ignore();
    }
    std::sort(p.begin(), p.end());

    int d{10000001};
    for(int i = 0; i < n-1; i++){
        if(p[i+1] - p[i] < d) d = p[i+1] - p[i];
    }
    std::cout << d << std::endl;
}