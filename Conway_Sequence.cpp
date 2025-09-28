#include <iostream>
#include <vector>

int main()
{
    int r;
    std::cin >> r; std::cin.ignore();
    int l;
    std::cin >> l; std::cin.ignore();

    std::vector<std::vector<int>> seq(l);
    seq[0] = {r};

    for(int i = 0; i < l-1; i++){
        int count{0};
        int val{seq[i][0]};
        for(int v : seq[i]){
            if(v == val){
                count++;
            }
            else{
                seq[i+1].push_back(count);
                seq[i+1].push_back(val);
                val = v;
                count = 1;
            }
        }
        seq[i+1].push_back(count);
        seq[i+1].push_back(val);
    }
    
    std::cout << seq[l-1][0];
    for(int i = 1; i < seq[l-1].size(); i++){
        std::cout << " " << seq[l-1][i];
    }
    std::cout << std::endl;
}