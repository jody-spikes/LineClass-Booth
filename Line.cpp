/*
* Author: Jody Spikes
* Assignment Title: Program 13
* Assignment Description: Line Class
* Due Date: 04/21/2024
* Date Created: 4/14/2024
* Date Last Modified: 04/21/2024
*/
#include "Line.h"

Line::Line(Point a, Point b){
    p1 = a;
    p2 = b;
}

void Line::setFirstPoint(const Point& p){
    p1 = p;
}
void Line::setSecondPoint(const Point& p){
    p2 = p;
}

Point Line::getFirstPoint() const{
    return p1;
}
Point Line::getSecondPoint() const{
    return p2;
}


bool Line::hasSlope() const{
    return p1.x != p2.x;
}

double Line::slope() const{
    return (p1.y - p2.y)/(p1.x - p2.x);
}

double Line::yIntercept() const{
    return p1.y - slope() *p1.x;
}


bool Line::isParallel(const Line& other) const {
    if(slope() == other.slope() && yIntercept() != other.yIntercept()){
        return true;
    }
    else{
        return false;
    }
}


bool Line::isCollinear(const Line& other) const {
    if(slope() == other.slope() && yIntercept() == other.yIntercept()){
        return true;
    }
    else{
        return false;
    }
}


bool Line::isPerpendicular(const Line& other) const {
    if(slope() * other.slope() == -1){
        return true;
    }
    else{
        return false;
    }
}



Point Line::intersect(const Line& other) const {
    double x_intersect, y_intersect;

    if (hasSlope() && other.hasSlope()) {
        double m1 = slope();
        double m2 = other.slope();
        double b1 = yIntercept();
        double b2 = other.yIntercept();

        x_intersect = (b2 - b1) / (m1 - m2);
        y_intersect = m1 * x_intersect + b1;
    } 
    else if (!hasSlope()) {
        x_intersect = p1.x;
        y_intersect = other.slope() * x_intersect + other.yIntercept();
    } 
    else {
        x_intersect = other.p1.x;
        y_intersect = slope() * x_intersect + yIntercept();
    }

    return Point(x_intersect, y_intersect);
}



void Line::display(ostream& out) const{
    double m, b;
    double x_constant = p1.x;
    
    if(hasSlope()){
        m = slope();
        b = yIntercept();
        
        if(m == 1){
            out << "y = x ";
        }
        else if(m == -1){
            out << "y = -x";
        }
        else{
            out << "y = " << m << "x";
        }
        if(b == 0){
            
        }
        else if(b > 0){
            out << " + " << b;
        }
        else{
            out << " - " << -b;
        }
    }else{
        out << "x = " << x_constant;
    }
    out << endl;
    
}
