#include <cstddef>
#include <cmath>
#include "geometry.h"

/* Point */
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

int Point::getX() const{
    return this->x;
}

int Point::getY() const{
    return this->y;
}

void Point::setX(const int new_x){
    this->x = new_x;
}

void Point::setY(const int new_y){
    this->y = new_y;
}

/* PointArray */
PointArray::PointArray(){
    this->len = 0;
    this->points = new Point[this->len];
}

PointArray::PointArray(const Point points[], const int size){
    this->len = size;
    this->points = new Point[this->len];
    for(int i = 0; i < this->len; i++){
        this->points[i] = points[i];
    }
}
// Copy constructor
PointArray::PointArray(const PointArray& pv){
    this->len = pv.len;
    this->points = new Point(this->len);
    for(int i = 0; i < this->len; i++){
        this->points[i] = pv.points[i];
    }
}

// Destructor
PointArray::~PointArray(){
    delete[] this->points;
}

void PointArray::resize(int newSize){
    Point *pts = new Point[newSize];
    int minSize =  newSize > this->len ? this->len : newSize;
    for (int i = 0; i < minSize ; i++){
        pts[i] = points [i];
    }

    delete[] this->points; // de-allocate array
    this->len = newSize;
    this->points = pts;
}

void PointArray::push_back(const Point &p){
    resize(this->len + 1);
    points[this->len - 1] = p;
}

void PointArray::insert(const int position, const Point &p){
    resize(this->len + 1);
    for(int i = this->len - 1; i > position; i --) {
        points [i] = points[i -1];
    }
    points [position] = p;
}

void PointArray::remove(const int pos){
    if(pos >= 0 && pos < this->len){
        // Shift everything over to the left
        for(int i = pos; i < this->len - 2; i++) {
            points [i] = points [i + 1];
        }
        resize(this->len - 1);
    }
}

const int PointArray::getSize() const{
    return this->len;
}

void PointArray::clear(){
    resize(0);
}

Point *PointArray::get(const int position){
    return position >= 0 && position < this->len ? points + position : NULL;
}

const Point *PointArray::get(const int position) const{
    return position >= 0 && position < this->len ? points + position : NULL ;
}

/* Polygon */
int Polygon::numPolygons = 0;

Polygon::Polygon(const PointArray &pa) : points(pa){
    ++numPolygons;
}

Polygon::Polygon(const Point pointArr [], const int numPoints) : points(pointArr, numPoints){
    ++ numPolygons;
}

/* Rectangle */
Point constructorPoints [4];

Point* updateConstructorPoints(const Point &p1 , const Point &p2,
                                const Point &p3 , const Point &p4 = Point (0 ,0)){
    constructorPoints [0] = p1;
    constructorPoints [1] = p2;
    constructorPoints [2] = p3;
    constructorPoints [3] = p4;
    return constructorPoints;
}

Rectangle::Rectangle(const Point &ll, const Point &ur):
     Polygon(updateConstructorPoints(ll ,Point(ll.getX(), ur.getY()), ur, Point(ur.getX() ,ll.getY ())), 4) {}

Rectangle::Rectangle(const int llx, const int lly, const int urx, const int ury):
    Polygon(updateConstructorPoints(Point(llx, lly), Point(llx ,ury), Point(urx , ury), Point(urx, lly)), 4) {}

double Rectangle::area() const{
    int length = points.get(1)->getY() - points.get(0)->getY();
    int width = points.get(2)->getX() - points.get(1)->getX();
    return abs((double)length * width);
}

/* Triangle */
Triangle::Triangle(const Point &a, const Point &b, const Point &c):
    Polygon(updateConstructorPoints (a, b, c), 3) {}

double Triangle::area() const{
    int dx01 = points.get(0)->getX() - points.get(1)->getX(),
    dx12 = points.get(1)->getX() - points.get (2)->getX(),
    dx20 = points.get (2)->getX() - points.get (0)->getX();
    int dy01 = points.get(0)->getY() - points.get(1)->getY(),
    dy12 = points.get(1)->getY() - points.get(2)->getY(),
    dy20 = points.get(2)->getY() - points.get(0)->getY();

    double a = sqrt(dx01 * dx01 + dy01 * dy01),
    b = sqrt(dx12 * dx12 + dy12 * dy12),
    c = sqrt(dx20 * dx20 + dy20 * dy20);

    double s = (a + b + c) / 2;

    return sqrt(s * (s-a) * (s-b) * (s-c));
}



