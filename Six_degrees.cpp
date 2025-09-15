#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

int main(){
    std::string actor_name;
    getline(std::cin, actor_name);

    int n;
    std::cin >> n;
    std::cin.ignore();

    int k{0};
    std::vector<std::vector<int>> movie_casts(n);
    std::unordered_map<std::string, int> actor_nums;
    for (int i = 0; i < n; i++) {
        std::cin.ignore(128, ':');
        std::string movie_cast;
        getline(std::cin, movie_cast);
        std::stringstream ss_movie_cast(movie_cast);
        std::string actor;
        while(getline(ss_movie_cast, actor, ',')){
            if(actor_nums.insert({actor, k}).second) k++;
            movie_casts[i].push_back(actor_nums[actor]);
        }
    }

    std::unordered_map<int, std::set<int>> actor_adjacency;
    for(std::vector<int> cast : movie_casts){
        int cast_len = cast.size();
        for(int i = 0; i < cast_len; i++){
            for(int j = i;  j < cast_len; j++){
                if(i != j){
                    actor_adjacency[cast[i]].insert(cast[j]);
                    actor_adjacency[cast[j]].insert(cast[i]);
                }
            }
        }
    }

    int actor_id{actor_nums[" " + actor_name]};
    int kevin_id{actor_nums[" Kevin Bacon"]};
    std::queue<int> q;
    q.push(actor_id);
    std::vector<int> dist(k, -1);
    dist[actor_id] = 0;
    while(!q.empty() || dist[kevin_id] == -1)
    {
        int curr_root = q.front();
        q.pop();

        for(int neighbor : actor_adjacency[curr_root]){
            if(dist[neighbor] != -1){
                continue;
            }
            if(neighbor == kevin_id){
                dist[neighbor] = dist[curr_root] + 1;
                break;
            }
            q.push(neighbor);
            dist[neighbor] = dist[curr_root] + 1;
        }
    }

    std::cout << dist[kevin_id] << std::endl;
}