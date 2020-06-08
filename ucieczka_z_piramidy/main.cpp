#include <iostream>
#include "graph.h"

int main()
{
    std::string pyramid_map_name = "current_pyramid.txt";
    std::cout << "Hello in my pyramid!" << std::endl << std::endl;

    Graph *giza_pyramid = new Graph(pyramid_map_name);
    giza_pyramid->print_pyramid_map();
    giza_pyramid->calculate_possible_way();

    std::system("pause");
    return 0;
}


