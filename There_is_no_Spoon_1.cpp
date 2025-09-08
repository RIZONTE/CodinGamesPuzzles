#include <iostream>
#include <string>
#include <vector>

int main(){
    int width; // the number of cells on the X axis
    std::cin >> width;
    std::cin.ignore();

    int height; // the number of cells on the Y axis
    std::cin >> height;
    std::cin.ignore();

    std::vector<std::string> grid(height);
    for (int i = 0; i < height; i++) {
        getline(std::cin, grid[i]);
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(grid[i][j] == '.') continue;
            int x2{-1},y2{-1};
            for(int k = j+1; k < width; k++){
                if(grid[i][k] == '0'){
                    x2 = k;
                    y2 = i;
                    break;
                }
            }
            int x3{-1}, y3{-1};
            for(int k = i+1; k < height; k++){
                if(grid[k][j] == '0'){
                    x3 = j;
                    y3 = k;
                    break;
                }
            }
            
            std::cout << j << " " << i << " " 
                      << x2 << " " << y2 << " "
                      << x3 << " " << y3 << std::endl;
        }
    }
}