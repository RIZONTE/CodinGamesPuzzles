#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

int main()
{
    int n, l, e;
    std::cin >> n >> l >> e;
    std::cin.ignore();
    std::vector<std::vector<bool>> node_adj_matrix(n);
    for(int i = 0; i < n; i++){
        node_adj_matrix[i].resize(n);
    }
    for (int i = 0; i < l; i++) {
        int n1, n2;
        std::cin >> n1 >> n2;
        std::cin.ignore();
        node_adj_matrix[n1][n2] = true;
        node_adj_matrix[n2][n1] = true;
    }

    std::vector<int> gateways(e);
    for (int i = 0; i < e; i++) {
        std::cin >> gateways[i]; std::cin.ignore();
    }

    struct Node{
        int id{-1};
        int dist{-1};
        std::vector<int> prevs;
    };
    while (1) {
        int si;
        std::cin >> si; std::cin.ignore();

        std::vector<Node> nodes(n);
        nodes[si] = {si, 0};
        std::queue<int> q;
        q.push(si);
        while(!q.empty()){
            int curr_root = q.front();
            q.pop();

            for(int i = 0; i < n; i++){
                if(node_adj_matrix[curr_root][i] && nodes[i].dist == -1){
                    nodes[i].id = i;
                    nodes[i].dist = nodes[curr_root].dist + 1;
                    nodes[i].prevs = nodes[curr_root].prevs;
                    nodes[i].prevs.push_back(curr_root);
                    q.push(i);
                }
            }
        }

        Node closest_gate{-1, 10000};
        for(int gate : gateways){
            if(closest_gate.dist > nodes[gate].dist && nodes[gate].id != -1){
                closest_gate = nodes[gate];
            }
        }

        int c1, c2;
        if(closest_gate.prevs.size() > 1){
            c1 = closest_gate.prevs[0];
            c2 = closest_gate.prevs[1];
        }
        else{
            c1 = closest_gate.id;
            c2 = closest_gate.prevs[0];
        }
        std::cout << c1 << " " << c2 << std::endl;
        node_adj_matrix[c1][c2] = false;
        node_adj_matrix[c2][c1] = false;        
    }
}