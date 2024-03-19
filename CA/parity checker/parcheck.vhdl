library ieee;
use ieee.std_logic_1164.all;

entity parcheck is
port
(
	S: in std_logic_vector(3 downto 0);
	ep, op: out std_logic
);
end parcheck;

architecture behave of parcheck is
begin
	op <= S(3) xor S(2) xor (S(1) xor S(0));
	ep <= not(S(3) xor S(2) xor (S(1) xor S(0)));
end behave;
