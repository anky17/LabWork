library ieee;
use ieee.std_logic_1164.all;

entity parcheck_tb is
end parcheck_tb;

architecture test of parcheck_tb is
component parcheck
port
(
	S: in std_logic_vector(3 downto 0);
	ep, op: out std_logic
);
end component;
signal ep, op: std_logic;
signal S: std_logic_vector(3 downto 0);
begin
parity_checker: parcheck port map
(S=>S, ep=>ep, op=>op);
process begin
	    S <= "0000";
		wait for 1 ns;
		S <= "0001";
		wait for 1 ns;
		S <= "0010";
		wait for 1 ns;
		S <= "0011";
		wait for 1 ns;
		S <= "0100";
		wait for 1 ns;
		S <= "0101";
		wait for 1 ns;
		S <= "0110";
		wait for 1 ns;
		S <= "0111";
		wait for 1 ns;
		S <= "1000";
		wait for 1 ns;
		S <= "1001";
		wait for 1 ns;
		S <= "1010";
		wait for 1 ns;
		S <= "1011";
		wait for 1 ns;
		S <= "1100";
		wait for 1 ns;
		S <= "1101";
		wait for 1 ns;
		S <= "1110";
		wait for 1 ns;
		S <= "1111";
		wait for 1 ns;
		assert false report "Reached end of test";
		wait;	
end process;
end test;