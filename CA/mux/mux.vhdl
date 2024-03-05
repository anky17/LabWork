library ieee;
use ieee.std_logic_1164.all;
entity mux is
port
(
	i: in std_logic_vector(2 downto 0);
	s: in std_logic_vector(7 downto 0);
	y: out std_logic
);
end mux;

architecture behave of mux is
begin
y <=(not(i(2)) and not(i(1)) and not(i(0)) and s(0)) or
	(not(i(2)) and not(i(1)) and i(0) and s(1)) or
	(not(i(2)) and i(1) and not(i(0)) and s(2)) or
	(not(i(2)) and i(1) and i(0) and s(3)) or
	(i(2) and not(i(1)) and not(i(0)) and s(4)) or
	(i(2) and not(i(1)) and i(0) and s(5)) or
	(i(2) and i(1) and not(i(0)) and s(6)) or
	(i(2) and i(1) and i(0) and s(7));
end behave;