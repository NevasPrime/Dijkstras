/*======================================================================
COIS-4310H Assignment 3 - Dijkstra's Network
Name: Network.hpp
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


#pragma once
#include <vector>
#include "Vertex.hpp"
#include <iostream>
class Network {
    // List of Vertexes
    std::vector<Vertex*> Vertexes;

    /* Network:find_vertex
    This method will find a vertex within our list of vertexes
    Given: int item - ID of the vertex we're looking for.
    Return: Vertex pointer to the vertex.*/
    Vertex* find_vertex(int item);
    
    public:
    /* Default Constructor */
    Network(void);

    /* Network:new_vertex
    This method will add a new vertex to our list with given ID.
    Given: int identification - ID of the new vertex*/
    void new_vertex(int identification);
    
    /* Network:new_edge
    This method will add a new edge with the given information. Each edge is directionless.
    Given: int ID1 - ID of the first vertex of new edge
           int ID2 - ID of the second vertex of the new edge
           int cost - weight of the edge.*/
    void new_edge(int ID1, int ID2, int cost);

    /* Network:Dijkstras    
    This method will find the shortest path from one device to device. Quite obviously this uses Dijkstra's algorithm
    Given: int source - device of start
           int destination - device of end
    Return: string - Solution of the algorithm.*/
    std::string Dijkstras(int source, int destination);
};