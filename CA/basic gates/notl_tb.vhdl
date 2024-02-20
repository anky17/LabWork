library ieee;
use ieee.std_logic_1164.all;
entity notl_tb is
end notl_tb;
architecture test of notl_tb is
component notl
port
(
a: in bit;
o: out bit
);
end component;
signal a,o: bit;
begin
not_gate:notl port map (a=>a, o=>o);
process begin
a <= '0';
wait for 1 ns;
a <= '1';
wait for 1 ns;
assert false report "Reached end of test";
wait;
end process;
end test;