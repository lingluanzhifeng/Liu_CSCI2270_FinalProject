#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <vector>

struct vertex;

struct adjVertex{//struct for adjacent cities
    vertex *v;
    double weight;
};

struct vertex{ // struct for each city
    std::string name;
    double distance_to_origin;
    int ID;
    bool visited;
    std::vector<adjVertex> adj;
};

struct queueVertex{
    int p[6];
    double distance; //number of edges on pathvoid print_shortest_distance (queueVertex *x);
    std::vector <vertex> path; //vertices on the path
};

struct Restaurant_str{//struct for restaurants
    double price;
    std::string type;
    std::string city;
    std::string name;
    Restaurant_str(){};
    Restaurant_str (double in_price, std::string in_type, std::string in_city, std::string in_name){
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
        void print_menu();
        void initial_all();//implement cities and restaurants
        void implement_graph();
        void implement_restaurants();
        void insert_restaurant(std::string in_type, std::string in_city, std::string in_name, double in_price);//for users to add their restaurants
        void addEdge(std::string v1, std::string v2, double weight);
        void addVertex(std::string name);
        void print_all_restaurants();//print all of the restaurants
        void print_one_type_restaurants(std::string type);//print the restaurants which users choose
        void print_one_city_restaurants(std::string city);//print restaurants in one city
        void print_nearest_restaurants(std::string position);//print restaurants near the user's city
        void print_minimum_cost_each_restaurants(double price, double mile, std::string position);//print the minimum costs for each restaurants, take the oil price and miles/gallon as parameters
        void print_total_cost_one_restaurant(std::string name, std::string position, double price, double mile);//print the cost for one restaurant
        queueVertex *Dijkstra_algorithm (std::string startingcity, std::string destination);
        void print_shortest_distance (queueVertex *x, std::string startingcity, std::string destination);
        void find_the_minimum_cost (double price, double mile, std::string position);//find the minimum cost among all of the restaurants

    protected:
    private:
        std::vector <vertex> vertices;
        std::vector <Restaurant_str> restaurant_array;
};

#endif // RESTAURANT_H
