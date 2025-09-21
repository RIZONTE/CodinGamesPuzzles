#include <iostream>
#include <string>

int main()
{
    int w, h;
    std::cin >> w >> h; std::cin.ignore();

    int n;
    std::cin >> n; std::cin.ignore();
    int x0, y0;
    std::cin >> x0 >> y0; std::cin.ignore();

    int u{0}, d{0}, r{0}, l{0};
    bool xFixed = w == 1 ? true : false;
    int X{x0}, Y{y0};
    //Направления движения
    int hDir{-1};
    int vDir{-1};
    while (1) {
        std::string bomb_dir;
        std::cin >> bomb_dir; std::cin.ignore();

        //Ищем координату X
        if(!xFixed){
            if(bomb_dir == "COLDER"){
                if(x0 >= X) l = (X+x0)/2;
                else r = w - 1 - (x0+X)/2;

                hDir = hDir == -1 ? 1 : -1;
            }
            else if(bomb_dir == "WARMER"){
                if(x0 >= X) r = w - 1 - (x0+X)/2;
                else l = (x0+X)/2;
            }
            x0 = X;
            y0 = Y;
            if(hDir == -1){
                if(x0 < l) X = (l+(w-r))/2;
                else X = (l+x0)/2;
            }
            else{
                if(x0 > w-r) X = (l+(w-r))/2;
                else X = (x0 + (w-r))/2;
            }

            //Проверка что координата x зафиксировалась
            if(w - (r + l) <= 2){
                xFixed = true;
            }
        }
        //Ищем координату Y
        else{
            if(bomb_dir == "COLDER"){
                if(y0 >= Y) u = (y0+Y)/2;
                else d = h - 1 - (y0+Y)/2;

                vDir = vDir == -1 ? 1 : -1;
            }
            else if(bomb_dir == "WARMER" && y0 != Y){
                if(y0 >= Y) d = h - 1 - (y0+Y)/2;
                else u = (y0+Y)/2;
            }

            x0 = X;
            y0 = Y;
            if(vDir == -1){
                if(y0 < u) Y = (u+(h-d))/2;
                else Y = (u+y0)/2;
            }
            else{
                if(y0 > h-d) Y = (u+(h-d))/2;
                else Y = (y0 + (h-d))/2;
            }
        }
        
        std::cout << X << " " << Y << std::endl;
    }
}