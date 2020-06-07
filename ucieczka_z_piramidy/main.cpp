#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    std::string nazwa_mapy_piramidy = "crocodiles_succes3.txt";
    cout << "Hello in my pyramid!" << endl << endl;

    Graph *giza_pyramid = new Graph(nazwa_mapy_piramidy);
    giza_pyramid->print_pyramid_map();
    giza_pyramid->calculate_possible_way();

    return 0;
}


