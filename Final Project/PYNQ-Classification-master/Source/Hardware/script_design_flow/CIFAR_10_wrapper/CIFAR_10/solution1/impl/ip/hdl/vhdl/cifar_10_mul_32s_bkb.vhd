-- ==============================================================
-- File generated on Mon Jan 06 15:37:44 +0800 2020
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;


entity cifar_10_mul_32s_bkb_Mul_LUT_0 is
port (
    a: in std_logic_vector(32 - 1 downto 0);
    b: in std_logic_vector(32 - 1 downto 0);
    p: out std_logic_vector(32 - 1 downto 0));

    attribute use_dsp : string;
    attribute use_dsp of cifar_10_mul_32s_bkb_Mul_LUT_0 : entity is "no";

end entity;

architecture behav of cifar_10_mul_32s_bkb_Mul_LUT_0 is
    signal a_i : std_logic_vector(32 - 1 downto 0);
    signal b_i : std_logic_vector(32 - 1 downto 0);
begin
    a_i <= a;
    b_i <= b;
    p <= std_logic_vector(resize(unsigned(std_logic_vector(signed(a_i) * signed(b_i))), 32));
end architecture;
Library IEEE;
use IEEE.std_logic_1164.all;

entity cifar_10_mul_32s_bkb is
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER);
    port (
        din0 : IN STD_LOGIC_VECTOR(din0_WIDTH - 1 DOWNTO 0);
        din1 : IN STD_LOGIC_VECTOR(din1_WIDTH - 1 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(dout_WIDTH - 1 DOWNTO 0));
end entity;

architecture arch of cifar_10_mul_32s_bkb is
    component cifar_10_mul_32s_bkb_Mul_LUT_0 is
        port (
            a : IN STD_LOGIC_VECTOR;
            b : IN STD_LOGIC_VECTOR;
            p : OUT STD_LOGIC_VECTOR);
    end component;



begin
    cifar_10_mul_32s_bkb_Mul_LUT_0_U :  component cifar_10_mul_32s_bkb_Mul_LUT_0
    port map (
        a => din0,
        b => din1,
        p => dout);

end architecture;


