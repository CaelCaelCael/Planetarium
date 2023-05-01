#include <iostream>
#include "RockPlanet.h"
#include "GasPlanet.h"
#include "Comparison.h"
#include "Space.h"
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    Space space;
    Planet p1(4.503, "Mercury", "3.285x10^23"); // Overloaded Constructor
    Planet p2(4.503, "Venus" , "4.867x10^24"); // Planet elements for comparison and solarsystems
    Planet p3(4.543, "Earth", "5.972x10^24");
    Planet p4(4.603, "Mars" , "6.39x10^23");
    Planet p5(4.603, "Jupiter", "1.898x10^27");
    Planet p6(4.503, "Saturn", "5.683x10^26");
    Planet p7(4.503, "Uranus", "8.681x10^25");
    Planet p8(4.503, "Neptune", "1.024x10^26");
    Planet p9(0.000,"Keplar 90B","13.55x10^24");
    Planet p10(0.000,"Keplar 90C","7.10x10^24"); // Default Planet.
    Planet p11(0.000,"Keplar 90I","1.373x10^25");
    Planet p12(0.000,"Keplar 90D","5.135x10^25");
    Planet p13(0.000,"Keplar 90E","4.514x10^25");
    Planet p14(0.000,"Keplar 90F","5.166x10^25");
    Planet p15(0.000,"Keplar 90G","1.518x10^27");
    Planet p16(0.000,"Keplar 90H","2.277x10^27");



    RockPlanet rp1; // Individual set functions for aquarium

    rp1.SetPlanet(&p2);
    rp1.SetKilos(1000);
    rp1.SetNofRockPlanets("Four");
    rp1.SetStars("1");
    rp1.SetSsName("Solar System");
    rp1.SetTemperature(35);
    rp1.display(); // uses solarsystems's display function

    RockPlanet rp2(2000, "Six", 60, "Keplar 90", "1"); // Overloaded Constructor
    rp2.SetPlanet(&p11); // 1:1 Aggregation
    rp2.display();
    cout << "Solar System Name:: " << rp2.GetSsnName() << endl;

    RockPlanet aq3; // Default constructor with constructor initialiser list

    space.addSolarSystem(&rp1); // Adding the 3 aquarium's addresses to the solarsystems vector
    space.addSolarSystem(&rp2); // 1:0*... Aggregation
    //space.addSolarSystem(&aq3);

    GasPlanet gp1; // GasPlanet object using set functions and default constructor
    gp1.SetPlanet(&p1);
    gp1.SetNofGasPlanets(5);
    gp1.SetGPName("Neptune"); // Multiple plants allowed: expands a
    //gp1.SetGPName("Uranus"); // vector of plants in this object
    gp1.SetStars("1"); // Inheritance property
    gp1.SetTemperature(40);
    gp1.SetSsName("Solar System");



    gp1.display(); // Overriding SolarSystem::display();

    GasPlanet gp2(5,"1",35,"SolarSystem"); // Overloaded Constructor
    gp2.SetGPName("Jupiter");
    //gp2.SetGPName("Saturn");
    gp2.SetPlanet(&p3);

    GasPlanet gp3; // Default Constructor
    gp3.SetPlanet(&p10);

    space.addSolarSystem(&gp1); // Adding jungles to the solarsystems vector
    space.addSolarSystem(&gp2);
    space.addSolarSystem(&gp3);

    space.display(); // Displays all solarsystems. Example of polymorphism.
    Comparison c1;


      // Create and open a text file
    ofstream MyFile("filename.txt");

  // Write to the file
    MyFile <<     gp1.getPlanet();
                gp1.GetNofGasPlanets();
                gp1.GetGPName(); // Multiple plants allowed: expands a

                gp1.GetStars(); // Inheritance property
                gp1.GetTemperature();
                gp1.GetSsnName();

  // Close the file
    MyFile.close();

return 0;
}

