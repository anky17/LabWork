library ieee;
use ieee.std_logic_1164.all;
entity ps is
port(A,B: in  STD_LOGIC_VECTOR(3 downto 0);
	S: out STD_LOGIC_VECTOR(3 downto 0);
	Cin: in STD_LOGIC;
	Cout: out STD_LOGIC
	);
end ps;

architecture behave of ps is
begin
  process (A,B,Cin)
	variable t: STD_LOGIC;
	begin
	t:=Cin;
	for i in 0 to 3 loop
		S(i) <= (A(i) xor (not B(i))) Xor t;
		t := (A(i) and (not B(i))) or ((t and A(i)) or (t and (not B(i))));
	end loop;
	Cout <= t;
   end process;
end behave;

 
