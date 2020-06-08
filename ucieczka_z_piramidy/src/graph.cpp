#include "graph.h"

#define PRIM_NULL 255
#define PRIM_INF 254
#define DEBBUG 0

Graph::Graph(std::string pyramid_file_name)
{
    crocodiles_along_the_way = look_at_the_crocodiles(pyramid_file_name);
    think_about_the_way(crocodiles_along_the_way);
}

std::string Graph::look_at_the_crocodiles(std::string pyramid_file_name)
{
    std::string line, something;
    int helpint;            // pomocniczy int do wyznaczenia dlugosci lancucha
    std::fstream file;
    file.open(pyramid_file_name,std::ios::in);

    if(file.good()==false)
    {
        std::cout << "Plik nie istnieje!";
        exit(0);
    }

    while(getline(file,line))
    {
        something = something + line + ",";
    }

    file.close();

    helpint = something.length();
    something.erase(helpint-1,1);
    crocodiles_along_the_way = something;

    return crocodiles_along_the_way;
}

void Graph::think_about_the_way(std::string crocodiles_along_the_way)
{
    std::vector <int> weights_vector;

    crocodiles_along_the_way = format_graph_string(crocodiles_along_the_way);
    weights_vector = graph_string_to_vector(crocodiles_along_the_way);


    int graph_vector_size = weights_vector.size();
    this->number_of_vertices = std::sqrt(graph_vector_size);

    this->adjacency_matrix = new std::vector <int>[number_of_vertices];
    for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
    {
        for (int neighbour = 0; neighbour < this->number_of_vertices; neighbour++)
        {
            if (weights_vector[vertex* this->number_of_vertices + neighbour] <= 5)
            {
                this->adjacency_matrix[vertex].push_back(weights_vector[vertex* this->number_of_vertices + neighbour]);
            }
            else
            {
                this->adjacency_matrix[vertex].push_back(0);
            }
        }
    }
}

bool Graph::check_algoritm(int finished_vertexs[]){
    bool return_value = true;

    for (int vertex = 0; vertex < this->number_of_vertices; vertex++){
        if(finished_vertexs[vertex] == 0){
            return_value = false;
            break;
        }
    }

    return return_value;
}

void Graph::print_algoritm_result(int path_weigths[], int previous_vertexs[], bool finished_flag){
    if(DEBBUG == 1){
        std::cout << std::endl;
        for(int i = 1; i < number_of_vertices; i++){
            std::cout << path_weigths[i] << ", ";
        }

        std::cout << std::endl;
        for(int i = 1; i < number_of_vertices; i++){
            std::cout << previous_vertexs[i] << ", ";
        }
    }

    if(finished_flag){
        std::cout << "Jest droga na druga strone" << std::endl;

        int step = number_of_vertices - 1;
        while(step != 0){
            std::cout << "do krokodyla o numerze: " << step << " dotrzemy z krokodyla o numerze: " << previous_vertexs[step] << " odleglosc wynosi: " << path_weigths[step] << " stop" << std::endl;
            step = previous_vertexs[step];
        }
    }
    else{
        std::cout << "Nie ma drogi na druga strone" << std::endl;
    }
}

