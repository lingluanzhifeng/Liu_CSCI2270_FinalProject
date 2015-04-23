#include <iostream>
#include "Restaurant.h"
using namespace std;

int main()
{
    Restaurant r;
    r.initial_all();
    r.print_all_restaurants();

    r.print_one_type_restaurants("Pizza");

    r.print_one_city_restaurants("Boulder");

    r.print_nearest_restaurants("Boulder");

    r.print_minimum_cost_each_restaurants(3, 8, "Boulder");

    r.print_total_cost_one_restaurant("Five Guys", "Broomfield", 3, 8);

    r.find_the_minimum_cost(3, 8, "Boulder");
    return 0;
}
