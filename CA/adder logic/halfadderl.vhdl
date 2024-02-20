library ieee;
use ieee.std_logic_1164.all;
entity halfadderl is
port
(
	a,b: in bit;
	s,c: out bit
);
end halfadderl;

architecture behave of halfadderl is
begin
s <= a xor b;
c <= a and b;
end behave;