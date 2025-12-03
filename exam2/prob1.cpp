// runtime polymorphism
#include <iostream>
#include <vector>

using namespace std;

class shape{
    public: 
    
    shape(){}
    //will be overridden in derived classes
    virtual double findArea()=0;
    
};


class rectangle: public shape{
    public:
    double base;
    double side;
    
    rectangle(double b, double s){
        base=b;
        side=s;
    }
    
    double findArea() override{
        return base*side;
    }
};

class circle: public shape{
    public:
    double radius;
    
    circle(double rad){
        radius=rad;
    }
    
    double findArea(){
        return radius*radius*3.14159;
    }
};

class triangle: public shape{
    public:
    double base;
    double height;
    
    triangle(double b, double h){
        base=b;
        height=h;
    }
    
    double findArea(){
        return base*height*0.5;
    }
};

int main(){
    
    //rectangle myRect(3,4);
    //circle myCirc(5);
    
    //hint
    //shape* myPtr=&myRect;
    
    //cout<<"rect area is: "<<myPtr->findArea();



    // create a vector of 9 shape pointers, 3 for each derived class
    vector<shape*> shapes;
    shapes.push_back(new rectangle(3,4));
    shapes.push_back(new rectangle(5,6));
    shapes.push_back(new rectangle(7,8));
    shapes.push_back(new circle(3));
    shapes.push_back(new circle(4));
    shapes.push_back(new circle(5));
    shapes.push_back(new triangle(3,4));
    shapes.push_back(new triangle(5,6));
    shapes.push_back(new triangle(7,8));

    // loop through the vector and print the area of each shape
    for(shape* s : shapes){
        cout<<"Area: "<<s->findArea()<<endl;
    }
    return 0;
}