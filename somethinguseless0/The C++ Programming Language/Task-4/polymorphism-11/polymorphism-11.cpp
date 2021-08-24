#include<iostream>
using namespace std;

class container
{

public:
    container(double radius1);
    virtual double surface_area() = 0;
    virtual double volume() = 0;
protected:
    double radius;
};
container::container(double radius1)
{
    radius = radius1;
}
class cube :public container
{
public:
    cube(double radius1) :container(radius1)
    {

    }
    double surface_area()
    {
        return 6 * radius * radius;
    }
    double volume()
    {
        return radius * radius * radius;
    }
};
class sphere :public container
{
public:
    sphere(double radius1) :container(radius1)
    {

    }
    double surface_area()
    {
        return 4 * 3.14 * radius * radius;
    }
    double volume()
    {
        return 4 / 3 * radius * radius * radius * 3.14;
    }
};
class cylinder :public container
{
public:
    cylinder(double radius1, double h) :container(radius1)
    {
        height = h;
    }
    double surface_area()
    {
        return 2 * 3.14 * radius * radius + 2 * 3.14 * radius * height;
    }
    double volume()
    {
        return 3.14 * radius * radius * height;
    }
private:
    double height;

};

int main()
{
    container* x;
    cube A(6.0);
    x = &A;
    cout << "正方体的表面积是: " << x->surface_area() << endl;
    //cout<<"正方体的表面积是: "<<A.surface_area()<<endl;
    cout << "正方体的体积是: " << x->volume() << endl;
    // cout<<"正方体的体积是: "<<A.volume()<<endl;

    sphere B(5.0);
    x = &B;
    cout << "球体的表面积是: " << x->surface_area() << endl;
    cout << "球体的体积是: " << x->volume() << endl;

    cylinder C(5.0, 6.0);
    x = &C;
    cout << "圆柱体的表面积是: " << x->surface_area() << endl;
    cout << "圆柱体的体积是: " << x->volume() << endl;
    return 0;
}

