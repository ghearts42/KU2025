#ifndef SHAPE_H
#define SHAPE_H

class Shape{
    protected:
    int x_;
    int y_;

    public:
    Shape();
    Shape(int x, int y);
    virtual ~Shape() { };

    void move(int x, int y);
    virtual double area() const = 0;
};

#endif