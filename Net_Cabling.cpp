#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n; std::cin.ignore();

    struct Point{ //Объект отображающий координаты здания
        int x{};
        int y{};
    };
    std::vector<Point> builds(n);
    for(int i = 0; i < n; i++) {
        std::cin >> builds[i].x >> builds[i].y; std::cin.ignore();
    }

    //Поиск граничных значений
    int minX{std::numeric_limits<int>::max()}, maxX{std::numeric_limits<int>::min()};
    for(auto p : builds){
        if(p.x > maxX) maxX = p.x;
        if(p.x < minX) minX = p.x;
    }
    
    //Сортировка по координате y
    std::sort(builds.begin(), builds.end(), [](const Point& lhs, const Point& rhs){
        return lhs.y < rhs.y;
    });

    //Рассчет длины кабеля
    int mainCable{builds[n/2].y};
    long long cableLength{maxX-minX};
    for(auto p : builds){
        cableLength += std::abs(p.y - mainCable);
    }

    std::cout << cableLength << std::endl;
}