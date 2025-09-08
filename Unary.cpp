#include <iostream>
#include <string>
#include <bitset>

int main()
{
    std::string message;
    std::getline(std::cin, message);

    std::string bitMessage;
    for(char c : message){
        std::bitset<7> representation(c);
        bitMessage += representation.to_string();
    }

    char currSimbol{'e'};
    int currLen{};
    for(int i = 0; i < bitMessage.size(); i++){
        if(currSimbol == 'e'){
            currSimbol = bitMessage[i];
            currLen += 1;
        }
        else if(currSimbol == bitMessage[i]){
            currLen += 1;
        }
        else{
            if(currSimbol == '1') std::cout << "0 ";
            else std::cout << "00 ";
            std::string zeros(currLen, '0');
            std::cout << zeros << " ";

            currLen = 1;
            currSimbol = bitMessage[i];
        }
    }
    if(currSimbol == '1') std::cout << "0 ";
    else std::cout << "00 ";
    std::string zeros(currLen, '0');
    std::cout << zeros;
}