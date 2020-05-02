#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    cout << "Hello in my pyramid!" << endl;

    giza_pyramid graph(/* plik tekstowy */);
    //giza_pyramid.print_the_way();
    giza_pyramid.calculate_possible_way();

    return 0;
}
