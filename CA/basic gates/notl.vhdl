library ieee;
use ieee.std_logic_1164.all;
entity notl is
port
(

a: in bit;
o: out bit

);
end notl;
architecture behave of notl is
begin
o<= not a;
end behave;