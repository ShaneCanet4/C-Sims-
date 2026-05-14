#include <iostream> // for terminal input output
#include <cmath>  //math
#include <fstream>  // for file saving

//simple kinematics sim to get used to syntax and c++ work flow such as compiling and running

const double g= 9.81;

const double rho = 1.225;

const double mu  = 1.81e-5; 

double speed(double a, double t){
    return  a*t;
}

//drag 
double getCd(double velocity, double radius) {
    double Re = (rho * velocity * (2 * radius)) / mu;

    if (Re < 1) return 24.0 / Re;               // Stokes Flow
    if (Re < 1000) return 24.0 / Re + 0.44;     // Intermediate
    return 0.44;                                // Fully Turbulent (Sphere)
}

double acceleration(double G, double mass, double velocity,  double radius){
    double drag = 0;

    if (velocity>0){
        drag =  -0.5*getCd(velocity,radius)*rho*(pow(velocity,2))*M_PI*pow(radius,2)/mass;
    } else if (velocity<0)
    {
        drag =  0.5*getCd(velocity,radius)*rho*(pow(velocity,2))*M_PI*pow(radius,2)/mass;
    } else {
        drag = 0;
    }
    
    return -G + drag;
}

int main (){
    // intial cond
    double angel_deg = 45; 
    double angle_rad = angel_deg * (M_PI/180);
    double velocity = 30;
    double height = 10 ; 
    double mass = 2 ;
    double radius = 0.5;

    double X= 0;
    double Y= height;
    double T= 0;
    double U = velocity*cos(angle_rad);
    double V = velocity*sin(angle_rad);

    // time steps and limit of sim
    double dt=0.1;

    double T_limit = 10;

    //creating file for csv and data post

    std::ofstream data("sim0_trajectory.csv");

    data << "Time(s),X(m),Y(m)\n"; // headers

    while(T<T_limit){

        data << T << "," << X << "," << Y << "\n"; //writing data 

        X+= U*dt;
        Y+=V*dt;

        U+=speed(acceleration(0,mass,U,radius),dt);
        V+=speed(acceleration(g,mass,V,radius),dt);

        if (Y<=0){
            V=-0.9*V; //coeficient of restituion or how elastic or bouncy it is -> its pretty bouncy would exp measure this
            Y=0; 
        }

        T+=dt;
    }

    data.close(); //close file same thing for python 

    return 0;  

}

