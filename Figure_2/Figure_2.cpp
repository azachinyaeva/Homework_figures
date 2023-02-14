#include <iostream>
#include <locale.h>
using namespace std;

class Figure {
public:
    Figure(string name_) {
        name = name_;
    }
    virtual void get_info() {
        cout << name;
    }
private:
    string name;
};

//треугольник
class Triangle : public Figure {
public:

    Triangle(string name_, int side_a_, int side_b_, int side_c_,
        int angle_A_, int angle_B_, int angle_C_) : Figure (name_) {
        name = name_;
        side_a = side_a_;
        side_b = side_b_;
        side_c = side_c_;
        angle_A = angle_A_;
        angle_B = angle_B_;
        angle_C = angle_C_;
    }

    void get_info() override {
        cout << this->name << "; " << '\n';
        cout << "Стороны: " << "a = " << this->side_a << " b = " << this->side_b
            << " c = " << this->side_c << '\n';
        cout << "Углы: " << "A = " << this->angle_A << " B = " << this->angle_B
            << " C = " << this->angle_C << '\n';
        cout << endl;
    }
   

protected:
    string name;
    int side_a, side_b, side_c;
    int angle_A, angle_B, angle_C;
};

//прямоугольный треугольник (угол C всегда равен 90);
class RightTriangle : public Triangle {

public:
    RightTriangle(string name_, int side_a_, int side_b_, int side_c_,
        int angle_A_, int angle_B_) : Triangle(name_, side_a_, side_b_, side_c_,
            angle_A_, angle_B_, 90)
    {

    }

};

//равнобедренный треугольник (стороны a и c равны, углы A и C равны)
class IsoscelesTriangle : public Triangle {

public:
    IsoscelesTriangle(string name_, int side_a_, int side_c_,
        int angle_A_, int angle_C_) : Triangle(name_, side_a_, side_c_, side_a_,
            angle_A_, angle_C_, angle_A_) {

    }

};

//равносторонний треугольник (все стороны равны, все углы равны 60);
class EquilateralTriangle : public IsoscelesTriangle {

public:
    EquilateralTriangle(string name_, int side_a_, int angle_A) 
    : IsoscelesTriangle(name_, side_a_, side_a_, 60, 60) {

    }

};

//четырёхугольник
class Quadrangle : public Figure {
public:
    Quadrangle (string name_, int side_a_, int side_b_, int side_c_, int side_d_,
            int angle_A_, int angle_B_, int angle_C_, int angle_D_) : Figure(name_) {
        name = name_;
        side_a = side_a_;
        side_b = side_b_;
        side_c = side_c_;
        side_d = side_d_;
        angle_A = angle_A_;
        angle_B = angle_B_;
        angle_C = angle_C_;
        angle_D = angle_D_;
    }

    void get_info() override {
        cout << this->name << "; " << '\n';
        cout << "Стороны: " << "a = " << this->side_a << " b = " << this->side_b
            << " c = " << this->side_c << " d = " << this->side_d << '\n';
        cout << "Углы: " << "A = " << this->angle_A << " B = " << this->angle_B
            << " C = " << this->angle_C << " D = " << this->angle_D << '\n';
        cout << endl;
    }


protected:
    string name;
    int side_a, side_b, side_c, side_d;
    int angle_A, angle_B, angle_C, angle_D;

};

//параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
class Parallelogram : public Quadrangle {

public:
    Parallelogram (string name_, int side_a_, int side_b_,
        int angle_A_, int angle_B_) : Quadrangle(name_, side_a_, side_b_, side_a_, side_b_,
            angle_A_, angle_B_, angle_A_, angle_B_) {}

};

//прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
class Rectangle : public Parallelogram {

public:
    Rectangle(string name_, int side_a_, int side_b_) : Parallelogram (name_, side_a_, side_b_, 90, 90) {}

};

//ромб (все стороны равны, углы A,C и B,D попарно равны).
class Rhombus : public Parallelogram {

public:
    Rhombus (string name_, int side_a_, int angle_A_, int angle_B_) 
        : Parallelogram(name_, side_a_, side_a_, angle_A_, angle_B_) {}

};

//квадрат (все стороны равны, все углы равны 90);
class Square : public Rhombus {

public:
    Square(string name_, int side_a_)
        : Rhombus (name_, side_a_, 90, 90) {}

};

int main()
{
    setlocale(LC_ALL, "Russian");
    Triangle triangle("Треугольник", 10, 10, 10, 60, 50, 50);
    RightTriangle triangle_r("Прямоугольный треугольник", 10, 10, 10, 60, 50);
    IsoscelesTriangle triangle_i("Равнобедренный треугольник", 10, 20, 60, 50);
    EquilateralTriangle triangle_e("Равносторонний треугольник", 10, 60);
    Quadrangle quad("Четырехугольник", 20, 30, 20, 30, 60, 50, 60, 50);
    Rectangle rect("Прямоугольник", 20, 30);
    Square square("Квадрат", 15);
    Parallelogram par("Параллелограмм", 20, 30, 60, 40);
    Rhombus rhombus("Ромб", 16, 35, 40);
    triangle.get_info();
    triangle_r.get_info();
    triangle_i.get_info();
    triangle_e.get_info();
    quad.get_info();
    rect.get_info();
    square.get_info();
    par.get_info();
    rhombus.get_info();

}

