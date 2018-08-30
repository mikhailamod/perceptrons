//AMDMIK002
//Mikhail Amod

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Perceptron" << endl;
    float theta = 1.0f;
    vector<float> inputs = {0, 1};
    
    //weights are 11, 12, 21, 22
    vector<float> weights = {0.6, 1.1, 0.6, 1.1};
    vector<float> second_weight = {-2, 1.1};

    cout << "Inputs: " << inputs[0] << ", " << inputs[1] << endl;
    
    float hidden1 = (inputs[0]*weights[0]) + (inputs[1]*weights[2]);
    float hidden2 = (inputs[0]*weights[1]) + (inputs[1] * weights[3]);
    cout << "hidden1 = " << hidden1 << endl;
    cout << "hidden2 = " << hidden2 << endl;

    float y1;
    if(hidden1 >= theta){ y1 = 1; }
    else { y1 = 0; }

    cout << "y1: " << y1 << endl;

    float y2;
    if(hidden2 >= theta){ y2 = 1; }
    else { y2 = 0; }
    cout << "y2: " << y2 << endl;

    float yin = (second_weight[0]*y1) + (second_weight[1] * y2);
    cout << "yin temp = " << yin << endl;
    if(yin >= theta){ yin = 1; }
    else { yin = 0; }

    cout << "Output = " << yin << endl;
    return 0;
}


