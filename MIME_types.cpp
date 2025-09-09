#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>


int main()
{
    int n, q;
    std::cin >> n >> q;
    std::cin.ignore();

    std::unordered_map<std::string, std::string> mimeMap;
    for (int i = 0; i < n; i++) {
        std::string ext; // file extension
        std::string mt; // MIME type.
        std::cin >> ext >> mt;
        std::cin.ignore();
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        mimeMap[ext] = mt;
    }
    for (int i = 0; i < q; i++) {
        std::string fname;
        getline(std::cin, fname);

        size_t pos = fname.rfind('.');
        std::string ext = pos != std::string::npos ? fname.substr(pos+1) : "";
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        if(auto iter = mimeMap.find(ext); iter != mimeMap.end()){
            std::cout << iter->second << std::endl;
        }
        else{
            std::cout << "UNKNOWN" << std::endl;
        }
    }
}