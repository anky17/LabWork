library ieee;
use ieee.std_logic_1164.all;
entity fullsubtractorl_tb is
end fullsubtractorl_tb;
architecture test of fullsubtractorl_tb is
component fullsubtractorl
port
(
	a,b,c: in bit;
	d,br: out bit
);
end component;
signal a,b,c,d,br: bit;
begin
full_subtractor:fullsubtractorl port map(a =>a, b=>b, c=>c, d=>d, br=>br);
process begin
a <= '0';
b <= '0';
c <= '0';
wait for 1 ns;
a <= '0';
b <= '0';
c <= '1';
wait for 1 ns;
a <= '0';
b <= '1';
c <= '0';
wait for 1 ns;
a <= '0';
b <= '1';
c <= '1';
wait for 1 ns;
a <= '1';
b <= '0';
c <= '0';
wait for 1 ns;
a <= '1';
b <= '0';
c <= '1';
wait for 1 ns;
a <= '1';
b <= '1';
c <= '0';
wait for 1 ns;
a <= '1';
b <= '1';
c <= '1';
wait for 1 ns;
assert false report "Reached end of test";
wait;
end process;
end test;
