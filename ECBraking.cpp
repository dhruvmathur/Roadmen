#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[]){
    if(argc >= 4){
        if(argc > 4){
            cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
        }
        
        float v = atof(argv[1]);
        float d = atof(argv[2]);
        float maxDecel = abs(atof(argv[3]));
        float a = abs(pow(v,2)/(2*d));
        
        if(d==0 && v!=0){
            cout << "Crash will occur in 0 seconds at velocity " << abs(v) << "m/s; deploying airbags." << endl;
        }
        else if((d<0 && v>0) || (d>0 && v<0)){
            cout << "There is no possibility of collision because the object is always behind the car" << endl;
        }
        else if(maxDecel==0){
            float time = d/v;
            cout << "Crash will occur in " << time << " seconds at velocity " << v << "m/s; deploying airbags." << endl;
        }
        else if(v==0 && d !=0){
            cout << "There is no possibility of collision because the car is not moving!" << endl;
        }
        else{
            v = abs(v);
            d = abs(d);
            
            float t = v/a;

            if(a > maxDecel){
                float vf;
                vf = pow(pow(v,2) - 2*maxDecel*d,0.5);
                t = (vf - v)/(-1*maxDecel);
                
                cout << "Crash will occur in " << t << " seconds at velocity " << vf << " m/s; deploying airbags." << endl;
            }
            else{
                cout << "Initial car velocity: " << v << "m/s" << endl;
                cout << "Distance to obstacle: " << d << "m" << endl;
                cout << "Minimum deceleration: " << a << " m/s/s" << endl;
                cout << "Maximum stopping time: " << t << " s" << endl;
            }
        }

    }
    else {
        cerr << "Error: insufficient arguments; expecting 3, recieved " << (argc-1) << endl;
    }
    
}
