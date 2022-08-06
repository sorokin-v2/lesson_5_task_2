#include <iostream>
#include <string>


class Figure {

protected:
    Figure() {}         //Конструктор protected чтобы нельзя было создать экземпляр класса. Класс используется как базовый

    std::string name;
};

class Triangle : public Figure {
public:
    Triangle(int new_a, int new_b, int new_c, int new_A, int new_B, int new_C) :
        a{ new_a }, b{ new_b }, c{ new_c }, A{ new_A }, B{ new_B }, C{new_C}
    {
        name = "Треугольник";
    }
    std::string get_params() {
        return name + ":\nСтороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n" +
            "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C);
    }

protected:
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
};

class Right_triangle : public Triangle {
public:
    Right_triangle(int new_a, int new_b, int new_c, int new_A, int new_B) :
        Triangle(new_a, new_b, new_c, new_A, new_B, 90)
    {
        name = "Прямоугольный треугольник";
    }
};

class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle(int new_a, int new_b,  int new_A, int new_B) :
        Triangle(new_a, new_b, new_a, new_A, new_B, new_A)
    {
        name = "Равнобедренный треугольник";
    }
};

class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int new_a) :
        Triangle(new_a, new_a, new_a, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure {
public:

    Quadrangle(int new_a, int new_b, int new_c, int new_d, int new_A, int new_B, int new_C, int new_D) :
        a{ new_a }, b{ new_b }, c{ new_c }, d{ new_d }, A{ new_A }, B{ new_B }, C{ new_C }, D{ new_D }
    {
        name = "Четырёхугольник";
    }

    std::string get_params() {
        return name + ":\nСтороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n" +
            "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + +" D=" + std::to_string(D);
    }
protected:

    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int new_a, int new_b, int new_A, int new_B) :
        Quadrangle(new_a, new_b, new_a, new_b, new_A, new_B, new_A, new_B)
    {
        name = "Параллелограмм";
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int new_a, int new_b) :
        Parallelogram(new_a, new_b, 90, 90)
    {
        name = "Прямоугольник";
    }
};

class Rhomb : public Parallelogram {
public:
    Rhomb(int new_a, int new_A, int new_B) :
        Parallelogram(new_a, new_a, new_A, new_B)
    {
        name = "Ромб";
    }
};

class Square : public Rectangle {
public:
    Square(int new_a) :
        Rectangle(new_a, new_a)
    {
        name = "Квадрат";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    Right_triangle right_triangle(10, 20, 30, 50, 60);
    Isosceles_triangle isosceles_triangle(10, 20, 50, 60);
    Equilateral_triangle equilateral_triangle(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rectangle rectangle(10, 20);
    Rhomb rhomb(30, 30, 40);
    Square square(20);

    std::cout << triangle.get_params() << "\n\n";
    std::cout << right_triangle.get_params() << "\n\n";
    std::cout << isosceles_triangle.get_params() << "\n\n";
    std::cout << equilateral_triangle.get_params() << "\n\n";
    std::cout << quadrangle.get_params() << "\n\n";
    std::cout << rectangle.get_params() << "\n\n";
    std::cout << square.get_params() << "\n\n";
    std::cout << parallelogram.get_params() << "\n\n";
    std::cout << rhomb.get_params() << std::endl;
    
}
