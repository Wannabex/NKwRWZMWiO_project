#include "graph.h"

#define PRIM_NULL 255
#define PRIM_INF 254

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
    std::string graph_string_example_fail = "0,8,6,0,7,0,8,0,5,4,0,1,6,5,0,1,0,2,0,4,1,0,0,3,7,0,0,0,0,7,0,1,2,3,7,0";
    std::string graph_string_example_pass = "0,0,1,5,7,4,0,0,0,4,4,5,1,0,0,2,2,7,5,4,2,0,6,2,7,4,2,6,0,1,4,5,7,2,1,0";
    std::string graph_string_example_test = "0,2,0,3,2,0,4,3,0,4,0,1,3,3,1,0";
    std::string graph_string_example = graph_string_example_test;
    std::cout << "startowy grafik " << graph_string_example << std::endl << std::endl;
    std::vector <int> weights_vector;

    graph_string_example = format_graph_string(graph_string_example);
    weights_vector = graph_string_to_vector(graph_string_example);


    int graph_vector_size = weights_vector.size();
    this->number_of_vertices = std::sqrt(graph_vector_size);
    std::cout << "wektor grafowy " << weights_vector.size() << " " << this->number_of_vertices << std::endl << std::endl;

    this->adjacency_matrix = new std::vector <int>[number_of_vertices];
    for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
    {
        for (int neighbour = 0; neighbour < this->number_of_vertices; neighbour++)
        {
            if (weights_vector[vertex* this->number_of_vertices + neighbour] < 5)
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


void Graph::print_the_way()
{
    std::cout << "print_the_way function" << std::endl;

    for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
    {
        for (int neighbour = 0; neighbour < this->number_of_vertices; neighbour++)
        {
            std::cout << this->adjacency_matrix[vertex][neighbour] << " ";
        }
        std::cout << std::endl;
    }

}


void Graph::calculate_possible_way()
{
    std::cout << std::endl << "calculate_possible_way function" << std::endl;

    bool vertex_has_weight_flag = find_row_without_value();

    if(vertex_has_weight_flag)
    {
        std::cout << "Da sie przejsc :)" << std::endl;
        prim_algorith();
    }
    else
    {
        std::cout << "Nie da sie przejsc :(" << std::endl;
    }
}

void Graph::prim_algorith()
{
    int path_weigths[number_of_vertices];                                           //ta tablica pokazuje wage sciezki ktora doprowadzila do danego wierzcholka path_weights[3] = 5 oznacza, ze sciezka ktora dostalismy do 3 z poprzedniego wierzcholka wynosi 5
    int previous_vertexs[number_of_vertices];                                       //pokazuje poprzedni wierzcho³ek, previous_vertexs[3] = 2 oznacza, ze do 3. wiercholka dostalismy sie z 2
    int finished_vertexs[number_of_vertices];                                       //tablica "techniczna" 0 oznacza, ze jeszcze nie dotarlismy do wierzcholka, 1 oznacza, ze juz tam dotarlismy
    for(int i = 0; i < number_of_vertices; i++){
        path_weigths[i] = PRIM_INF;
        previous_vertexs[i] = PRIM_NULL;                                            //inicjalizacja powyzszych tablic
        finished_vertexs[i] = 0;
    }

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

    bool is_work_flag = true;

    for (int vertex = 0; vertex < this->number_of_vertices; vertex++){
        if(finished_vertexs[vertex] == 0){
            is_work_flag = false;
            break;
        }
    }

    if(is_work_flag){
        int step = number_of_vertices - 1;
        while(1){
            std::cout << "do krokodyla o numerze: " << step << " dotrzemy z krokodyla o numerze: " << previous_vertexs[step] << " odleglosc wynosi: " << path_weigths[step] << " stop" << std::endl;
            step = previous_vertexs[step];
            if(step == 0)
                break;
        }

        /*std::cout << std::endl;
        for(int i = 1; i < number_of_vertices; i++){
            std::cout << "do krokodyla o numerze: " << i << " dotrzemy z krokodyla o numerze: " << previous_vertexs[i] << " odleglosc wynosi: " << path_weigths[i] << " stop" << std::endl;
        }

        std::cout << std::endl;
        for(int i = 1; i < number_of_vertices; i++){
            std::cout << previous_vertexs[i] << ", ";
        }*/
    }
    else{
        std::cout << "Error: Algorytm prima nie zostal wykonany prawidlowo" << std::endl;
    }

}

bool Graph::find_row_without_value()
{
    bool return_value = false;

    for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
    {
        return_value = false;
        for (int neighbour = 0; neighbour < this->number_of_vertices; neighbour++)
        {
            if(this->adjacency_matrix[vertex][neighbour] != 0)
                return_value = true;
        }
        if(!return_value)
            break;
    }

    return return_value;
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
    std::cout << "sformatowany grafik " << formatted_string << std::endl << std::endl;
    return formatted_string;
}

std::vector <int> Graph::graph_string_to_vector(std::string& string_with_graph)
{
    std::cout << "zmienie go w wektor " << string_with_graph << std::endl << std::endl;
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

