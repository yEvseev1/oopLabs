#include <cmath>
#include <iostream>

#include "include/FigureList.hpp"
#include "include/Hexagon.hpp"
#include "include/Octagon.hpp"
#include "include/Triangle.hpp"

int main() {
    Triangle triangleOne(Point(1, sqrt(3)), Point(2, 0), Point(0, 0));
    Point pointOne = triangleOne.geom_center();
    std::cout << triangleOne << std::endl;
    std::cout << pointOne << std::endl;
    std::cout << triangleOne.area() << std::endl << std::endl;

    Triangle triangleTwo(2);
    Point pointTwo = triangleTwo.geom_center();
    std::cout << triangleTwo << std::endl;
    std::cout << pointTwo << std::endl;
    std::cout << triangleTwo.area() << std::endl << std::endl;

    Hexagon hexagonOne(3);
    Point point3 = hexagonOne.geom_center();
    std::cout << hexagonOne << std::endl;
    std::cout << point3 << std::endl;
    std::cout << hexagonOne.area() << std::endl << std::endl;

    Octagon octagonOne(4);
    Point point4 = octagonOne.geom_center();
    std::cout << octagonOne << std::endl;
    std::cout << point4 << std::endl;
    std::cout << octagonOne.area() << std::endl << std::endl;

    FigureList figureList{};
    figureList.push_back(&triangleOne);
    figureList.push_back(&triangleTwo);
    figureList.push_back(&hexagonOne);
    figureList.push_back(&octagonOne);

    figureList.print_geom_center();
    std::cout << figureList.total_area() << std::endl;

    return 0;
}
