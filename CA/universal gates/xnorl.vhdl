library ieee;
use ieee.std_logic_1164.all;
entity xnorl is
port
(
	a,b: in bit;
	o: out bit
);
end xnorl;

architecture behave of xnorl is
begin
o<=a xnor b;
end behave;
