#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <vector>

struct vertex;

struct adjVertex{//struct for adjacent cities
    vertex *v;
    int weight;
};

struct vertex{ // struct for each city
    std::string name;
    int distance_to_origin;
    int ID;
    bool visited;
    std::vector<adjVertex> adj;
};

struct queueVertex{
    int p[6];
    int distance; //number of edges on pathvoid print_shortest_distance (queueVertex *x);
    std::vector <vertex> path; //vertices on the path
};

struct Restaurant_str{//struct for restaurants
    int price;
    std::string type;
    std::string city;
    std::string name;
    Restaurant_str(){};
    Restaurant_str (int in_price, std::string in_type, std::string in_city, std::string in_name){
        type = in_type;
        name = in_name;
        city = in_city;
        price = in_price;
    }
};

class Restaurant
{
    public:
        Restaurant();
        ~Restaurant();
        void initial_all();//implement cities and restaurants
        void implement_graph();
        void implement_restaurants();

        void insert_restaurant(std::string in_title, std::string in_city, std::string in_name, int in_price);//for users to add their restaurants
        void print_all_restaurants();//print all of the restaurants
        void print_one_type_restaurants(std::string type);//print the restaurants which users choose
        void print_one_city_restaurants(std::string city);//print restaurants in one city
        void print_nearest_restaurants(std::string position);//print restaurants near the user's city
        void print_minimum_cost_each_restaurants();//print the minimum costs for each restaurants
        void print_total_cost_one_restaurant(std::string name);//print the cost for one restaurant


        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        int get_vertices_size();

        queueVertex *Dijkstra_algorithm (std::string startingcity, std::string destination);
        void print_shortest_distance (queueVertex *x, std::string startingcity, std::string destination);

    protected:
    private:
        std::vector <vertex> vertices;
        std::vector <Restaurant_str> restaurant_array;
};

#endif // RESTAURANT_H
