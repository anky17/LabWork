library ieee;
use ieee.std_logic_1164.all;
entity halfsubtractorl is
port
(
	a,b: in bit;
	d,br: out bit
);
end halfsubtractorl;

architecture behave of halfsubtractorl is
begin
d <= (not a and b) or (a and not b);
br <= (not a and b);
end behave;
