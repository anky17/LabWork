library ieee;
use ieee.std_logic_1164.all;
entity norl is
port
(
	a,b: in bit;
	o: out bit
);
end norl;

architecture behave of norl is
begin
o<=a nor b;
end behave;
