/*======================================================================
COIS-4310H Assignment 3 - Dijkstra's Network
Name: Driver.cpp
Written By: Trevor Gilbert 
Purpose: This is the driver for the rest of the program. This will create
a snapshot of a network, simulated as a graph and will find the fasted way 
from A to B through a series of connections and other devices. Each 
connection has an associated weight that is speed of data transer. 
This could be effected by things like length, traffic, type of connection etc.
Devices are given an ID in this case just a simple int, but in real world
would be a much bigger.

Compilation: Please use the provided Make file that will make the result

----------------------------------------------------------------------*/


#include "Network.hpp"


int main(void)
{
    // Create our mock Network
    Network hd = Network();
    // Add Vertexes for each device
    for (int x =0; x < 18; x++)
        hd.new_vertex(x);
    
    // Add connections between devices
    hd.new_edge(15, 1, 7);
    hd.new_edge(16, 1, 3);
    hd.new_edge(1, 4, 1);
    hd.new_edge(1, 17, 5);
    hd.new_edge(17, 3, 3);
    hd.new_edge(17, 0, 11);
    hd.new_edge(4, 5, 5);
    hd.new_edge(5, 2, 12);
    hd.new_edge(2, 6, 7);
    hd.new_edge(5, 9, 7);
    hd.new_edge(0, 12, 18);
    hd.new_edge(9, 10, 9);
    hd.new_edge(10, 11, 8);
    hd.new_edge(11, 8, 9);
    hd.new_edge(11, 13, 5);
    hd.new_edge(8, 12, 5);
    hd.new_edge(13, 7, 7);
    int source, destination;
    // Get User Input
    std::cout << "Enter ID of Starting Node: ";
    std::cin >> source;
    std::cout << "Enter ID of Destination Node: ";
    std::cin >> destination;
    // Call the algorithm and display the returned solution.
    std::cout << hd.Dijkstras(source, destination) << std::endl;

    // Implicitly deconstruct network at the end
}