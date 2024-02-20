library ieee;
use ieee.std_logic_1164.all;
entity xnorl_tb is
end xnorl_tb;
architecture test of xnorl_tb is
component xnorl
port
(
	a: in bit;
	b: in bit;
	o: out bit
);
end component;
signal a,b,o: bit;
begin
xnor_gate:xnorl port map (a=>a, b=>b, o=>o);
process begin
a <= '0';
b <= '0';
wait for 1 ns;
a <= '0';
b <= '1';
wait for 1 ns;
a <= '1';
b <= '0';
wait for 1 ns;
a <= '1';
b <= '1';
wait for 1 ns;
assert false report "Reached end of test";
wait;
end process;
end test;

