library ieee;
use ieee.std_logic_1164.all;

entity parcheck_tb is
end parcheck_tb;

architecture test of parcheck_tb is
component parcheck
port
(
	S: in std_logic_vector(2 downto 0);
	ep, op: out std_logic
);
end component;
signal ep, op: std_logic;
signal S: std_logic_vector(2 downto 0);
begin
parity_checker: parcheck port map
(S=>S, ep=>ep, op=>op);
process begin
	S <= "000";
	wait for 1 ns;
	S <= "001";
	wait for 1 ns;
	S <= "010";
	wait for 1 ns;
	S <= "011";
	wait for 1 ns;
	S <= "100";
	wait for 1 ns;
	S <= "101";
	wait for 1 ns;
	S <= "110";
	wait for 1 ns;
	S <= "111";
	wait for 1 ns;
	assert false report "Reached end of test";
wait;	
end process;
end test;