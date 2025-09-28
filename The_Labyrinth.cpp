#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

struct Point{
    int r{-1};
    int c{-1};
};
struct Path{
    Point endpoint;
    int dist{-1};
    std::vector<Point> points;  //Путь до endpoint
};

int main()
{
    int r, c, a;
    std::cin >> r >> c >> a; std::cin.ignore();

    std::vector<std::string> maze(r);           //лабиринт
    std::vector<std::vector<Path>> paths(r);    //пути до точек лабиринта от Кирка
    Point C{-1, -1};                            //координаты комнаты управления
    Point T{-1, -1};                            //кординаты начальной точки
    bool reachC{false};
    Path currPath;
    while (1) {
        int kr, kc;
        std::cin >> kr >> kc; std::cin.ignore();
        //Запоминаем начальную точку
        if(T.r == -1){
            T.r = kr;
            T.c = kc;
        }
        //Проверка что Кирк в пункте управления
        if(C.r == kr && C.c == kc){
            reachC = true;
        }
        for (int i = 0; i < r; i++) {
            std::cin >> maze[i]; std::cin.ignore();
            if(size_t index = maze[i].find('C'); C.r == -1 && index != std::string::npos){
                C.r = i;
                C.c = index;
            }
        }

        //Очищаем вектор путей
        for(int i=0; i < r; i++){
            paths[i].clear();
            paths[i].resize(c);
        }


        //Выбор цели поиска
        char goal{'Q'};
        if(C.c != -1 && !reachC){
            goal = 'C';
        }
        else if(reachC){
            goal = 'T';
        }

        //Поиск в ширину для 'C' и 'T'
        Point K{kr, kc};
        if( ( C.c != -1 && !reachC) || reachC ){
            std::queue<Point> q;
            q.push(K);
            paths[K.r][K.c] = {K, 0};
            while(!q.empty()){
                Point currP{q.front()};
                int currDist = paths[currP.r][currP.c].dist;
                q.pop();

                if(maze[currP.r][currP.c] == goal){
                    currPath = paths[currP.r][currP.c];
                    break;
                }

                for(int i = -1; i < 2; i++){
                    if(char c = maze[currP.r+i][currP.c]; c != '#' && c != '?'){
                        if(paths[currP.r+i][currP.c].dist == -1){
                            q.push({currP.r+i, currP.c});
                            paths[currP.r+i][currP.c].dist = currDist + 1;
                            paths[currP.r+i][currP.c].points = paths[currP.r][currP.c].points;
                            paths[currP.r+i][currP.c].points.push_back({currP.r+i, currP.c});
                        }
                    }
                }
                for(int i = -1; i < 2; i++){
                    if(char c = maze[currP.r][currP.c+i]; c != '#' && c != '?'){
                        if(paths[currP.r][currP.c+i].dist == -1){
                            q.push({currP.r, currP.c+i});
                            paths[currP.r][currP.c+i].dist = currDist + 1;
                            paths[currP.r][currP.c+i].points = paths[currP.r][currP.c].points;
                            paths[currP.r][currP.c+i].points.push_back({currP.r, currP.c+i});
                        }
                    }
                }
            }
        }
        //Поиск в ширину для '?'
        if( C.r == -1 || !reachC ){
            for(int i=0; i < r; i++){
                paths[i].clear();
                paths[i].resize(c);
            }
            std::queue<Point> q;
            q.push(K);
            paths[K.r][K.c] = {K, 0};
            while(!q.empty()){
                Point currP{q.front()};
                int currDist = paths[currP.r][currP.c].dist;
                q.pop();

                if(maze[currP.r][currP.c] == '?'){
                    currPath = paths[currP.r][currP.c];
                    break;
                }

                for(int i = -1; i < 2; i++){
                    if(char c = maze[currP.r+i][currP.c]; c != '#'){
                        if(paths[currP.r+i][currP.c].dist == -1){
                            q.push({currP.r+i, currP.c});
                            paths[currP.r+i][currP.c].dist = currDist + 1;
                            paths[currP.r+i][currP.c].points = paths[currP.r][currP.c].points;
                            paths[currP.r+i][currP.c].points.push_back({currP.r+i, currP.c});
                        }
                    }
                }
                for(int i = -1; i < 2; i++){
                    if(char c = maze[currP.r][currP.c+i]; c != '#'){
                        if(paths[currP.r][currP.c+i].dist == -1){
                            q.push({currP.r, currP.c+i});
                            paths[currP.r][currP.c+i].dist = currDist + 1;
                            paths[currP.r][currP.c+i].points = paths[currP.r][currP.c].points;
                            paths[currP.r][currP.c+i].points.push_back({currP.r, currP.c+i});
                        }
                    }
                }
            }
        }

        //Выбор направления
        Point nextP = currPath.points[currPath.points.size()-currPath.dist];
        currPath.dist--;
        Point dir = {nextP.r - K.r, nextP.c - K.c};
        if(dir.r == 0 && dir.c == -1){
            std::cout << "LEFT" << std::endl;
        }
        else if(dir.r == 0 && dir.c == 1){
            std::cout << "RIGHT" << std::endl;
        }
        else if(dir.r == -1 && dir.c == 0){
            std::cout << "UP" << std::endl;
        }
        else{
            std::cout << "DOWN" << std::endl;
        }
    }
}