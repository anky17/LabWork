library ieee;
use ieee.std_logic_1164.all;
entity orl is
port
(

a,b: in bit;
o: out bit

);
end orl;
architecture behave of orl is
begin
o<= a or b;
end behave;