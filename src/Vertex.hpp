/*======================================================================
COIS-4310H Assignment 3 - Dijkstra's Network
Name: Vertex.hpp
Written By: Trevor Gilbert 
Purpose: Vertex Class
Each vertex is a device on the network (end user, server, router, switch). 

Compilation: Please use the provided Make file that will make the result

----------------------------------------------------------------------*/

#pragma once
#include <list>
class Vertex;
#include "Edge.hpp"


class Vertex {
    // ID of the vertex
    int ID;
    
    public:

    // List of edges
    std::list<Edge*> Edges;
    
    /* Vertex Constructor
    Given: int identification - identification ID of the vertex.*/
    Vertex(int identification);

    /* Vertex Deconstructor
     Remove all edges associated with this
    */
    ~Vertex();
    
    /* Vertex:get_ID
    Returns the id
    Returns: int - ID of the vertex*/
    int get_ID(void);

    /* Vertex:add_edge
    Adds an existing edge to the vertex.
    Given: edge E - Edge that included the vertex*/
    void add_edge(Edge *e);
};