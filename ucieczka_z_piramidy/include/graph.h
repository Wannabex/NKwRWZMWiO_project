#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <iostream>

class Graph
{
    public:
        Graph(/*plik tekstowy grafu*/);
        void calculate_possible_way();                                       // G³ówny algorytm - sprawdzenie czy uda siê przeskoczyæ na drug¹ stronê - algorytm prima/kruskala

        void print_the_way();                                                // Wypisaæ grafik jako macierz s¹siedztwa, nawet niepotrzebne

    private:
        std::string look_at_the_crocodiles(/*plik tekstowy grafu*/);         // Wczytanie grafu z pliku crocodiles.txt, zwrócenie stringa
        void think_about_the_way(std::string crocodiles_along_the_way);      // Zamiana wczytanego pliku w wierzcholki i krawedzie, czyli w listê s¹siedztwa, usuniêcie wszystkich krawedzi >= 5

        std::string crocodiles_along_the_way;                                // Odczytany plik tekstowy tutaj

        int number_of_vertices;                                              // Iloœæ wierzcho³ków, start + krokodyle + meta
        std::vector < int > *adjacency_list;                                 // Lista s¹siedztwa reprezentuj¹ca graf
};

#endif // GRAPH_H
