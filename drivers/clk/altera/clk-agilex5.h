/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2024 Intel Corporation <www.intel.com>
 */

#ifndef	_CLK_AGILEX5_
#define	_CLK_AGILEX5_

#ifndef __ASSEMBLY__
#include <linux/bitops.h>
#endif

#define CORE0		1
#define CORE1		2
#define CORE2		3
#define CORE3		4

/* Derived from l4_main_clk (PSS clock) */
#define COUNTER_FREQUENCY_REAL	400000000

#define CM_REG_READL(plat, reg)				\
	readl((plat)->regs + (reg))

#define CM_REG_WRITEL(plat, data, reg)			\
	writel(data, (plat)->regs + (reg))

#define CM_REG_CLRBITS(plat, reg, clear)		\
	clrbits_le32((plat)->regs + (reg), (clear))

#define CM_REG_SETBITS(plat, reg, set)			\
	setbits_le32((plat)->regs + (reg), (set))

struct cm_config {
	/* main group */
	u32 main_pll_nocclk;
	u32 main_pll_nocdiv;
	u32 main_pll_pllglob;
	u32 main_pll_fdbck;
	u32 main_pll_pllc0;
	u32 main_pll_pllc1;
	u32 main_pll_pllc2;
	u32 main_pll_pllc3;
	u32 main_pll_pllm;

	/* peripheral group */
	u32 per_pll_emacctl;
	u32 per_pll_gpiodiv;
	u32 per_pll_pllglob;
	u32 per_pll_fdbck;
	u32 per_pll_pllc0;
	u32 per_pll_pllc1;
	u32 per_pll_pllc2;
	u32 per_pll_pllc3;
	u32 per_pll_pllm;

	/* control group */
	u32 ctl_emacactr;
	u32 ctl_emacbctr;
	u32 ctl_emacptpctr;
	u32 ctl_gpiodbctr;
	u32 ctl_s2fuser0ctr;
	u32 ctl_s2fuser1ctr;
	u32 ctl_psirefctr;
	u32 ctl_usb31ctr;
	u32 ctl_dsuctr;
	u32 ctl_core01ctr;
	u32 ctl_core23ctr;
	u32 ctl_core2ctr;
	u32 ctl_core3ctr;

	/* incoming clock */
	u32 hps_osc_clk_hz;
	u32 fpga_clk_hz;
	u32 spare[3];
};

/* Clock Manager registers */
#define CLKMGR_CTRL				0
#define CLKMGR_STAT				4
#define CLKMGR_TESTIOCTRL			8
#define CLKMGR_INTRGEN				0x0c
#define CLKMGR_INTRMSK				0x10
#define CLKMGR_INTRCLR				0x14
#define CLKMGR_INTRSTS				0x18
#define CLKMGR_INTRSTK				0x1c
#define CLKMGR_INTRRAW				0x20

/* Clock Manager Main PPL group registers */
#define CLKMGR_MAINPLL_EN			0x24
#define CLKMGR_MAINPLL_ENS			0x28
#define CLKMGR_MAINPLL_ENR			0x2c
#define CLKMGR_MAINPLL_BYPASS			0x30
#define CLKMGR_MAINPLL_BYPASSS			0x34
#define CLKMGR_MAINPLL_BYPASSR			0x38
#define CLKMGR_MAINPLL_NOCCLK			0x40
#define CLKMGR_MAINPLL_NOCDIV			0x44
#define CLKMGR_MAINPLL_PLLGLOB			0x48
#define CLKMGR_MAINPLL_FDBCK			0x4c
#define CLKMGR_MAINPLL_MEM			0x50
#define CLKMGR_MAINPLL_MEMSTAT			0x54
#define CLKMGR_MAINPLL_VCOCALIB			0x58
#define CLKMGR_MAINPLL_PLLC0			0x5c
#define CLKMGR_MAINPLL_PLLC1			0x60
#define CLKMGR_MAINPLL_PLLC2			0x64
#define CLKMGR_MAINPLL_PLLC3			0x68
#define CLKMGR_MAINPLL_PLLM			0x6c
#define CLKMGR_MAINPLL_FHOP			0x70
#define CLKMGR_MAINPLL_SSC			0x74
#define CLKMGR_MAINPLL_LOSTLOCK			0x78

