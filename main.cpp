#include <iostream>
#include "Restaurant.h"
using namespace std;

int main()
{
    string position;
    cout << "Enter current city: " << endl;

    getline(cin, position);

    Restaurant r;
    r.print_menu();
    int command;
    string type;
    string city;
    string restaurant;
    cin >> command;
    while (command != 9){
        if (command == 1){
            r.initial_all();
            r.print_menu();
            cin >> command;
        }
        else if (command == 2){
            r.print_all_restaurants();
            r.print_menu();
            cin >> command;
        }
        else if (command == 3){
            cout << "Enter type of food: " << endl;
            cin.ignore();
            getline(cin, type);
            r.print_one_type_restaurants(type);
            r.print_menu();
            cin >> command;
        }
        else if (command == 4){
            cout << "Enter the city: " << endl;
            cin.ignore();
            getline(cin, city);
            r.print_one_city_restaurants(city);
            r.print_menu();
            cin >> command;
        }
        else if (command == 5){
            r.print_nearest_restaurants(position);
            r.print_menu();
            cin >> command;
        }
        else if (command == 6){
            double price;
            double mile;
            cout << "Enter price of gasoline: " << endl;
            cin >> price;
            cout << "Enter miles per gallon for your vehicle: " << endl;
            cin >> mile;
            r.print_minimum_cost_each_restaurants(price, mile,position);
            r.print_menu();
            cin >> command;
        }
        else if (command == 7){
            cout << "Enter the name of restaurant: " << endl;
            cin.ignore();
            getline(cin, restaurant);
            double price;
            double mile;
            cout << "Enter price of gasoline: " << endl;
            cin >> price;
            cout << "Enter miles per gallon for your vehicle: "<<endl;
            cin >> mile;
            r.print_total_cost_one_restaurant(restaurant, position, price, mile);
            r.print_menu();
            cin >> command;
        }
        else if (command == 8){
            double price;
            double mile;
            cout << "Enter price of gasoline: " << endl;
            cin >> price;
            cout << "Enter miles per gallon for your vehicle: "<<endl;
            cin >> mile;
            r.find_the_minimum_cost(price, mile, position);
            r.print_menu();
            cin >> command;
        }
        else{
            r.print_menu();
            cin >> command;
        }

    }
    cout << "Goodbye!" << endl;
    return 0;
}
