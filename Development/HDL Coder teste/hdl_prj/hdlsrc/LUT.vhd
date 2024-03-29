-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\LUT.vhd
-- Created: 2014-07-15 16:33:33
-- 
-- Generated by MATLAB 8.0 and HDL Coder 3.1
-- 
-- 
-- -------------------------------------------------------------
-- Rate and Clocking Details
-- -------------------------------------------------------------
-- Model base rate: 1e-07
-- Target subsystem base rate: 1e-07
-- 
-- 
-- Clock Enable  Sample Time
-- -------------------------------------------------------------
-- ce_out        0.001
-- -------------------------------------------------------------
-- 
-- 
-- Output Signal                 Clock Enable  Sample Time
-- -------------------------------------------------------------
-- Out1                          ce_out        0.001
-- -------------------------------------------------------------
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: LUT
-- Source Path: LUT
-- Hierarchy Level: 0
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE work.LUT_pkg.ALL;

ENTITY LUT IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        clk_enable                        :   IN    std_logic;
        In1                               :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        ce_out                            :   OUT   std_logic;
        Out1                              :   OUT   std_logic_vector(15 DOWNTO 0)  -- sfix16_En8
        );
END LUT;


ARCHITECTURE rtl OF LUT IS

  -- Component Declarations
  COMPONENT LUT_tc
    PORT( clk                             :   IN    std_logic;
          reset                           :   IN    std_logic;
          clk_enable                      :   IN    std_logic;
          enb_1_10000_1                   :   OUT   std_logic
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : LUT_tc
    USE ENTITY work.LUT_tc(rtl);

  -- Constants
  CONSTANT nc                             : vector_of_signed16(0 TO 52) := ( to_signed(21542, 16), to_signed(22815, 16), to_signed(23860, 16), to_signed(24667, 16), 
                                                                           to_signed(25228, 16), to_signed(25536, 16), to_signed(25589, 16), to_signed(25387, 16), 
                                                                           to_signed(24930, 16), to_signed(24225, 16), to_signed(23278, 16), to_signed(22098, 16), 
                                                                           to_signed(20698, 16), to_signed(19090, 16), to_signed(17292, 16), to_signed(15321, 16), 
                                                                           to_signed(13197, 16), to_signed(10941, 16), to_signed(8576, 16), to_signed(6125, 16), 
                                                                           to_signed(3613, 16), to_signed(1064, 16), to_signed(-1494, 16), to_signed(-4038, 16), 
                                                                           to_signed(-6542, 16), to_signed(-8980, 16), to_signed(-11329, 16), to_signed(-13564, 16), 
                                                                           to_signed(-15664, 16), to_signed(-17607, 16), to_signed(-19374, 16), to_signed(-20948, 16), 
                                                                           to_signed(-22312, 16), to_signed(-23454, 16), to_signed(-24361, 16), to_signed(-25025, 16), 
                                                                           to_signed(-25438, 16), to_signed(-25598, 16), to_signed(-25502, 16), to_signed(-25151, 16), 
                                                                           to_signed(-24548, 16), to_signed(-23701, 16), to_signed(-22616, 16), to_signed(-21306, 16), 
                                                                           to_signed(-19783, 16), to_signed(-18062, 16), to_signed(-16160, 16), to_signed(-14098, 16), 
                                                                           to_signed(-11894, 16), to_signed(-9571, 16), to_signed(-7153, 16), to_signed(-4663, 16), 
                                                                           to_signed(-2127, 16) );  -- sfix16 [53]

  -- Signals
  SIGNAL enb_1_10000_1                    : std_logic;
  SIGNAL In1_unsigned                     : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Rate_Transition_bypass_reg       : unsigned(7 DOWNTO 0);  -- ufix8
  SIGNAL Rate_Transition_out1             : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL alpha1_D_Lookup_Table_k          : unsigned(5 DOWNTO 0);  -- ufix6
  SIGNAL alpha1_D_Lookup_Table_out1       : signed(15 DOWNTO 0);  -- sfix16_En8

BEGIN
  u_LUT_tc : LUT_tc
    PORT MAP( clk => clk,
              reset => reset,
              clk_enable => clk_enable,
              enb_1_10000_1 => enb_1_10000_1
              );

  In1_unsigned <= unsigned(In1);

  Rate_Transition_bypass_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Rate_Transition_bypass_reg <= to_unsigned(0, 8);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb_1_10000_1 = '1' THEN
        Rate_Transition_bypass_reg <= In1_unsigned;
      END IF;
    END IF;
  END PROCESS Rate_Transition_bypass_process;

  
  Rate_Transition_out1 <= In1_unsigned WHEN enb_1_10000_1 = '1' ELSE
      Rate_Transition_bypass_reg;

  
  alpha1_D_Lookup_Table_k <= to_unsigned(0, 6) WHEN Rate_Transition_out1 <= 1 ELSE
      to_unsigned(52, 6) WHEN Rate_Transition_out1 >= 53 ELSE
      resize(Rate_Transition_out1 - 1, 6);
  alpha1_D_Lookup_Table_out1 <= nc(to_integer(alpha1_D_Lookup_Table_k));

  Out1 <= std_logic_vector(alpha1_D_Lookup_Table_out1);

  ce_out <= enb_1_10000_1;

END rtl;

