#include <iostream>

using namespace std;

int main(){

double inputs[4] = {2, 3, 4, 0.5};

double weights1[4] = {1, 0.5, 2, 1};
double weights2[4] = {2, -0.3, 4, 0.2};
double weights3[4] = {0.2, 2, 0, 2.5};

double bias1 = 1;
double bias2 = 2;
double bias3 = 0.5;

double output[3] = {inputs[0] * weights1[0] + inputs[1] * weights1[1] + inputs[2] * weights1[2] + inputs[3] * weights1[3] + bias1,
		 inputs[0] * weights2[0] + inputs[1] * weights2[1] + inputs[2] * weights2[2] + inputs[3] * weights2[3] + bias2,
		 inputs[0] * weights3[0] + inputs[1] * weights3[1] + inputs[2] * weights3[2] + inputs[3] * weights3[3] + bias3};

cout << "[" << output[0] << ", " << output[1] << ", " << output[2] << "]" << endl;

return 0;
}
