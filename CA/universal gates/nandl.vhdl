library ieee;
use ieee.std_logic_1164.all;
entity nandl is
port
(
	a,b: in bit;
	o: out bit
);
end nandl;

architecture behave of nandl is
begin 
o<=a nand b;
end behave;
