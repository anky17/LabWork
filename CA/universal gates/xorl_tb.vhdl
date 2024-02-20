library ieee;
use ieee.std_logic_1164.all;
entity xorl_tb is
end xorl_tb;
architecture test of xorl_tb is
component xorl
port
(
	a: in bit;
	b: in bit;
	o: out bit
);
end component;
signal a,b,o: bit;
begin
xor_gate:xorl port map (a=>a, b=>b, o=>o);
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

