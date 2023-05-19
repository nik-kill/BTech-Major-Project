//D-ALgorithm for single stuck at fault simulation

#include <iostream>
#include <vector>

using namespace std;

// Gate structure to represent a gate in the circuit
struct Gate
{
    bool value;               // Current value of the gate
    vector<Gate *> inputs;    // Pointers to input gates
    vector<bool> inputValues; // Values of input gates for fault simulation
};

// Function to propagate values through the circuit
void propagateValues(Gate *gate)
{
    for (Gate *input : gate->inputs)
    {
        if (input->value)
        {
            gate->value = true;
            return;
        }
    }
    gate->value = false;
}

// Function to perform fault simulation on the circuit
void performFaultSimulation(Gate *circuit, vector<bool> &inputValues)
{
    for (size_t i = 0; i < inputValues.size(); ++i)
    {
        circuit->inputs[i]->value = inputValues[i];
    }

    for (Gate *gate = circuit; gate != nullptr; gate = gate->inputs[0])
    {
        propagateValues(gate);
    }
}

// D-algorithm function to generate test pattern for a single stuck-at fault
void generateTestPattern(Gate *circuit, Gate *faultGate, vector<bool> &inputValues)
{
    for (size_t i = 0; i < inputValues.size(); ++i)
    {
        circuit->inputs[i]->value = inputValues[i];
    }

    propagateValues(circuit);

    vector<bool> testPattern;
    testPattern.reserve(inputValues.size());
    for (Gate *input : faultGate->inputs)
    {
        testPattern.push_back(input->value);
    }

    cout << "Generated test pattern: ";
    for (bool value : testPattern)
    {
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    // Create the circuit
    Gate *circuit = new Gate();
    Gate *gate1 = new Gate();
    Gate *gate2 = new Gate();
    Gate *gate3 = new Gate();

    circuit->inputs = {gate1};
    gate1->inputs = {gate2};
    gate2->inputs = {gate3};

    // Set up the fault
    Gate *faultGate = gate2;

    // Generate test patterns for fault simulation
    vector<bool> inputValues1 = {0};
    vector<bool> inputValues2 = {1};

    // Perform fault simulation and generate test patterns
    performFaultSimulation(circuit, inputValues1);
    generateTestPattern(circuit, faultGate, inputValues1);

    performFaultSimulation(circuit, inputValues2);
    generateTestPattern(circuit, faultGate, inputValues2);

    // Cleanup - deallocate memory
    delete circuit;
    delete gate1;
    delete gate2;
    delete gate3;

    return 0;
}
