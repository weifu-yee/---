#include "map.h"

vector<pair<int, pair<int, int>>> MAP::node;     //<index, x, y>
vector<vector<int>> MAP::adj_list(num_of_nodes);       //adjacency_list

void MAP::buildNode(){
    std::ifstream file(buildNodeFilePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    YAML::Node pathConfig = YAML::Load(file);
    for (auto nodeElement : pathConfig) {
        auto node = nodeElement["node"];
        int index = node[0].as<int>();
        int x = node[1].as<int>();
        int y = node[2].as<int>();
        MAP::node.push_back(make_pair(index, make_pair(x, y)));
    }
}
void MAP::initBuildEdge(){
    auto buildEdge = [&](int u, int v){
        MAP::adj_list[u].push_back(v);
        MAP::adj_list[v].push_back(u);
    };
    
    std::ifstream file(initBuildEdgeFilePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    YAML::Node pathConfig = YAML::Load(file);
    for (auto nodeElement : pathConfig) {
        auto edge = nodeElement["initEdge"];
        int u = edge[0].as<int>();
        int v = edge[1].as<int>();
        buildEdge(u,v);
    }
}
void MAP::eraseEdge(int u, int v){
    auto find_n_erase = [&](int x, int y){
        for(auto it = MAP::adj_list[x].begin(); it != MAP::adj_list[x].end(); ++it){
            if(*it == y){
                MAP::adj_list[x].erase(it);
            }
        }
    };
    find_n_erase(u,v);
    find_n_erase(v,u);
}