//AMDMIK002
//Mikhail Amod

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

float training_rate = 0.01f;
float bias = 1.0f;

float test(vector<float> & weights, float input1, float input2)
{
    int sum = (input1*weights[0]) + (input2 * weights[1]) + weights[2];
    if(sum>=1.0f){ sum = 1; }
    else{ sum = 0; }

    return sum;
}

void train(vector<float> & weights, float input1, float input2, float output)
{
    int sum = (input1*weights[0]) + (input2 * weights[1]) + weights[2];
    if(sum>=1.0f){ sum = 1; }
    else{ sum = 0; }

    //percerptron rule
    weights[0] = weights[0] + (training_rate*(output-sum)*input1);
    weights[1] = weights[1] + (training_rate*(output-sum)*input2);
    weights[2] = weights[2] + (training_rate*(output-sum));
}

void loadData(string & filename, vector<vector<float>> & vec)
{
    ifstream file(filename);
    if(!file){
        cout << "No file" << endl;
        return;
    }
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        vector<float> tokens;
        for (string s; iss >> s;)
        {
            tokens.push_back(stof(s));
        }
        vec.push_back(tokens);
    }
}

int main(int argc, char const *argv[])
{
    cout << "Perceptron" << endl;
    float theta = 1.0f;
    vector<vector<float>> inputs;
    string or_file = "or.txt";
    string and_file = "and.txt";
    string nand_file = "nand.txt";
    string xor_file = "xor.txt";

    loadData(or_file, inputs);
    //weights are 11, 12, 21, 22
    vector<float> or_weights = {1, 1, 1};
    vector<float> nand_weights = {1, 1, 1};
    vector<float> and_weights = {1, 1, 1};
    
    cout << "training or gate" << endl;
    int iterations = 100;
    for(int i = 0; i < iterations; ++i)
    {
        for(int j = 0; j < inputs.size(); ++j)
        {
            train(or_weights, inputs[j][0], inputs[j][1], inputs[j][2]);
        }
    }

    cout << "training nand gate" << endl;
    inputs.clear();
    loadData(nand_file, inputs);
    for(int i = 0; i < iterations; ++i)
    {
        for(int j = 0; j < inputs.size(); ++j)
        {
            train(nand_weights, inputs[j][0], inputs[j][1], inputs[j][2]);
        }
    }

    cout << "training and gate" << endl;
    inputs.clear();
    loadData(and_file, inputs);
    for(int i = 0; i < iterations; ++i)
    {
        for(int j = 0; j < inputs.size(); ++j)
        {
            train(and_weights, inputs[j][0], inputs[j][1], inputs[j][2]);
        }
    }
    
    cout << "or gate has weights: " << or_weights[0] << ", " << or_weights[1] << ", "<< or_weights[2] << endl;
    cout << "nand gate has weights: " << nand_weights[0] << ", " << nand_weights[1] << ", "<< nand_weights[2] << endl;
    cout << "and gate has weights: " << and_weights[0] << ", " << and_weights[1] << ", "<< and_weights[2] << endl;

    vector<vector<float>> test_input;
    loadData(xor_file, test_input);

    cout << "Testing xor" << endl;
    for(int i = 0; i<test_input.size(); ++i)
    {
        cout << "input (" << test_input[i][0] << ", " << test_input[i][1] << "), expecting: " << test_input[i][2] << endl;;
        float or_result = test(or_weights, test_input[i][0], test_input[i][1]);
        float nand_result = test(nand_weights, test_input[i][0], test_input[i][1]);
        float result = test(and_weights, or_result, nand_result);
        
        cout << "Result: " << result;
        if(result == test_input[i][2])
        {
            cout << " - CORRECT" << endl; 
        }
        else{
            cout << " - INCORRECT" << endl;
        }
    }
    return 0;
}


