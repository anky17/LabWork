library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ps_tb is 
end ps_tb;

architecture test of ps_tb is
    component ps
        Port(
            A : in STD_LOGIC_VECTOR (3 downto 0);
            B : in STD_LOGIC_VECTOR (3 downto 0);
            S : out STD_LOGIC_VECTOR (3 downto 0);
            Cin : in STD_LOGIC;
            Cout : out STD_LOGIC
        );
    end component;

    -- input signal
    signal A, B: STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
    signal Cin: STD_LOGIC:='1';

    -- output signal
    signal S: STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
    signal Cout: STD_LOGIC;
    begin
    -- Instantiate the Unit Under Test (UUT)
    UUT: ps port map(
        A => A, B => B, S => S, Cin => Cin, Cout => Cout);

    process begin
        -- Test Case 1: A - B where A > B
        A <= "0101";  -- 5 in decimal
        B <= "0011";  -- 3 in decimal
        wait for 20 ns;

        -- Test Case 2: A - B
        A <= "1101"; 
        B <= "0011";  
        wait for 20 ns;
		
		  -- Test Case 3: A - B
        A <= "1100"; 
        B <= "1001";  
        wait for 20 ns;
        
		-- Test Case 4: A - B
        A <= "1010"; 
        B <= "1001";  
        wait for 20 ns;
		assert false report "Reached end of test";
        wait;  -- Terminate simulation
    end process;
end test;
