#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

class Point {
    int x, y;

public:
    Point(int = 0, int = 0);
    int getX() const;
    int getY() const;
    void setX(const int);
    void setY(const int);
};

class PointArray {
    Point *points;
    int len;
    void resize(int);

public:
    PointArray(); // default constructor
    PointArray(const Point [], const int size);
    PointArray(const PointArray &); //copy constructor
    ~PointArray(); //destructor
    void push_back(const Point &);
    void insert(const int, const Point &);
    void remove(const int);
    const int getSize() const;
    void clear();
    Point * get(const int);
    const Point * get(const int) const;
};

class Polygon {
protected :
    static int numPolygons ;
    PointArray points ;

public:
    Polygon(const PointArray &);
    Polygon(const Point points [], const int);
    virtual double area() const = 0;
    static int getNumPolygons(){return numPolygons;}
    int getNumSides() const{return points.getSize();}
    const PointArray * getPoints() const{return &points;}
    ~Polygon(){--numPolygons;}
};

class Rectangle : public Polygon {
public :
    Rectangle(const Point &, const Point &);
    Rectangle(const int, const int, const int, const int);
    virtual double area() const;
};

class Triangle : public Polygon {
public :
    Triangle(const Point &a, const Point &b, const Point &c);
    virtual double area() const;
};


#endif // GEOMETRY_H_INCLUDED
