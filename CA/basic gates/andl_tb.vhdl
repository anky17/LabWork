library ieee;
use ieee.std_logic_1164.all;
entity andl_tb is
end andl_tb;
architecture test of andl_tb is
component andl
port
(
a: in bit;
b: in bit;
o: out bit
);
end component;
signal a,b,o: bit;
begin
and_gate:andl port map (a=>a, b=>b, o=>o);
process begin
a <= '0';
b <= '0' ;
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