#include <iostream>
#include "Restaurant.h"
#include <vector>
#include <string>
#include <queue>

using namespace std;

Restaurant::Restaurant(){}
Restaurant::~Restaurant(){}

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

void Restaurant::addEdge(std::string v1, std::string v2, int weight){//function to add edges
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
    addEdge("Boulder", "Broomfield", 13);
    addEdge("Boulder", "Lafayette", 10);
    addEdge("Boulder", "Longmont", 16);
    addEdge("Brighton", "Denver", 22);
    addEdge("Brighton", "Lafayette", 14);
    addEdge("Brighton", "Longmont", 20);
    addEdge("Broomfield", "Denver", 18);
    addEdge("Denver", "Lafayette", 25);
    addEdge("Lafayette", "Longmont", 15);
}
void Restaurant::insert_restaurant(std::string in_type, std::string in_city, std::string in_name, int in_price){
    Restaurant_str temp = Restaurant_str(in_price, in_type, in_city, in_name);
    restaurant_array.push_back(temp);
}
void Restaurant::implement_restaurants(){
    string h = "Hamburger";
    string p = "Pizza";
    string a = "Asian Food";
    insert_restaurant(h, "Boulder", "Wendy's", 10);
    insert_restaurant(h, "Brighton", "Five Guys", 13);
    insert_restaurant(h, "Broomfield", "Burger King", 15);
    insert_restaurant(p, "Denver", "Pizza Hut", 7);
    insert_restaurant(p, "Lafayette", "Domino's", 9);
    insert_restaurant(p, "Longmont", "Papa John's", 14);
    insert_restaurant(a, "Boulder", "Five Spice", 13);
    insert_restaurant(a, "Brighton", "Golden Sun", 9);
    insert_restaurant(a, "Longmongt", "Panda Express", 7);
}
void Restaurant::initial_all(){
    implement_graph();
    implement_restaurants();
}
void Restaurant::print_all_restaurants(){
    for(int i = 0; i < restaurant_array.size(); i++){
        cout << restaurant_array[i].type << ":  " << restaurant_array[i].name << ":  " << restaurant_array[i].city << ":  " << restaurant_array[i].price << endl;
    }
}
void Restaurant::print_one_type_restaurants(std::string type){
    for(int i = 0; i < restaurant_array.size(); i++){
        if (type == restaurant_array[i].type){
            cout << restaurant_array[i].name << ":  " << restaurant_array[i].city << ":  " << restaurant_array[i].price << endl;
        }
    }
}
void Restaurant::print_one_city_restaurants(std::string city){
    for(int i = 0; i < restaurant_array.size(); i++){
        if (city == restaurant_array[i].city){
            cout << restaurant_array[i].type << ":  " << restaurant_array[i].name << ":  " << restaurant_array[i].price << endl;
        }
    }
}
void Restaurant::print_nearest_restaurants(std::string position){
    vertex a;
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == position){a = vertices[i];}
    }
    bool findit = false;
    for(int i = 0; i < restaurant_array.size(); i++){
        if (position == restaurant_array[i].city){
            cout << restaurant_array[i].type << ":  " << restaurant_array[i].name << ":  " << restaurant_array[i].price << endl;
            findit = true;
        }
    }
    if (findit == false){
        string city_name;
        int temp = 10000;
        for(int i = 0; i < a.adj.size(); i++){
            if (a.adj[i].weight <= temp){
                temp = a.adj[i].weight;
                city_name = a.adj[i].v->name;
            }
        }
        print_one_city_restaurants(city_name);
    }
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
    if (s == d){cout << "They are the same city" << endl;}
    else{
        int previous[15];
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
                            if (temp < minDistance){
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
                previous[a->ID] = u->ID;
                qv->path.push_back(*a);
                qv->distance = minDistance;
            }
        }
        for (int i = 0; i < 15 ; i++){
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
        cout << "," << cities[i];
    }

}


