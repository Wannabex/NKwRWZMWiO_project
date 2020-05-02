#ifndef GRAPH_H
#define GRAPH_H

#include <string.h>

class graph
{
    public:
        graph(/*plik tekstowy grafu*/);

    private:
        string look_at_the_crocodiles(/*plik tekstowy grafu*/);         // Wczytanie grafu z pliku crocodiles.txt, zwrócenie stringa
        void think_about_the_way(string crocodiles_along_the_way);      // Zamiana wczytanego pliku w wierzcholki i krawedzie, czyli w macierz s¹siedztwa, usuniêcie wszystkich krawedzi >= 5
        void calculate_possible_way();                                  // G³ówny algorytm - sprawdzenie czy uda siê przeskoczyæ na drug¹ stronê - algorytm prima/kruskala

        void print_the_way();                                           // Wypisaæ grafik jako macierz s¹siedztwa, nawet niepotrzebne

        string crocodiles_along_the_way;                                // Odczytany plik tekstowy tutaj
};

#endif // GRAPH_H