/* Clock Manager Peripheral PPL group registers */
#define CLKMGR_PERPLL_EN			0x7c
#define CLKMGR_PERPLL_ENS			0x80
#define CLKMGR_PERPLL_ENR			0x84
#define CLKMGR_PERPLL_BYPASS			0x88
#define CLKMGR_PERPLL_BYPASSS			0x8c
#define CLKMGR_PERPLL_BYPASSR			0x90
#define CLKMGR_PERPLL_EMACCTL			0x94
#define CLKMGR_PERPLL_GPIODIV			0x98
#define CLKMGR_PERPLL_PLLGLOB			0x9c
#define CLKMGR_PERPLL_FDBCK			0xa0
#define CLKMGR_PERPLL_MEM			0xa4
#define CLKMGR_PERPLL_MEMSTAT			0xa8
#define CLKMGR_PERPLL_VCOCALIB			0xac
#define CLKMGR_PERPLL_PLLC0			0xb0
#define CLKMGR_PERPLL_PLLC1			0xb4
#define CLKMGR_PERPLL_PLLC2			0xb8
#define CLKMGR_PERPLL_PLLC3			0xbc
#define CLKMGR_PERPLL_PLLM			0xc0
#define CLKMGR_PERPLL_FHOP			0xc4
#define CLKMGR_PERPLL_SSC			0xc8
#define CLKMGR_PERPLL_LOSTLOCK			0xcc

/* Clock Manager Control group registers */
#define CLKMGR_CTL_JTAG			0xd0
#define CLKMGR_CTL_EMACACTR			0xd4
#define CLKMGR_CTL_EMACBCTR			0xd8
#define CLKMGR_CTL_EMACPTPCTR			0xdc
#define CLKMGR_CTL_GPIODBCTR			0xe0
#define CLKMGR_CTL_S2FUSER0CTR			0xe8
#define CLKMGR_CTL_S2FUSER1CTR			0xec
#define CLKMGR_CTL_PSIREFCTR			0xf0
#define CLKMGR_CTL_EXTCNTRST			0xf4
#define CLKMGR_CTL_USB31CTR				0xf8
#define CLKMGR_CTL_DSUCTR				0xfc
#define CLKMGR_CTL_CORE01CTR			0x100
#define CLKMGR_CTL_CORE23CTR			0x104
#define CLKMGR_CTL_CORE2CTR				0x108
#define CLKMGR_CTL_CORE3CTR				0x10C

#define CLKMGR_CTRL_BOOTMODE			BIT(0)

#define CLKMGR_STAT_BUSY			BIT(0)
#define CLKMGR_STAT_MAINPLL_LOCKED		BIT(8)
#define CLKMGR_STAT_MAIN_TRANS			BIT(9)
#define CLKMGR_STAT_PERPLL_LOCKED		BIT(16)
#define CLKMGR_STAT_PERF_TRANS			BIT(17)
#define CLKMGR_STAT_BOOTMODE			BIT(24)
#define CLKMGR_STAT_BOOTCLKSRC			BIT(25)

#define CLKMGR_STAT_ALLPLL_LOCKED_MASK		\
	(CLKMGR_STAT_MAINPLL_LOCKED | CLKMGR_STAT_PERPLL_LOCKED)

#define CLKMGR_INTER_MAINPLLLOCKED_MASK		0x00000001
#define CLKMGR_INTER_PERPLLLOCKED_MASK		0x00000002
#define CLKMGR_INTER_MAINPLLLOST_MASK		0x00000004
#define CLKMGR_INTER_PERPLLLOST_MASK		0x00000008

