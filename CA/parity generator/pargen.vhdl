library ieee;
use ieee.std_logic_1164.all;

entity pargen is
port
(
	S: in std_logic_vector(2 downto 0);
	ep, op: out std_logic
);
end pargen;

architecture behave of pargen is
begin
ep <= S(2) xor (S(1) xor S(0));
op <= not(S(2) xor (S(1) xor S(0)));
end behave;	