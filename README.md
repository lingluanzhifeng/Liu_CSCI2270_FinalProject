# Liu_CSCI2270_FinalProject
### Project Summary
My project is a program to give the user the list of restaurant in six cities: Boulder, Denver, Longmont, Broomfield, Brighton, and Lafayette. There is a struct called restaurant in my project, which contains the price of a meal per person, the city of the restaurant, the name of the restaurant, and the type of food the restaurant order. There is a graph in my program to track the distance between cities and the shortest path go from the user's position to the restaurant. Then the program will give the lowest price of eating at a restaurant, including the cost of oil and the price of the meal. Initially, there will be 15 restaurants, and the user could add restaurants with their price, name, type and price, then the user could search a restaurant in the new system. 
### How to Run
1. The user needs to give the program the city they are in, and the city needs to be one of the six cities. 
2. [Project documentation](https://github.com/lingluanzhifeng/Liu_CSCI2270_FinalProject/blob/master/Project_documentation.md)
3. There will be 9 options for the user to choose. And for some options, the user needs to follow the instructions, and gives the program commands. 
4. Types of food: Pizza, Hamburger, Asian Food, and the type of food user added. 
5. Cities: Boulder, Denver, Longmont, Broomfield, Brighton, and Lafayette. 
```go
    /*
    ================Menu================
    1. Insert Restaurant
    2. List all restaurants
    3. One type restaurants
    4. Restaurants in a city
    5. Nearest restaurants
    6. Minimum cost for each restaurant
    7. Total cost for chosen restaurant
    8. Restaurant with minimum cost
    9. Quit
    */
```
### Dependencies
The program requires to include serverval functions.
```go
    #include <iostream>
    #include <vector>
    #include <string>
    #include <queue>
    
    using namespace std;
````
### System Requirements
The program is for Linux and built by C++.
### Group Members
Yuming Liu
### Contributors
### Open Issues/Bugs
