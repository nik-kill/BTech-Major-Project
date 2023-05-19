// generates test patterns and checks a circuit for hardware trojan using the built-in Vivado simulator


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random test pattern
vector<bool> generateTestPattern(int testLength)
{
    vector<bool> testPattern(testLength);
    for (int i = 0; i < testLength; ++i)
    {
        testPattern[i] = (std::rand() % 2 == 0);
    }
    return testPattern;
}

int main()
{
    // Set up simulation environment
    const char *simulationFileName = "testbench.v";
    ofstream simulationFile(simulationFileName);
    simulationFile << "module testbench();" << endl;
    simulationFile << "  reg clk, reset;" << endl;
    simulationFile << "  wire in, out, detected;" << endl;
    simulationFile << "  hardware_trojan dut(.clk(clk), .reset(reset), .in(in), .out(out));" << endl;
    simulationFile << "  initial begin" << endl;
    simulationFile << "    clk = 0; reset = 1; in = 0;" << endl;
    simulationFile << "    #10 reset = 0;" << endl;
    simulationFile << "    #10 in = 1;" << endl;

    // Generate and apply test patterns
    const int numTests = 10;
    const int testLength = 32;
    std::srand(std::time(0)); // set random seed based on current time
    for (int i = 0; i < numTests; ++i)
    {
        vector<bool> testPattern = generateTestPattern(testLength);
        simulationFile << "    // Test " << i + 1 << endl;
        simulationFile << "    #10 in = " << testPattern[0] << ";" << endl;
        for (int j = 1; j < testLength; ++j)
        {
            simulationFile << "    #10 in = " << testPattern[j] << ";" << endl;
        }
        simulationFile << "    #10 if (out != " << testPattern.back() << ") detected = 1;" << endl;
    }

    // Finish simulation environment and close file
    simulationFile << "    $display(\"Testbench finished\");" << endl;
    simulationFile << "    $finish;" << endl;
    simulationFile << "  end" << endl;
    simulationFile << "endmodule" << endl;
    simulationFile.close();

    // Run simulation
    const char *simulationCommand = "xvlog hardware_trojan.v testbench.v && xsim -gui testbench";
    system(simulationCommand);

    // Check for hardware trojan
    ifstream simResultFile("xsim.log");
    string simResult;
    while (getline(simResultFile, simResult))
    {
        if (simResult.find("detected") != string::npos)
        {
            cout << "Hardware trojan detected!" << endl;
            return 1;
        }
    }
    cout << "No hardware trojan detected." << endl;
    return 0;
}