#define CLKMGR_CLKSRC_MASK			GENMASK(18, 16)
#define CLKMGR_CLKSRC_OFFSET			16
#define CLKMGR_CLKSRC_MAIN			0
#define CLKMGR_CLKSRC_PER			1
#define CLKMGR_CLKSRC_OSC1			2
#define CLKMGR_CLKSRC_INTOSC			3
#define CLKMGR_CLKSRC_FPGA			4
#define CLKMGR_CLKCNT_MSK			GENMASK(10, 0)

#define CLKMGR_BYPASS_MAINPLL_ALL		0xf6
#define CLKMGR_BYPASS_PERPLL_ALL		0xef

#define CLKMGR_NOCDIV_SOFTPHY_DIV_ONE		0
#define CLKMGR_NOCDIV_SOFTPHY_DIV_TWO		1
#define CLKMGR_NOCDIV_SOFTPHY_DIV_FOUR		2
#define CLKMGR_NOCDIV_L4SYSFREECLK_OFFSET		0
#define CLKMGR_NOCDIV_L4MPCLK_OFFSET		4
#define CLKMGR_NOCDIV_L4SPCLK_OFFSET		6
#define CLKMGR_NOCDIV_SOFTPHY_OFFSET		16
#define CLKMGR_NOCDIV_CCU_OFFSET			18
#define CLKMGR_NOCDIV_MPUPERIPH_OFFSET		20
#define CLKMGR_NOCDIV_CSATCLK_OFFSET		24
#define CLKMGR_NOCDIV_CSTRACECLK_OFFSET		26
#define CLKMGR_NOCDIV_CSPDBGCLK_OFFSET		28
#define CLKMGR_NOCDIV_DIVIDER_MASK		0x3

#define CLKMGR_PLLGLOB_PD_MASK				BIT(0)
#define CLKMGR_PLLGLOB_RST_MASK				BIT(1)
#define CLKMGR_PLLGLOB_AREFCLKDIV_MASK			GENMASK(11, 8)
#define CLKMGR_PLLGLOB_DREFCLKDIV_MASK			GENMASK(13, 12)
#define CLKMGR_PLLGLOB_REFCLKDIV_MASK			GENMASK(13, 8)
#define CLKMGR_PLLGLOB_MODCLKDIV_MASK			GENMASK(24, 27)
#define CLKMGR_PLLGLOB_AREFCLKDIV_OFFSET		8
#define CLKMGR_PLLGLOB_DREFCLKDIV_OFFSET		12
#define CLKMGR_PLLGLOB_REFCLKDIV_OFFSET			8
#define CLKMGR_PLLGLOB_MODCLKDIV_OFFSET			24
#define CLKMGR_PLLGLOB_VCO_PSRC_MASK			GENMASK(17, 16)
#define CLKMGR_PLLGLOB_VCO_PSRC_OFFSET			16
#define CLKMGR_PLLGLOB_CLR_LOSTLOCK_BYPASS_MASK		BIT(29)

#define CLKMGR_VCO_PSRC_EOSC1			0
#define CLKMGR_VCO_PSRC_INTOSC			1
#define CLKMGR_VCO_PSRC_F2S			2

#define CLKMGR_MEM_REQ_SET_MSK			BIT(24)
#define CLKMGR_MEM_WR_SET_MSK			BIT(25)
#define CLKMGR_MEM_ERR_MSK			BIT(26)
#define CLKMGR_MEM_WDAT_LSB_OFFSET		16
#define CLKMGR_MEM_ADDR_MASK			GENMASK(15, 0)
#define CLKMGR_MEM_ADDR_START			0x00004000

#define CLKMGR_PLLCX_EN_SET_MSK			BIT(27)
#define CLKMGR_PLLCX_MUTE_SET_MSK		BIT(28)

