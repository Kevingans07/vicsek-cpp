#include "box.h"

Box::Box(){
    // an empty constructor
}

Box::Box(double lx, double ly, double x0, double y0){
     //this constructor actually assigns values

    // using setters and getters 
    this->setSides (lx,ly);
    this->setOrigin (x0,y0);
}

void Box::setSides(double lx, double ly){
    this->sidex = lx; 
    // this is used for modifying a variable to store it permanently
    this->sidey = ly;
}

double Box::getSidex(){
    return this->sidex;
}

double Box::getSidey(){
    return this->sidey;
}

void Box::setOrigin(double x0, double y0){
    this->x0 = x0;
    this->y0 = y0;
}


// cpp file is for definition