library ieee;
use ieee.std_logic_1164.all;
entity fullsubtractorl is
port
(
	a,b,c: in bit;
	d,br: out bit
);
end fullsubtractorl;

architecture behave of fullsubtractorl is
begin
d <= (a xor b) xor c;
br <= (not a and b) or (not a and c) or ( b and c);
end behave;

	