library ieee;
use ieee.std_logic_1164.all;
entity halfsubtractorl_tb is
end halfsubtractorl_tb;
architecture test of halfsubtractorl_tb is
component halfsubtractorl
port
(
	a,b: in bit;
	d,br: out bit
);
end component;
signal a,b,d,br: bit;
begin
half_subtractor:halfsubtractorl port map(a=>a, b=>b, d=>d, br=>br);
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