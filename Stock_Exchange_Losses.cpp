#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n; std::cin.ignore();
    std::vector<int> values(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i]; std::cin.ignore();
    }

    int minProfit{};   //минимальная прибыль (максимальный убыток)
    int startDown{};   //начало движения вниз
    bool down{false};  //флаг указывающий что движение идет вниз
    for(int i = 1; i < n; i++){
        if(!down && values[i-1] > values[i]){
            startDown = values[i-1];
            down = true;
        }
        else if(down && values[i-1] < values[i]){
            minProfit = std::min(minProfit, values[i-1] - startDown);
            down = values[i] >= startDown ? false : true;
        }
    }
    //Если движение вниз не закончилось
    if(down){
        minProfit = std::min(minProfit, values.back() - startDown);
    }

    std::cout << minProfit << std::endl;
}