void Graph::prim_algoritm(int path_weigths[], int previous_vertexs[], int finished_vertexs[]){
    int actual_vertex = 0;                                                          //arbitralne wybranie poczatkowego wezla
    path_weigths[actual_vertex] = 0;

    //Ten "for" to glowna petla, wykonuje sie tyle razy ile wynosi liczba vertex bo w kazdej iteracji wybieramy jeden vertex
    for (int vertex = 0; vertex < this->number_of_vertices; vertex++){
        finished_vertexs[actual_vertex] = 1;                                         //aktualny wezel zostal zakonczony w poprzednich krokach

        //Ten "for" sluzy do wypelniania tablicy path_weights i previous_vertexs zgodnie z aktulnym vertexem
        for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
        {
            if(finished_vertexs[vertex] == 0                                                //Jezeli polaczenie nie jest zakonczone...
            &&this->adjacency_matrix[actual_vertex][vertex] != 0                            //... i jezeli istnieje polaczenie...
            && path_weigths[vertex] > this->adjacency_matrix[actual_vertex][vertex])        //...i nowe polaczenie jest krotsze od aktualnego...
            {
                path_weigths[vertex] = adjacency_matrix[actual_vertex][vertex];             //...zastepujemy to polaczenie nowym
                previous_vertexs[vertex] = actual_vertex;
            }
        }
        int smallest_weigth = PRIM_INF;
        //W tym forze szukamy najkrotszego polaczenia dla niezakonczonych wierzcholkow
        for(int vertex = 0; vertex < number_of_vertices; vertex++){
            if(!finished_vertexs[vertex]){
                if(smallest_weigth > path_weigths[vertex]){
                    smallest_weigth = path_weigths[vertex];
                    actual_vertex = vertex;
                }
            }
        }
    }
}

void Graph::calculate_possible_way()
{
    int path_weigths[number_of_vertices];                                           //ta tablica pokazuje wage sciezki ktora doprowadzila do danego wierzcholka path_weights[3] = 5 oznacza, ze sciezka ktora dostalismy do 3 z poprzedniego wierzcholka wynosi 5
    int previous_vertexs[number_of_vertices];                                       //pokazuje poprzedni wierzcho³ek, previous_vertexs[3] = 2 oznacza, ze do 3. wiercholka dostalismy sie z 2
    int finished_vertexs[number_of_vertices];                                       //tablica "techniczna" 0 oznacza, ze jeszcze nie dotarlismy do wierzcholka, 1 oznacza, ze juz tam dotarlismy
    for(int i = 0; i < number_of_vertices; i++){
        path_weigths[i] = PRIM_INF;
        previous_vertexs[i] = PRIM_NULL;                                            //inicjalizacja powyzszych tablic
        finished_vertexs[i] = 0;
    }

    prim_algoritm(path_weigths, previous_vertexs, finished_vertexs);                //policz algorytm
    bool finished_flag = check_algoritm(finished_vertexs);                          //sprawdz czy algorytm sie udal
    print_algoritm_result(path_weigths, previous_vertexs, finished_flag);           //wyswietl wyniki algorytmu

}

void Graph::print_pyramid_map()
{
    for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
    {
        for (int neighbour = 0; neighbour < this->number_of_vertices; neighbour++)
        {
            std::cout << this->adjacency_matrix[vertex][neighbour] << " ";
        }
        std::cout << std::endl;
    }
}

std::string Graph::format_graph_string(std::string& string_with_graph)
{
    std::string formatted_string;
    int string_length = string_with_graph.length();
    char current_character;
    for (int string_position = 0; string_position < string_length; string_position++)
    {
        current_character = string_with_graph[string_position];
        if (current_character != ' ')
        {
            formatted_string.push_back(current_character);
        }
    }
    return formatted_string;
}

std::vector <int> Graph::graph_string_to_vector(std::string& string_with_graph)
{
    std::vector <int> weights_vector;
    int string_length = string_with_graph.length();
    int current_weight_starting_position = 0;
    char current_character;

    for (int string_position = 0; string_position < string_length; string_position++)
    {
        current_character = string_with_graph[string_position];
        if (current_character == ',')
        {
            std::string current_weight_string = "";
            for (int weight_position = current_weight_starting_position; weight_position < string_position; weight_position++)
            {
                current_weight_string.push_back(string_with_graph[weight_position]);
            }
            int weight = std::stoi(current_weight_string);            // string to int
            weights_vector.push_back(weight);
            current_weight_starting_position = string_position + 1;
        }
        else if(string_position == string_length - 1)
        {
            std::string current_weight_string = "";
            for (int weight_start = current_weight_starting_position; weight_start <= string_position; weight_start++)
            {
                current_weight_string.push_back(string_with_graph[weight_start]);
            }
            int weight = std::stoi(current_weight_string);            // string to int
            weights_vector.push_back(weight);
        }
    }
    return weights_vector;
}

