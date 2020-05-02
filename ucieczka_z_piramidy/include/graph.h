#ifndef GRAPH_H
#define GRAPH_H

#include <string.h>

class graph
{
    public:
        graph(/*plik tekstowy grafu*/);

    private:
        string look_at_the_crocodiles(/*plik tekstowy grafu*/);         // Wczytanie grafu z pliku crocodiles.txt, zwr�cenie stringa
        void think_about_the_way(string crocodiles_along_the_way);      // Zamiana wczytanego pliku w wierzcholki i krawedzie, czyli w macierz s�siedztwa, usuni�cie wszystkich krawedzi >= 5
        void calculate_possible_way();                                  // G��wny algorytm - sprawdzenie czy uda si� przeskoczy� na drug� stron� - algorytm prima/kruskala

        void print_the_way();                                           // Wypisa� grafik jako macierz s�siedztwa, nawet niepotrzebne

        string crocodiles_along_the_way;                                // Odczytany plik tekstowy tutaj
};

#endif // GRAPH_H
