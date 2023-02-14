#include <iostream>
#include <locale.h>
using namespace std;
class Figure{
public:
    Figure() {
        name = "Фигура";
        sides_count = 0;
    }
    Figure(string name, int sides_count) {
        this->name = name;
        this->sides_count = sides_count;
    }

    void get_sides_count() {
        cout << this-> name << ": " << this->sides_count;
    }

private:
    int sides_count;
    string name;
};

class Triangle : public Figure {
public:
    Triangle() : Figure ("Треугольник", 3) {

    }
 
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure ("Прямоугольник", 4) {

    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;
    cout << "Количество сторон: " << '\n';
    figure.get_sides_count();
    cout << '\n';
    triangle.get_sides_count();
    cout << '\n';
    quadrangle.get_sides_count();

}

