#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <math.h>   // dla sqrt
#include <fstream>
#include <cstdlib>

class Graph
{
    public:
        Graph(std::string nazwa_pliku);
        void calculate_possible_way();                                       // zad 4. Glówny algorytm - sprawdzenie czy uda sie przeskoczyc na druga strone - algorytm prima/kruskala
        bool check_algoritm(int finished_vertexs[]);                                                    //funkcja pomocnicza do zad 4.
        void print_algoritm_result(int path_weigths[], int previous_vertexs[], bool finished_flag);     //funkcja pomocnicza do zad 4.
        void prim_algoritm(int path_weigths[], int previous_vertexs[], int finished_vertexs[]);         //funkcja pomocnicza do zad 4.

        void print_pyramid_map();                                                // Wypisac grafik jako macierz sasiedztwa, nawet niepotrzebne

    private:
        std::string look_at_the_crocodiles(std::string nazwa_pliku);         // zad 2. Wczytanie grafu z pliku crocodiles.txt, zwrocenie stringa
        void think_about_the_way(std::string crocodiles_along_the_way);      // zad 3. Zamiana wczytanego pliku w wierzcholki i krawedzie, czyli w macierz sasiedztwa, usuniêcie wszystkich krawedzi >= 5

        std::string crocodiles_along_the_way;                                // Odczytany plik tekstowy tutaj

        int number_of_vertices;                                              // Ilosc wierzcholkow, start + krokodyle + meta
        std::vector < int > *adjacency_matrix;                               // Macierz sasiedztwa reprezentujaca graf

        std::string format_graph_string(std::string& string_with_graph);                  // Funkcja pomagajaca przy zad 3.
        std::vector <int> graph_string_to_vector(std::string& formatted_string_with_graph);        // Funkcja pomagajaca przy zad 3.
};

#endif // GRAPH_H
