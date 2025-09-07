#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>


int main()
{
    int l;
    std::cin >> l;
    std::cin.ignore();

    int h;
    std::cin >> h;
    std::cin.ignore();

    std::string t;
    getline(std::cin, t);
    std::transform(t.begin(), t.end(), t.begin(),
        [](unsigned char c){ return std::tolower(c);});

    std::string alphabet {"abcdefghijklmnopqrstuvwxyz?"};
    std::vector<std::string> representation(h);
    for(int i = 0; i < h; i++){
        std::string row;
        getline(std::cin, row);
        representation[i] = row;
    }

    int question = alphabet.find('?');
    for(int i = 0; i < h; i++){
        for(char c : t){
            if(int j = alphabet.find(c); j != std::string::npos){
                std::cout << representation[i].substr(j*l, l);
            }
            else{
                std::cout << representation[i].substr(question*l, l);
            }
        }
        std::cout << std::endl;
    }
}