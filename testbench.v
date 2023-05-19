module testbench();
  reg clk, reset;
  wire in, out, detected;
  hardware_trojan dut(.clk(clk), .reset(reset), .in(in), .out(out));
  initial begin
    clk = 0; reset = 1; in = 0;
    #10 reset = 0;
    #10 in = 1;
    // Test 1
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 if (out != 1) detected = 1;
    // Test 2
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 if (out != 1) detected = 1;
    // Test 3
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 if (out != 1) detected = 1;
    // Test 4
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 if (out != 0) detected = 1;
    // Test 5
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 if (out != 1) detected = 1;
    // Test 6
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 if (out != 0) detected = 1;
    // Test 7
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 if (out != 0) detected = 1;
    // Test 8
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 if (out != 1) detected = 1;
    // Test 9
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 if (out != 0) detected = 1;
    // Test 10
    #10 in = 1;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 1;
    #10 in = 1;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 in = 0;
    #10 if (out != 0) detected = 1;
    $display("Testbench finished");
    $finish;
  end
endmodule