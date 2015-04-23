#include <iostream>
#include "Restaurant.h"
#include <vector>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;

Restaurant::Restaurant(){}
Restaurant::~Restaurant(){}

void Restaurant::print_menu(){
    cout << "================Menu===============" << endl;
    cout << "1. Insert Restaurant" << endl;
    cout << "2. List all restaurants" << endl;
    cout << "3. One type restaurants" << endl;
    cout << "4. Restaurants in a city" << endl;
    cout << "5. Nearest restaurants" << endl;
    cout << "6. Minimum cost for each restaurant" << endl;
    cout << "7. Total cost for chosen restaurant" << endl;
    cout << "8. Restaurant with minimum cost" << endl;
    cout << "9. Quit" << endl;
    cout << "===================================" << endl;
}

void Restaurant::addVertex(std::string n){//function to add cities
    bool found = false; // check if the vertex is added
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.ID = vertices.size();
        vertices.push_back(v);
    }
}

void Restaurant::addEdge(std::string v1, std::string v2, double weight){//function to add edges
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Restaurant::implement_graph(){
    addVertex("Boulder");
    addVertex("Brighton");
    addVertex("Broomfield");
    addVertex("Denver");
    addVertex("Lafayette");
    addVertex("Longmont");
    addEdge("Boulder", "Broomfield", 13.1);
    addEdge("Boulder", "Lafayette", 9.69);
    addEdge("Boulder", "Longmont", 15.6);
    addEdge("Brighton", "Denver", 22.2);
    addEdge("Brighton", "Lafayette", 14.28);
    addEdge("Brighton", "Longmont", 19.50);
    addEdge("Broomfield", "Denver", 17.5);
    addEdge("Denver", "Lafayette", 25.00);
    addEdge("Lafayette", "Longmont", 12.9);
}
void Restaurant::insert_restaurant(std::string in_type, std::string in_city, std::string in_name, double in_price){
    Restaurant_str temp = Restaurant_str(in_price, in_type, in_city, in_name);
    restaurant_array.push_back(temp);
}
void Restaurant::implement_restaurants(){
    string h = "Hamburger";
    string p = "Pizza";
    string a = "Asian Food";
    insert_restaurant(h, "Boulder", "Wendy's", 10.5);
    insert_restaurant(h, "Brighton", "Five Guys", 13.6);
    insert_restaurant(h, "Broomfield", "Burger King", 15.7);
    insert_restaurant(p, "Denver", "Pizza Hut", 7.8);
    insert_restaurant(p, "Lafayette", "Domino's", 9.9);
    insert_restaurant(p, "Longmont", "Papa John's", 14.1);
    insert_restaurant(a, "Boulder", "Five Spice", 13.2);
    insert_restaurant(a, "Brighton", "Golden Sun", 9.3);
    insert_restaurant(a, "Longmongt", "Panda Express", 7.4);
}
void Restaurant::initial_all(){
    implement_graph();
    implement_restaurants();
}
void Restaurant::print_all_restaurants(){
    cout << "============================================" << endl;
    for(int i = 0; i < restaurant_array.size(); i++){
        cout << restaurant_array[i].type << ":  " << restaurant_array[i].name << ":  " << restaurant_array[i].city << ":  " << restaurant_array[i].price << endl;
    }
    cout << "============================================\n" << endl;
}
void Restaurant::print_one_type_restaurants(std::string type){
    bool findit = false;
    for(int i = 0; i < restaurant_array.size(); i++){
        if (type == restaurant_array[i].type){
            findit = true;
        }
    }
    if (findit == false){cout << "The type of food is not in the system" << endl;}
    else{
        cout << "=============================" << endl;
        for(int i = 0; i < restaurant_array.size(); i++){
            if (type == restaurant_array[i].type){
                cout << restaurant_array[i].name << ":  " << restaurant_array[i].city << ":  " << restaurant_array[i].price << endl;
            }
        }
        cout << "=============================\n" << endl;
    }

}
void Restaurant::print_one_city_restaurants(std::string city){
    bool findit = false;
    for(int i = 0; i < restaurant_array.size(); i++){
        if (city == restaurant_array[i].city){
            findit = true;
        }
    }
    if (findit == false){cout << "The city is not in the system" << endl;}
    else{
        cout << "==============================" << endl;
        for(int i = 0; i < restaurant_array.size(); i++){
            if (city == restaurant_array[i].city){
                cout << restaurant_array[i].type << ":  " << restaurant_array[i].name << ":  " << restaurant_array[i].price << endl;
            }
        }
        cout << "==============================\n" << endl;
    }
}
void Restaurant::print_nearest_restaurants(std::string position){
    vertex a;
    bool finditt = false;
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == position){
            a = vertices[i];
            finditt = true;
        }
    }
    bool findit = false;
    if (finditt == true){
        cout << "==============================" << endl;
        for(int i = 0; i < restaurant_array.size(); i++){
            if (position == restaurant_array[i].city){
                cout << restaurant_array[i].type << ":  " << restaurant_array[i].name << ":  " << restaurant_array[i].price << endl;
                findit = true;
            }
        }
        cout << "==============================\n" << endl;
    }
    if (findit == false && finditt == true){
        string city_name;
        int temp = 10000;
        for(int i = 0; i < a.adj.size(); i++){
            if (a.adj[i].weight <= temp){
                temp = a.adj[i].weight;
                city_name = a.adj[i].v->name;
            }
        }
        cout << "==============================" << endl;
        print_one_city_restaurants(city_name);
        cout << "==============================\n" << endl;
    }
    if (finditt == false){cout << "The position you are currently at is not in the system"<<endl;}
}
queueVertex* Restaurant::Dijkstra_algorithm (std::string startingcity, std::string destination){
    vertex *s = NULL;
    vertex *d = NULL;
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == startingcity){
            s = &vertices[i];//set s == startingcity node
        }
        if (vertices[i].name == destination){
            d = &vertices[i];//set d == destination node
        }
    }
    if (s == NULL || d == NULL){
        cout << "One or more cities doesn't exist" <<endl;
        return NULL;
    }
    if (s == d){
        queueVertex *qv = new queueVertex;//vector of solved vertices
        qv->distance = 0;
        return qv;
    }
    else{
        int previous[6];
        for (int i = 0; i < vertices.size(); i++){
            vertices[i].visited = false;
            vertices[i].distance_to_origin = 10000;
            previous[vertices[i].ID] = -1;
        }
        s->visited = true;
        s->distance_to_origin = 0;
        queueVertex *qv = new queueVertex;//vector of solved vertices
        qv->distance = 0;
        qv->path.push_back(*s);
        int minDistance;
        int temp;
        vertex *a;
        vertex *u;
        while (d->visited == false){//haven't reach the destination
            minDistance = 10000;//initialize distance
            a = NULL;
            u = NULL;
            for (int i = 0; i < qv->path.size(); i++){//for each u in solved
                for (int j = 0; j < qv->path[i].adj.size(); j++){//for each vertex adjacent to u
                    if (qv->path[i].adj[j].weight != 0 && qv->path[i].adj[j].weight !=-1){
                        if (qv->path[i].adj[j].v->visited == false){
                            temp = qv->path[i].adj[j].weight + qv->path[i].distance_to_origin;
                            if (temp < minDistance){//compare current distance with the minDistance
                                minDistance = temp;
                                a = qv->path[i].adj[j].v;
                                u = &qv->path[i];
                            }
                        }
                    }
                }
            }
            if (a != NULL){
                a->visited = true;
                a->distance_to_origin = minDistance;
                previous[a->ID] = u->ID;//keep track of previous cities
                qv->path.push_back(*a);
                qv->distance = minDistance;
            }
        }
        for (int i = 0; i < 6 ; i++){
            qv->p[i] = previous[i];
        }
        return qv;
    }
    return NULL;
}
void Restaurant::print_shortest_distance (queueVertex *x, string startingcity, string destination){
    vertex *s = NULL;
    vertex *d = NULL;
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == startingcity){
            s = &vertices[i];
        }
        if (vertices[i].name == destination){
            d = &vertices[i];
        }
    }
    int d_id = x->p[d->ID];
    vector <string> cities;
    cities.push_back(destination);
    while (d_id != -1){
        cities.push_back(vertices[d_id].name);
        d = &vertices[d_id];
        d_id = x->p[d->ID];
    }
    for (int i = cities.size()-1; i >= 0; i--){
        cout << " " << cities[i];
    }

}
void Restaurant::print_minimum_cost_each_restaurants(double price, double mile, std::string position){//price = oil price; mile = miles/gallon
    double cost = 0;
    double total_cost = 0;
    double distance = 0;
    bool findit = false;
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == position){findit = true;}
    }
    if (findit == true){
        cout << "============================================" << endl;
        for (int i = 0; i <vertices.size() && findit == true; i++){
            queueVertex *a;//give a temp queueVertex
            a = Dijkstra_algorithm(position, vertices[i].name);
            if (a->distance != 0){
                distance = a->distance;
                cost = price * (distance/mile);//compute how much will cost to drive to the city from the user's position

            }
            for (int j = 0; j < restaurant_array.size(); j++){
                if (restaurant_array[j].city == vertices[i].name){
                    total_cost = cost + restaurant_array[j].price;
                    cout << restaurant_array[j].city << ":  " << restaurant_array[j].type << ":  " << restaurant_array[j].name << ":  ";
                    cout << fixed << setprecision(2) << total_cost << endl;
                }
            }
        }
        cout << "============================================\n" << endl;
    }
    if (findit == false){cout << "The position you are currently at is not in the system!" << endl;}
}
void Restaurant::print_total_cost_one_restaurant(std::string name, std::string position, double price, double mile){
    bool findit = false;
    Restaurant_str temp;
    for (int i = 0; i < restaurant_array.size(); i++){
        if (restaurant_array[i].name == name){
            temp = restaurant_array[i];
            findit = true;
        }
    }
    if (findit == false){cout << "The restaurant is not in the system" << endl;}
    else{
        double cost = 0;
        double total_cost = 0;
        double distance = 0;
        string city;
        city = temp.city;
        queueVertex *a;//give a temp queueVertex
        a = Dijkstra_algorithm(position, city);
        if (a->distance != 0){
            distance = a->distance;
            cost = price * (distance/mile);//compute how much will cost to drive to the city from the user's position
        }
        total_cost = cost + temp.price;
        cout << "=====================" << endl;
        cout << temp.name << ":  " << temp.type << endl;
        if (temp.city != position){
            cout << "The route to the restaurant: ";
            print_shortest_distance(a, position, city);
            cout << endl;
        }
        cout << "Total minimum cost: ";
        cout << fixed << setprecision(2) << total_cost << endl;
        cout << "=====================" << endl;
        cout << endl;
    }
}
void Restaurant::find_the_minimum_cost (double price, double mile, std::string position){
    double cost = 0;
    double total_cost = 0;
    double distance = 0;
    bool findit = false;
    double mincost = 10000;
    Restaurant_str best;
    queueVertex *best2;
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == position){findit = true;}
    }
    if (findit == true){
        for (int i = 0; i <vertices.size() && findit == true; i++){
            queueVertex *a;//give a temp queueVertex
            a = Dijkstra_algorithm(position, vertices[i].name);
            if (a->distance != 0){
                distance = a->distance;
                cost = price * (distance/mile);//compute how much will cost to drive to the city from the user's position
            }
            for (int j = 0; j < restaurant_array.size(); j++){
                if (restaurant_array[j].city == vertices[i].name){
                    total_cost = cost + restaurant_array[j].price;
                    if (total_cost <= mincost){
                        mincost = total_cost;
                        best = restaurant_array[j];
                        best2 = a;
                    }
                }
            }
        }
        cout << "=====================" << endl;
        cout << best.name << ":  " << best.type;
        if (best.city != position){
            cout << endl;
            cout << "The route to the restaurant: ";
            print_shortest_distance(best2, position, best.city);
            cout << endl;
        }
        else {cout << ":  " << position << endl;}
        cout << "Total minimum cost: ";
        cout << fixed << setprecision(2) << mincost << endl;
        cout << "=====================" << endl;
        cout << endl;
    }
    if (findit == false){cout << "The position you are currently at is not in the system!" << endl;}
}

