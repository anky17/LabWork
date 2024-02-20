library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity pa_tb is 
end pa_tb;
architecture test of pa_tb is
component pa
Port( A : in STD_LOGIC_VECTOR (3 downto 0);
	  B : in STD_LOGIC_VECTOR (3 downto 0);
	  S : out STD_LOGIC_VECTOR (3 downto 0);
	  Cin : in STD_LOGIC;
	  Cout : out STD_LOGIC
	);
end component;

-- input signal

signal A,B:STD_LOGIC_VECTOR(3 downto 0):= (others => '0');
signal Cin:STD_LOGIC;

-- output signal

signal S:STD_LOGIC_VECTOR (3 downto 0):= (others => '0');
signal Cout:STD_LOGIC;
begin

-- Instantiate the Unit Under Test (UUT)

UUT : pa port map(
A=>A,B=>B,S=>S,Cin=>Cin,Cout=>Cout);
process
  begin
  A <="0101";
  B <="0100";
  Cin <='0';
  wait for 20 ns;
  A <="1101";
  B <="0011";
  Cin <='1';
  wait for 20 ns;
  wait;
 end process;
 end test;

  

