library ieee;
use ieee.std_logic_1164.all;
entity mux_tb is
end mux_tb;

architecture test of mux_tb is
component mux
port
(
	i: in std_logic_vector(2 downto 0);
	s: in std_logic_vector(7 downto 0);
	y: out std_logic
);
end component;	
signal s: std_logic_vector(7 downto 0) :=(others=>'0');
signal i: std_logic_vector(2 downto 0);
signal y: std_logic;
begin
mux_8x1: mux port map
(i=>i, s=>s, y=>y);
process begin
	i <= "000";
	s <= "00000001";
	wait for 1 ns;
	i <= "001";
	s <= "00000010";
	wait for 1 ns;
	i <= "010";
	s <= "00000100";
	wait for 1 ns;
	i <= "011";
	s <= "00001000";
	wait for 1 ns;
	i <= "100";
	s <= "00010000";
	wait for 1 ns;
	i <= "101";
	s <= "00100000";
	wait for 1 ns;
	i <= "110";
	s <= "01000000";
	wait for 1 ns;
	i <= "111";
	s <= "10000000";
	wait for 1 ns;
	assert false report "Reached end of test";
wait;
end process;
end test;