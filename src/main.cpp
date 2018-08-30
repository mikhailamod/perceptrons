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
    vector<float> inputs = {0.9, 0.9};
    
    //weights are 11, 12, 21, 22
    vector<float> weights = {0.6, 1.1, 0.6, 1.1};
    vector<float> second_weight = {-2, 1.1};

    cout << "Inputs: " << inputs[0] << ", " << inputs[1] << endl;
    
    float hidden_activation_1 = (inputs[0]*weights[0]) + (inputs[1]*weights[2]);
    float hidden_activation_2 = (inputs[0]*weights[1]) + (inputs[1] * weights[3]);
    cout << "hidden_activation_1 = " << hidden_activation_1 << endl;
    cout << "hidden_activation_2 = " << hidden_activation_2 << endl;

    float hidden_output_1;
    if(hidden_activation_1 >= theta){ hidden_output_1 = 1; }
    else { hidden_output_1 = 0; }

    cout << "hidden_output_1: " << hidden_output_1 << endl;

    float hidden_output_2;
    if(hidden_activation_2 >= theta){ hidden_output_2 = 1; }
    else { hidden_output_2 = 0; }
    cout << "hidden_output_2: " << hidden_output_2 << endl;

    float output = (second_weight[0]*hidden_output_1) + (second_weight[1] * hidden_output_2);
    if(output >= theta){ output = 1; }
    else { output = 0; }

    cout << "Output = " << output << endl;
    return 0;
}


