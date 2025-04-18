#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape{
private:
    int radius_;

public:
    Circle(int x, int y, int r);
    virtual ~Circle() {}

    double area() const;
    double getCircumstance() const;
};

#endif