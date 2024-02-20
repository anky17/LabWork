library ieee;
use ieee.std_logic_1164.all;
entity fulladderl is
port
(
	a,b,c: in bit;
	s,cr: out bit
);
end fulladderl;

architecture behave of fulladderl is
begin
s <= (a xor b) xor c;
cr <= (a and b) or ( a and c) or (b and c);
end behave;

	