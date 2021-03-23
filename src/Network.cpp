/*======================================================================
COIS-4310H Assignment 3 - Dijkstra's Network
Name: Network.cpp
Written By: Trevor Gilbert 
Purpose: Network Class
For this algorithm we are representing our network as a direction less graph.
Each vertex is a device on the network (end user, server, 
router, switch). Each network connection is represented by an edge.
Each edge is given a weight, this weight represents many things that
may reduce reduce the speed of transport such as other traffic, 
type of connection, distance, etc.

Compilation: Please use the provided Make file that will make the result

----------------------------------------------------------------------*/


#include "Network.hpp"
#include <limits>
#include <unordered_map>
#include <queue>

#define DEBUG true

/* Default Constructor */
Network::Network(void)
{

}

/* Network:new_vertex
    This method will add a new vertex to our list with given ID.
    Given: int identification - ID of the new vertex*/
void Network::new_vertex(int identification)
{
    Vertexes.push_back(new Vertex(identification));
}

/* Network:new_edge
    This method will add a new edge with the given information. Each edge is directionless.
    Given: int ID1 - ID of the first vertex of new edge
           int ID2 - ID of the second vertex of the new edge
           int cost - weight of the edge.
*/
void Network::new_edge(int ID1, int ID2, int cost)
{
    if (cost < 0) {
        std::cout << "Does not accept cost less than 0" << std::endl;
        return;
    }
    // Find vertexes
    Vertex *v1 = find_vertex(ID1);
    Vertex *v2 = find_vertex(ID2);
    // Create new edge
    Edge *e = new Edge(v1, v2, cost);
    // Add that edge to each vertex
    v1->add_edge(e);
    v2->add_edge(e);
}

/* Network:find_vertex
    This method will find a vertex within our list of vertexes
    Given: int item - ID of the vertex we're looking for.
    Return: Vertex pointer to the vertex.*/
Vertex* Network::find_vertex(int item)
{
    // Loop through our list
    for (auto i :  Vertexes)
    {
        // If ID matches, return.
        if (i->get_ID() == item)
        {
            return i;
        }
    }
    return NULL;
}

/* Network:Dijkstras
This method will find the shortest path from one device to device. Quite obviously this uses Dijkstra's algorithm
    Given: int source - device of start
           int destination - device of end
    Return: string - Solution of the algorithm.*/
std::string Network::Dijkstras(int source, int destination)
{
    // Unordered map of Distance for that vertex 
    std::unordered_map<int, int> dist;
    // Unordered map of whether that vertex has been visited 
    std::unordered_map<int, bool> visited;
    // Unordered map of list of solutions
    std::unordered_map<int, int> prev;
    // A priority queue of pair min distance and vertex pointer
    std::priority_queue<std::pair<int, Vertex*>,  std::vector<std::pair<int, Vertex*>>,
     std::greater<std::pair<int, Vertex*>>> queue;
    // holds id for easy access
    int id;
    // holds cost of the current vertex plus edge cost
    int weight;
    // A pair to hold value from the queue
    std::pair<int, Vertex*> current;
    // pointer to the adjacent vertex attached to current
    Vertex* next;
    // Loop through the list of vertexes
    for (auto i :  Vertexes)
    {
        id = i->get_ID();
        // If its source, set dist to 0, visited to false and add to queue
        if (id == source) {
            dist[id] = 0;
            visited[id] = false;
            queue.push(std::make_pair(0,i));
        }
        // Set distance to the max value as not found the distance yet
        else {
            dist[id] =  std::numeric_limits<int>::max();
            visited[id] = false;
        }
    }

    // Loop through the queue until the queue is empty
    while (queue.size() > 0) {
        // Get the top of the priority queue and take it off the list
        current = queue.top();
        queue.pop();
        id = current.second->get_ID();
        // If we've visited it before, skip to next
        if (visited[id] == true) {
            continue;
        }
        // Set to visited
        visited[id] = true;
        // Loop through current's edges
        for (auto const connected_edge : current.second->Edges) {
            // Find out which of the ends of the edge is the other vertex
            if (connected_edge->ends[0]->get_ID() == id)
                next = connected_edge->ends[1];
            else
                next = connected_edge->ends[0];
            // Get the weight by current dist + edge weight
            weight = dist[id] + connected_edge->weight;

            // Check if new distance is less than old distance.
            if (dist[next->get_ID()] > weight) {
                if (DEBUG == true)
                    std::cout << "ID" << id << " -> ID" << next->get_ID() << " cost="<< weight << std::endl;
                // Set weight and prev to solution list
                dist[next->get_ID()] = weight;
                prev[next->get_ID()] = id;
                // Add vertex to queue. This could result in multiple copies of that vertex, but visited prevents harm
                queue.push(std::make_pair(weight, next));
            }

            // Check if we reached our destination. Dijkstras assumes if we reach the destination it will be the shortest.
            if (next->get_ID() == destination) {
                // Put initialize our solution string.
                id = next->get_ID();
                std::string solution = " Total_Cost=" + std::to_string(dist[id]); 
                solution.insert(0, std::to_string(id));
                // Loop through our solution until we get to the to the source. Adding to the string.
                while (id != source) {
                    id = prev[id];
                    solution.insert(0, " -> ");
                    solution.insert(0, std::to_string(id));
                }
                return solution;
            }
        }
    }
    // If we got here, queue is empty and we didn't reach the destination. 
    // path is not available.
    return "Could not find path";
}