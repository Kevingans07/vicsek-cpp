#include <iostream>
#include "system.h"


// this is the constructor
System::System(int particleNumber,double sideLength, double timeStep,double noiseStrength,int seed){
    
  // whatever we want to do as we instantiate the system
    
    std::cout<<"I am constructing the System!"<<std::endl;

    this->particleNumber = particleNumber;
    this->sideLength = sideLength;
    this-> timeStep = timeStep;
    this->noiseStrength = noiseStrength;

    

    this->simulationBox = Box(sideLength,sideLength,0,0);

    this->particles.resize(this->particleNumber);

    // initialise random number generator
    this->gen = std::mt19937(seed);

    
}

// 3rd Section Implementation (Week 4)
void System:: randomStart(){
    for (Particle &p : this->particles){
        p.x = this->uniform(0,this->simulationBox.getSidex());
        p.y =this->uniform(0,this->simulationBox.getSidey());
        p.theta = this->uniform(-M_PI,M_PI);
    }
}

void System::saveConfig(const std::string &filename)
{   
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return; // Exit if file cannot be opened
    }
    outFile << std::to_string(particles.size())+"\nParticles"<<std::endl;
    
    // Write particle properties to the file

    for (size_t i = 0; i < particles.size(); ++i) {
        outFile << i << " " << particles[i].x <<" "<<particles[i].y<<" "<<particles[i].theta << std::endl;
    }
    outFile.close(); // Close the file
}    



void System::updateRule(){
  // the Vicsek update rule...
std::cout<<"Updating the system..."<<std::endl; // to make a statement
}

double System::uniform(double min, double max){
    return (max-min)* this->uniformDist(gen)+min;
}


//SYTEM.CPP IS FOR THE IMPLEMENTATION OF THE CODE