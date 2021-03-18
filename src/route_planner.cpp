#include "route_planner.h"
#include <algorithm>
#include <vector>
#include <numeric>

using std::vector;
using std::cout;

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    // TODO 2: Use the m_Model.FindClosestNode method to find the closest nodes to the starting and ending coordinates.
    // Store the nodes you find in the RoutePlanner's start_node and end_node attributes.
    this->start_node = &m_Model.FindClosestNode(start_x, start_y);
    this->end_node = &m_Model.FindClosestNode(end_x, end_y);
}


// TODO 3: Implement the CalculateHValue method.
// Tips:
// - You can use the distance to the end_node for the h value.
// - Node objects have a distance method to determine the distance to another node.

float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
    float H_value;
    H_value = node->distance(*(this->end_node));
    return H_value;
}


// TODO 4: Complete the AddNeighbors method to expand the current node by adding all unvisited neighbors to the open list.
// Tips:
// - Use the FindNeighbors() method of the current_node to populate current_node.neighbors vector with all the neighbors.
// - For each node in current_node.neighbors, set the parent, the h_value, the g_value. 
// - Use CalculateHValue below to implement the h-Value calculation.
// - For each node in current_node.neighbors, add the neighbor to open_list and set the node's visited attribute to true.

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
    current_node->FindNeighbors();
    
    for (RouteModel::Node* nbr_node:current_node->neighbors){
        nbr_node->parent = current_node;
        nbr_node->h_value = this->CalculateHValue(nbr_node);
        nbr_node->g_value = current_node->g_value + current_node->distance(*nbr_node);
        this->open_list.push_back(nbr_node);
        nbr_node->visited = true;
    }
}


// TODO 5: Complete the NextNode method to sort the open list and return the next node.
// Tips:
// - Sort the open_list according to the sum of the h value and g value.
// - Create a pointer to the node in the list with the lowest sum.
// - Remove that node from the open_list.
// - Return the pointer.

RouteModel::Node *RoutePlanner::NextNode() {
    //check back my sorting algo from cpp_practice folder
    vector<float> sum_vec;

    for (RouteModel::Node* check_node:this->open_list ){    
        sum_vec.push_back(check_node->g_value + check_node->h_value);
    }
    
    //sort in descending order
    vector<int> V (sum_vec.size());
    std::iota(V.begin(), V.end(), 0);
    //descending order
    sort(V.begin(), V.end(), [&](int i, int j){ return sum_vec[i] > sum_vec[j]; });
    
    std::vector<RouteModel::Node*> temp_list = this->open_list;
    for (int i=0, j=0; i<sum_vec.size() && j<sum_vec.size(); i++, j++){
         this->open_list[i] = temp_list[V[j]];
    }

    RouteModel::Node* sorted_node = this->open_list.back();
    this->open_list.pop_back();

    return sorted_node;
}

// RouteModel::Node* RoutePlanner::NextNode() {
//     std::sort(open_list.begin(), open_list.end(), [](const auto &_1st, const auto &_2nd) {
//         return _1st->h_value + _1st->g_value < _2nd->h_value + _2nd->g_value;
//     });

//     RouteModel::Node *lowest_node = open_list.front();
//     open_list.erase(open_list.begin());
//     return lowest_node;
// }


// TODO 6: Complete the ConstructFinalPath method to return the final path found from your A* search.
// Tips:
// - This method should take the current (final) node as an argument and iteratively follow the 
//   chain of parents of nodes until the starting node is found.
// - For each node in the chain, add the distance from the node to its parent to the distance variable.
// - The returned vector should be in the correct order: the start node should be the first element
//   of the vector, the end node should be the last element.

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
    // Create path_found vector
    // this->distance = 0.0f;
    std::vector<RouteModel::Node> path_found;

    // TODO: Implement your solution here.
    RouteModel::Node* temp_node = current_node;
    // cout << "I am COnstruc:" << "\n";
    while (temp_node){
        
        path_found.push_back(*temp_node);
        if (temp_node->parent) {
            distance = distance + temp_node->distance(*temp_node->parent);
            
            temp_node = temp_node->parent;
        }
        else {
            break;
        }
    }

    //reversing array
    // for (int j=0; j<path_found.size(); j++){
    //     path_found[j] = path_found[path_found.size() -1 -j];
    // }
    std::reverse(path_found.begin(), path_found.end());
    
    this->distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;

}


// TODO 7: Write the A* Search algorithm here.
// Tips:
// - Use the AddNeighbors method to add all of the neighbors of the current node to the open_list.
// - Use the NextNode() method to sort the open_list and return the next node.
// - When the search has reached the end_node, use the ConstructFinalPath method to return the final path that was found.
// - Store the final path in the m_Model.path attribute before the method exits. This path will then be displayed on the map tile.

void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;

    // TODO: Implement your solution here.
    this->start_node->visited = true;
    this->open_list.push_back(this->start_node);

    while (open_list.size() > 0){
        
        current_node = NextNode();
        

        if(current_node->distance(*(this->end_node)) == 0){
            m_Model.path =  ConstructFinalPath(current_node);
            
            return;
        }
        else{
            AddNeighbors(current_node);
            
        }
    }
}