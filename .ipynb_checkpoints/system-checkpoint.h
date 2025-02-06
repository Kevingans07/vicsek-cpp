#ifndef SYSTEM_H
#define SYSTEM_H 
// if SYSTEM_H is not defined, this will be defined with #define

#include <vector> //to use standard C++ vectors
#include <random> // to generate random number
#include "box.h" //yet to be created! now created in week 3
#include "particle.h" //yet to be created! now created in week 3

#include <fstream>

class System {
  public:
    System(int particleNumber, double noiseStrength, double sideLength, double timeStep, int seed); 
//constructor is used to construct the object when you declare it
    int   particleNumber;
    double noiseStrength;
    double sideLength;
    double timeStep;


    Box simulationBox;
    std::vector<Particle> particles;

    //generate random number
    std::mt19937 gen;  

    //for uniform distribution
    std::uniform_real_distribution<double> uniformDist;

    // function to sample uniformly distributed random numbers
    double uniform(double min, double max);


    void randomStart();
    void updateRule();

    void saveConfig(const std::string &filename);

    

};

#endif

//HEADER FILE IS FOR THE PROPERTY TO TELL THE ATTRIBUTE OF CPP FILE
