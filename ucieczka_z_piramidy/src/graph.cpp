#include "graph.h"

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
    std::string graph_string_example = "  0,1,2,3  ,4,0,6,7,8,     9, 0, 5, 6, 7, 2, 0  ";
    std::cout << "startowy grafik " << graph_string_example << std::endl << std::endl;
    std::vector <int> weights_vector;

    graph_string_example = format_graph_string(graph_string_example);
    weights_vector = graph_string_to_vector(graph_string_example);


    int graph_vector_size = weights_vector.size();
    this->number_of_vertices = std::sqrt(graph_vector_size);
    std::cout << "wektor grafowy " << weights_vector.size() << this->number_of_vertices << std::endl << std::endl;

    this->adjacency_matrix = new std::vector <int>[number_of_vertices];
    for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
    {
        for (int neighbour = 0; neighbour < this->number_of_vertices; neighbour++)
        {
            this->adjacency_matrix[vertex].push_back(weights_vector[vertex* this->number_of_vertices + neighbour]);
            std::cout << weights_vector[vertex* this->number_of_vertices + neighbour];
        }
        std::cout << std::endl;
    }

}


void Graph::print_the_way()
{

    std::cout << "print_the_way function" << std::endl;

    for (int vertex = 0; vertex < this->number_of_vertices; vertex++)
    {
        for (int neighbour = 0; neighbour < this->number_of_vertices; neighbour++)
        {
         //   std::cout << this->adjacency_matrix[vertex* this->number_of_vertices + neighbour] << " ";
        }
      //  std::cout << std::endl;
    }

}


void Graph::calculate_possible_way()
{
    std::cout << "calculate_possible_way function" << std::endl;

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

