@echo off
echo ghdl runner
set /p logicfile="Enter Architecture Filename: "
set /p tbfile="Enter TestBench Filename: "
set /p archunit="Enter Architecture unit: "
set /p tbunit="Enter TestBench unit: "
set /p outfile="Enter vcd file: "

ghdl -s %logicfile%.vhdl
ghdl -s %tbfile%.vhdl
ghdl -a %logicfile%.vhdl
ghdl -a %tbfile%.vhdl
ghdl -e %archunit%
ghdl -e %tbunit%
ghdl -r %archunit%
ghdl -r %tbunit%
ghdl -r %tbunit% --vcd=%outfile%.vcd

pause