#define CLKMGR_VCOCALIB_MSCNT_MASK		GENMASK(23, 16)
#define CLKMGR_VCOCALIB_MSCNT_OFFSET		16
#define CLKMGR_VCOCALIB_HSCNT_MASK		GENMASK(9, 0)
#define CLKMGR_VCOCALIB_MSCNT_CONST		100
#define CLKMGR_VCOCALIB_HSCNT_CONST		4

#define CLKMGR_PLLM_MDIV_MASK			GENMASK(9, 0)

#define CLKMGR_LOSTLOCK_SET_MASK		BIT(0)

#define CLKMGR_PERPLLGRP_EN_SDMMCCLK_MASK		BIT(5)
#define CLKMGR_PERPLLGRP_EMACCTL_EMAC0SELB_OFFSET	26
#define CLKMGR_PERPLLGRP_EMACCTL_EMAC0SELB_MASK		BIT(26)
#define CLKMGR_PERPLLGRP_EMACCTL_EMAC1SELB_OFFSET	27
#define CLKMGR_PERPLLGRP_EMACCTL_EMAC1SELB_MASK		BIT(27)
#define CLKMGR_PERPLLGRP_EMACCTL_EMAC2SELB_OFFSET	28
#define CLKMGR_PERPLLGRP_EMACCTL_EMAC2SELB_MASK		BIT(28)

#define CLKMGR_CTL_EMACCTR_SRC_OFFSET		16
#define CLKMGR_CTL_EMACCTR_SRC_MASK		GENMASK(18, 16)
#define CLKMGR_CTL_EMACCTR_CNT_OFFSET		0
#define CLKMGR_CTL_EMACCTR_CNT_MASK		GENMASK(10, 0)

#define CLKMGR_CTL_EXTCNTRST_EMACACNTRST	BIT(0)
#define CLKMGR_CTL_EXTCNTRST_EMACBCNTRST	BIT(1)
#define CLKMGR_CTL_EXTCNTRST_EMACPTPCNTRST	BIT(2)
#define CLKMGR_CTL_EXTCNTRST_GPIODBCNTRST	BIT(3)
#define CLKMGR_CTL_EXTCNTRST_S2FUSER0CNTRST	BIT(5)
#define CLKMGR_CTL_EXTCNTRST_S2FUSER1CNTRST	BIT(6)
#define CLKMGR_CTL_EXTCNTRST_PSIREFCNTRST	BIT(7)
#define CLKMGR_CTL_EXTCNTRST_USB31REFCNTRST	BIT(8)
#define CLKMGR_CTL_EXTCNTRST_DSUCNTRST		BIT(10)
#define CLKMGR_CTL_EXTCNTRST_CORE01CNTRST	BIT(11)
#define CLKMGR_CTL_EXTCNTRST_CORE2CNTRST	BIT(12)
#define CLKMGR_CTL_EXTCNTRST_CORE3CNTRST	BIT(13)
#define CLKMGR_CTL_EXTCNTRST_ALLCNTRST		\
	(CLKMGR_CTL_EXTCNTRST_EMACACNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_EMACBCNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_EMACPTPCNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_GPIODBCNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_S2FUSER0CNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_S2FUSER1CNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_PSIREFCNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_USB31REFCNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_DSUCNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_CORE01CNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_CORE2CNTRST |	\
	 CLKMGR_CTL_EXTCNTRST_CORE3CNTRST)

#define MEMBUS_MAINPLL				0
#define MEMBUS_PERPLL				1
#define MEMBUS_TIMEOUT				1000

#define MEMBUS_CLKSLICE_REG				0x27
#define MEMBUS_SYNTHCALFOSC_INIT_CENTERFREQ_REG		0xb3
#define MEMBUS_SYNTHPPM_WATCHDOGTMR_VF01_REG		0xe6
#define MEMBUS_CALCLKSLICE0_DUTY_LOCOVR_REG		0x03
#define MEMBUS_CALCLKSLICE1_DUTY_LOCOVR_REG		0x07

#define MPIDR_AFF1_OFFSET	8
#define MPIDR_AFF1_MASK		0x3
#endif /* _CLK_AGILEX5_ */
