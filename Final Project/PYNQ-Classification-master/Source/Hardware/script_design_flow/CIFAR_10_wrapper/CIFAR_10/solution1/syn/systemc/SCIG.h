// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.3
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _SCIG_HH_
#define _SCIG_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "cifar_10_mul_32s_bkb.h"
#include "cifar_10_mul_32s_cud.h"
#include "SCIG_inputBuf_V.h"
#include "SCIG_inElem_V.h"

namespace ap_rtl {

struct SCIG : public sc_module {
    // Port declarations 16
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_in< sc_logic > start_full_n;
    sc_out< sc_logic > ap_done;
    sc_in< sc_logic > ap_continue;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_logic > start_out;
    sc_out< sc_logic > start_write;
    sc_in< sc_lv<32> > in_V_V_dout;
    sc_in< sc_logic > in_V_V_empty_n;
    sc_out< sc_logic > in_V_V_read;
    sc_out< sc_lv<32> > out_V_V_din;
    sc_in< sc_logic > out_V_V_full_n;
    sc_out< sc_logic > out_V_V_write;


    // Module declarations
    SCIG(sc_module_name name);
    SC_HAS_PROCESS(SCIG);

    ~SCIG();

    sc_trace_file* mVcdFile;

    SCIG_inputBuf_V* inputBuf_V_U;
    SCIG_inElem_V* inElem_V_U;
    cifar_10_mul_32s_bkb<1,1,32,32,32>* cifar_10_mul_32s_bkb_U11;
    cifar_10_mul_32s_cud<1,1,32,16,32>* cifar_10_mul_32s_cud_U12;
    cifar_10_mul_32s_bkb<1,1,32,32,32>* cifar_10_mul_32s_bkb_U13;
    cifar_10_mul_32s_bkb<1,1,32,32,32>* cifar_10_mul_32s_bkb_U14;
    sc_signal< sc_logic > real_start;
    sc_signal< sc_logic > start_once_reg;
    sc_signal< sc_logic > ap_done_reg;
    sc_signal< sc_lv<16> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > internal_ap_ready;
    sc_signal< sc_logic > in_V_V_blk_n;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_logic > ap_CS_fsm_state8;
    sc_signal< sc_logic > ap_CS_fsm_pp1_stage1;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter0;
    sc_signal< bool > ap_block_pp1_stage1;
    sc_signal< sc_lv<1> > exitcond_reg_895;
    sc_signal< sc_lv<1> > tmp_84_reg_904;
    sc_signal< sc_lv<1> > or_cond1_reg_908;
    sc_signal< sc_logic > ap_CS_fsm_pp1_stage2;
    sc_signal< bool > ap_block_pp1_stage2;
    sc_signal< sc_logic > ap_CS_fsm_pp1_stage0;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter1;
    sc_signal< bool > ap_block_pp1_stage0;
    sc_signal< sc_logic > ap_CS_fsm_pp0_stage0;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter1;
    sc_signal< bool > ap_block_pp0_stage0;
    sc_signal< sc_lv<1> > exitcond2_reg_886;
    sc_signal< sc_logic > out_V_V_blk_n;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter2;
    sc_signal< sc_lv<1> > tmp_93_reg_924;
    sc_signal< sc_lv<1> > tmp_93_reg_924_pp1_iter1_reg;
    sc_signal< sc_lv<1> > tmp_93_reg_924_pp1_iter2_reg;
    sc_signal< sc_lv<32> > i6_reg_235;
    sc_signal< sc_lv<32> > inp_reg_246;
    sc_signal< sc_lv<32> > i_reg_258;
    sc_signal< sc_lv<32> > inp_6_reg_280;
    sc_signal< sc_lv<1> > tmp_s_fu_335_p2;
    sc_signal< sc_lv<1> > tmp_s_reg_780;
    sc_signal< bool > ap_block_state1;
    sc_signal< sc_lv<32> > tmp_V_283_reg_784;
    sc_signal< bool > ap_block_state2;
    sc_signal< sc_lv<32> > tmp_V_285_reg_789;
    sc_signal< bool > ap_block_state3;
    sc_signal< sc_lv<32> > tmp_V_287_reg_795;
    sc_signal< bool > ap_block_state4;
    sc_signal< sc_lv<32> > tmp_V_291_reg_800;
    sc_signal< bool > ap_block_state6;
    sc_signal< sc_lv<32> > KER_size_0_fu_341_p2;
    sc_signal< sc_lv<32> > KER_size_0_reg_805;
    sc_signal< bool > ap_block_state8;
    sc_signal< sc_lv<32> > baseIterBound_fu_350_p2;
    sc_signal< sc_lv<32> > baseIterBound_reg_854;
    sc_signal< sc_lv<32> > KER_size_1_fu_370_p2;
    sc_signal< sc_lv<32> > KER_size_1_reg_876;
    sc_signal< sc_logic > ap_CS_fsm_state9;
    sc_signal< sc_lv<32> > KER_bound_fu_374_p2;
    sc_signal< sc_lv<32> > KER_bound_reg_881;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<1> > exitcond2_fu_378_p2;
    sc_signal< bool > ap_block_state11_pp0_stage0_iter0;
    sc_signal< bool > ap_block_state12_pp0_stage0_iter1;
    sc_signal< bool > ap_block_pp0_stage0_11001;
    sc_signal< sc_lv<32> > i_7_fu_383_p2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter0;
    sc_signal< sc_lv<1> > exitcond_fu_389_p2;
    sc_signal< bool > ap_block_state14_pp1_stage0_iter0;
    sc_signal< bool > ap_predicate_op181_read_state17;
    sc_signal< bool > ap_block_state17_pp1_stage0_iter1;
    sc_signal< bool > ap_block_state20_pp1_stage0_iter2;
    sc_signal< bool > ap_block_pp1_stage0_11001;
    sc_signal< sc_lv<1> > exitcond_reg_895_pp1_iter1_reg;
    sc_signal< sc_lv<32> > i_8_fu_394_p2;
    sc_signal< sc_lv<32> > i_8_reg_899;
    sc_signal< sc_lv<1> > tmp_84_fu_407_p2;
    sc_signal< sc_lv<1> > tmp_84_reg_904_pp1_iter1_reg;
    sc_signal< sc_lv<1> > or_cond1_fu_459_p2;
    sc_signal< sc_lv<32> > inp_2_fu_465_p2;
    sc_signal< sc_lv<32> > tmp_89_fu_482_p2;
    sc_signal< sc_lv<32> > tmp_89_reg_917;
    sc_signal< bool > ap_predicate_op114_read_state15;
    sc_signal< bool > ap_block_state15_pp1_stage1_iter0;
    sc_signal< bool > ap_block_state18_pp1_stage1_iter1;
    sc_signal< bool > ap_block_state21_pp1_stage1_iter2;
    sc_signal< bool > ap_block_pp1_stage1_11001;
    sc_signal< sc_lv<1> > tmp_93_fu_488_p2;
    sc_signal< sc_lv<32> > input_ind_fu_536_p2;
    sc_signal< sc_lv<32> > input_ind_reg_928;
    sc_signal< sc_lv<32> > input_ind_reg_928_pp1_iter1_reg;
    sc_signal< sc_lv<1> > tmp_96_fu_548_p2;
    sc_signal< sc_lv<1> > tmp_97_fu_565_p2;
    sc_signal< sc_lv<1> > tmp_98_fu_585_p2;
    sc_signal< sc_lv<32> > p_inp_1_fu_611_p3;
    sc_signal< sc_lv<32> > tmp_94_fu_729_p2;
    sc_signal< sc_lv<32> > tmp_94_reg_951;
    sc_signal< bool > ap_predicate_op161_read_state16;
    sc_signal< bool > ap_block_state16_pp1_stage2_iter0;
    sc_signal< bool > ap_block_state19_pp1_stage2_iter1;
    sc_signal< bool > ap_block_state22_pp1_stage2_iter2;
    sc_signal< bool > ap_block_pp1_stage2_11001;
    sc_signal< sc_lv<16> > inputBuf_V_q1;
    sc_signal< sc_lv<16> > inputBuf_V_load_1_reg_966;
    sc_signal< bool > ap_block_pp0_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp0_exit_iter0_state11;
    sc_signal< bool > ap_block_pp1_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp1_exit_iter0_state14;
    sc_signal< bool > ap_block_pp1_stage2_subdone;
    sc_signal< sc_lv<14> > inputBuf_V_address0;
    sc_signal< sc_logic > inputBuf_V_ce0;
    sc_signal< sc_logic > inputBuf_V_we0;
    sc_signal< sc_lv<16> > inputBuf_V_q0;
    sc_signal< sc_lv<14> > inputBuf_V_address1;
    sc_signal< sc_logic > inputBuf_V_ce1;
    sc_signal< sc_logic > inputBuf_V_we1;
    sc_signal< sc_lv<8> > inElem_V_address0;
    sc_signal< sc_logic > inElem_V_ce0;
    sc_signal< sc_lv<16> > inElem_V_q0;
    sc_signal< sc_lv<8> > inElem_V_address1;
    sc_signal< sc_logic > inElem_V_ce1;
    sc_signal< sc_logic > inElem_V_we1;
    sc_signal< sc_lv<16> > inElem_V_d1;
    sc_signal< sc_lv<32> > ap_phi_mux_inp_phi_fu_250_p4;
    sc_signal< sc_lv<32> > ap_phi_mux_i_phi_fu_262_p4;
    sc_signal< sc_lv<32> > ap_phi_reg_pp1_iter0_inp_1_reg_269;
    sc_signal< sc_lv<32> > ap_phi_reg_pp1_iter0_inp_6_reg_280;
    sc_signal< sc_lv<16> > ap_phi_mux_storemerge_phi_fu_305_p4;
    sc_signal< sc_lv<16> > tmp_241_fu_695_p1;
    sc_signal< sc_lv<16> > ap_phi_reg_pp1_iter1_storemerge_reg_301;
    sc_signal< sc_lv<16> > ap_phi_reg_pp1_iter0_storemerge_reg_301;
    sc_signal< sc_lv<64> > tmp_90_fu_700_p1;
    sc_signal< sc_lv<64> > tmp_165_2_fu_709_p1;
    sc_signal< sc_lv<64> > tmp_165_1_fu_719_p1;
    sc_signal< sc_lv<64> > tmp_95_fu_734_p1;
    sc_signal< sc_lv<64> > tmp_174_1_fu_745_p1;
    sc_signal< sc_lv<64> > tmp_174_2_fu_764_p1;
    sc_signal< bool > ap_block_state5;
    sc_signal< bool > ap_block_state7;
    sc_signal< bool > ap_block_pp0_stage0_01001;
    sc_signal< sc_lv<32> > tmp_V_301_fu_750_p1;
    sc_signal< bool > ap_block_pp1_stage0_01001;
    sc_signal< sc_lv<32> > tmp_V_302_fu_755_p1;
    sc_signal< bool > ap_block_pp1_stage1_01001;
    sc_signal< sc_lv<32> > tmp_V_303_fu_769_p1;
    sc_signal< bool > ap_block_pp1_stage2_01001;
    sc_signal< sc_lv<12> > IFMPadDimSqrt_fu_102;
    sc_signal< sc_lv<32> > oy_fu_114;
    sc_signal< sc_lv<32> > p_1_fu_619_p3;
    sc_signal< sc_lv<32> > ox_fu_118;
    sc_signal< sc_lv<32> > ox_1_fu_579_p2;
    sc_signal< sc_lv<32> > ky_fu_122;
    sc_signal< sc_lv<32> > ky_3_fu_559_p2;
    sc_signal< sc_lv<32> > inp_j_fu_126;
    sc_signal< sc_lv<32> > inp_j_1_fu_677_p3;
    sc_signal< sc_lv<32> > inp_i_fu_130;
    sc_signal< sc_lv<32> > inp_i_2_fu_669_p3;
    sc_signal< sc_lv<32> > kx_fu_134;
    sc_signal< sc_lv<32> > kx_3_fu_542_p2;
    sc_signal< sc_lv<16> > tmp_239_fu_471_p1;
    sc_signal< sc_lv<16> > tmp_240_fu_632_p1;
    sc_signal< sc_lv<16> > baseIterBound_fu_350_p1;
    sc_signal< sc_lv<32> > extLd_fu_403_p1;
    sc_signal< sc_lv<32> > tmp_85_fu_413_p2;
    sc_signal< sc_lv<27> > tmp_235_fu_427_p4;
    sc_signal< sc_lv<27> > tmp_236_fu_437_p4;
    sc_signal< sc_lv<27> > tmp_237_fu_447_p2;
    sc_signal< sc_lv<1> > tmp_238_fu_453_p2;
    sc_signal< sc_lv<1> > tmp_234_fu_419_p3;
    sc_signal< sc_lv<32> > tmp_242_fu_476_p2;
    sc_signal< sc_lv<32> > tmp_fu_506_p2;
    sc_signal< sc_lv<32> > tmp_243_fu_512_p2;
    sc_signal< sc_lv<32> > tmp_244_fu_518_p2;
    sc_signal< sc_lv<32> > tmp4_fu_530_p2;
    sc_signal< sc_lv<32> > tmp3_fu_524_p2;
    sc_signal< sc_lv<32> > oy_1_fu_599_p2;
    sc_signal< sc_lv<1> > tmp_99_fu_605_p2;
    sc_signal< sc_lv<32> > inp_j_3_fu_637_p2;
    sc_signal< sc_lv<32> > inp_i_1_fu_649_p2;
    sc_signal< sc_lv<1> > tmp_92_fu_655_p2;
    sc_signal< sc_lv<1> > tmp_91_fu_643_p2;
    sc_signal< sc_lv<32> > p_s_fu_661_p3;
    sc_signal< sc_lv<32> > tmp_164_2_fu_704_p2;
    sc_signal< sc_lv<32> > tmp_164_1_fu_714_p2;
    sc_signal< sc_lv<32> > tmp_245_fu_724_p2;
    sc_signal< sc_lv<32> > tmp_173_1_fu_739_p2;
    sc_signal< sc_lv<32> > tmp_173_2_fu_759_p2;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<16> > ap_NS_fsm;
    sc_signal< bool > ap_block_pp1_stage1_subdone;
    sc_signal< bool > ap_block_pp0;
    sc_signal< bool > ap_block_pp1;
    sc_signal< bool > ap_predicate_op189_store_state17;
    sc_signal< bool > ap_enable_operation_189;
    sc_signal< bool > ap_enable_state17_pp1_iter1_stage0;
    sc_signal< bool > ap_predicate_op194_store_state17;
    sc_signal< bool > ap_enable_operation_194;
    sc_signal< bool > ap_predicate_op199_store_state18;
    sc_signal< bool > ap_enable_operation_199;
    sc_signal< bool > ap_enable_state18_pp1_iter1_stage1;
    sc_signal< bool > ap_enable_operation_205;
    sc_signal< bool > ap_enable_state19_pp1_iter1_stage2;
    sc_signal< bool > ap_enable_operation_210;
    sc_signal< bool > ap_enable_state20_pp1_iter2_stage0;
    sc_signal< bool > ap_enable_operation_209;
    sc_signal< bool > ap_enable_operation_213;
    sc_signal< bool > ap_enable_operation_219;
    sc_signal< bool > ap_enable_state21_pp1_iter2_stage1;
    sc_signal< bool > ap_enable_operation_220;
    sc_signal< bool > ap_enable_state22_pp1_iter2_stage2;
    sc_signal< sc_logic > ap_idle_pp0;
    sc_signal< sc_logic > ap_enable_pp0;
    sc_signal< sc_logic > ap_idle_pp1;
    sc_signal< sc_logic > ap_enable_pp1;
    sc_signal< bool > ap_condition_807;
    sc_signal< bool > ap_condition_483;
    sc_signal< bool > ap_condition_460;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<16> ap_ST_fsm_state1;
    static const sc_lv<16> ap_ST_fsm_state2;
    static const sc_lv<16> ap_ST_fsm_state3;
    static const sc_lv<16> ap_ST_fsm_state4;
    static const sc_lv<16> ap_ST_fsm_state5;
    static const sc_lv<16> ap_ST_fsm_state6;
    static const sc_lv<16> ap_ST_fsm_state7;
    static const sc_lv<16> ap_ST_fsm_state8;
    static const sc_lv<16> ap_ST_fsm_state9;
    static const sc_lv<16> ap_ST_fsm_state10;
    static const sc_lv<16> ap_ST_fsm_pp0_stage0;
    static const sc_lv<16> ap_ST_fsm_state13;
    static const sc_lv<16> ap_ST_fsm_pp1_stage0;
    static const sc_lv<16> ap_ST_fsm_pp1_stage1;
    static const sc_lv<16> ap_ST_fsm_pp1_stage2;
    static const sc_lv<16> ap_ST_fsm_state23;
    static const bool ap_const_boolean_1;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_D;
    static const bool ap_const_boolean_0;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<16> ap_const_lv16_2;
    static const sc_lv<64> ap_const_lv64_0;
    static const sc_lv<64> ap_const_lv64_1;
    static const sc_lv<64> ap_const_lv64_2;
    static const sc_lv<12> ap_const_lv12_510;
    static const sc_lv<32> ap_const_lv32_FFFFFFFE;
    static const sc_lv<32> ap_const_lv32_64D8;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<27> ap_const_lv27_0;
    static const sc_lv<32> ap_const_lv32_D8;
    static const sc_lv<32> ap_const_lv32_20;
    static const sc_lv<32> ap_const_lv32_22;
    static const sc_lv<32> ap_const_lv32_B;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_IFMPadDimSqrt_fu_102();
    void thread_ap_CS_fsm_pp0_stage0();
    void thread_ap_CS_fsm_pp1_stage0();
    void thread_ap_CS_fsm_pp1_stage1();
    void thread_ap_CS_fsm_pp1_stage2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_CS_fsm_state8();
    void thread_ap_CS_fsm_state9();
    void thread_ap_block_pp0();
    void thread_ap_block_pp0_stage0();
    void thread_ap_block_pp0_stage0_01001();
    void thread_ap_block_pp0_stage0_11001();
    void thread_ap_block_pp0_stage0_subdone();
    void thread_ap_block_pp1();
    void thread_ap_block_pp1_stage0();
    void thread_ap_block_pp1_stage0_01001();
    void thread_ap_block_pp1_stage0_11001();
    void thread_ap_block_pp1_stage0_subdone();
    void thread_ap_block_pp1_stage1();
    void thread_ap_block_pp1_stage1_01001();
    void thread_ap_block_pp1_stage1_11001();
    void thread_ap_block_pp1_stage1_subdone();
    void thread_ap_block_pp1_stage2();
    void thread_ap_block_pp1_stage2_01001();
    void thread_ap_block_pp1_stage2_11001();
    void thread_ap_block_pp1_stage2_subdone();
    void thread_ap_block_state1();
    void thread_ap_block_state11_pp0_stage0_iter0();
    void thread_ap_block_state12_pp0_stage0_iter1();
    void thread_ap_block_state14_pp1_stage0_iter0();
    void thread_ap_block_state15_pp1_stage1_iter0();
    void thread_ap_block_state16_pp1_stage2_iter0();
    void thread_ap_block_state17_pp1_stage0_iter1();
    void thread_ap_block_state18_pp1_stage1_iter1();
    void thread_ap_block_state19_pp1_stage2_iter1();
    void thread_ap_block_state2();
    void thread_ap_block_state20_pp1_stage0_iter2();
    void thread_ap_block_state21_pp1_stage1_iter2();
    void thread_ap_block_state22_pp1_stage2_iter2();
    void thread_ap_block_state3();
    void thread_ap_block_state4();
    void thread_ap_block_state5();
    void thread_ap_block_state6();
    void thread_ap_block_state7();
    void thread_ap_block_state8();
    void thread_ap_condition_460();
    void thread_ap_condition_483();
    void thread_ap_condition_807();
    void thread_ap_condition_pp0_exit_iter0_state11();
    void thread_ap_condition_pp1_exit_iter0_state14();
    void thread_ap_done();
    void thread_ap_enable_operation_189();
    void thread_ap_enable_operation_194();
    void thread_ap_enable_operation_199();
    void thread_ap_enable_operation_205();
    void thread_ap_enable_operation_209();
    void thread_ap_enable_operation_210();
    void thread_ap_enable_operation_213();
    void thread_ap_enable_operation_219();
    void thread_ap_enable_operation_220();
    void thread_ap_enable_pp0();
    void thread_ap_enable_pp1();
    void thread_ap_enable_state17_pp1_iter1_stage0();
    void thread_ap_enable_state18_pp1_iter1_stage1();
    void thread_ap_enable_state19_pp1_iter1_stage2();
    void thread_ap_enable_state20_pp1_iter2_stage0();
    void thread_ap_enable_state21_pp1_iter2_stage1();
    void thread_ap_enable_state22_pp1_iter2_stage2();
    void thread_ap_idle();
    void thread_ap_idle_pp0();
    void thread_ap_idle_pp1();
    void thread_ap_phi_mux_i_phi_fu_262_p4();
    void thread_ap_phi_mux_inp_phi_fu_250_p4();
    void thread_ap_phi_mux_storemerge_phi_fu_305_p4();
    void thread_ap_phi_reg_pp1_iter0_storemerge_reg_301();
    void thread_ap_predicate_op114_read_state15();
    void thread_ap_predicate_op161_read_state16();
    void thread_ap_predicate_op181_read_state17();
    void thread_ap_predicate_op189_store_state17();
    void thread_ap_predicate_op194_store_state17();
    void thread_ap_predicate_op199_store_state18();
    void thread_ap_ready();
    void thread_baseIterBound_fu_350_p1();
    void thread_exitcond2_fu_378_p2();
    void thread_exitcond_fu_389_p2();
    void thread_extLd_fu_403_p1();
    void thread_i_7_fu_383_p2();
    void thread_i_8_fu_394_p2();
    void thread_inElem_V_address0();
    void thread_inElem_V_address1();
    void thread_inElem_V_ce0();
    void thread_inElem_V_ce1();
    void thread_inElem_V_d1();
    void thread_inElem_V_we1();
    void thread_in_V_V_blk_n();
    void thread_in_V_V_read();
    void thread_inp_2_fu_465_p2();
    void thread_inp_i_1_fu_649_p2();
    void thread_inp_i_2_fu_669_p3();
    void thread_inp_j_1_fu_677_p3();
    void thread_inp_j_3_fu_637_p2();
    void thread_inputBuf_V_address0();
    void thread_inputBuf_V_address1();
    void thread_inputBuf_V_ce0();
    void thread_inputBuf_V_ce1();
    void thread_inputBuf_V_we0();
    void thread_inputBuf_V_we1();
    void thread_input_ind_fu_536_p2();
    void thread_internal_ap_ready();
    void thread_kx_3_fu_542_p2();
    void thread_ky_3_fu_559_p2();
    void thread_or_cond1_fu_459_p2();
    void thread_out_V_V_blk_n();
    void thread_out_V_V_din();
    void thread_out_V_V_write();
    void thread_ox_1_fu_579_p2();
    void thread_oy_1_fu_599_p2();
    void thread_p_1_fu_619_p3();
    void thread_p_inp_1_fu_611_p3();
    void thread_p_s_fu_661_p3();
    void thread_real_start();
    void thread_start_out();
    void thread_start_write();
    void thread_tmp3_fu_524_p2();
    void thread_tmp4_fu_530_p2();
    void thread_tmp_164_1_fu_714_p2();
    void thread_tmp_164_2_fu_704_p2();
    void thread_tmp_165_1_fu_719_p1();
    void thread_tmp_165_2_fu_709_p1();
    void thread_tmp_173_1_fu_739_p2();
    void thread_tmp_173_2_fu_759_p2();
    void thread_tmp_174_1_fu_745_p1();
    void thread_tmp_174_2_fu_764_p1();
    void thread_tmp_234_fu_419_p3();
    void thread_tmp_235_fu_427_p4();
    void thread_tmp_236_fu_437_p4();
    void thread_tmp_237_fu_447_p2();
    void thread_tmp_238_fu_453_p2();
    void thread_tmp_239_fu_471_p1();
    void thread_tmp_240_fu_632_p1();
    void thread_tmp_241_fu_695_p1();
    void thread_tmp_242_fu_476_p2();
    void thread_tmp_243_fu_512_p2();
    void thread_tmp_244_fu_518_p2();
    void thread_tmp_245_fu_724_p2();
    void thread_tmp_84_fu_407_p2();
    void thread_tmp_85_fu_413_p2();
    void thread_tmp_89_fu_482_p2();
    void thread_tmp_90_fu_700_p1();
    void thread_tmp_91_fu_643_p2();
    void thread_tmp_92_fu_655_p2();
    void thread_tmp_93_fu_488_p2();
    void thread_tmp_94_fu_729_p2();
    void thread_tmp_95_fu_734_p1();
    void thread_tmp_96_fu_548_p2();
    void thread_tmp_97_fu_565_p2();
    void thread_tmp_98_fu_585_p2();
    void thread_tmp_99_fu_605_p2();
    void thread_tmp_V_301_fu_750_p1();
    void thread_tmp_V_302_fu_755_p1();
    void thread_tmp_V_303_fu_769_p1();
    void thread_tmp_fu_506_p2();
    void thread_tmp_s_fu_335_p2();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
