#include <iostream>
#include <clocale>

using namespace std;

class IShape {
public:
    virtual ~IShape() = default;
    virtual double CalculateArea() const = 0;
    virtual double CalculatePerimeter() const = 0;
};

class Circle : public IShape {
private:
    double radius;
    const double PI = 3.141592653589793;

public:
    Circle(double r) : radius(r) {}

    double CalculateArea() const override {
        return PI * radius * radius;
    }

    double CalculatePerimeter() const override {
        return 2 * PI * radius;
    }
};

class Rectangle : public IShape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double CalculateArea() const override {
        return width * height;
    }

    double CalculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public IShape {
private:
    double a, b, c;

    double customSqrt(double value) const {
        if (value <= 0) return 0;
        double x = value;
        for (int i = 0; i < 20; ++i) {
            x = 0.5 * (x + value / x);
        }
        return x;
    }

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    double CalculatePerimeter() const override {
        return a + b + c;
    }

    double CalculateArea() const override {
        double p = CalculatePerimeter() / 2.0;
        double areaSquared = p * (p - a) * (p - b) * (p - c);
        return customSqrt(areaSquared);
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);

    IShape* shapes[] = { &circle, &rectangle, &triangle };

    cout << "Коло -> Площа: " << shapes[0]->CalculateArea()
        << ", Периметр: " << shapes[0]->CalculatePerimeter() << endl;
    cout << "Прямокутник -> Площа: " << shapes[1]->CalculateArea()
        << ", Периметр: " << shapes[1]->CalculatePerimeter() << endl;
    cout << "Трикутник -> Площа: " << shapes[2]->CalculateArea()
        << ", Периметр: " << shapes[2]->CalculatePerimeter() << endl;

    return 0;
}