library ieee;
use ieee.std_logic_1164.all;
entity xorl is
port
(
	a,b: in bit;
	o: out bit
);
end xorl;

architecture behave of xorl is
begin
o<=a xor b;
end behave;
