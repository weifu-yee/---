#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <yaml-cpp/yaml.h>
#include <utility>
#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Int8.h"

#define buildNodeFilePath "/home/ditrobotics/tdk_ws/src/main_func/params/buildNode.yaml"
#define initBuildEdgeFilePath "/home/ditrobotics/tdk_ws/src/main_func/params/initBuildEdge.yaml"
#define num_of_nodes 16

using namespace std;

namespace MAP{
    extern vector<pair<int, pair<int, int>>> node;    //<index, x, y>
    extern vector<vector<int>> adj_list;     //adjacency_list
    void buildNode();
    void initBuildEdge();
    void eraseEdge(int u, int v);
}

using namespace MAP;

#endif