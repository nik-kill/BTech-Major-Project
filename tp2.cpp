// a simple combinational logic circuit with two inputs and one output,
// and we will introduce a stuck-at-0 trojan in the circuit. We will
// use the ATPG (Automatic Test Pattern Generation) technique
// to generate test patterns that can detect the trojan.

//STUCK-AT-0


#include <iostream>
#include <bitset>
#include <vector>
#include <ctime>

using namespace std;

// Define the circuit inputs and output
bool input1, input2, output;

// Define the trojan parameters
bool trojan = false;
bool trojan_input1, trojan_input2;

// Define the stuck-at-0 trojan fault model
bool stuck_at_0 = true;

// Generate a test pattern for the circuit
void generate_test_pattern(vector<bool> &inputs, bool &expected_output)
{
    // Generate random input values
    input1 = rand() % 2;
    input2 = rand() % 2;

    // Check for trojan activation conditions and apply the trojan behavior
    if (input1 == trojan_input1 && input2 == trojan_input2)
    {
        trojan = true;
    }

    // Apply the circuit logic, with or without the trojan
    if (trojan && stuck_at_0)
    {
        output = false;
    }
    else
    {
        output = input1 && input2;
    }

    // Save the input and output values to the vector
    inputs.clear();
    inputs.push_back(input1);
    inputs.push_back(input2);
    expected_output = output;
}

// Generate test patterns using the ATPG algorithm
vector<vector<bool>> generate_atpg_test_patterns(int num_patterns)
{
    vector<vector<bool>> patterns;

    for (int i = 0; i < num_patterns; i++)
    {
        vector<bool> inputs;
        bool expected_output;

        generate_test_pattern(inputs, expected_output);

        // Add the input vector to the patterns vector
        patterns.push_back(inputs);
    }

    return patterns;
}

int main()
{
    // Set the random seed for consistent test pattern generation
    srand(time(NULL));

    // Set the trojan activation conditions
    trojan_input1 = true;
    trojan_input2 = true;

    // Generate 10 test patterns using the ATPG algorithm
    vector<vector<bool>> test_patterns = generate_atpg_test_patterns(10);

    // Print the test patterns and expected outputs
    for (int i = 0; i < test_patterns.size(); i++)
    {
        vector<bool> inputs = test_patterns[i];
        bool expected_output;

        generate_test_pattern(inputs, expected_output);

        cout << "Test Pattern " << i + 1 << ": " << inputs[0] << ", " << inputs[1] << " -> " << expected_output << endl;
    }

    return 0;
}

// we first define a simple combinational logic circuit with two inputs and one output, 
// and we introduce a stuck-at-0 trojan in the circuit. We then define a function generate_test_pattern() 
//that generates a random test pattern for the circuit, taking into account the trojan activation conditions and the stuck-at-0 fault model.
// Finally, we define a function generate_atpg_test_patterns() that uses the ATPG algorithm to generate a set of test patterns that can detect the trojan. 
//The main function generates 10 test patterns using the ATPG algorithm and prints them to the console, along with their expected outputs.
//we first define a simple combinational logic circuit with two inputs and one output, and we introduce a stuck-at-0 trojan in the circuit. 
//We then define a function generate_test_pattern() that generates a random test pattern for the circuit, taking into account the trojan activation conditions 
//and the stuck-at-0 fault model. Finally, we define a function generate_atpg_test_patterns() that uses the ATPG algorithm to generate a set of test patterns that 
//can detect the trojan. The main function generates 10 test patterns using the ATPG algorithm and prints them to the console, along with their expected outputs.