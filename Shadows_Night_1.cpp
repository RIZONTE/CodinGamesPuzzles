#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int w, h;
    std::cin >> w >> h; std::cin.ignore();
    int n;
    std::cin >> n; std::cin.ignore();
    int x0, y0;
    std::cin >> x0 >> y0; std::cin.ignore();

    int u{0}, d{0}, r{0}, l{0};
    while (1) {
        std::string bomb_dir;
        std::cin >> bomb_dir; std::cin.ignore();

        char c1 = bomb_dir[0];
        int X, Y;
        switch(c1){
            case 'U':
                Y = ((y0 - u) / 2) + u;
                X = x0;
                d = h-y0;
                break;
            case 'D':
                Y = ((h - y0 - d) / 2) + y0;
                X = x0;
                u = y0;
                break;
            case 'R':
                Y = y0;
                X = ((w - x0 - r) / 2) + x0;
                l = x0;
                break;
            case 'L':
                Y = y0;
                X = ((x0 - l) / 2) + l;
                r = w - x0;
                break;
        }
        if(bomb_dir.size() > 1){
            int c2 = bomb_dir[1];
            switch(c2){
                case 'R':
                    X = ((w - x0 - r) / 2) + x0;
                    l = x0;
                    break;
                case 'L':
                    X = ((x0 - l) / 2) + l;
                    r = w - x0;
                    break;
            }
        }

        x0 = X;
        y0 = Y;
        std::cout << X << " " << Y << std::endl;
    }
}