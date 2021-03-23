/*======================================================================
COIS-4310H Assignment 3 - Dijkstra's Network
Name: Edge.hpp
Written By: Trevor Gilbert 
Purpose: Edge Class
For this algorithm we are representing our network as a direction less graph.
Each network connection is represented by an edge. Each edge is given a weight, 
this weight represents many things that may reduce reduce the speed of transport 
such as other traffic, type of connection, distance, etc.


Compilation: Please use the provided Make file that will make the result

----------------------------------------------------------------------*/

#pragma once
#include <list>
class Edge;
#include "Vertex.hpp"

class Edge {   
    public:
    // Cost of the edge
    int weight;
    // List of two vertexes
    Vertex *ends[2];

    /* Default Constructor
    Directionless edge so does not matter which is which vertex is which.
    Given: vertex one - first vertex of the edge.
           vertex two - second vertex of the edge. 
           int cost - weight of the edge*/
    Edge(Vertex *one, Vertex *two, int cost); 
};
