#include "graph.h"

Graph::Graph(/*plik tekstowy grafu*/)
{
    std::cout << "constructor here" << std::endl;
    crocodiles_along_the_way = look_at_the_crocodiles(/*plik tekstowy grafu*/);
    think_about_the_way(crocodiles_along_the_way);
}



std::string Graph::look_at_the_crocodiles(/*plik tekstowy grafu*/)
{
    std::cout << "look_at_the_crocodiles function" << std::endl;
    std::string file_content;

    return file_content;
}


void Graph::think_about_the_way(std::string crocodiles_along_the_way)
{
    std::cout << "think_about_the_way function" << std::endl;
    int n = 4; //przykladowa wartosc
    number_of_vertices = n;
    this->adjacency_list = new std::vector <int>[number_of_vertices];

}


void Graph::print_the_way()
{
    std::cout << "print_the_way function" << std::endl;

}


void Graph::calculate_possible_way()
{
    std::cout << "calculate_possible_way function" << std::endl;

}
