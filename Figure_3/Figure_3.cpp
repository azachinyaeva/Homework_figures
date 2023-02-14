#include <iostream>
#include <locale.h>
using namespace std;

class Figure {
public:
    Figure(string name_) {
        name = name_;
        sides = 0;
    }
    //метод вывода на экран
    virtual void get_info() {
        cout << name << ": " << '\n';
        if (check() == true) {
            cout << "Правильная" << '\n';
        }
        else {
            cout << "Неправильная" << '\n';
        }
        cout << "Количество сторон: " << this->sides << '\n';
        cout << endl;
    }
    //метод проверки
    virtual bool check() {
        return true;
    }
private:
    string name;
    int sides;
};

//треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
class Triangle : public Figure {
public:

    Triangle(string name_, int side_a_, int side_b_, int side_c_,
        int angle_A_, int angle_B_, int angle_C_) : Figure(name_) {
        name = name_;
        side_a = side_a_;
        side_b = side_b_;
        side_c = side_c_;
        angle_A = angle_A_;
        angle_B = angle_B_;
        angle_C = angle_C_;
    }

    //геттеры
    int get_side_a() {
        return side_a;
    }
    int get_side_b() {
        return side_b;
    }
    int get_side_c() {
        return side_c;
    }

    int get_angle_A() {
        return angle_A;
    }
    int get_angle_B() {
        return angle_B;
    }
    int get_angle_C() {
        return angle_C;
    }

    //метод вывода на экран
    void get_info() override {
        cout << this->name << ": " << '\n';

        if (check() == true) {
            cout << "Правильная" << '\n';
        }
        else {
            cout << "Неправильная" << '\n';
        }
        cout << "Стороны: " << "a = " << this->side_a << " b = " << this->side_b
            << " c = " << this->side_c << '\n';
        cout << "Углы: " << "A = " << this->angle_A << " B = " << this->angle_B
            << " C = " << this->angle_C << '\n';
        cout << endl;
    }

    //метод проверки
    bool check() override {
        return get_angle_A() + get_angle_B() + get_angle_C() == 180;
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

    bool check() override {
        return (Triangle::check() == true) && (this->get_angle_C() == 90);
    }
};

//равнобедренный треугольник (стороны a и c равны, углы A и C равны)
class IsoscelesTriangle : public Triangle {

public:
    IsoscelesTriangle(string name_, int side_a_, int side_c_,
        int angle_A_, int angle_C_) : Triangle(name_, side_a_, side_c_, side_a_,
            angle_A_, angle_C_, angle_A_) {

    }

    bool check() override {
        return ((Triangle::check() == true)) &&
            (this->get_side_a() == this->get_side_c()) && (this->get_angle_A() == this->get_angle_C());
    }
};

//равносторонний треугольник (все стороны равны, все углы равны 60);
class EquilateralTriangle : public IsoscelesTriangle {

public:
    EquilateralTriangle(string name_, int side_a_, int angle_A)
        : IsoscelesTriangle(name_, side_a_, side_a_, 60, 60) {

    }

    bool check() override {
        return (Triangle::check() == true) &&
            (this->get_side_a() == this->get_side_b()) && (this->get_side_a() == this->get_side_c());
    }
};

//четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
class Quadrangle : public Figure {
public:
    Quadrangle(string name_, int side_a_, int side_b_, int side_c_, int side_d_,
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

    //геттеры
    int get_side_a() {
        return side_a;
    }
    int get_side_b() {
        return side_b;
    }
    int get_side_c() {
        return side_c;
    }
    int get_side_d() {
        return side_d;
    }

    int get_angle_A() {
        return angle_A;
    }
    int get_angle_B() {
        return angle_B;
    }
    int get_angle_C() {
        return angle_C;
    }
    int get_angle_D() {
        return angle_D;
    }

    //метод вывода на экран
    void get_info() override {
        cout << this->name << "; " << '\n';
        if (check() == true) {
            cout << "Правильная" << '\n';
        }
        else {
            cout << "Неправильная" << '\n';
        }

        cout << "Стороны: " << "a = " << this->side_a << " b = " << this->side_b
            << " c = " << this->side_c << " d = " << this->side_d << '\n';
        cout << "Углы: " << "A = " << this->angle_A << " B = " << this->angle_B
            << " C = " << this->angle_C << " D = " << this->angle_D << '\n';
        cout << endl;
    }

    //метод проверки
    bool check() override {
        return (this->get_angle_A() + this->get_angle_B() + this->get_angle_C() + this->get_angle_D() == 360);
    }

protected:
    string name;
    int side_a, side_b, side_c, side_d;
    int angle_A, angle_B, angle_C, angle_D;

};

//параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
class Parallelogram : public Quadrangle {

public:
    Parallelogram(string name_, int side_a_, int side_b_,
        int angle_A_, int angle_B_) : Quadrangle(name_, side_a_, side_b_, side_a_, side_b_,
            angle_A_, angle_B_, angle_A_, angle_B_) {}

