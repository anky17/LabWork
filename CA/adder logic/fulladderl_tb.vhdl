library ieee;
use ieee.std_logic_1164.all;
entity fulladderl_tb is
end fulladderl_tb;
architecture test of fulladderl_tb is
component fulladderl
port
(
	a,b,c: in bit;
	s,cr: out bit
);
end component;
signal a,b,c,s,cr: bit;
begin
full_adder:fulladderl port map(a =>a, b=>b, c=>c, s=>s, cr=>cr);
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
