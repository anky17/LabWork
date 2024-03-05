library ieee;
use ieee.std_logic_1164.all;
entity demux is
port
(
	i: in std_logic_vector(2 downto 0);
	y: in std_logic;
	o: out std_logic_vector(7 downto 0)
);
end demux;

architecture behave of demux is
begin
o(0) <= (not(i(2))) and (not(i(1))) and (not(i(0))) and y;
o(1) <= (not(i(2))) and (not(i(1))) and i(0) and y;
o(2) <= (not(i(2))) and i(1) and (not(i(0))) and y;
o(3) <= (not(i(2))) and i(1) and i(0) and y;
o(4) <= i(2) and (not(i(1))) and (not(i(0))) and y;
o(5) <= i(2) and (not(i(1))) and i(0) and y;
o(6) <= i(2) and i(1) and (not(i(0))) and y;
o(7) <= i(2) and i(1) and i(0) and y;
end behave;