    bool check() override {
        return (Quadrangle::check() == true) &&
            ((this->get_angle_A() == this->get_angle_C()) && this->get_angle_B() == this->get_angle_D()) &&
            (this->get_side_a() == this->get_side_c() && this->get_side_b() == this->get_side_d());
    }
};

//прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
class Rectangle : public Parallelogram {

public:
    Rectangle(string name_, int side_a_, int side_b_) : Parallelogram(name_, side_a_, side_b_, 90, 90) {}

    bool check() override {
        return (Quadrangle::check() == true) &&
            (this->get_side_a() == this->get_side_c() && this->get_side_b() == this->get_side_d()) &&
            ((this->get_angle_A() == 90) && (this->get_angle_B() == 90) && (this->get_angle_C() == 90) && (this->get_angle_D() == 90));
    }
};

//ромб (все стороны равны, углы A,C и B,D попарно равны).
class Rhombus : public Parallelogram {

public:
    Rhombus(string name_, int side_a_, int angle_A_, int angle_B_)
        : Parallelogram(name_, side_a_, side_a_, angle_A_, angle_B_) {}

    bool check() override {
        return (Quadrangle::check() == true) &&
        (this->get_side_a() == this->get_side_b() && this->get_side_c() == this->get_side_d() && this->get_side_a() == this->get_side_c()) &&
            ((this->get_angle_A() == this->get_angle_C()) && this->get_angle_B() == this->get_angle_D());
    }
};

//квадрат (все стороны равны, все углы равны 90);
class Square : public Rhombus {

public:
    Square(string name_, int side_a_)
        : Rhombus(name_, side_a_, 90, 90) {}

    bool check() override {
        return (Quadrangle::check() == true) &&
            (this->get_side_a() == this->get_side_b() && this->get_side_c() == this->get_side_d() && this->get_side_a() == this->get_side_c()) &&
            ((this->get_angle_A() == 90) && (this->get_angle_B() == 90) && (this->get_angle_C() == 90) && (this->get_angle_D() == 90));
    }
};

void print_object(Figure* figure) {
    figure->get_info();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Figure figure("Фигура");
    Triangle triangle("Треугольник", 10, 10, 10, 60, 70, 50);
    RightTriangle triangle_r("Прямоугольный треугольник", 10, 10, 10, 60, 50);
    IsoscelesTriangle triangle_i("Равнобедренный треугольник", 10, 20, 60, 50);
    EquilateralTriangle triangle_e("Равносторонний треугольник", 10, 60);
    Quadrangle quad("Четырехугольник", 20, 30, 20, 30, 60, 50, 60, 50);
    Rectangle rect("Прямоугольник", 20, 30);
    Square square("Квадрат", 15);
    Parallelogram par("Параллелограмм", 20, 30, 100, 80);
    Rhombus rhombus("Ромб", 16, 100, 80);
    Figure* ptr_figure = &figure;
    print_object(ptr_figure);
    ptr_figure = &triangle;
    print_object(ptr_figure);
    ptr_figure = &triangle_r;
    print_object(ptr_figure);
    ptr_figure = &triangle_i;
    print_object(ptr_figure);
    ptr_figure = &triangle_e;
    print_object(ptr_figure);
    ptr_figure = &quad;
    print_object(ptr_figure);
    ptr_figure = &rect;
    print_object(ptr_figure);
    ptr_figure = &square;
    print_object(ptr_figure);
    ptr_figure = &par;
    print_object(ptr_figure);
    ptr_figure = &rhombus;
    print_object(ptr_figure);

}

