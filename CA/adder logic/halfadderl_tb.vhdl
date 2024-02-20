library ieee;
use ieee.std_logic_1164.all;
entity halfadderl_tb is
end halfadderl_tb;
architecture test of halfadderl_tb is
component halfadderl
port
(
	a: in bit;
	b: in bit;
	s,c: out bit
);
end component;
signal a,b,s,c: bit;
begin
half_adder:halfadderl port map(a=>a, b=>b, s=>s, c=>c);
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
