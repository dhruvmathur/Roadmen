#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[]){
    if(argc >= 4){
        if(argc > 4){
            cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
        }
        else
        {
            collisionCheck(atof(argv[1]), atof(argv[2]), atof(argv[3]));
        }
       
    }
    else {
        cerr << "Error: insufficient arguments; expecting 3, recieved " << (argc-1) << endl;
    }
    
}
void collisionCheck(float velocity, float distance, float maxDeceleration)
{
     if ((distance<0 && velocity>0) || (distance>0 && velocity<0))
        {
            cout << "There is no possibility of collision because the car is traveling away from the obstacle" << endl;
        }
        else if(velocity==0 && distance!=0)
        {
            cout << "There is no possibility of collision because the car is not moving" << endl;
        }
        else
        {
            float minDeceleration= (pow(velocity, 2)/(2*abs(distance)));
            float stoppingTime= abs(velocity)/abs(minDeceleration);
            if (abs(minDeceleration) <= abs(maxDeceleration))
            {
                cout << "Initial car velocity: " << velocity << "m/s" << endl;  
                cout << "Distance to obstacle: " << distance << "m/s" << endl;
                cout << "Minimum deceleration: " << minDeceleration << "m/s/s" << endl;           
                cout << "Maximum stopping time: " << stoppingTime << "s" << endl;
            }
            else
            {   
                distance= abs(distance);
                velocity= abs(velocity);

                float velocityFinal= sqrt((pow(velocity,2)-(2*abs(maxDeceleration)*distance)));
                stoppingTime= ((velocity-abs(velocityFinal))/abs(maxDeceleration));
                cout << "Crash will occur in " << stoppingTime << " seconds at velocity " << velocityFinal << "m/s; deploying airbags." << endl;
            }
        }    
}
