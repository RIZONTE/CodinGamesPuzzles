#include <iostream>
#include <queue>
#include <string>
#include <vector>


int intRepr(const std::string& card) {  //Функция для представления карт в виде чисел
    switch(card[0]) {
        case '2': return 1; case '3': return 2; case '4': return 3;
        case '5': return 4; case '6': return 5; case '7': return 6;
        case '8': return 7; case '9': return 8; 
        case '1': return 9; // "10"
        case 'J': return 10; case 'Q': return 11;
        case 'K': return 12; case 'A': return 13;
        default: return 0;
    }
}

int main()
{
    int n;
    std::cin >> n; std::cin.ignore();
    std::queue<int> p1;
    for (int i = 0; i < n; i++) {
        std::string cardp_1;
        std::cin >> cardp_1; std::cin.ignore();
        p1.push(intRepr(cardp_1));
    }
    int m;
    std::cin >> m; std::cin.ignore();
    std::queue<int> p2;
    for (int i = 0; i < m; i++) {
        std::string cardp_2;
        std::cin >> cardp_2; std::cin.ignore();
        p2.push(intRepr(cardp_2));
    }

    bool pat{false};                 //флаг указывающий на то что случилась ничья
    int rounds{};                    //Кол-во раундов
    std::vector<int> currP1;         //Карты в "бою" 1 игрока
    std::vector<int> currP2;         //Карты в "бою" 2 игрока
    while(!p1.empty() && !p2.empty()){
        currP1.push_back(p1.front());
        p1.pop();
        currP2.push_back(p2.front());
        p2.pop();

        
        if(currP1.back() > currP2.back()){
            for(int s : currP1){
                p1.push(s);
            }
            for(int s : currP2){
                p1.push(s);
            }
            rounds++;
            currP1.clear();
            currP2.clear();
        }
        else if(currP1.back() < currP2.back()){
            for(int s : currP1){
                p2.push(s);
            }
            for(int s : currP2){
                p2.push(s);
            }
            rounds++;
            currP1.clear();
            currP2.clear();
        }
        else{
            for(int i = 0; i < 3; i++){
                if(p1.empty() || p2.empty()){
                    pat = true;
                    break;
                }
                currP1.push_back(p1.front());
                p1.pop();
                currP2.push_back(p2.front());
                p2.pop();
            }
            if(pat) break;
        }
    }

    if(pat){
        std::cout << "PAT" << std::endl;
    }
    else{
        if(p1.empty()){
            std::cout << 2 << " " << rounds << std::endl;
        }
        else{
            std::cout << 1 << " " << rounds << std::endl;
        }
    }
}