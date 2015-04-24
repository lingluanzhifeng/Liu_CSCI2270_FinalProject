# Porject Documentation
### Initially
The user of the code needs to prompt for a current position which needs to be one of the followings: Boulder, Denver, Longmont, Broomfield, Brighton, and Lafayette. Otherwise, there will be segmentation faults or other problems. Then the user of the code needs to call the initial() function in the class to implement the graph and the array of restaurants. 

I will talk about the code according to the menu I provide in "README.md" file.
### Insert Restaurant
The first option will call this function: void insert_restaurant(std::string in_type, std::string in_city, std::string in_name, double in_price)

The function will help to insert some restaurants that are not in the initial implementation. 
Before calling the function, the user of the code need to prompt for the name, city, type and price of the restaurant. After calling the function, there will be nothing showed on the screen, but if you check it, the new restaurant is added to the vector of restaurants.
### Print all of the restaurants
The second option of the menu will call this function: void print_all_restaurants()

The function could only be called after initialing all of the things, using the function: void initial_all(). Otherwise, there will be several segmentation faults.

After calling the pringing fuction, all of the restaurants in the vector of restaurants will be printed as: (Type:  Name:  City:  Price)
### Print restaurants of one type
The third option of the menu is to print all of the restaurants of one type of food which is provided by the user of the program. Before the function called, the graph and other things need to be implemented and the user needs to provide the current position. 

After the function is called, the output will be like: (Name:  City:  Price)
### Print restaurants in one city
The fourth option of the menu will print all of the restaurants in one city, which is provided by the user of the program. Pre-condition is the same as the last option. 

After the function is called, the output will be like: (Type:  Name:  Price)
### Print the nearest restaurants
The fifth option of the menu is to print all of the restaurants that are nearest to the current position. Pre-condition is the same as the fourth one. 

We regard the cities as points, which means there is no distance between restaurants in one city. In this way, if there is no restaurants in current city, the program will find one in the nearest city.

After the function is called, the output will be like: (Type:  Name:  Price)
### Minimum cost for each restaurant
Pre-condition: the user of the program needs to provide the price of current gasoline, miles per gallon of the vehicle, and the current position. The function will count the minimum cost for the user of the program to eat at each restaurant, including the cost of gasoline and the cost of meal.

After the function is called, the output will be like: (City:  Type:  Name:  Total cost)
### Total cost for chosen restaurant
Pre-condition: The user of the program needs to provide the name of the restaurant, the price of current gasoline, miles per gallon of the vehicle, and the current position. The function will count the minimum cost for user to be there and have a meal. The function will show the shorest and cheapest way to be the restaurant. 

The out put is like: 

Name:  Type

The route to the restaurant: 

Total minimum cost: 
### Restaurant with minimum cost
Pre-condition: The user of the program needs to provide the price of current gasoline, miles per gallon of the vehicle, and the current position. Then the function will count based on the shorest distance and the price of the restaurant to give the user the restaurant with minimum cost to have a meal.

The output is like: 

Name:  Type(:  City)(if they are in the same city)

The route to the restaurant: (if they are in different city)

Total minimum cost: 