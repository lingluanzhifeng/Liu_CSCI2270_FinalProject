#include <iostream>
#include "Restaurant.h"
using namespace std;

int main()
{
    Restaurant r;
    r.initial_all();
    r.print_all_restaurants();
    cout << endl;
    r.print_one_type_restaurants("Pizza");
    cout << endl;
    r.print_one_city_restaurants("Boulder");
    cout << endl;
    r.print_nearest_restaurants("Boulder");
    return 0;
}
