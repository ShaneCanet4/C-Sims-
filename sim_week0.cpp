#include <iostream> // for terminal input output
#include <cmath>  //math
#include <fstream>  // for file saving

//simple kinematics sim to get used to syntax and c++ work flow such as compiling and running

const double g= 9.81;

double speed(double a, double t){
    return  a*t;
}

int main (){
    // intial cond
    double angel_deg = 45; 
    double angle_rad = angel_deg * (M_PI/180);
    double velocity = 30;
    double height = 10 ; 

    double X= 0;
    double Y= height;
    double T= 0;
    double U = velocity*cos(angle_rad);
    double V = velocity*sin(angle_rad);

    // time steps
    double dt=0.1;

    //creating file for csv and data post

    std::ofstream data("sim0_trajectory.csv");

    data << "Time(s),X(m),Y(m)\n"; // headers

    while(Y>=0){

        data << T << "," << X << "," << Y << "\n"; //writing data 

        X+= U*dt;
        Y+=V*dt;

        V+=speed(-g,dt);

        T+=dt;
    }

    data.close(); //close file same thing for python 

    return 0;  

}

