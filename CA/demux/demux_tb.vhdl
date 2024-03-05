library ieee;
use ieee.std_logic_1164.all;
entity demux_tb is
end demux_tb;

architecture test of demux_tb is
component demux
port
(
	i: in std_logic_vector(2 downto 0);
	y: in std_logic;
	o: out std_logic_vector(7 downto 0)
);
end component;	
signal o: std_logic_vector(7 downto 0);
signal i: std_logic_vector(2 downto 0);
signal y: std_logic := '1';
begin
demux_1x8: demux port map(i => i, y => y, o => o);

process begin
	i <= "000";
	wait for 1 ns;
	i <= "001";
	wait for 1 ns;
	i <= "010";
	wait for 1 ns;
	i <= "011";
	wait for 1 ns;
	i <= "100";
	wait for 1 ns;
	i <= "101";
	wait for 1 ns;
	i <= "110";
	wait for 1 ns;
	i <= "111";
	wait for 1 ns;
	assert false report "Reached end of test";
wait;
end process;
end test;