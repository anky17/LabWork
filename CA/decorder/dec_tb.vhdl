library ieee;
use ieee.std_logic_1164.all;
entity dec_tb is
end dec_tb;
architecture test of dec_tb is
component dec
port
(
	i0,i1,i2: in std_logic;
	o0,o1,o2,o3,o4,o5,o6,o7: out std_logic
);
end component;
signal i0,i1,i2,o0,o1,o2,o3,o4,o5,o6,o7: std_logic;
begin
decorder: dec port map(i0=>i0, i1=>i1, i2=>i2, o0=>o0, o1=>o1, o2=>o2, o3=>o3, o4=>o4, o5=>o5, o6=>o6, o7=>o7); 
process begin
i0 <= '0';
i1 <= '0';
i2 <= '0';
wait for 1 ns;
i0 <= '0';
i1 <= '0';
i2 <= '1';
wait for 1 ns;
i0 <= '0';
i1 <= '1';
i2 <= '0';
wait for 1 ns;
i0 <= '0';
i1 <= '1';
i2 <= '1';
wait for 1 ns;
i0 <= '1';
i1 <= '0';i2 <= '0';
wait for 1 ns;
i0 <= '1';
i1 <= '0';
i2 <= '1';
wait for 1 ns;
i0 <= '1';
i1 <= '1';
i2 <= '0';
wait for 1 ns;
i0 <= '1';
i1 <= '1';
i2 <= '1';
wait for 1 ns;
assert false report "Reached end of test";
wait;
end process;
end test;
