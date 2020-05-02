#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <iostream>

class Graph
{
    public:
        Graph(/*plik tekstowy grafu*/);
        void calculate_possible_way();                                       // G��wny algorytm - sprawdzenie czy uda si� przeskoczy� na drug� stron� - algorytm prima/kruskala

        void print_the_way();                                                // Wypisa� grafik jako macierz s�siedztwa, nawet niepotrzebne

    private:
        std::string look_at_the_crocodiles(/*plik tekstowy grafu*/);         // Wczytanie grafu z pliku crocodiles.txt, zwr�cenie stringa
        void think_about_the_way(std::string crocodiles_along_the_way);      // Zamiana wczytanego pliku w wierzcholki i krawedzie, czyli w list� s�siedztwa, usuni�cie wszystkich krawedzi >= 5

        std::string crocodiles_along_the_way;                                // Odczytany plik tekstowy tutaj

        int number_of_vertices;                                              // Ilo�� wierzcho�k�w, start + krokodyle + meta
        std::vector < int > *adjacency_list;                                 // Lista s�siedztwa reprezentuj�ca graf
};

#endif // GRAPH_H
