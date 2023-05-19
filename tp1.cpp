// C++ code to generate random test patterns for a simple design



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define input and output signals for the design
int input1, input2, output;

// Define the trojan activation conditions and behavior
bool trojan_active = false;
int trojan_input1, trojan_input2;

// Generate a random test pattern for the design
void generate_test_pattern()
{
    // Set the input signals randomly
    input1 = rand() % 2;
    input2 = rand() % 2;

    // Check for trojan activation conditions and apply the trojan behavior
    if (input1 == trojan_input1 && input2 == trojan_input2)
    {
        trojan_active = true;
    }

    if (trojan_active)
    {
        // Apply the trojan behavior to the output signal
        output = !input1;
    }
    else
    {
        // Apply the normal behavior to the output signal
        output = input2;
    }
}

int main()
{
    // Set the random seed for consistent test pattern generation
    srand(time(NULL));

    // Generate 100 random test patterns for the design
    for (int i = 0; i < 100; i++)
    {
        generate_test_pattern();
        cout << "Input1: " << input1 << ", Input2: " << input2 << ", Output: " << output << endl;
    }

    return 0;
}
