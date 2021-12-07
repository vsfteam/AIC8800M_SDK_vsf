#ifndef _REG_SYSCTRL_H_
#define _REG_SYSCTRL_H_

#include "chip.h"

/* ================================================================================ */
/* ================                CPU System Control              ================ */
/* ================================================================================ */
typedef struct {
  __IO uint32_t SYSREM;         /* 0x000: System matrix remap */
  __IO uint32_t CLKSEL;         /* 0x004: Clock selection */
  __IO uint32_t HCLKCM;         /* 0x008: HCLK control mode */
  __IO uint32_t PCLKCM;         /* 0x00C: PCLK control mode */
  __IO uint32_t OCLKCM;         /* 0x010: Others CLK control mode */
  __IO uint32_t USBCCFG;        /* 0x014: USB controller config */
  __IO uint32_t VPCCLKCTL;      /* 0x018: VPC clock control */
  __IO uint32_t ROMCFG;         /* 0x01C: ROM config */
  __IO uint32_t SRAMCFG[5];     /* 0x020: SRAM0 ~ SRAM4 config */
  __IO uint32_t ASDMAMCFG;      /* 0x034: ASDMA memory config */
  __IO uint32_t CACHEMCFG;      /* 0x038: Cache memory config */
  __IO uint32_t SDIOMCFG;       /* 0x03C: SDIO memory config */
  __IO uint32_t SPIMCFG;        /* 0x040: SPI memory config */
  __IO uint32_t USBCMCFG;       /* 0x044: USBC memory config */
  __IO uint32_t DMAMCFG;        /* 0x048: DMA memory config */
  __IO uint32_t CEMCFG;         /* 0x04C: CE memory config */
  __IO uint32_t VPCMCFG;        /* 0x050: VPC memory config */
  __IO uint32_t TPSEL;          /* 0x054: Tports selection */
  __IO uint32_t TRAPBP;         /* 0x058: TRAP bypass */
  __IO uint32_t CACHEBP;        /* 0x05C: Cache bypass */
  __IO uint32_t HCLK1CM;        /* 0x060: HCLK1 control mode */
  __IO uint32_t SRAMCFG5;       /* 0x064: SRAM5 config */
  __IO uint32_t UARTMCFG;       /* 0x068: UART memory config */
  __IO uint32_t CRCLKDIV;       /* 0x06C: Camera ref clock div */
  __IO uint32_t JPEGENCMCFG;    /* 0x070: JPEG encoder memory config */
  __IO uint32_t BTROMCFG;       /* 0x074: BTROM memory config */
  __IO uint32_t ASDMACLKDIV;    /* 0x078: ASDMA clock div */
  __IO uint32_t PSRMDSEL;       /* 0x07C: PSRAM mode selection */
  __IO uint32_t SRAMCFG6;       /* 0x080: SRAM6 config */
  __IO uint32_t PCLKDIV;        /* 0x084: PCLK div */
  __IO uint32_t CMCLKDIV;       /* 0x088: Codec MCLK div */
  __IO uint32_t CBCLKSEL;       /* 0x08C: Codec BCLK selection */
  __IO uint32_t ULPICD;         /* 0x090: ULPI clock detection */
  __IO uint32_t ULPICS;         /* 0x094: ULPI clock status */
  __IO uint32_t PSRDBGSEL;      /* 0x098: PSRAM debug selection */
  __IO uint32_t RESERVED0[25];  /* 0x09C: Reserved */
  __IO uint32_t HCLKME;         /* 0x100: HCLK manual enable */
  __IO uint32_t HCLKMD;         /* 0x104: HCLK manual disable */
  __IO uint32_t PCLKME;         /* 0x108: PCLK manual enable */
  __IO uint32_t PCLKMD;         /* 0x10C: PCLK manual disable */
  __IO uint32_t OCLKME;         /* 0x110: Others CLK manual enable */
  __IO uint32_t OCLKMD;         /* 0x114: Others CLK manual disable */
  __IO uint32_t HCLKRS;         /* 0x118: HCLK soft resetn set register */
  __IO uint32_t HCLKRC;         /* 0x11C: HCLK soft resetn clear register */
  __IO uint32_t PCLKRS;         /* 0x120: PCLK soft resetn set register */
  __IO uint32_t PCLKRC;         /* 0x124: PCLK soft resetn clear register */
  __IO uint32_t OCLKRS;         /* 0x128: Others CLK soft resetn set register */
  __IO uint32_t OCLKRC;         /* 0x12C: Others CLK soft resetn clear register */
  __IO uint32_t HCLK1ME;        /* 0x130: HCLK1 manual enable */
  __IO uint32_t HCLK1MD;        /* 0x134: HCLK1 manual disable */
  __IO uint32_t HCLK1RS;        /* 0x138: HCLK1 soft resetn set register */
  __IO uint32_t HCLK1RC;        /* 0x13C: HCLK1 soft resetn clear register */
} AIC_CPUSYSCTRL_TypeDef;

/* ================================================================================ */
/* ================                AON System Control              ================ */
/* ================================================================================ */
typedef struct {
  __I  uint32_t CHIPID;         /* 0x000: Chip ID */
  __IO uint32_t CLKSEL;         /* 0x004: Clock selection */
  __IO uint32_t HCLKCM;         /* 0x008: HCLK control mode */
  __IO uint32_t FCLKCM;         /* 0x00C: FCLK control mode */
  __IO uint32_t OCLKCM;         /* 0x010: Others CLK control mode */
  __IO uint32_t HCLKDIV;        /* 0x014: HCLK div */
  __IO uint32_t FCLKDIV;        /* 0x018: FCLK div */
  __IO uint32_t AONSRAMCFG0;    /* 0x01C: AON SRAM0 config */
  __I  uint32_t RSTCAUSE;       /* 0x020: Reset cause */
  __IO uint32_t SYSTPSEL;       /* 0x024: AON system tports selection */
  __IO uint32_t TOPTPSEL;       /* 0x028: digital top tports selection */
  __IO uint32_t PSRCLKDIV;      /* 0x02C: PSRAM clock div */
  __IO uint32_t PSRCLKSEL;      /* 0x030: PSRAM clock selection */
  __IO uint32_t R480MCLKDIV;    /* 0x034: Real 480M CLK div */
  __IO uint32_t R320MCLKDIV;    /* 0x038: Real 320M CLK div */
  __IO uint32_t CPUSWRA;        /* 0x03C: CPU sw reset address */
  __IO uint32_t DSPRA;          /* 0x040: DSP reset address */
  __IO uint32_t AONSRAMCFG1;    /* 0x044: AON SRAM1 config */
  __IO uint32_t AONSRAMCFG2;    /* 0x048: AON SRAM2 config */
  __IO uint32_t SRAMSDCFG;      /* 0x04C: SRAM SD config */
  __IO uint32_t AONCLKDIV;      /* 0x050: AON clock div */
  __IO uint32_t AONRAMMUX;      /* 0x054: AON RAM mux */
  __IO uint32_t CPUSBRA;        /* 0x058: CPU sb reset address */
  __IO uint32_t CPUAONRA;       /* 0x05C: CPU AON reset address */
  __IO uint32_t AONROMCFG;      /* 0x060: AON ROM config */
  __IO uint32_t AONTRAPC;       /* 0x064: AON TRAP control */
  __IO uint32_t AONTRAPI[2];    /* 0x068: AON TRAP in 0~1, 2~3 */
  __IO uint32_t AONTRAPOB;      /* 0x070: AON TRAP out base */
  __IO uint32_t OSCEN;          /* 0x074: OSC enable */
  __IO uint32_t RESERVED0[34];  /* 0x078: Reserved */
  __IO uint32_t HCLKME;         /* 0x100: HCLK manual enable */
  __IO uint32_t HCLKMD;         /* 0x104: HCLK manual disable */
  __IO uint32_t FCLKME;         /* 0x108: FCLK manual enable */
  __IO uint32_t FCLKMD;         /* 0x10C: FCLK manual disable */
  __IO uint32_t OCLKME;         /* 0x110: Others CLK manual enable */
  __IO uint32_t OCLKMD;         /* 0x114: Others CLK manual disable */
  __IO uint32_t GLBRS;          /* 0x118: Global soft resetn set register */
  __IO uint32_t GLBRC;          /* 0x11C: Global soft resetn clear register */
  __IO uint32_t HCLKRS;         /* 0x120: HCLK soft resetn set register */
  __IO uint32_t HCLKRC;         /* 0x124: HCLK soft resetn clear register */
  __IO uint32_t FCLKRS;         /* 0x128: FCLK soft resetn set register */
  __IO uint32_t FCLKRC;         /* 0x12C: FCLK soft resetn clear register */
  __IO uint32_t OCLKRS;         /* 0x130: Others CLK soft resetn set register */
  __IO uint32_t OCLKRC;         /* 0x134: Others CLK soft resetn clear register */
  __IO uint32_t BOOTMD;         /* 0x138: Boot mode */
  __IO uint32_t WDTRE;          /* 0x13C: Watch dog timer reset enable */
  union {
    __IO uint32_t AONCOMREG[8]; /* 0x140~0x15C: Aon common regs, sw defined below */
    struct {
      __IO uint32_t BTFWCTRL;   /* 0x140: Bt fw stack top & bt_core sw ctrl mode */
      __IO uint32_t WIFIFWCTRL; /* 0x144: Wifi fw stack top & wifi_core sw ctrl mode */
      __IO uint32_t BOOTENTRY;  /* 0x148: Boot entry */
      __IO uint32_t BOOTSTACK;  /* 0x14C: Boot stack */
      __IO uint32_t HOSTTCLSB;  /* 0x150: Host time count lsb */
      __IO uint32_t HOSTTCMSB;  /* 0x154: Host time count msb */
      __IO uint32_t HOSTSYST;   /* 0x158: Host systick */
      __IO uint32_t BTPWRCTRL;  /* 0x15C: BT power control */
    };
  };
} AIC_AONSYSCTRL_TypeDef;

/* ================================================================================ */
/* ================                  Power Control                 ================ */
/* ================================================================================ */
typedef struct {
  __IO uint32_t CPUSYS;         /* 0x000: CPU system */
  __IO uint32_t BTCORE;         /* 0x004: BT core */
  __IO uint32_t WIFICORE;       /* 0x008: WIFI core */
  __IO uint32_t RESERVED0;      /* 0x00C: Reserved */
  __IO uint32_t PWRSYS;         /* 0x010: Power system */
  __IO uint32_t OFFTIMTH[2];    /* 0x014: Power off timer th 0 ~ 1 */
  __IO uint32_t CTRLDLY[2];     /* 0x01C: Power control delay 0 ~ 1 */
  __IO uint32_t SYSDLY[2];      /* 0x024: Power system delay 0 ~ 1 */
  __IO uint32_t RESERVED1;      /* 0x02C: Reserved */
  __I  uint32_t STATE[2];       /* 0x030: State 0 ~ 1 */
  __IO uint32_t SOFTMD1;        /* 0x038: Soft mode 1 */
  __IO uint32_t AONRAM1;        /* 0x03C: Aon RAM1 */
  __IO uint32_t AONRAM2;        /* 0x040: Aon RAM2 */
  __IO uint32_t IRQCTRL;        /* 0x044: IRQ control */
  __IO uint32_t IRQSTATUS;      /* 0x048: IRQ status */
  __IO uint32_t MMSYS;          /* 0x04C: Memory system */
  __IO uint32_t SOFTMD2;        /* 0x050: Soft mode 2 */
  __IO uint32_t VCORESYS;       /* 0x054: vcore system */
  __IO uint32_t OFFTIMTH3;      /* 0x058: Power off timer th 3 */
  __IO uint32_t PWRMD;          /* 0x05C: Power mode */
} AIC_PWRCTRL_TypeDef;

static AIC_CPUSYSCTRL_TypeDef * const AIC_CPUSYSCTRL = ((AIC_CPUSYSCTRL_TypeDef *)AIC_CPUSYSCTRL_BASE);
static AIC_AONSYSCTRL_TypeDef * const AIC_AONSYSCTRL = ((AIC_AONSYSCTRL_TypeDef *)AIC_AONSYSCTRL_BASE);
static AIC_PWRCTRL_TypeDef    * const AIC_PWRCTRL    = ((AIC_PWRCTRL_TypeDef    *)AIC_PWRCTRL_BASE);

/**
 * Address Offset: 0x000
 * Register Name : ASC CHIPID
 */

#define ASC_CHIPID_CHIP_ID_LSB          (0)
#define ASC_CHIPID_CHIP_ID_WIDTH        (16)
#define ASC_CHIPID_CHIP_ID_MASK         (((0x01UL << ASC_CHIPID_CHIP_ID_WIDTH) - 1) << ASC_CHIPID_CHIP_ID_LSB)
#define ASC_CHIPID_METAL_ID_LSB         (16)
#define ASC_CHIPID_METAL_ID_WIDTH       (8)
#define ASC_CHIPID_METAL_ID_MASK        (((0x01UL << ASC_CHIPID_METAL_ID_WIDTH) - 1) << ASC_CHIPID_METAL_ID_LSB)
#define ASC_CHIPID_BOND_ID_LSB          (24)
#define ASC_CHIPID_BOND_ID_WIDTH        (8)
#define ASC_CHIPID_BOND_ID_MASK         (((0x01UL << ASC_CHIPID_BOND_ID_WIDTH) - 1) << ASC_CHIPID_BOND_ID_LSB)

__STATIC_INLINE uint16_t aonsysctrl_chipid_chip_id_getf(void)
{
    return ((AIC_AONSYSCTRL->CHIPID & ASC_CHIPID_CHIP_ID_MASK) >> ASC_CHIPID_CHIP_ID_LSB);
}

__STATIC_INLINE uint8_t aonsysctrl_chipid_metal_id_getf(void)
{
    return ((AIC_AONSYSCTRL->CHIPID & ASC_CHIPID_METAL_ID_MASK) >> ASC_CHIPID_METAL_ID_LSB);
}

__STATIC_INLINE uint8_t aonsysctrl_chipid_bond_id_getf(void)
{
    return ((AIC_AONSYSCTRL->CHIPID & ASC_CHIPID_BOND_ID_MASK) >> ASC_CHIPID_BOND_ID_LSB);
}

/**
 * Address Offset: 0x004
 * Register Name : ASC CLKSEL
 */

#define ASC_CLKSEL_FASTHWEN_POS         (0)
#define ASC_CLKSEL_FASTHWEN_BIT         (0x01UL << ASC_CLKSEL_FASTHWEN_POS)
#define ASC_CLKSEL_FASTCLK_POS          (4)
#define ASC_CLKSEL_FASTCLK_BIT          (0x01UL << ASC_CLKSEL_FASTCLK_POS)
#define ASC_CLKSEL_PLL320M_POS          (8)
#define ASC_CLKSEL_PLL320M_BIT          (0x01UL << ASC_CLKSEL_PLL320M_POS)
#define ASC_CLKSEL_PLLFLEX_POS          (12)
#define ASC_CLKSEL_PLLFLEX_BIT          (0x01UL << ASC_CLKSEL_PLLFLEX_POS)
#define ASC_CLKSEL_AONCLK_POS           (16)
#define ASC_CLKSEL_AONCLK_BIT           (0x01UL << ASC_CLKSEL_AONCLK_POS)

__STATIC_INLINE uint32_t aonsysctrl_clksel_get(void)
{
    return AIC_AONSYSCTRL->CLKSEL;
}

__STATIC_INLINE void aonsysctrl_clksel_set(uint32_t clk_sel)
{
    AIC_AONSYSCTRL->CLKSEL = clk_sel;
}

__STATIC_INLINE uint8_t aonsysctrl_fast_hwen_getb(void)
{
    return (AIC_AONSYSCTRL->CLKSEL & ASC_CLKSEL_FASTHWEN_BIT) >> ASC_CLKSEL_FASTHWEN_POS;
}

__STATIC_INLINE void aonsysctrl_fast_hwen_setb(void)
{
    AIC_AONSYSCTRL->CLKSEL |=  ASC_CLKSEL_FASTHWEN_BIT;
}

__STATIC_INLINE void aonsysctrl_fast_hwen_clrb(void)
{
    AIC_AONSYSCTRL->CLKSEL &= ~ASC_CLKSEL_FASTHWEN_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_fast_clk_getb(void)
{
    return (AIC_AONSYSCTRL->CLKSEL & ASC_CLKSEL_FASTCLK_BIT) >> ASC_CLKSEL_FASTCLK_POS;
}

__STATIC_INLINE void aonsysctrl_fast_clk_setb(void)
{
    AIC_AONSYSCTRL->CLKSEL |=  ASC_CLKSEL_FASTCLK_BIT;
}

__STATIC_INLINE void aonsysctrl_fast_clk_clrb(void)
{
    AIC_AONSYSCTRL->CLKSEL &= ~ASC_CLKSEL_FASTCLK_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_pll_320m_getb(void)
{
    return (AIC_AONSYSCTRL->CLKSEL & ASC_CLKSEL_PLL320M_BIT) >> ASC_CLKSEL_PLL320M_POS;
}

__STATIC_INLINE void aonsysctrl_pll_320m_setb(void)
{
    AIC_AONSYSCTRL->CLKSEL |=  ASC_CLKSEL_PLL320M_BIT;
}

__STATIC_INLINE void aonsysctrl_pll_320m_clrb(void)
{
    AIC_AONSYSCTRL->CLKSEL &= ~ASC_CLKSEL_PLL320M_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_pll_flex_getb(void)
{
    return (AIC_AONSYSCTRL->CLKSEL & ASC_CLKSEL_PLLFLEX_BIT) >> ASC_CLKSEL_PLLFLEX_POS;
}

__STATIC_INLINE void aonsysctrl_pll_flex_setb(void)
{
    AIC_AONSYSCTRL->CLKSEL |=  ASC_CLKSEL_PLLFLEX_BIT;
}

__STATIC_INLINE void aonsysctrl_pll_flex_clrb(void)
{
    AIC_AONSYSCTRL->CLKSEL &= ~ASC_CLKSEL_PLLFLEX_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_aon_clk_getb(void)
{
    return (AIC_AONSYSCTRL->CLKSEL & ASC_CLKSEL_AONCLK_BIT) >> ASC_CLKSEL_AONCLK_POS;
}

__STATIC_INLINE void aonsysctrl_aon_clk_setb(void)
{
    AIC_AONSYSCTRL->CLKSEL |=  ASC_CLKSEL_AONCLK_BIT;
}

__STATIC_INLINE void aonsysctrl_aon_clk_clrb(void)
{
    AIC_AONSYSCTRL->CLKSEL &= ~ASC_CLKSEL_AONCLK_BIT;
}

/**
 * Address Offset: 0x010
 * Register Name : ASC OCLK_CTRL_MODE
 */

#define ASC_OCLKCM_CLK26M_AONSYS_MANUAL_POS         (0)
#define ASC_OCLKCM_CLK26M_AONSYS_MANUAL_BIT         (0x01UL << ASC_OCLKCM_CLK26M_AONSYS_MANUAL_POS)
#define ASC_OCLKCM_CLK26M_CPUSYS_MANUAL_POS         (1)
#define ASC_OCLKCM_CLK26M_CPUSYS_MANUAL_BIT         (0x01UL << ASC_OCLKCM_CLK26M_CPUSYS_MANUAL_POS)
#define ASC_OCLKCM_CLK26M_TIMER20_MANUAL_POS        (2)
#define ASC_OCLKCM_CLK26M_TIMER20_MANUAL_BIT        (0x01UL << ASC_OCLKCM_CLK26M_TIMER20_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_TIMER21_MANUAL_POS        (3)
#define ASC_OCLKCM_CLK32K_TIMER21_MANUAL_BIT        (0x01UL << ASC_OCLKCM_CLK32K_TIMER21_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_TIMER22_MANUAL_POS        (4)
#define ASC_OCLKCM_CLK32K_TIMER22_MANUAL_BIT        (0x01UL << ASC_OCLKCM_CLK32K_TIMER22_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_AONSYS_MANUAL_POS         (5)
#define ASC_OCLKCM_CLK32K_AONSYS_MANUAL_BIT         (0x01UL << ASC_OCLKCM_CLK32K_AONSYS_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_CPUSYS_MANUAL_POS         (6)
#define ASC_OCLKCM_CLK32K_CPUSYS_MANUAL_BIT         (0x01UL << ASC_OCLKCM_CLK32K_CPUSYS_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_WIFISYS_MANUAL_POS        (7)
#define ASC_OCLKCM_CLK32K_WIFISYS_MANUAL_BIT        (0x01UL << ASC_OCLKCM_CLK32K_WIFISYS_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_BTSYS_MANUAL_POS          (8)
#define ASC_OCLKCM_CLK32K_BTSYS_MANUAL_BIT          (0x01UL << ASC_OCLKCM_CLK32K_BTSYS_MANUAL_POS)
#define ASC_OCLKCM_CLK_I2CS_MANUAL_POS              (9)
#define ASC_OCLKCM_CLK_I2CS_MANUAL_BIT              (0x01UL << ASC_OCLKCM_CLK_I2CS_MANUAL_POS)
#define ASC_OCLKCM_CLK_MEM2X_MANUAL_POS             (10)
#define ASC_OCLKCM_CLK_MEM2X_MANUAL_BIT             (0x01UL << ASC_OCLKCM_CLK_MEM2X_MANUAL_POS)
#define ASC_OCLKCM_CLK_EFUSE_MANUAL_POS             (11)
#define ASC_OCLKCM_CLK_EFUSE_MANUAL_BIT             (0x01UL << ASC_OCLKCM_CLK_EFUSE_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_WIFIAON_MANUAL_POS        (12)
#define ASC_OCLKCM_CLK32K_WIFIAON_MANUAL_BIT        (0x01UL << ASC_OCLKCM_CLK32K_WIFIAON_MANUAL_POS)
#define ASC_OCLKCM_CLK32K_BTAON_MANUAL_POS          (13)
#define ASC_OCLKCM_CLK32K_BTAON_MANUAL_BIT          (0x01UL << ASC_OCLKCM_CLK32K_BTAON_MANUAL_POS)
#define ASC_OCLKCM_CLK52M_CPUSYS_MANUAL_POS         (14)
#define ASC_OCLKCM_CLK52M_CPUSYS_MANUAL_BIT         (0x01UL << ASC_OCLKCM_CLK52M_CPUSYS_MANUAL_POS)
#define ASC_OCLKCM_HCLK_AONROM_MANUAL_POS           (15)
#define ASC_OCLKCM_HCLK_AONROM_MANUAL_BIT           (0x01UL << ASC_OCLKCM_HCLK_AONROM_MANUAL_POS)
#define ASC_OCLKCM_HCLK_APB1_MANUAL_POS             (16)
#define ASC_OCLKCM_HCLK_APB1_MANUAL_BIT             (0x01UL << ASC_OCLKCM_HCLK_APB1_MANUAL_POS)
#define ASC_OCLKCM_HCLK_I2CS_MANUAL_POS             (17)
#define ASC_OCLKCM_HCLK_I2CS_MANUAL_BIT             (0x01UL << ASC_OCLKCM_HCLK_I2CS_MANUAL_POS)
#define ASC_OCLKCM_PCLK_SYSCTRL_MANUAL_POS          (18)
#define ASC_OCLKCM_PCLK_SYSCTRL_MANUAL_BIT          (0x01UL << ASC_OCLKCM_PCLK_SYSCTRL_MANUAL_POS)
#define ASC_OCLKCM_PCLK_PWRCTRL_MANUAL_POS          (19)
#define ASC_OCLKCM_PCLK_PWRCTRL_MANUAL_BIT          (0x01UL << ASC_OCLKCM_PCLK_PWRCTRL_MANUAL_POS)
#define ASC_OCLKCM_PCLK_GPIO_MANUAL_POS             (20)
#define ASC_OCLKCM_PCLK_GPIO_MANUAL_BIT             (0x01UL << ASC_OCLKCM_PCLK_GPIO_MANUAL_POS)
#define ASC_OCLKCM_PCLK_TIMER2_MANUAL_POS           (21)
#define ASC_OCLKCM_PCLK_TIMER2_MANUAL_BIT           (0x01UL << ASC_OCLKCM_PCLK_TIMER2_MANUAL_POS)
#define ASC_OCLKCM_PCLK_IOMUX_MANUAL_POS            (22)
#define ASC_OCLKCM_PCLK_IOMUX_MANUAL_BIT            (0x01UL << ASC_OCLKCM_PCLK_IOMUX_MANUAL_POS)
#define ASC_OCLKCM_PCLK_EFUSE_MANUAL_POS            (23)
#define ASC_OCLKCM_PCLK_EFUSE_MANUAL_BIT            (0x01UL << ASC_OCLKCM_PCLK_EFUSE_MANUAL_POS)
#define ASC_OCLKCM_HCLK_ALWAYS_CPUAON_MANUAL_POS    (24)
#define ASC_OCLKCM_HCLK_ALWAYS_CPUAON_MANUAL_BIT    (0x01UL << ASC_OCLKCM_HCLK_ALWAYS_CPUAON_MANUAL_POS)
#define ASC_OCLKCM_HCLK_CPUAON_MANUAL_POS           (25)
#define ASC_OCLKCM_HCLK_CPUAON_MANUAL_BIT           (0x01UL << ASC_OCLKCM_HCLK_CPUAON_MANUAL_POS)
#define ASC_OCLKCM_HCLK_AONSRAM_MANUAL_POS          (26)
#define ASC_OCLKCM_HCLK_AONSRAM_MANUAL_BIT          (0x01UL << ASC_OCLKCM_HCLK_AONSRAM_MANUAL_POS)
#define ASC_OCLKCM_PCLK_WDG4_MANUAL_POS             (27)
#define ASC_OCLKCM_PCLK_WDG4_MANUAL_BIT             (0x01UL << ASC_OCLKCM_PCLK_WDG4_MANUAL_POS)
#define ASC_OCLKCM_PCLK_PSIM_MANUAL_POS             (28)
#define ASC_OCLKCM_PCLK_PSIM_MANUAL_BIT             (0x01UL << ASC_OCLKCM_PCLK_PSIM_MANUAL_POS)
#define ASC_OCLKCM_PCLK_ANAREG_MANUAL_POS           (29)
#define ASC_OCLKCM_PCLK_ANAREG_MANUAL_BIT           (0x01UL << ASC_OCLKCM_PCLK_ANAREG_MANUAL_POS)
#define ASC_OCLKCM_CLKRTC_WDG4_MANUAL_POS           (30)
#define ASC_OCLKCM_CLKRTC_WDG4_MANUAL_BIT           (0x01UL << ASC_OCLKCM_CLKRTC_WDG4_MANUAL_POS)
#define ASC_OCLKCM_HCLK_WCNAON_MANUAL_POS           (31)
#define ASC_OCLKCM_HCLK_WCNAON_MANUAL_BIT           (0x01UL << ASC_OCLKCM_HCLK_WCNAON_MANUAL_POS)

__STATIC_INLINE uint32_t aonsysctrl_oclkcm_get(void)
{
    return AIC_AONSYSCTRL->OCLKCM;
}

__STATIC_INLINE void aonsysctrl_oclkcm_set(uint32_t manual_mode)
{
    AIC_AONSYSCTRL->OCLKCM = manual_mode;
}

/**
 * Address Offset: 0x014
 * Register Name : ASC HCLK_DIV
 */

#define ASC_HCLKDIV_DENOM_LSB           (0)
#define ASC_HCLKDIV_DENOM_WIDTH         (8)
#define ASC_HCLKDIV_DENOM_MASK          (((0x01UL << ASC_HCLKDIV_DENOM_WIDTH) - 1) << ASC_HCLKDIV_DENOM_LSB)
#define ASC_HCLKDIV_UPDATE_POS          (8)
#define ASC_HCLKDIV_UPDATE_BIT          (0x01UL << ASC_HCLKDIV_UPDATE_POS)

__STATIC_INLINE uint8_t aonsysctrl_hclkdiv_denom_getf(void)
{
    return ((AIC_AONSYSCTRL->HCLKDIV & ASC_HCLKDIV_DENOM_MASK) >> ASC_HCLKDIV_DENOM_LSB);
}

__STATIC_INLINE void aonsysctrl_hclkdiv_denom_setf(uint8_t div_denom)
{
    uint32_t local_val = AIC_AONSYSCTRL->HCLKDIV & ~ASC_HCLKDIV_DENOM_MASK;
    AIC_AONSYSCTRL->HCLKDIV = local_val | ((div_denom << ASC_HCLKDIV_DENOM_LSB) & ASC_HCLKDIV_DENOM_MASK) | ASC_HCLKDIV_UPDATE_BIT;
}

/**
 * Address Offset: 0x018
 * Register Name : ASC FCLK_DIV
 */

#define ASC_FCLKDIV_DENOM_LSB           (0)
#define ASC_FCLKDIV_DENOM_WIDTH         (8)
#define ASC_FCLKDIV_DENOM_MASK          (((0x01UL << ASC_FCLKDIV_DENOM_WIDTH) - 1) << ASC_FCLKDIV_DENOM_LSB)
#define ASC_FCLKDIV_UPDATE_POS          (8)
#define ASC_FCLKDIV_UPDATE_BIT          (0x01UL << ASC_FCLKDIV_UPDATE_POS)

__STATIC_INLINE uint8_t aonsysctrl_fclkdiv_denom_getf(void)
{
    return ((AIC_AONSYSCTRL->FCLKDIV & ASC_FCLKDIV_DENOM_MASK) >> ASC_FCLKDIV_DENOM_LSB);
}

__STATIC_INLINE void aonsysctrl_fclkdiv_denom_setf(uint8_t div_denom)
{
    uint32_t local_val = AIC_AONSYSCTRL->FCLKDIV & ~ASC_FCLKDIV_DENOM_MASK;
    AIC_AONSYSCTRL->FCLKDIV = local_val | ((div_denom << ASC_FCLKDIV_DENOM_LSB) & ASC_FCLKDIV_DENOM_MASK) | ASC_FCLKDIV_UPDATE_BIT;
}

/**
 * Address Offset: 0x020
 * Register Name : ASC RESET_CAUSE
 */

#define ASC_RSTCAUSE_WDT0_RST_POS           (0)
#define ASC_RSTCAUSE_WDT0_RST_BIT           (0x01UL << ASC_RSTCAUSE_WDT0_RST_POS)
#define ASC_RSTCAUSE_WDT1_RST_POS           (1)
#define ASC_RSTCAUSE_WDT1_RST_BIT           (0x01UL << ASC_RSTCAUSE_WDT1_RST_POS)
#define ASC_RSTCAUSE_WDT2_RST_POS           (2)
#define ASC_RSTCAUSE_WDT2_RST_BIT           (0x01UL << ASC_RSTCAUSE_WDT2_RST_POS)
#define ASC_RSTCAUSE_WDT3_RST_POS           (3)
#define ASC_RSTCAUSE_WDT3_RST_BIT           (0x01UL << ASC_RSTCAUSE_WDT3_RST_POS)
#define ASC_RSTCAUSE_WDT4_RST_POS           (4)
#define ASC_RSTCAUSE_WDT4_RST_BIT           (0x01UL << ASC_RSTCAUSE_WDT4_RST_POS)
#define ASC_RSTCAUSE_CPUP_SYSRST_REQ_POS    (5)
#define ASC_RSTCAUSE_CPUP_SYSRST_REQ_BIT    (0x01UL << ASC_RSTCAUSE_CPUP_SYSRST_REQ_POS)
#define ASC_RSTCAUSE_CPUSW_SYSRST_REQ_POS   (6)
#define ASC_RSTCAUSE_CPUSW_SYSRST_REQ_BIT   (0x01UL << ASC_RSTCAUSE_CPUSW_SYSRST_REQ_POS)
#define ASC_RSTCAUSE_DSP_SYSRST_REQ_POS     (7)
#define ASC_RSTCAUSE_DSP_SYSRST_REQ_BIT     (0x01UL << ASC_RSTCAUSE_DSP_SYSRST_REQ_POS)
#define ASC_RSTCAUSE_CPUSB_SYSRST_REQ_POS   (8)
#define ASC_RSTCAUSE_CPUSB_SYSRST_REQ_BIT   (0x01UL << ASC_RSTCAUSE_CPUSB_SYSRST_REQ_POS)
#define ASC_RSTCAUSE_CPUAON_SYSRST_REQ_POS  (9)
#define ASC_RSTCAUSE_CPUAON_SYSRST_REQ_BIT  (0x01UL << ASC_RSTCAUSE_CPUAON_SYSRST_REQ_POS)
#define ASC_RSTCAUSE_GLOBAL_SOFT_RESET_POS  (10)
#define ASC_RSTCAUSE_GLOBAL_SOFT_RESET_BIT  (0x01UL << ASC_RSTCAUSE_GLOBAL_SOFT_RESET_POS)

__STATIC_INLINE uint32_t aonsysctrl_rstcause_get(void)
{
    return AIC_AONSYSCTRL->RSTCAUSE;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_wdt0_rst_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_WDT0_RST_BIT) >> ASC_RSTCAUSE_WDT0_RST_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_wdt1_rst_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_WDT1_RST_BIT) >> ASC_RSTCAUSE_WDT1_RST_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_wdt2_rst_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_WDT2_RST_BIT) >> ASC_RSTCAUSE_WDT2_RST_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_wdt3_rst_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_WDT3_RST_BIT) >> ASC_RSTCAUSE_WDT3_RST_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_wdt4_rst_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_WDT4_RST_BIT) >> ASC_RSTCAUSE_WDT4_RST_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_cpup_sysrst_req_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_CPUP_SYSRST_REQ_BIT) >> ASC_RSTCAUSE_CPUP_SYSRST_REQ_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_cpusw_sysrst_req_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_CPUSW_SYSRST_REQ_BIT) >> ASC_RSTCAUSE_CPUSW_SYSRST_REQ_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_dsp_sysrst_req_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_DSP_SYSRST_REQ_BIT) >> ASC_RSTCAUSE_DSP_SYSRST_REQ_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_cpusb_sysrst_req_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_CPUSB_SYSRST_REQ_BIT) >> ASC_RSTCAUSE_CPUSB_SYSRST_REQ_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_cpuaon_sysrst_req_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_CPUAON_SYSRST_REQ_BIT) >> ASC_RSTCAUSE_CPUAON_SYSRST_REQ_POS;
}

__STATIC_INLINE uint8_t aonsysctrl_rstcause_global_soft_reset_getb(void)
{
    return (AIC_AONSYSCTRL->RSTCAUSE & ASC_RSTCAUSE_GLOBAL_SOFT_RESET_BIT) >> ASC_RSTCAUSE_GLOBAL_SOFT_RESET_POS;
}

/**
 * Address Offset: 0x02C
 * Register Name : ASC PSRAM_CLK_DIV
 */

#define ASC_PSRCLKDIV_DENOM_LSB         (0)
#define ASC_PSRCLKDIV_DENOM_WIDTH       (8)
#define ASC_PSRCLKDIV_DENOM_MASK        (((0x01UL << ASC_PSRCLKDIV_DENOM_WIDTH) - 1) << ASC_PSRCLKDIV_DENOM_LSB)
#define ASC_PSRCLKDIV_UPDATE_POS        (8)
#define ASC_PSRCLKDIV_UPDATE_BIT        (0x01UL << ASC_PSRCLKDIV_UPDATE_POS)

__STATIC_INLINE uint8_t aonsysctrl_psrclkdiv_denom_getf(void)
{
    return ((AIC_AONSYSCTRL->PSRCLKDIV & ASC_PSRCLKDIV_DENOM_MASK) >> ASC_PSRCLKDIV_DENOM_LSB);
}

__STATIC_INLINE void aonsysctrl_psrclkdiv_denom_setf(uint8_t div_denom)
{
    uint32_t local_val = AIC_AONSYSCTRL->PSRCLKDIV & ~ASC_PSRCLKDIV_DENOM_MASK;
    AIC_AONSYSCTRL->PSRCLKDIV = local_val | ((div_denom << ASC_PSRCLKDIV_DENOM_LSB) & ASC_PSRCLKDIV_DENOM_MASK) | ASC_PSRCLKDIV_UPDATE_BIT;
}

/**
 * Address Offset: 0x030
 * Register Name : ASC PSRAM_CLK_SEL
 */

#define ASC_PSRCLKSEL_FAST_POS          (0)
#define ASC_PSRCLKSEL_FAST_BIT          (0x01UL << ASC_PSRCLKSEL_FAST_POS)

__STATIC_INLINE uint8_t aonsysctrl_psrclksel_fast_getb(void)
{
    return (AIC_AONSYSCTRL->PSRCLKSEL & ASC_PSRCLKSEL_FAST_BIT) >> ASC_PSRCLKSEL_FAST_POS;
}

__STATIC_INLINE void aonsysctrl_psrclksel_fast_setb(void)
{
    AIC_AONSYSCTRL->PSRCLKSEL |=  ASC_PSRCLKSEL_FAST_BIT;
}

__STATIC_INLINE void aonsysctrl_psrclksel_fast_clrb(void)
{
    AIC_AONSYSCTRL->PSRCLKSEL &= ~ASC_PSRCLKSEL_FAST_BIT;
}

/**
 * Address Offset: 0x03C
 * Register Name : ASC CPU_SW_RESET_ADDR
 */

__STATIC_INLINE uint32_t aonsysctrl_cpuswra_get(void)
{
    return AIC_AONSYSCTRL->CPUSWRA;
}

__STATIC_INLINE void aonsysctrl_cpuswra_set(uint32_t reset_addr)
{
    AIC_AONSYSCTRL->CPUSWRA = reset_addr;
}

/**
 * Address Offset: 0x040
 * Register Name : ASC DSP_RESET_ADDR
 */

__STATIC_INLINE uint32_t aonsysctrl_dspra_get(void)
{
    return AIC_AONSYSCTRL->DSPRA;
}

__STATIC_INLINE void aonsysctrl_dspra_set(uint32_t reset_addr)
{
    AIC_AONSYSCTRL->DSPRA = reset_addr;
}

/**
 * Address Offset: 0x044
 * Register Name : ASC AON_SRAM1_CONFIG
 */

__STATIC_INLINE uint32_t aonsysctrl_aonsramcfg1_get(void)
{
    return AIC_AONSYSCTRL->AONSRAMCFG1;
}

__STATIC_INLINE void aonsysctrl_aonsramcfg1_set(uint32_t config)
{
    AIC_AONSYSCTRL->AONSRAMCFG1 = config;
}

/**
 * Address Offset: 0x048
 * Register Name : ASC AON_SRAM2_CONFIG
 */

__STATIC_INLINE uint32_t aonsysctrl_aonsramcfg2_get(void)
{
    return AIC_AONSYSCTRL->AONSRAMCFG2;
}

__STATIC_INLINE void aonsysctrl_aonsramcfg2_set(uint32_t config)
{
    AIC_AONSYSCTRL->AONSRAMCFG2 = config;
}

/**
 * Address Offset: 0x04C
 * Register Name : ASC SRAM_SD_CONFIG
 */

#define ASC_SRAMSDCFG_SRAM0_POS         (0)
#define ASC_SRAMSDCFG_SRAM0_BIT         (0x01UL << ASC_SRAMSDCFG_SRAM0_POS)
#define ASC_SRAMSDCFG_SRAM1_POS         (1)
#define ASC_SRAMSDCFG_SRAM1_BIT         (0x01UL << ASC_SRAMSDCFG_SRAM1_POS)
#define ASC_SRAMSDCFG_SRAM2_POS         (2)
#define ASC_SRAMSDCFG_SRAM2_BIT         (0x01UL << ASC_SRAMSDCFG_SRAM2_POS)
#define ASC_SRAMSDCFG_SRAM3_POS         (3)
#define ASC_SRAMSDCFG_SRAM3_BIT         (0x01UL << ASC_SRAMSDCFG_SRAM3_POS)
#define ASC_SRAMSDCFG_SRAM4_POS         (4)
#define ASC_SRAMSDCFG_SRAM4_BIT         (0x01UL << ASC_SRAMSDCFG_SRAM4_POS)
#define ASC_SRAMSDCFG_SRAM5_POS         (5)
#define ASC_SRAMSDCFG_SRAM5_BIT         (0x01UL << ASC_SRAMSDCFG_SRAM5_POS)
#define ASC_SRAMSDCFG_SRAM6_POS         (6)
#define ASC_SRAMSDCFG_SRAM6_BIT         (0x01UL << ASC_SRAMSDCFG_SRAM6_POS)
#define ASC_SRAMSDCFG_ROM0_POS          (7)
#define ASC_SRAMSDCFG_ROM0_BIT          (0x01UL << ASC_SRAMSDCFG_ROM0_POS)
#define ASC_SRAMSDCFG_ROM1_POS          (8)
#define ASC_SRAMSDCFG_ROM1_BIT          (0x01UL << ASC_SRAMSDCFG_ROM1_POS)
#define ASC_SRAMSDCFG_ROM2_POS          (9)
#define ASC_SRAMSDCFG_ROM2_BIT          (0x01UL << ASC_SRAMSDCFG_ROM2_POS)
#define ASC_SRAMSDCFG_BTROM0_POS        (10)
#define ASC_SRAMSDCFG_BTROM0_BIT        (0x01UL << ASC_SRAMSDCFG_BTROM0_POS)
#define ASC_SRAMSDCFG_BTROM1_POS        (11)
#define ASC_SRAMSDCFG_BTROM1_BIT        (0x01UL << ASC_SRAMSDCFG_BTROM1_POS)
#define ASC_SRAMSDCFG_BTROM2_POS        (12)
#define ASC_SRAMSDCFG_BTROM2_BIT        (0x01UL << ASC_SRAMSDCFG_BTROM2_POS)

__STATIC_INLINE uint32_t aonsysctrl_sramsdcfg_get(void)
{
    return AIC_AONSYSCTRL->SRAMSDCFG;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_set(uint32_t config)
{
    AIC_AONSYSCTRL->SRAMSDCFG = config;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_sram0_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_SRAM0_BIT) >> ASC_SRAMSDCFG_SRAM0_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram0_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_SRAM0_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram0_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_SRAM0_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_sram1_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_SRAM1_BIT) >> ASC_SRAMSDCFG_SRAM1_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram1_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_SRAM1_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram1_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_SRAM1_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_sram2_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_SRAM2_BIT) >> ASC_SRAMSDCFG_SRAM2_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram2_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_SRAM2_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram2_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_SRAM2_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_sram3_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_SRAM3_BIT) >> ASC_SRAMSDCFG_SRAM3_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram3_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_SRAM3_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_SRAM3_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_SRAM3_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_sram4_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_SRAM4_BIT) >> ASC_SRAMSDCFG_SRAM4_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram4_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_SRAM4_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram4_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_SRAM4_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_sram5_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_SRAM5_BIT) >> ASC_SRAMSDCFG_SRAM5_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram5_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_SRAM5_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram5_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_SRAM5_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_sram6_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_SRAM6_BIT) >> ASC_SRAMSDCFG_SRAM6_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram6_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_SRAM6_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_sram6_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_SRAM6_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_rom0_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_ROM0_BIT) >> ASC_SRAMSDCFG_ROM0_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_rom0_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_ROM0_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_rom0_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_ROM0_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_rom1_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_ROM1_BIT) >> ASC_SRAMSDCFG_ROM1_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_rom1_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_ROM1_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_rom1_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_ROM1_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_rom2_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_ROM2_BIT) >> ASC_SRAMSDCFG_ROM2_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_rom2_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_ROM2_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_rom2_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_ROM2_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_btrom0_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_BTROM0_BIT) >> ASC_SRAMSDCFG_BTROM0_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_btrom0_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_BTROM0_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_btrom0_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_BTROM0_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_btrom1_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_BTROM1_BIT) >> ASC_SRAMSDCFG_BTROM1_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_btrom1_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_BTROM1_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_btrom1_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_BTROM1_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_sramsdcfg_btrom2_getb(void)
{
    return (AIC_AONSYSCTRL->SRAMSDCFG & ASC_SRAMSDCFG_BTROM2_BIT) >> ASC_SRAMSDCFG_BTROM2_POS;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_btrom2_setb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG |=  ASC_SRAMSDCFG_BTROM2_BIT;
}

__STATIC_INLINE void aonsysctrl_sramsdcfg_btrom2_clrb(void)
{
    AIC_AONSYSCTRL->SRAMSDCFG &= ~ASC_SRAMSDCFG_BTROM2_BIT;
}

/**
 * Address Offset: 0x050
 * Register Name : ASC AON_CLK_DIV
 */

#define ASC_AONCLKDIV_DENOM_LSB         (0)
#define ASC_AONCLKDIV_DENOM_WIDTH       (4)
#define ASC_AONCLKDIV_DENOM_MASK        (((0x01UL << ASC_AONCLKDIV_DENOM_WIDTH) - 1) << ASC_AONCLKDIV_DENOM_LSB)
#define ASC_AONCLKDIV_UPDATE_POS        (4)
#define ASC_AONCLKDIV_UPDATE_BIT        (0x01UL << ASC_AONCLKDIV_UPDATE_POS)

__STATIC_INLINE uint8_t aonsysctrl_aonclkdiv_denom_getf(void)
{
    return ((AIC_AONSYSCTRL->AONCLKDIV & ASC_AONCLKDIV_DENOM_MASK) >> ASC_AONCLKDIV_DENOM_LSB);
}

__STATIC_INLINE void aonsysctrl_aonclkdiv_denom_setf(uint8_t div_denom)
{
    uint32_t local_val = AIC_AONSYSCTRL->AONCLKDIV & ~ASC_AONCLKDIV_DENOM_MASK;
    AIC_AONSYSCTRL->AONCLKDIV = local_val | ((div_denom << ASC_AONCLKDIV_DENOM_LSB) & ASC_AONCLKDIV_DENOM_MASK) | ASC_AONCLKDIV_UPDATE_BIT;
}

/**
 * Address Offset: 0x054
 * Register Name : ASC AON_RAM_MUX
 */

#define ASC_AONRAMMUX_HI32K_POS         (0)
#define ASC_AONRAMMUX_HI32K_BIT         (0x01UL << ASC_AONRAMMUX_HI32K_POS)
#define ASC_AONRAMMUX_LO32K_POS         (1)
#define ASC_AONRAMMUX_LO32K_BIT         (0x01UL << ASC_AONRAMMUX_LO32K_POS)

__STATIC_INLINE uint8_t aonsysctrl_aonrammux_hi32k_getb(void)
{
    return (AIC_AONSYSCTRL->AONRAMMUX & ASC_AONRAMMUX_HI32K_BIT) >> ASC_AONRAMMUX_HI32K_POS;
}

__STATIC_INLINE void aonsysctrl_aonrammux_hi32k_setb(void)
{
    AIC_AONSYSCTRL->AONRAMMUX |=  ASC_AONRAMMUX_HI32K_BIT;
}

__STATIC_INLINE void aonsysctrl_aonrammux_hi32k_clrb(void)
{
    AIC_AONSYSCTRL->AONRAMMUX &= ~ASC_AONRAMMUX_HI32K_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_aonrammux_lo32k_getb(void)
{
    return (AIC_AONSYSCTRL->AONRAMMUX & ASC_AONRAMMUX_LO32K_BIT) >> ASC_AONRAMMUX_LO32K_POS;
}

__STATIC_INLINE void aonsysctrl_aonrammux_lo32k_setb(void)
{
    AIC_AONSYSCTRL->AONRAMMUX |=  ASC_AONRAMMUX_LO32K_BIT;
}

__STATIC_INLINE void aonsysctrl_aonrammux_lo32k_clrb(void)
{
    AIC_AONSYSCTRL->AONRAMMUX &= ~ASC_AONRAMMUX_LO32K_BIT;
}

/**
 * Address Offset: 0x058
 * Register Name : ASC CPU_SB_RESET_ADDR
 */

__STATIC_INLINE uint32_t aonsysctrl_cpusbra_get(void)
{
    return AIC_AONSYSCTRL->CPUSBRA;
}

__STATIC_INLINE void aonsysctrl_cpusbra_set(uint32_t reset_addr)
{
    AIC_AONSYSCTRL->CPUSBRA = reset_addr;
}

/**
 * Address Offset: 0x05C
 * Register Name : ASC CPU_AON_RESET_ADDR
 */

__STATIC_INLINE uint32_t aonsysctrl_cpuaonra_get(void)
{
    return AIC_AONSYSCTRL->CPUAONRA;
}

__STATIC_INLINE void aonsysctrl_cpuaonra_set(uint32_t reset_addr)
{
    AIC_AONSYSCTRL->CPUAONRA = reset_addr;
}

/**
 * Address Offset: 0x074
 * Register Name : ASC OSCEN
 */

#define ASC_OSCEN_BT_OSC_EN_POS         (0)
#define ASC_OSCEN_BT_OSC_EN_BIT         (0x01UL << ASC_OSCEN_BT_OSC_EN_POS)
#define ASC_OSCEN_WIFI_OSC_EN_POS       (1)
#define ASC_OSCEN_WIFI_OSC_EN_BIT       (0x01UL << ASC_OSCEN_WIFI_OSC_EN_POS)
#define ASC_OSCEN_BT_OSC_MANUAL_POS     (2)
#define ASC_OSCEN_BT_OSC_MANUAL_BIT     (0x01UL << ASC_OSCEN_BT_OSC_MANUAL_POS)
#define ASC_OSCEN_WIFI_OSC_MANUAL_POS   (3)
#define ASC_OSCEN_WIFI_OSC_MANUAL_BIT   (0x01UL << ASC_OSCEN_WIFI_OSC_MANUAL_POS)
#define ASC_OSCEN_WIFI_OSC_COMB_EN_POS  (4)
#define ASC_OSCEN_WIFI_OSC_COMB_EN_BIT  (0x01UL << ASC_OSCEN_WIFI_OSC_COMB_EN_POS)

__STATIC_INLINE uint8_t aonsysctrl_oscen_bt_osc_en_getb(void)
{
    return (AIC_AONSYSCTRL->OSCEN & ASC_OSCEN_BT_OSC_EN_BIT) >> ASC_OSCEN_BT_OSC_EN_POS;
}

__STATIC_INLINE void aonsysctrl_oscen_bt_osc_en_setb(void)
{
    AIC_AONSYSCTRL->OSCEN |=  ASC_OSCEN_BT_OSC_EN_BIT;
}

__STATIC_INLINE void aonsysctrl_oscen_bt_osc_en_clrb(void)
{
    AIC_AONSYSCTRL->OSCEN &= ~ASC_OSCEN_BT_OSC_EN_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oscen_wifi_osc_en_getb(void)
{
    return (AIC_AONSYSCTRL->OSCEN & ASC_OSCEN_WIFI_OSC_EN_BIT) >> ASC_OSCEN_WIFI_OSC_EN_POS;
}

__STATIC_INLINE void aonsysctrl_oscen_wifi_osc_en_setb(void)
{
    AIC_AONSYSCTRL->OSCEN |=  ASC_OSCEN_WIFI_OSC_EN_BIT;
}

__STATIC_INLINE void aonsysctrl_oscen_wifi_osc_en_clrb(void)
{
    AIC_AONSYSCTRL->OSCEN &= ~ASC_OSCEN_WIFI_OSC_EN_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oscen_bt_osc_manual_getb(void)
{
    return (AIC_AONSYSCTRL->OSCEN & ASC_OSCEN_BT_OSC_MANUAL_BIT) >> ASC_OSCEN_BT_OSC_MANUAL_POS;
}

__STATIC_INLINE void aonsysctrl_oscen_bt_osc_manual_setb(void)
{
    AIC_AONSYSCTRL->OSCEN |=  ASC_OSCEN_BT_OSC_MANUAL_BIT;
}

__STATIC_INLINE void aonsysctrl_oscen_bt_osc_manual_clrb(void)
{
    AIC_AONSYSCTRL->OSCEN &= ~ASC_OSCEN_BT_OSC_MANUAL_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oscen_wifi_osc_manual_getb(void)
{
    return (AIC_AONSYSCTRL->OSCEN & ASC_OSCEN_WIFI_OSC_MANUAL_BIT) >> ASC_OSCEN_WIFI_OSC_MANUAL_POS;
}

__STATIC_INLINE void aonsysctrl_oscen_wifi_osc_manual_setb(void)
{
    AIC_AONSYSCTRL->OSCEN |=  ASC_OSCEN_WIFI_OSC_MANUAL_BIT;
}

__STATIC_INLINE void aonsysctrl_oscen_wifi_osc_manual_clrb(void)
{
    AIC_AONSYSCTRL->OSCEN &= ~ASC_OSCEN_WIFI_OSC_MANUAL_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oscen_wifi_osc_comb_en_getb(void)
{
    return (AIC_AONSYSCTRL->OSCEN & ASC_OSCEN_WIFI_OSC_COMB_EN_BIT) >> ASC_OSCEN_WIFI_OSC_COMB_EN_POS;
}

__STATIC_INLINE void aonsysctrl_oscen_wifi_osc_comb_en_setb(void)
{
    AIC_AONSYSCTRL->OSCEN |=  ASC_OSCEN_WIFI_OSC_COMB_EN_BIT;
}

__STATIC_INLINE void aonsysctrl_oscen_wifi_osc_comb_en_clrb(void)
{
    AIC_AONSYSCTRL->OSCEN &= ~ASC_OSCEN_WIFI_OSC_COMB_EN_BIT;
}

/**
 * Address Offset: 0x100
 * Register Name : ASC HCLK_MANUAL_ENABLE (write 1 valid)
 */

#define ASC_HCLKME_CPUSYS_EN_POS        (0)
#define ASC_HCLKME_CPUSYS_EN_BIT        (0x01UL << ASC_HCLKME_CPUSYS_EN_POS)
#define ASC_HCLKME_BTSYS_EN_POS         (1)
#define ASC_HCLKME_BTSYS_EN_BIT         (0x01UL << ASC_HCLKME_BTSYS_EN_POS)
#define ASC_HCLKME_BTFREE_EN_POS        (2)
#define ASC_HCLKME_BTFREE_EN_BIT        (0x01UL << ASC_HCLKME_BTFREE_EN_POS)
#define ASC_HCLKME_WIFISYS_EN_POS       (3)
#define ASC_HCLKME_WIFISYS_EN_BIT       (0x01UL << ASC_HCLKME_WIFISYS_EN_POS)
#define ASC_HCLKME_AONSRAM0_EN_POS      (4)
#define ASC_HCLKME_AONSRAM0_EN_BIT      (0x01UL << ASC_HCLKME_AONSRAM0_EN_POS)
#define ASC_HCLKME_AONSRAM1_EN_POS      (5)
#define ASC_HCLKME_AONSRAM1_EN_BIT      (0x01UL << ASC_HCLKME_AONSRAM1_EN_POS)
#define ASC_HCLKME_AONSRAM2_EN_POS      (6)
#define ASC_HCLKME_AONSRAM2_EN_BIT      (0x01UL << ASC_HCLKME_AONSRAM2_EN_POS)
#define ASC_HCLKME_AONSRAMCPUSYS_EN_POS (7)
#define ASC_HCLKME_AONSRAMCPUSYS_EN_BIT (0x01UL << ASC_HCLKME_AONSRAMCPUSYS_EN_POS)
#define ASC_HCLKME_AONMERGE_EN_POS      (8)
#define ASC_HCLKME_AONMERGE_EN_BIT      (0x01UL << ASC_HCLKME_AONMERGE_EN_POS)

__STATIC_INLINE uint32_t aonsysctrl_hclkme_get(void)
{
    return AIC_AONSYSCTRL->HCLKME;
}

__STATIC_INLINE void aonsysctrl_hclkme_set(uint32_t enable_bits)
{
    AIC_AONSYSCTRL->HCLKME = enable_bits;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkme_cpusys_en_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKME & ASC_HCLKME_CPUSYS_EN_BIT) >> ASC_HCLKME_CPUSYS_EN_POS;
}

__STATIC_INLINE void aonsysctrl_hclkme_cpusys_en_setb(void)
{
    AIC_AONSYSCTRL->HCLKME = ASC_HCLKME_CPUSYS_EN_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkme_btsys_en_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKME & ASC_HCLKME_BTSYS_EN_BIT) >> ASC_HCLKME_BTSYS_EN_POS;
}

__STATIC_INLINE void aonsysctrl_hclkme_btsys_en_setb(void)
{
    AIC_AONSYSCTRL->HCLKME = ASC_HCLKME_BTSYS_EN_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkme_btfree_en_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKME & ASC_HCLKME_BTFREE_EN_BIT) >> ASC_HCLKME_BTFREE_EN_POS;
}

__STATIC_INLINE void aonsysctrl_hclkme_btfree_en_setb(void)
{
    AIC_AONSYSCTRL->HCLKME = ASC_HCLKME_BTFREE_EN_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkme_wifisys_en_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKME & ASC_HCLKME_WIFISYS_EN_BIT) >> ASC_HCLKME_WIFISYS_EN_POS;
}

__STATIC_INLINE void aonsysctrl_hclkme_wifisys_en_setb(void)
{
    AIC_AONSYSCTRL->HCLKME = ASC_HCLKME_WIFISYS_EN_BIT;
}

/**
 * Address Offset: 0x104
 * Register Name : ASC HCLK_MANUAL_DISABLE (write 1 valid)
 */

#define ASC_HCLKMD_CPUSYS_DIS_POS           (0)
#define ASC_HCLKMD_CPUSYS_DIS_BIT           (0x01UL << ASC_HCLKMD_CPUSYS_DIS_POS)
#define ASC_HCLKMD_BTSYS_DIS_POS            (1)
#define ASC_HCLKMD_BTSYS_DIS_BIT            (0x01UL << ASC_HCLKMD_BTSYS_DIS_POS)
#define ASC_HCLKMD_BTFREE_DIS_POS           (2)
#define ASC_HCLKMD_BTFREE_DIS_BIT           (0x01UL << ASC_HCLKMD_BTFREE_DIS_POS)
#define ASC_HCLKMD_WIFISYS_DIS_POS          (3)
#define ASC_HCLKMD_WIFISYS_DIS_BIT          (0x01UL << ASC_HCLKMD_WIFISYS_DIS_POS)
#define ASC_HCLKMD_AONSRAM0_DIS_POS         (4)
#define ASC_HCLKMD_AONSRAM0_DIS_BIT         (0x01UL << ASC_HCLKMD_AONSRAM0_DIS_POS)
#define ASC_HCLKMD_AONSRAM1_DIS_POS         (5)
#define ASC_HCLKMD_AONSRAM1_DIS_BIT         (0x01UL << ASC_HCLKMD_AONSRAM1_DIS_POS)
#define ASC_HCLKMD_AONSRAM2_DIS_POS         (6)
#define ASC_HCLKMD_AONSRAM2_DIS_BIT         (0x01UL << ASC_HCLKMD_AONSRAM2_DIS_POS)
#define ASC_HCLKMD_AONSRAMCPUSYS_DIS_POS    (7)
#define ASC_HCLKMD_AONSRAMCPUSYS_DIS_BIT    (0x01UL << ASC_HCLKMD_AONSRAMCPUSYS_DIS_POS)
#define ASC_HCLKMD_AONMERGE_DIS_POS         (8)
#define ASC_HCLKMD_AONMERGE_DIS_BIT         (0x01UL << ASC_HCLKMD_AONMERGE_DIS_POS)

__STATIC_INLINE uint32_t aonsysctrl_hclkmd_get(void)
{
    return AIC_AONSYSCTRL->HCLKMD;
}

__STATIC_INLINE void aonsysctrl_hclkmd_set(uint32_t disable_bits)
{
    AIC_AONSYSCTRL->HCLKMD = disable_bits;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkmd_cpusys_dis_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKMD & ASC_HCLKMD_CPUSYS_DIS_BIT) >> ASC_HCLKMD_CPUSYS_DIS_POS;
}

__STATIC_INLINE void aonsysctrl_hclkmd_cpusys_dis_setb(void)
{
    AIC_AONSYSCTRL->HCLKMD = ASC_HCLKMD_CPUSYS_DIS_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkmd_btsys_dis_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKMD & ASC_HCLKMD_BTSYS_DIS_BIT) >> ASC_HCLKMD_BTSYS_DIS_POS;
}

__STATIC_INLINE void aonsysctrl_hclkmd_btsys_dis_setb(void)
{
    AIC_AONSYSCTRL->HCLKMD = ASC_HCLKMD_BTSYS_DIS_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkmd_btfree_dis_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKMD & ASC_HCLKMD_BTFREE_DIS_BIT) >> ASC_HCLKMD_BTFREE_DIS_POS;
}

__STATIC_INLINE void aonsysctrl_hclkmd_btfree_dis_setb(void)
{
    AIC_AONSYSCTRL->HCLKMD = ASC_HCLKMD_BTFREE_DIS_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkmd_wifisys_dis_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKMD & ASC_HCLKMD_WIFISYS_DIS_BIT) >> ASC_HCLKMD_WIFISYS_DIS_POS;
}

__STATIC_INLINE void aonsysctrl_hclkmd_wifisys_dis_setb(void)
{
    AIC_AONSYSCTRL->HCLKMD = ASC_HCLKMD_WIFISYS_DIS_BIT;
}

/**
 * Address Offset: 0x108
 * Register Name : ASC FCLK_MANUAL_ENABLE (write 1 valid)
 */

#define ASC_FCLKME_CPUSYS_EN_POS        (0)
#define ASC_FCLKME_CPUSYS_EN_BIT        (0x01UL << ASC_FCLKME_CPUSYS_EN_POS)

__STATIC_INLINE uint32_t aonsysctrl_fclkme_get(void)
{
    return AIC_AONSYSCTRL->FCLKME;
}

__STATIC_INLINE void aonsysctrl_fclkme_set(uint32_t enable_bits)
{
    AIC_AONSYSCTRL->FCLKME = enable_bits;
}

/**
 * Address Offset: 0x10C
 * Register Name : ASC FCLK_MANUAL_DISABLE (write 1 valid)
 */

#define ASC_FCLKMD_CPUSYS_DIS_POS       (0)
#define ASC_FCLKMD_CPUSYS_DIS_BIT       (0x01UL << ASC_FCLKMD_CPUSYS_DIS_POS)

__STATIC_INLINE uint32_t aonsysctrl_fclkmd_get(void)
{
    return AIC_AONSYSCTRL->FCLKMD;
}

__STATIC_INLINE void aonsysctrl_fclkmd_set(uint32_t disable_bits)
{
    AIC_AONSYSCTRL->FCLKMD = disable_bits;
}

/**
 * Address Offset: 0x110
 * Register Name : ASC OCLK_MANUAL_ENABLE (write 1 valid)
 */

#define ASC_OCLKME_CLK26M_AONSYS_EN_POS         (0)
#define ASC_OCLKME_CLK26M_AONSYS_EN_BIT         (0x01UL << ASC_OCLKME_CLK26M_AONSYS_EN_POS)
#define ASC_OCLKME_CLK26M_CPUSYS_EN_POS         (1)
#define ASC_OCLKME_CLK26M_CPUSYS_EN_BIT         (0x01UL << ASC_OCLKME_CLK26M_CPUSYS_EN_POS)
#define ASC_OCLKME_CLK26M_TIMER20_EN_POS        (2)
#define ASC_OCLKME_CLK26M_TIMER20_EN_BIT        (0x01UL << ASC_OCLKME_CLK26M_TIMER20_EN_POS)
#define ASC_OCLKME_CLK32K_TIMER21_EN_POS        (3)
#define ASC_OCLKME_CLK32K_TIMER21_EN_BIT        (0x01UL << ASC_OCLKME_CLK32K_TIMER21_EN_POS)
#define ASC_OCLKME_CLK32K_TIMER22_EN_POS        (4)
#define ASC_OCLKME_CLK32K_TIMER22_EN_BIT        (0x01UL << ASC_OCLKME_CLK32K_TIMER22_EN_POS)
#define ASC_OCLKME_CLK32K_AONSYS_EN_POS         (5)
#define ASC_OCLKME_CLK32K_AONSYS_EN_BIT         (0x01UL << ASC_OCLKME_CLK32K_AONSYS_EN_POS)
#define ASC_OCLKME_CLK32K_CPUSYS_EN_POS         (6)
#define ASC_OCLKME_CLK32K_CPUSYS_EN_BIT         (0x01UL << ASC_OCLKME_CLK32K_CPUSYS_EN_POS)
#define ASC_OCLKME_CLK32K_WIFISYS_EN_POS        (7)
#define ASC_OCLKME_CLK32K_WIFISYS_EN_BIT        (0x01UL << ASC_OCLKME_CLK32K_WIFISYS_EN_POS)
#define ASC_OCLKME_CLK32K_BTSYS_EN_POS          (8)
#define ASC_OCLKME_CLK32K_BTSYS_EN_BIT          (0x01UL << ASC_OCLKME_CLK32K_BTSYS_EN_POS)
#define ASC_OCLKME_CLK_I2CS_EN_POS              (9)
#define ASC_OCLKME_CLK_I2CS_EN_BIT              (0x01UL << ASC_OCLKME_CLK_I2CS_EN_POS)
#define ASC_OCLKME_CLK_MEM2X_EN_POS             (10)
#define ASC_OCLKME_CLK_MEM2X_EN_BIT             (0x01UL << ASC_OCLKME_CLK_MEM2X_EN_POS)
#define ASC_OCLKME_CLK_EFUSE_EN_POS             (11)
#define ASC_OCLKME_CLK_EFUSE_EN_BIT             (0x01UL << ASC_OCLKME_CLK_EFUSE_EN_POS)
#define ASC_OCLKME_CLK32K_WIFIAON_EN_POS        (12)
#define ASC_OCLKME_CLK32K_WIFIAON_EN_BIT        (0x01UL << ASC_OCLKME_CLK32K_WIFIAON_EN_POS)
#define ASC_OCLKME_CLK32K_BTAON_EN_POS          (13)
#define ASC_OCLKME_CLK32K_BTAON_EN_BIT          (0x01UL << ASC_OCLKME_CLK32K_BTAON_EN_POS)
#define ASC_OCLKME_CLK52M_CPUSYS_EN_POS         (14)
#define ASC_OCLKME_CLK52M_CPUSYS_EN_BIT         (0x01UL << ASC_OCLKME_CLK52M_CPUSYS_EN_POS)
#define ASC_OCLKME_HCLK_AONROM_EN_POS           (15)
#define ASC_OCLKME_HCLK_AONROM_EN_BIT           (0x01UL << ASC_OCLKME_HCLK_AONROM_EN_POS)
#define ASC_OCLKME_HCLK_APB1_EN_POS             (16)
#define ASC_OCLKME_HCLK_APB1_EN_BIT             (0x01UL << ASC_OCLKME_HCLK_APB1_EN_POS)
#define ASC_OCLKME_HCLK_I2CS_EN_POS             (17)
#define ASC_OCLKME_HCLK_I2CS_EN_BIT             (0x01UL << ASC_OCLKME_HCLK_I2CS_EN_POS)
#define ASC_OCLKME_PCLK_SYSCTRL_EN_POS          (18)
#define ASC_OCLKME_PCLK_SYSCTRL_EN_BIT          (0x01UL << ASC_OCLKME_PCLK_SYSCTRL_EN_POS)
#define ASC_OCLKME_PCLK_PWRCTRL_EN_POS          (19)
#define ASC_OCLKME_PCLK_PWRCTRL_EN_BIT          (0x01UL << ASC_OCLKME_PCLK_PWRCTRL_EN_POS)
#define ASC_OCLKME_PCLK_GPIO_EN_POS             (20)
#define ASC_OCLKME_PCLK_GPIO_EN_BIT             (0x01UL << ASC_OCLKME_PCLK_GPIO_EN_POS)
#define ASC_OCLKME_PCLK_TIMER2_EN_POS           (21)
#define ASC_OCLKME_PCLK_TIMER2_EN_BIT           (0x01UL << ASC_OCLKME_PCLK_TIMER2_EN_POS)
#define ASC_OCLKME_PCLK_IOMUX_EN_POS            (22)
#define ASC_OCLKME_PCLK_IOMUX_EN_BIT            (0x01UL << ASC_OCLKME_PCLK_IOMUX_EN_POS)
#define ASC_OCLKME_PCLK_EFUSE_EN_POS            (23)
#define ASC_OCLKME_PCLK_EFUSE_EN_BIT            (0x01UL << ASC_OCLKME_PCLK_EFUSE_EN_POS)
#define ASC_OCLKME_HCLK_ALWAYS_CPUAON_EN_POS    (24)
#define ASC_OCLKME_HCLK_ALWAYS_CPUAON_EN_BIT    (0x01UL << ASC_OCLKME_HCLK_ALWAYS_CPUAON_EN_POS)
#define ASC_OCLKME_HCLK_CPUAON_EN_POS           (25)
#define ASC_OCLKME_HCLK_CPUAON_EN_BIT           (0x01UL << ASC_OCLKME_HCLK_CPUAON_EN_POS)
#define ASC_OCLKME_HCLK_AONSRAM_EN_POS          (26)
#define ASC_OCLKME_HCLK_AONSRAM_EN_BIT          (0x01UL << ASC_OCLKME_HCLK_AONSRAM_EN_POS)
#define ASC_OCLKME_PCLK_WDG4_EN_POS             (27)
#define ASC_OCLKME_PCLK_WDG4_EN_BIT             (0x01UL << ASC_OCLKME_PCLK_WDG4_EN_POS)
#define ASC_OCLKME_PCLK_PSIM_EN_POS             (28)
#define ASC_OCLKME_PCLK_PSIM_EN_BIT             (0x01UL << ASC_OCLKME_PCLK_PSIM_EN_POS)
#define ASC_OCLKME_PCLK_ANAREG_EN_POS           (29)
#define ASC_OCLKME_PCLK_ANAREG_EN_BIT           (0x01UL << ASC_OCLKME_PCLK_ANAREG_EN_POS)
#define ASC_OCLKME_CLKRTC_WDG4_EN_POS           (30)
#define ASC_OCLKME_CLKRTC_WDG4_EN_BIT           (0x01UL << ASC_OCLKME_CLKRTC_WDG4_EN_POS)
#define ASC_OCLKME_HCLK_WCNAON_EN_POS           (31)
#define ASC_OCLKME_HCLK_WCNAON_EN_BIT           (0x01UL << ASC_OCLKME_HCLK_WCNAON_EN_POS)

__STATIC_INLINE uint32_t aonsysctrl_oclkme_get(void)
{
    return AIC_AONSYSCTRL->OCLKME;
}

__STATIC_INLINE void aonsysctrl_oclkme_set(uint32_t enable_bits)
{
    AIC_AONSYSCTRL->OCLKME = enable_bits;
}

/**
 * Address Offset: 0x114
 * Register Name : ASC OCLK_MANUAL_DISABLE (write 1 valid)
 */

#define ASC_OCLKMD_CLK26M_AONSYS_DIS_POS        (0)
#define ASC_OCLKMD_CLK26M_AONSYS_DIS_BIT        (0x01UL << ASC_OCLKMD_CLK26M_AONSYS_DIS_POS)
#define ASC_OCLKMD_CLK26M_CPUSYS_DIS_POS        (1)
#define ASC_OCLKMD_CLK26M_CPUSYS_DIS_BIT        (0x01UL << ASC_OCLKMD_CLK26M_CPUSYS_DIS_POS)
#define ASC_OCLKMD_CLK26M_TIMER20_DIS_POS       (2)
#define ASC_OCLKMD_CLK26M_TIMER20_DIS_BIT       (0x01UL << ASC_OCLKMD_CLK26M_TIMER20_DIS_POS)
#define ASC_OCLKMD_CLK32K_TIMER21_DIS_POS       (3)
#define ASC_OCLKMD_CLK32K_TIMER21_DIS_BIT       (0x01UL << ASC_OCLKMD_CLK32K_TIMER21_DIS_POS)
#define ASC_OCLKMD_CLK32K_TIMER22_DIS_POS       (4)
#define ASC_OCLKMD_CLK32K_TIMER22_DIS_BIT       (0x01UL << ASC_OCLKMD_CLK32K_TIMER22_DIS_POS)
#define ASC_OCLKMD_CLK32K_AONSYS_DIS_POS        (5)
#define ASC_OCLKMD_CLK32K_AONSYS_DIS_BIT        (0x01UL << ASC_OCLKMD_CLK32K_AONSYS_DIS_POS)
#define ASC_OCLKMD_CLK32K_CPUSYS_DIS_POS        (6)
#define ASC_OCLKMD_CLK32K_CPUSYS_DIS_BIT        (0x01UL << ASC_OCLKMD_CLK32K_CPUSYS_DIS_POS)
#define ASC_OCLKMD_CLK32K_WIFISYS_DIS_POS       (7)
#define ASC_OCLKMD_CLK32K_WIFISYS_DIS_BIT       (0x01UL << ASC_OCLKMD_CLK32K_WIFISYS_DIS_POS)
#define ASC_OCLKMD_CLK32K_BTSYS_DIS_POS         (8)
#define ASC_OCLKMD_CLK32K_BTSYS_DIS_BIT         (0x01UL << ASC_OCLKMD_CLK32K_BTSYS_DIS_POS)
#define ASC_OCLKMD_CLK_I2CS_DIS_POS             (9)
#define ASC_OCLKMD_CLK_I2CS_DIS_BIT             (0x01UL << ASC_OCLKMD_CLK_I2CS_DIS_POS)
#define ASC_OCLKMD_CLK_MEM2X_DIS_POS            (10)
#define ASC_OCLKMD_CLK_MEM2X_DIS_BIT            (0x01UL << ASC_OCLKMD_CLK_MEM2X_DIS_POS)
#define ASC_OCLKMD_CLK_EFUSE_DIS_POS            (11)
#define ASC_OCLKMD_CLK_EFUSE_DIS_BIT            (0x01UL << ASC_OCLKMD_CLK_EFUSE_DIS_POS)
#define ASC_OCLKMD_CLK32K_WIFIAON_DIS_POS       (12)
#define ASC_OCLKMD_CLK32K_WIFIAON_DIS_BIT       (0x01UL << ASC_OCLKMD_CLK32K_WIFIAON_DIS_POS)
#define ASC_OCLKMD_CLK32K_BTAON_DIS_POS         (13)
#define ASC_OCLKMD_CLK32K_BTAON_DIS_BIT         (0x01UL << ASC_OCLKMD_CLK32K_BTAON_DIS_POS)
#define ASC_OCLKMD_CLK52M_CPUSYS_DIS_POS        (14)
#define ASC_OCLKMD_CLK52M_CPUSYS_DIS_BIT        (0x01UL << ASC_OCLKMD_CLK52M_CPUSYS_DIS_POS)
#define ASC_OCLKMD_HCLK_AONROM_DIS_POS          (15)
#define ASC_OCLKMD_HCLK_AONROM_DIS_BIT          (0x01UL << ASC_OCLKMD_HCLK_AONROM_DIS_POS)
#define ASC_OCLKMD_HCLK_APB1_DIS_POS            (16)
#define ASC_OCLKMD_HCLK_APB1_DIS_BIT            (0x01UL << ASC_OCLKMD_HCLK_APB1_DIS_POS)
#define ASC_OCLKMD_HCLK_I2CS_DIS_POS            (17)
#define ASC_OCLKMD_HCLK_I2CS_DIS_BIT            (0x01UL << ASC_OCLKMD_HCLK_I2CS_DIS_POS)
#define ASC_OCLKMD_PCLK_SYSCTRL_DIS_POS         (18)
#define ASC_OCLKMD_PCLK_SYSCTRL_DIS_BIT         (0x01UL << ASC_OCLKMD_PCLK_SYSCTRL_DIS_POS)
#define ASC_OCLKMD_PCLK_PWRCTRL_DIS_POS         (19)
#define ASC_OCLKMD_PCLK_PWRCTRL_DIS_BIT         (0x01UL << ASC_OCLKMD_PCLK_PWRCTRL_DIS_POS)
#define ASC_OCLKMD_PCLK_GPIO_DIS_POS            (20)
#define ASC_OCLKMD_PCLK_GPIO_DIS_BIT            (0x01UL << ASC_OCLKMD_PCLK_GPIO_DIS_POS)
#define ASC_OCLKMD_PCLK_TIMER2_DIS_POS          (21)
#define ASC_OCLKMD_PCLK_TIMER2_DIS_BIT          (0x01UL << ASC_OCLKMD_PCLK_TIMER2_DIS_POS)
#define ASC_OCLKMD_PCLK_IOMUX_DIS_POS           (22)
#define ASC_OCLKMD_PCLK_IOMUX_DIS_BIT           (0x01UL << ASC_OCLKMD_PCLK_IOMUX_DIS_POS)
#define ASC_OCLKMD_PCLK_EFUSE_DIS_POS           (23)
#define ASC_OCLKMD_PCLK_EFUSE_DIS_BIT           (0x01UL << ASC_OCLKMD_PCLK_EFUSE_DIS_POS)
#define ASC_OCLKMD_HCLK_ALWAYS_CPUAON_DIS_POS   (24)
#define ASC_OCLKMD_HCLK_ALWAYS_CPUAON_DIS_BIT   (0x01UL << ASC_OCLKMD_HCLK_ALWAYS_CPUAON_DIS_POS)
#define ASC_OCLKMD_HCLK_CPUAON_DIS_POS          (25)
#define ASC_OCLKMD_HCLK_CPUAON_DIS_BIT          (0x01UL << ASC_OCLKMD_HCLK_CPUAON_DIS_POS)
#define ASC_OCLKMD_HCLK_AONSRAM_DIS_POS         (26)
#define ASC_OCLKMD_HCLK_AONSRAM_DIS_BIT         (0x01UL << ASC_OCLKMD_HCLK_AONSRAM_DIS_POS)
#define ASC_OCLKMD_PCLK_WDG4_DIS_POS            (27)
#define ASC_OCLKMD_PCLK_WDG4_DIS_BIT            (0x01UL << ASC_OCLKMD_PCLK_WDG4_DIS_POS)
#define ASC_OCLKMD_PCLK_PSIM_DIS_POS            (28)
#define ASC_OCLKMD_PCLK_PSIM_DIS_BIT            (0x01UL << ASC_OCLKMD_PCLK_PSIM_DIS_POS)
#define ASC_OCLKMD_PCLK_ANAREG_DIS_POS          (29)
#define ASC_OCLKMD_PCLK_ANAREG_DIS_BIT          (0x01UL << ASC_OCLKMD_PCLK_ANAREG_DIS_POS)
#define ASC_OCLKMD_CLKRTC_WDG4_DIS_POS          (30)
#define ASC_OCLKMD_CLKRTC_WDG4_DIS_BIT          (0x01UL << ASC_OCLKMD_CLKRTC_WDG4_DIS_POS)
#define ASC_OCLKMD_HCLK_WCNAON_DIS_POS          (31)
#define ASC_OCLKMD_HCLK_WCNAON_DIS_BIT          (0x01UL << ASC_OCLKMD_HCLK_WCNAON_DIS_POS)

__STATIC_INLINE uint32_t aonsysctrl_oclkmd_get(void)
{
    return AIC_AONSYSCTRL->OCLKMD;
}

__STATIC_INLINE void aonsysctrl_oclkmd_set(uint32_t disable_bits)
{
    AIC_AONSYSCTRL->OCLKMD = disable_bits;
}

/**
 * Address Offset: 0x118
 * Register Name : ASC GLOBAL_SOFT_RESETn_SET (write 1 valid)
 */

#define ASC_GLBRS_SOFTSET_POS           (0)
#define ASC_GLBRS_SOFTSET_BIT           (0x01UL << ASC_GLBRS_SOFTSET_POS)

__STATIC_INLINE uint8_t aonsysctrl_glbrs_softset_getb(void)
{
    return (AIC_AONSYSCTRL->GLBRS & ASC_GLBRS_SOFTSET_BIT) >> ASC_GLBRS_SOFTSET_POS;
}

__STATIC_INLINE void aonsysctrl_glbrs_softset_setb(void)
{
    AIC_AONSYSCTRL->GLBRS = ASC_GLBRS_SOFTSET_BIT;
}

/**
 * Address Offset: 0x11C
 * Register Name : ASC GLOBAL_SOFT_RESETn_CLEAR (write 1 valid)
 */

#define ASC_GLBRC_SOFTCLR_POS           (0)
#define ASC_GLBRC_SOFTCLR_BIT           (0x01UL << ASC_GLBRC_SOFTCLR_POS)

__STATIC_INLINE uint8_t aonsysctrl_glbrc_softclr_getb(void)
{
    return (AIC_AONSYSCTRL->GLBRC & ASC_GLBRC_SOFTCLR_BIT) >> ASC_GLBRC_SOFTCLR_POS;
}

__STATIC_INLINE void aonsysctrl_glbrc_softclr_setb(void)
{
    AIC_AONSYSCTRL->GLBRC = ASC_GLBRC_SOFTCLR_BIT;
}

/**
 * Address Offset: 0x120
 * Register Name : ASC HCLK_SOFT_RESETn_SET (write 1 valid)
 */

#define ASC_HCLKRS_CPUSBSET_POS         (5)
#define ASC_HCLKRS_CPUSBSET_BIT         (0x01UL << ASC_HCLKRS_CPUSBSET_POS)
#define ASC_HCLKRS_CPUSWSET_POS         (6)
#define ASC_HCLKRS_CPUSWSET_BIT         (0x01UL << ASC_HCLKRS_CPUSWSET_POS)
#define ASC_HCLKRS_DSPSET_POS           (7)
#define ASC_HCLKRS_DSPSET_BIT           (0x01UL << ASC_HCLKRS_DSPSET_POS)

__STATIC_INLINE uint32_t aonsysctrl_hclkrs_get(void)
{
    return AIC_AONSYSCTRL->HCLKRS;
}

__STATIC_INLINE void aonsysctrl_hclkrs_set(uint32_t reset_bits)
{
    AIC_AONSYSCTRL->HCLKRS = reset_bits;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkrs_cpusbset_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKRS & ASC_HCLKRS_CPUSBSET_BIT) >> ASC_HCLKRS_CPUSBSET_POS;
}

__STATIC_INLINE void aonsysctrl_hclkrs_cpusbset_setb(void)
{
    AIC_AONSYSCTRL->HCLKRS = ASC_HCLKRS_CPUSBSET_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkrs_cpuswset_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKRS & ASC_HCLKRS_CPUSWSET_BIT) >> ASC_HCLKRS_CPUSWSET_POS;
}

__STATIC_INLINE void aonsysctrl_hclkrs_cpuswset_setb(void)
{
    AIC_AONSYSCTRL->HCLKRS = ASC_HCLKRS_CPUSWSET_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkrs_dspset_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKRS & ASC_HCLKRS_DSPSET_BIT) >> ASC_HCLKRS_DSPSET_POS;
}

__STATIC_INLINE void aonsysctrl_hclkrs_dspset_setb(void)
{
    AIC_AONSYSCTRL->HCLKRS = ASC_HCLKRS_DSPSET_BIT;
}

/**
 * Address Offset: 0x124
 * Register Name : ASC HCLK_SOFT_RESETn_CLEAR (write 1 valid)
 */

#define ASC_HCLKRC_CPUSBCLR_POS         (5)
#define ASC_HCLKRC_CPUSBCLR_BIT         (0x01UL << ASC_HCLKRC_CPUSBCLR_POS)
#define ASC_HCLKRC_CPUSWCLR_POS         (6)
#define ASC_HCLKRC_CPUSWCLR_BIT         (0x01UL << ASC_HCLKRC_CPUSWCLR_POS)
#define ASC_HCLKRC_DSPCLR_POS           (7)
#define ASC_HCLKRC_DSPCLR_BIT           (0x01UL << ASC_HCLKRC_DSPCLR_POS)

__STATIC_INLINE uint32_t aonsysctrl_hclkrc_get(void)
{
    return AIC_AONSYSCTRL->HCLKRC;
}

__STATIC_INLINE void aonsysctrl_hclkrc_set(uint32_t reset_bits)
{
    AIC_AONSYSCTRL->HCLKRC = reset_bits;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkrc_cpusbclr_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKRC & ASC_HCLKRC_CPUSBCLR_BIT) >> ASC_HCLKRC_CPUSBCLR_POS;
}

__STATIC_INLINE void aonsysctrl_hclkrc_cpusbclr_setb(void)
{
    AIC_AONSYSCTRL->HCLKRC = ASC_HCLKRC_CPUSBCLR_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkrc_cpuswclr_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKRC & ASC_HCLKRC_CPUSWCLR_BIT) >> ASC_HCLKRC_CPUSWCLR_POS;
}

__STATIC_INLINE void aonsysctrl_hclkrc_cpuswclr_setb(void)
{
    AIC_AONSYSCTRL->HCLKRC = ASC_HCLKRC_CPUSWCLR_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_hclkrc_dspclr_getb(void)
{
    return (AIC_AONSYSCTRL->HCLKRC & ASC_HCLKRC_DSPCLR_BIT) >> ASC_HCLKRC_DSPCLR_POS;
}

__STATIC_INLINE void aonsysctrl_hclkrc_dspclr_setb(void)
{
    AIC_AONSYSCTRL->HCLKRC = ASC_HCLKRC_DSPCLR_BIT;
}

/**
 * Address Offset: 0x130
 * Register Name : ASC OTHERS_SOFT_RESETn_SET (write 1 valid)
 */

#define ASC_OCLKRS_32KWIFIAONSET_POS    (11)
#define ASC_OCLKRS_32KWIFIAONSET_BIT    (0x01UL << ASC_OCLKRS_32KWIFIAONSET_POS)
#define ASC_OCLKRS_32KBTAONSET_POS      (12)
#define ASC_OCLKRS_32KBTAONSET_BIT      (0x01UL << ASC_OCLKRS_32KBTAONSET_POS)
#define ASC_OCLKRS_CPUAONSET_POS        (24)
#define ASC_OCLKRS_CPUAONSET_BIT        (0x01UL << ASC_OCLKRS_CPUAONSET_POS)

__STATIC_INLINE uint32_t aonsysctrl_oclkrs_get(void)
{
    return AIC_AONSYSCTRL->OCLKRS;
}

__STATIC_INLINE void aonsysctrl_oclkrs_set(uint32_t reset_bits)
{
    AIC_AONSYSCTRL->OCLKRS = reset_bits;
}

__STATIC_INLINE uint8_t aonsysctrl_oclkrs_32kwifiaonset_getb(void)
{
    return (AIC_AONSYSCTRL->OCLKRS & ASC_OCLKRS_32KWIFIAONSET_BIT) >> ASC_OCLKRS_32KWIFIAONSET_POS;
}

__STATIC_INLINE void aonsysctrl_oclkrs_32kwifiaonset_setb(void)
{
    AIC_AONSYSCTRL->OCLKRS = ASC_OCLKRS_32KWIFIAONSET_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oclkrs_32kbtaonset_getb(void)
{
    return (AIC_AONSYSCTRL->OCLKRS & ASC_OCLKRS_32KBTAONSET_BIT) >> ASC_OCLKRS_32KBTAONSET_POS;
}

__STATIC_INLINE void aonsysctrl_oclkrs_32kbtaonset_setb(void)
{
    AIC_AONSYSCTRL->OCLKRS = ASC_OCLKRS_32KBTAONSET_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oclkrs_cpuaonset_getb(void)
{
    return (AIC_AONSYSCTRL->OCLKRS & ASC_OCLKRS_CPUAONSET_BIT) >> ASC_OCLKRS_CPUAONSET_POS;
}

__STATIC_INLINE void aonsysctrl_oclkrs_cpuaonset_setb(void)
{
    AIC_AONSYSCTRL->OCLKRS = ASC_OCLKRS_CPUAONSET_BIT;
}

/**
 * Address Offset: 0x134
 * Register Name : ASC OTHERS_SOFT_RESETn_CLEAR (write 1 valid)
 */

#define ASC_OCLKRC_32KWIFIAONCLR_POS    (11)
#define ASC_OCLKRC_32KWIFIAONCLR_BIT    (0x01UL << ASC_OCLKRC_32KWIFIAONCLR_POS)
#define ASC_OCLKRC_32KBTAONCLR_POS      (12)
#define ASC_OCLKRC_32KBTAONCLR_BIT      (0x01UL << ASC_OCLKRC_32KBTAONCLR_POS)
#define ASC_OCLKRC_CPUAONCLR_POS        (24)
#define ASC_OCLKRC_CPUAONCLR_BIT        (0x01UL << ASC_OCLKRC_CPUAONCLR_POS)

__STATIC_INLINE uint32_t aonsysctrl_oclkrc_get(void)
{
    return AIC_AONSYSCTRL->OCLKRC;
}

__STATIC_INLINE void aonsysctrl_oclkrc_set(uint32_t reset_bits)
{
    AIC_AONSYSCTRL->OCLKRC = reset_bits;
}

__STATIC_INLINE uint8_t aonsysctrl_oclkrc_32kwifiaonclr_getb(void)
{
    return (AIC_AONSYSCTRL->OCLKRC & ASC_OCLKRC_32KWIFIAONCLR_BIT) >> ASC_OCLKRC_32KWIFIAONCLR_POS;
}

__STATIC_INLINE void aonsysctrl_oclkrc_32kwifiaonclr_setb(void)
{
    AIC_AONSYSCTRL->OCLKRC = ASC_OCLKRC_32KWIFIAONCLR_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oclkrc_32kbtaonclr_getb(void)
{
    return (AIC_AONSYSCTRL->OCLKRC & ASC_OCLKRC_32KBTAONCLR_BIT) >> ASC_OCLKRC_32KBTAONCLR_POS;
}

__STATIC_INLINE void aonsysctrl_oclkrc_32kbtaonclr_setb(void)
{
    AIC_AONSYSCTRL->OCLKRC = ASC_OCLKRC_32KBTAONCLR_BIT;
}

__STATIC_INLINE uint8_t aonsysctrl_oclkrc_cpuaonclr_getb(void)
{
    return (AIC_AONSYSCTRL->OCLKRC & ASC_OCLKRC_CPUAONCLR_BIT) >> ASC_OCLKRC_CPUAONCLR_POS;
}

__STATIC_INLINE void aonsysctrl_oclkrc_cpuaonclr_setb(void)
{
    AIC_AONSYSCTRL->OCLKRC = ASC_OCLKRC_CPUAONCLR_BIT;
}

/**
 * Address Offset: 0x138
 * Register Name : ASC BOOTMD
 */

#define ASC_BOOTMD_HW_BOOT_MODE_LSB     (0)
#define ASC_BOOTMD_HW_BOOT_MODE_WIDTH   (4)
#define ASC_BOOTMD_HW_BOOT_MODE_MASK    (((0x01UL << ASC_BOOTMD_HW_BOOT_MODE_WIDTH) - 1) << ASC_BOOTMD_HW_BOOT_MODE_LSB)
#define ASC_BOOTMD_SW_BOOT_MODE_LSB     (4)
#define ASC_BOOTMD_SW_BOOT_MODE_WIDTH   (4)
#define ASC_BOOTMD_SW_BOOT_MODE_MASK    (((0x01UL << ASC_BOOTMD_SW_BOOT_MODE_WIDTH) - 1) << ASC_BOOTMD_SW_BOOT_MODE_LSB)

__STATIC_INLINE uint8_t aonsysctrl_bootmd_hw_boot_mode_getf(void)
{
    return ((AIC_AONSYSCTRL->BOOTMD & ASC_BOOTMD_HW_BOOT_MODE_MASK) >> ASC_BOOTMD_HW_BOOT_MODE_LSB);
}

__STATIC_INLINE void aonsysctrl_bootmd_hw_boot_mode_setf(uint8_t boot_mode)
{
    uint32_t local_val = AIC_AONSYSCTRL->BOOTMD & ~ASC_BOOTMD_HW_BOOT_MODE_MASK;
    AIC_AONSYSCTRL->BOOTMD = local_val | ((boot_mode << ASC_BOOTMD_HW_BOOT_MODE_LSB) & ASC_BOOTMD_HW_BOOT_MODE_MASK);
}

__STATIC_INLINE uint8_t aonsysctrl_bootmd_sw_boot_mode_getf(void)
{
    return ((AIC_AONSYSCTRL->BOOTMD & ASC_BOOTMD_SW_BOOT_MODE_MASK) >> ASC_BOOTMD_SW_BOOT_MODE_LSB);
}

__STATIC_INLINE void aonsysctrl_bootmd_sw_boot_mode_setf(uint8_t boot_mode)
{
    uint32_t local_val = AIC_AONSYSCTRL->BOOTMD & ~ASC_BOOTMD_SW_BOOT_MODE_MASK;
    AIC_AONSYSCTRL->BOOTMD = local_val | ((boot_mode << ASC_BOOTMD_SW_BOOT_MODE_LSB) & ASC_BOOTMD_SW_BOOT_MODE_MASK);
}

/**
 * Address Offset: 0x140
 * Register Name : ASC BTFW_CTRL
 */

#define ASC_BTFWCTRL_STACK_TOP_LSB          (0)
#define ASC_BTFWCTRL_STACK_TOP_WIDTH        (24)
#define ASC_BTFWCTRL_STACK_TOP_MASK         (((0x01UL << ASC_BTFWCTRL_STACK_TOP_WIDTH) - 1) << ASC_BTFWCTRL_STACK_TOP_LSB)
#define ASC_BTFWCTRL_BTCORE_SWCTRL_LSB      (24)
#define ASC_BTFWCTRL_BTCORE_SWCTRL_WIDTH    (2)
#define ASC_BTFWCTRL_BTCORE_SWCTRL_MASK     (((0x01UL << ASC_BTFWCTRL_BTCORE_SWCTRL_WIDTH) - 1) << ASC_BTFWCTRL_BTCORE_SWCTRL_LSB)
#define ASC_BTFWCTRL_STACK_TOP_VALID_POS    (31)
#define ASC_BTFWCTRL_STACK_TOP_VALID_BIT    (0x01UL << ASC_BTFWCTRL_STACK_TOP_VALID_POS)

__STATIC_INLINE uint32_t aonsysctrl_btfwctrl_stack_top_getf(void)
{
    return ((AIC_AONSYSCTRL->BTFWCTRL & ASC_BTFWCTRL_STACK_TOP_MASK) >> ASC_BTFWCTRL_STACK_TOP_LSB);
}

__STATIC_INLINE void aonsysctrl_btfwctrl_stack_top_setf(uint32_t addr)
{
    uint32_t local_val = AIC_AONSYSCTRL->BTFWCTRL & ~ASC_BTFWCTRL_STACK_TOP_MASK;
    AIC_AONSYSCTRL->BTFWCTRL = local_val | ((addr << ASC_BTFWCTRL_STACK_TOP_LSB) & ASC_BTFWCTRL_STACK_TOP_MASK) | ASC_BTFWCTRL_STACK_TOP_VALID_BIT;
}

__STATIC_INLINE uint32_t aonsysctrl_btfwctrl_btcore_swctrl_getf(void)
{
    return ((AIC_AONSYSCTRL->BTFWCTRL & ASC_BTFWCTRL_BTCORE_SWCTRL_MASK) >> ASC_BTFWCTRL_BTCORE_SWCTRL_LSB);
}

__STATIC_INLINE void aonsysctrl_btfwctrl_btcore_swctrl_setf(uint32_t addr)
{
    uint32_t local_val = AIC_AONSYSCTRL->BTFWCTRL & ~ASC_BTFWCTRL_BTCORE_SWCTRL_MASK;
    AIC_AONSYSCTRL->BTFWCTRL = local_val | ((addr << ASC_BTFWCTRL_BTCORE_SWCTRL_LSB) & ASC_BTFWCTRL_BTCORE_SWCTRL_MASK);
}

/**
 * Address Offset: 0x144
 * Register Name : ASC WIFIFW_CTRL
 */

#define ASC_WIFIFWCTRL_STACK_TOP_LSB            (0)
#define ASC_WIFIFWCTRL_STACK_TOP_WIDTH          (24)
#define ASC_WIFIFWCTRL_STACK_TOP_MASK           (((0x01UL << ASC_WIFIFWCTRL_STACK_TOP_WIDTH) - 1) << ASC_WIFIFWCTRL_STACK_TOP_LSB)
#define ASC_WIFIFWCTRL_WIFICORE_SWCTRL_LSB      (24)
#define ASC_WIFIFWCTRL_WIFICORE_SWCTRL_WIDTH    (2)
#define ASC_WIFIFWCTRL_WIFICORE_SWCTRL_MASK     (((0x01UL << ASC_WIFIFWCTRL_WIFICORE_SWCTRL_WIDTH) - 1) << ASC_WIFIFWCTRL_WIFICORE_SWCTRL_LSB)
#define ASC_WIFIFWCTRL_STACK_TOP_VALID_POS      (31)
#define ASC_WIFIFWCTRL_STACK_TOP_VALID_BIT      (0x01UL << ASC_WIFIFWCTRL_STACK_TOP_VALID_POS)

__STATIC_INLINE uint32_t aonsysctrl_wififwctrl_stack_top_getf(void)
{
    return ((AIC_AONSYSCTRL->WIFIFWCTRL & ASC_WIFIFWCTRL_STACK_TOP_MASK) >> ASC_WIFIFWCTRL_STACK_TOP_LSB);
}

__STATIC_INLINE void aonsysctrl_wififwctrl_stack_top_setf(uint32_t addr)
{
    uint32_t local_val = AIC_AONSYSCTRL->WIFIFWCTRL & ~ASC_WIFIFWCTRL_STACK_TOP_MASK;
    AIC_AONSYSCTRL->WIFIFWCTRL = local_val | ((addr << ASC_WIFIFWCTRL_STACK_TOP_LSB) & ASC_WIFIFWCTRL_STACK_TOP_MASK) | ASC_WIFIFWCTRL_STACK_TOP_VALID_BIT;
}

__STATIC_INLINE uint32_t aonsysctrl_wififwctrl_wificore_swctrl_getf(void)
{
    return ((AIC_AONSYSCTRL->WIFIFWCTRL & ASC_WIFIFWCTRL_WIFICORE_SWCTRL_MASK) >> ASC_WIFIFWCTRL_WIFICORE_SWCTRL_LSB);
}

__STATIC_INLINE void aonsysctrl_wififwctrl_wificore_swctrl_setf(uint32_t addr)
{
    uint32_t local_val = AIC_AONSYSCTRL->WIFIFWCTRL & ~ASC_WIFIFWCTRL_WIFICORE_SWCTRL_MASK;
    AIC_AONSYSCTRL->WIFIFWCTRL = local_val | ((addr << ASC_WIFIFWCTRL_WIFICORE_SWCTRL_LSB) & ASC_WIFIFWCTRL_WIFICORE_SWCTRL_MASK);
}

/**
 * Address Offset: 0x148
 * Register Name : ASC BOOT_ENTRY
 */

#define ASC_BOOTENTRY_ADDR_LSB          (0)
#define ASC_BOOTENTRY_ADDR_WIDTH        (28)
#define ASC_BOOTENTRY_ADDR_MASK         (((0x01UL << ASC_BOOTENTRY_ADDR_WIDTH) - 1) << ASC_BOOTENTRY_ADDR_LSB)
#define ASC_BOOTENTRY_ADDR_VALID_POS    (31)
#define ASC_BOOTENTRY_ADDR_VALID_BIT    (0x01UL << ASC_BOOTENTRY_ADDR_VALID_POS)

__STATIC_INLINE uint32_t aonsysctrl_bootentry_get(void)
{
    return AIC_AONSYSCTRL->BOOTENTRY;
}

__STATIC_INLINE void aonsysctrl_bootentry_set(uint32_t entry)
{
    AIC_AONSYSCTRL->BOOTENTRY = entry;
}

/**
 * Address Offset: 0x14C
 * Register Name : ASC BOOT_STACK
 */

#define ASC_BOOTSTACK_ADDR_LSB          (0)
#define ASC_BOOTSTACK_ADDR_WIDTH        (28)
#define ASC_BOOTSTACK_ADDR_MASK         (((0x01UL << ASC_BOOTSTACK_ADDR_WIDTH) - 1) << ASC_BOOTSTACK_ADDR_LSB)
#define ASC_BOOTSTACK_ADDR_VALID_POS    (31)
#define ASC_BOOTSTACK_ADDR_VALID_BIT    (0x01UL << ASC_BOOTSTACK_ADDR_VALID_POS)

__STATIC_INLINE uint32_t aonsysctrl_bootstack_get(void)
{
    return AIC_AONSYSCTRL->BOOTSTACK;
}

__STATIC_INLINE void aonsysctrl_bootstack_set(uint32_t stack)
{
    AIC_AONSYSCTRL->BOOTSTACK = stack;
}

/**
 * Address Offset: 0x150
 * Register Name : ASC HOST_TC_LSB
 */

__STATIC_INLINE uint32_t aonsysctrl_hosttclsb_get(void)
{
    return AIC_AONSYSCTRL->HOSTTCLSB;
}

__STATIC_INLINE void aonsysctrl_hosttclsb_set(uint32_t lsb)
{
    AIC_AONSYSCTRL->HOSTTCLSB = lsb;
}

/**
 * Address Offset: 0x154
 * Register Name : ASC HOST_TC_MSB
 */

__STATIC_INLINE uint32_t aonsysctrl_hosttcmsb_get(void)
{
    return AIC_AONSYSCTRL->HOSTTCMSB;
}

__STATIC_INLINE void aonsysctrl_hosttcmsb_set(uint32_t msb)
{
    AIC_AONSYSCTRL->HOSTTCMSB = msb;
}

/**
 * Address Offset: 0x158
 * Register Name : ASC HOST_SYST
 */

__STATIC_INLINE uint32_t aonsysctrl_hostsyst_get(void)
{
    return AIC_AONSYSCTRL->HOSTSYST;
}

__STATIC_INLINE void aonsysctrl_hostsyst_set(uint32_t syst)
{
    AIC_AONSYSCTRL->HOSTSYST = syst;
}

/**
 * Address Offset: 0x15C
 * Register Name : ASC BT_PWR_CTRL
 */

__STATIC_INLINE uint32_t aonsysctrl_btpwrctrl_get(void)
{
    return AIC_AONSYSCTRL->BTPWRCTRL;
}

__STATIC_INLINE void aonsysctrl_btpwrctrl_set(uint32_t ctrl)
{
    AIC_AONSYSCTRL->BTPWRCTRL = ctrl;
}

/**
 * Address Offset: 0x004
 * Register Name : CSC CLKSEL
 */

#define CSC_CLKSEL_FLASHCLK_POS         (0)
#define CSC_CLKSEL_FLASHCLK_BIT         (0x01UL << CSC_CLKSEL_FLASHCLK_POS)
#define CSC_CLKSEL_UART0CLK_POS         (1)
#define CSC_CLKSEL_UART0CLK_BIT         (0x01UL << CSC_CLKSEL_UART0CLK_POS)
#define CSC_CLKSEL_UART1CLK_POS         (2)
#define CSC_CLKSEL_UART1CLK_BIT         (0x01UL << CSC_CLKSEL_UART1CLK_POS)
#define CSC_CLKSEL_UART2CLK_POS         (3)
#define CSC_CLKSEL_UART2CLK_BIT         (0x01UL << CSC_CLKSEL_UART2CLK_POS)
#define CSC_CLKSEL_CAMERAREFCLK_POS     (4)
#define CSC_CLKSEL_CAMERAREFCLK_BIT     (0x01UL << CSC_CLKSEL_CAMERAREFCLK_POS)
#define CSC_CLKSEL_ASDMACLK_POS         (5)
#define CSC_CLKSEL_ASDMACLK_BIT         (0x01UL << CSC_CLKSEL_ASDMACLK_POS)

__STATIC_INLINE uint8_t cpusysctrl_flash_clk_getb(void)
{
    return (AIC_CPUSYSCTRL->CLKSEL & CSC_CLKSEL_FLASHCLK_BIT) >> CSC_CLKSEL_FLASHCLK_POS;
}

__STATIC_INLINE void cpusysctrl_flash_clk_setb(void)
{
    AIC_CPUSYSCTRL->CLKSEL |=  CSC_CLKSEL_FLASHCLK_BIT;
}

__STATIC_INLINE void cpusysctrl_flash_clk_clrb(void)
{
    AIC_CPUSYSCTRL->CLKSEL &= ~CSC_CLKSEL_FLASHCLK_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_uart0_clk_getb(void)
{
    return (AIC_CPUSYSCTRL->CLKSEL & CSC_CLKSEL_UART0CLK_BIT) >> CSC_CLKSEL_UART0CLK_POS;
}

__STATIC_INLINE void cpusysctrl_uart0_clk_setb(void)
{
    AIC_CPUSYSCTRL->CLKSEL |=  CSC_CLKSEL_UART0CLK_BIT;
}

__STATIC_INLINE void cpusysctrl_uart0_clk_clrb(void)
{
    AIC_CPUSYSCTRL->CLKSEL &= ~CSC_CLKSEL_UART0CLK_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_uart1_clk_getb(void)
{
    return (AIC_CPUSYSCTRL->CLKSEL & CSC_CLKSEL_UART1CLK_BIT) >> CSC_CLKSEL_UART1CLK_POS;
}

__STATIC_INLINE void cpusysctrl_uart1_clk_setb(void)
{
    AIC_CPUSYSCTRL->CLKSEL |=  CSC_CLKSEL_UART1CLK_BIT;
}

__STATIC_INLINE void cpusysctrl_uart1_clk_clrb(void)
{
    AIC_CPUSYSCTRL->CLKSEL &= ~CSC_CLKSEL_UART1CLK_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_uart2_clk_getb(void)
{
    return (AIC_CPUSYSCTRL->CLKSEL & CSC_CLKSEL_UART2CLK_BIT) >> CSC_CLKSEL_UART2CLK_POS;
}

__STATIC_INLINE void cpusysctrl_uart2_clk_setb(void)
{
    AIC_CPUSYSCTRL->CLKSEL |=  CSC_CLKSEL_UART2CLK_BIT;
}

__STATIC_INLINE void cpusysctrl_uart2_clk_clrb(void)
{
    AIC_CPUSYSCTRL->CLKSEL &= ~CSC_CLKSEL_UART2CLK_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_uart_clk_getb(int idx)
{
    return (AIC_CPUSYSCTRL->CLKSEL >> (CSC_CLKSEL_UART0CLK_POS + idx)) & 0x01U;
}

__STATIC_INLINE uint8_t cpusysctrl_cameraref_clk_getb(void)
{
    return (AIC_CPUSYSCTRL->CLKSEL & CSC_CLKSEL_CAMERAREFCLK_BIT) >> CSC_CLKSEL_CAMERAREFCLK_POS;
}

__STATIC_INLINE void cpusysctrl_cameraref_clk_setb(void)
{
    AIC_CPUSYSCTRL->CLKSEL |=  CSC_CLKSEL_CAMERAREFCLK_BIT;
}

__STATIC_INLINE void cpusysctrl_cameraref_clk_clrb(void)
{
    AIC_CPUSYSCTRL->CLKSEL &= ~CSC_CLKSEL_CAMERAREFCLK_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_asdma_clk_getb(void)
{
    return (AIC_CPUSYSCTRL->CLKSEL & CSC_CLKSEL_ASDMACLK_BIT) >> CSC_CLKSEL_ASDMACLK_POS;
}

__STATIC_INLINE void cpusysctrl_asdma_clk_setb(void)
{
    AIC_CPUSYSCTRL->CLKSEL |=  CSC_CLKSEL_ASDMACLK_BIT;
}

__STATIC_INLINE void cpusysctrl_asdma_clk_clrb(void)
{
    AIC_CPUSYSCTRL->CLKSEL &= ~CSC_CLKSEL_ASDMACLK_BIT;
}

/**
 * Address Offset: 0x008
 * Register Name : CSC HCLK_CTRL_MODE
 */

#define CSC_HCLKCM_CPUP_MANUAL_POS              (0)
#define CSC_HCLKCM_CPUP_MANUAL_BIT              (0x01UL << CSC_HCLKCM_CPUP_MANUAL_POS)
#define CSC_HCLKCM_CPUP_GATED_MANUAL_POS        (1)
#define CSC_HCLKCM_CPUP_GATED_MANUAL_BIT        (0x01UL << CSC_HCLKCM_CPUP_GATED_MANUAL_POS)
#define CSC_HCLKCM_CPUS_MANUAL_POS              (2)
#define CSC_HCLKCM_CPUS_MANUAL_BIT              (0x01UL << CSC_HCLKCM_CPUS_MANUAL_POS)
#define CSC_HCLKCM_CPUS_GATED_MANUAL_POS        (3)
#define CSC_HCLKCM_CPUS_GATED_MANUAL_BIT        (0x01UL << CSC_HCLKCM_CPUS_GATED_MANUAL_POS)
#define CSC_HCLKCM_ROM_MANUAL_POS               (4)
#define CSC_HCLKCM_ROM_MANUAL_BIT               (0x01UL << CSC_HCLKCM_ROM_MANUAL_POS)
#define CSC_HCLKCM_RAM0_MANUAL_POS              (5)
#define CSC_HCLKCM_RAM0_MANUAL_BIT              (0x01UL << CSC_HCLKCM_RAM0_MANUAL_POS)
#define CSC_HCLKCM_RAM1_MANUAL_POS              (6)
#define CSC_HCLKCM_RAM1_MANUAL_BIT              (0x01UL << CSC_HCLKCM_RAM1_MANUAL_POS)
#define CSC_HCLKCM_RAM2_MANUAL_POS              (7)
#define CSC_HCLKCM_RAM2_MANUAL_BIT              (0x01UL << CSC_HCLKCM_RAM2_MANUAL_POS)
#define CSC_HCLKCM_RAM3_MANUAL_POS              (8)
#define CSC_HCLKCM_RAM3_MANUAL_BIT              (0x01UL << CSC_HCLKCM_RAM3_MANUAL_POS)
#define CSC_HCLKCM_RAM4_MANUAL_POS              (9)
#define CSC_HCLKCM_RAM4_MANUAL_BIT              (0x01UL << CSC_HCLKCM_RAM4_MANUAL_POS)
#define CSC_HCLKCM_SYS_MATRIX_MANUAL_POS        (10)
#define CSC_HCLKCM_SYS_MATRIX_MANUAL_BIT        (0x01UL << CSC_HCLKCM_SYS_MATRIX_MANUAL_POS)
#define CSC_HCLKCM_AHB0_MANUAL_POS              (11)
#define CSC_HCLKCM_AHB0_MANUAL_BIT              (0x01UL << CSC_HCLKCM_AHB0_MANUAL_POS)
#define CSC_HCLKCM_AHB1_MANUAL_POS              (12)
#define CSC_HCLKCM_AHB1_MANUAL_BIT              (0x01UL << CSC_HCLKCM_AHB1_MANUAL_POS)
#define CSC_HCLKCM_APB0_MANUAL_POS              (13)
#define CSC_HCLKCM_APB0_MANUAL_BIT              (0x01UL << CSC_HCLKCM_APB0_MANUAL_POS)
#define CSC_HCLKCM_EXMEM_BUS_MANUAL_POS         (14)
#define CSC_HCLKCM_EXMEM_BUS_MANUAL_BIT         (0x01UL << CSC_HCLKCM_EXMEM_BUS_MANUAL_POS)
#define CSC_HCLKCM_CACHE0_MANUAL_POS            (15)
#define CSC_HCLKCM_CACHE0_MANUAL_BIT            (0x01UL << CSC_HCLKCM_CACHE0_MANUAL_POS)
#define CSC_HCLKCM_CACHE1_MANUAL_POS            (16)
#define CSC_HCLKCM_CACHE1_MANUAL_BIT            (0x01UL << CSC_HCLKCM_CACHE1_MANUAL_POS)
#define CSC_HCLKCM_DMA_MANUAL_POS               (17)
#define CSC_HCLKCM_DMA_MANUAL_BIT               (0x01UL << CSC_HCLKCM_DMA_MANUAL_POS)
#define CSC_HCLKCM_FLASH_MANUAL_POS             (18)
#define CSC_HCLKCM_FLASH_MANUAL_BIT             (0x01UL << CSC_HCLKCM_FLASH_MANUAL_POS)
#define CSC_HCLKCM_PSRAM_ALWAYS_MANUAL_POS      (19)
#define CSC_HCLKCM_PSRAM_ALWAYS_MANUAL_BIT      (0x01UL << CSC_HCLKCM_PSRAM_ALWAYS_MANUAL_POS)
#define CSC_HCLKCM_PSRAM_MANUAL_POS             (20)
#define CSC_HCLKCM_PSRAM_MANUAL_BIT             (0x01UL << CSC_HCLKCM_PSRAM_MANUAL_POS)
#define CSC_HCLKCM_PSRAM_REG_MANUAL_POS         (21)
#define CSC_HCLKCM_PSRAM_REG_MANUAL_BIT         (0x01UL << CSC_HCLKCM_PSRAM_REG_MANUAL_POS)
#define CSC_HCLKCM_TRAP_MANUAL_POS              (22)
#define CSC_HCLKCM_TRAP_MANUAL_BIT              (0x01UL << CSC_HCLKCM_TRAP_MANUAL_POS)
#define CSC_HCLKCM_UART0_MANUAL_POS             (23)
#define CSC_HCLKCM_UART0_MANUAL_BIT             (0x01UL << CSC_HCLKCM_UART0_MANUAL_POS)
#define CSC_HCLKCM_UART1_MANUAL_POS             (24)
#define CSC_HCLKCM_UART1_MANUAL_BIT             (0x01UL << CSC_HCLKCM_UART1_MANUAL_POS)
#define CSC_HCLKCM_UART2_MANUAL_POS             (25)
#define CSC_HCLKCM_UART2_MANUAL_BIT             (0x01UL << CSC_HCLKCM_UART2_MANUAL_POS)
#define CSC_HCLKCM_USBC_MANUAL_POS              (26)
#define CSC_HCLKCM_USBC_MANUAL_BIT              (0x01UL << CSC_HCLKCM_USBC_MANUAL_POS)
#define CSC_HCLKCM_VPC_MANUAL_POS               (27)
#define CSC_HCLKCM_VPC_MANUAL_BIT               (0x01UL << CSC_HCLKCM_VPC_MANUAL_POS)
#define CSC_HCLKCM_MAILBOX_MANUAL_POS           (28)
#define CSC_HCLKCM_MAILBOX_MANUAL_BIT           (0x01UL << CSC_HCLKCM_MAILBOX_MANUAL_POS)
#define CSC_HCLKCM_ASDMA_MANUAL_POS             (29)
#define CSC_HCLKCM_ASDMA_MANUAL_BIT             (0x01UL << CSC_HCLKCM_ASDMA_MANUAL_POS)
#define CSC_HCLKCM_SDIO_MANUAL_POS              (30)
#define CSC_HCLKCM_SDIO_MANUAL_BIT              (0x01UL << CSC_HCLKCM_SDIO_MANUAL_POS)
#define CSC_HCLKCM_RAM5_MANUAL_POS              (31)
#define CSC_HCLKCM_RAM5_MANUAL_BIT              (0x01UL << CSC_HCLKCM_RAM5_MANUAL_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclkcm_get()
{
    return AIC_CPUSYSCTRL->HCLKCM;
}

__STATIC_INLINE void cpusysctrl_hclkcm_set(uint32_t manual_mode)
{
    AIC_CPUSYSCTRL->HCLKCM = manual_mode;
}

/**
 * Address Offset: 0x00C
 * Register Name : CSC PCLK_CTRL_MODE
 */

#define CSC_PCLKCM_CPU_SYSCTRL_MANUAL_POS       (0)
#define CSC_PCLKCM_CPU_SYSCTRL_MANUAL_BIT       (0x01UL << CSC_PCLKCM_CPU_SYSCTRL_MANUAL_POS)
#define CSC_PCLKCM_WDG0_MANUAL_POS              (1)
#define CSC_PCLKCM_WDG0_MANUAL_BIT              (0x01UL << CSC_PCLKCM_WDG0_MANUAL_POS)
#define CSC_PCLKCM_WDG1_MANUAL_POS              (2)
#define CSC_PCLKCM_WDG1_MANUAL_BIT              (0x01UL << CSC_PCLKCM_WDG1_MANUAL_POS)
#define CSC_PCLKCM_WDG2_MANUAL_POS              (3)
#define CSC_PCLKCM_WDG2_MANUAL_BIT              (0x01UL << CSC_PCLKCM_WDG2_MANUAL_POS)
#define CSC_PCLKCM_TIMER0_MANUAL_POS            (4)
#define CSC_PCLKCM_TIMER0_MANUAL_BIT            (0x01UL << CSC_PCLKCM_TIMER0_MANUAL_POS)
#define CSC_PCLKCM_TIMER1_MANUAL_POS            (5)
#define CSC_PCLKCM_TIMER1_MANUAL_BIT            (0x01UL << CSC_PCLKCM_TIMER1_MANUAL_POS)
#define CSC_PCLKCM_SPINLOCK_MANUAL_POS          (6)
#define CSC_PCLKCM_SPINLOCK_MANUAL_BIT          (0x01UL << CSC_PCLKCM_SPINLOCK_MANUAL_POS)
#define CSC_PCLKCM_SPI_MANUAL_POS               (7)
#define CSC_PCLKCM_SPI_MANUAL_BIT               (0x01UL << CSC_PCLKCM_SPI_MANUAL_POS)
#define CSC_PCLKCM_PWM_MANUAL_POS               (8)
#define CSC_PCLKCM_PWM_MANUAL_BIT               (0x01UL << CSC_PCLKCM_PWM_MANUAL_POS)
#define CSC_PCLKCM_I2CM_MANUAL_POS              (9)
#define CSC_PCLKCM_I2CM_MANUAL_BIT              (0x01UL << CSC_PCLKCM_I2CM_MANUAL_POS)
#define CSC_PCLKCM_JPEG_ENC_MANUAL_POS          (10)
#define CSC_PCLKCM_JPEG_ENC_MANUAL_BIT          (0x01UL << CSC_PCLKCM_JPEG_ENC_MANUAL_POS)
#define CSC_PCLKCM_TRNG_MANUAL_POS              (11)
#define CSC_PCLKCM_TRNG_MANUAL_BIT              (0x01UL << CSC_PCLKCM_TRNG_MANUAL_POS)
#define CSC_PCLKCM_WDG3_MANUAL_POS              (12)
#define CSC_PCLKCM_WDG3_MANUAL_BIT              (0x01UL << CSC_PCLKCM_WDG3_MANUAL_POS)
#define CSC_PCLKCM_ANALOG_REG0_MANUAL_POS       (13)
#define CSC_PCLKCM_ANALOG_REG0_MANUAL_BIT       (0x01UL << CSC_PCLKCM_ANALOG_REG0_MANUAL_POS)
#define CSC_PCLKCM_PROCESS_MON_MANUAL_POS       (14)
#define CSC_PCLKCM_PROCESS_MON_MANUAL_BIT       (0x01UL << CSC_PCLKCM_PROCESS_MON_MANUAL_POS)

__STATIC_INLINE uint32_t cpusysctrl_pclkcm_get()
{
    return AIC_CPUSYSCTRL->PCLKCM;
}

__STATIC_INLINE void cpusysctrl_pclkcm_set(uint32_t manual_mode)
{
    AIC_CPUSYSCTRL->PCLKCM = manual_mode;
}

/**
 * Address Offset: 0x010
 * Register Name : CSC OCLK_CTRL_MODE
 */

#define CSC_OCLKCM_OPI_2X_ALWAYS_MANUAL_POS     (0)
#define CSC_OCLKCM_OPI_2X_ALWAYS_MANUAL_BIT     (0x01UL << CSC_OCLKCM_OPI_2X_ALWAYS_MANUAL_POS)
#define CSC_OCLKCM_OPI_2X_MANUAL_POS            (1)
#define CSC_OCLKCM_OPI_2X_MANUAL_BIT            (0x01UL << CSC_OCLKCM_OPI_2X_MANUAL_POS)
#define CSC_OCLKCM_SDMMC_MANUAL_POS             (2)
#define CSC_OCLKCM_SDMMC_MANUAL_BIT             (0x01UL << CSC_OCLKCM_SDMMC_MANUAL_POS)
#define CSC_OCLKCM_ASDMA_MANUAL_POS             (3)
#define CSC_OCLKCM_ASDMA_MANUAL_BIT             (0x01UL << CSC_OCLKCM_ASDMA_MANUAL_POS)
#define CSC_OCLKCM_FLASH_MANUAL_POS             (4)
#define CSC_OCLKCM_FLASH_MANUAL_BIT             (0x01UL << CSC_OCLKCM_FLASH_MANUAL_POS)
#define CSC_OCLKCM_TIMER00_MANUAL_POS           (5)
#define CSC_OCLKCM_TIMER00_MANUAL_BIT           (0x01UL << CSC_OCLKCM_TIMER00_MANUAL_POS)
#define CSC_OCLKCM_TIMER01_MANUAL_POS           (6)
#define CSC_OCLKCM_TIMER01_MANUAL_BIT           (0x01UL << CSC_OCLKCM_TIMER01_MANUAL_POS)
#define CSC_OCLKCM_TIMER10_MANUAL_POS           (7)
#define CSC_OCLKCM_TIMER10_MANUAL_BIT           (0x01UL << CSC_OCLKCM_TIMER10_MANUAL_POS)
#define CSC_OCLKCM_TIMER11_MANUAL_POS           (8)
#define CSC_OCLKCM_TIMER11_MANUAL_BIT           (0x01UL << CSC_OCLKCM_TIMER11_MANUAL_POS)
#define CSC_OCLKCM_SPI_MANUAL_POS               (9)
#define CSC_OCLKCM_SPI_MANUAL_BIT               (0x01UL << CSC_OCLKCM_SPI_MANUAL_POS)
#define CSC_OCLKCM_UART0_MANUAL_POS             (10)
#define CSC_OCLKCM_UART0_MANUAL_BIT             (0x01UL << CSC_OCLKCM_UART0_MANUAL_POS)
#define CSC_OCLKCM_UART1_MANUAL_POS             (11)
#define CSC_OCLKCM_UART1_MANUAL_BIT             (0x01UL << CSC_OCLKCM_UART1_MANUAL_POS)
#define CSC_OCLKCM_UART2_MANUAL_POS             (12)
#define CSC_OCLKCM_UART2_MANUAL_BIT             (0x01UL << CSC_OCLKCM_UART2_MANUAL_POS)
#define CSC_OCLKCM_ULPI_MANUAL_POS              (13)
#define CSC_OCLKCM_ULPI_MANUAL_BIT              (0x01UL << CSC_OCLKCM_ULPI_MANUAL_POS)
#define CSC_OCLKCM_SDIO_MANUAL_POS              (14)
#define CSC_OCLKCM_SDIO_MANUAL_BIT              (0x01UL << CSC_OCLKCM_SDIO_MANUAL_POS)
#define CSC_OCLKCM_PWM_MANUAL_POS               (15)
#define CSC_OCLKCM_PWM_MANUAL_BIT               (0x01UL << CSC_OCLKCM_PWM_MANUAL_POS)
#define CSC_OCLKCM_TIMER02_MANUAL_POS           (16)
#define CSC_OCLKCM_TIMER02_MANUAL_BIT           (0x01UL << CSC_OCLKCM_TIMER02_MANUAL_POS)
#define CSC_OCLKCM_TIMER12_MANUAL_POS           (17)
#define CSC_OCLKCM_TIMER12_MANUAL_BIT           (0x01UL << CSC_OCLKCM_TIMER12_MANUAL_POS)
#define CSC_OCLKCM_RTC_ALWAYS_MANUAL_POS        (18)
#define CSC_OCLKCM_RTC_ALWAYS_MANUAL_BIT        (0x01UL << CSC_OCLKCM_RTC_ALWAYS_MANUAL_POS)
#define CSC_OCLKCM_RTC_WDG0_MANUAL_POS          (19)
#define CSC_OCLKCM_RTC_WDG0_MANUAL_BIT          (0x01UL << CSC_OCLKCM_RTC_WDG0_MANUAL_POS)
#define CSC_OCLKCM_RTC_WDG1_MANUAL_POS          (20)
#define CSC_OCLKCM_RTC_WDG1_MANUAL_BIT          (0x01UL << CSC_OCLKCM_RTC_WDG1_MANUAL_POS)
#define CSC_OCLKCM_RTC_WDG2_MANUAL_POS          (21)
#define CSC_OCLKCM_RTC_WDG2_MANUAL_BIT          (0x01UL << CSC_OCLKCM_RTC_WDG2_MANUAL_POS)
#define CSC_OCLKCM_DDR_2X_MANUAL_POS            (22)
#define CSC_OCLKCM_DDR_2X_MANUAL_BIT            (0x01UL << CSC_OCLKCM_DDR_2X_MANUAL_POS)
#define CSC_OCLKCM_DDR_2X_ALWAYS_MANUAL_POS     (23)
#define CSC_OCLKCM_DDR_2X_ALWAYS_MANUAL_BIT     (0x01UL << CSC_OCLKCM_DDR_2X_ALWAYS_MANUAL_POS)
#define CSC_OCLKCM_CAMERA_REF_MANUAL_POS        (24)
#define CSC_OCLKCM_CAMERA_REF_MANUAL_BIT        (0x01UL << CSC_OCLKCM_CAMERA_REF_MANUAL_POS)
#define CSC_OCLKCM_AUDIO_PROC_MANUAL_POS        (25)
#define CSC_OCLKCM_AUDIO_PROC_MANUAL_BIT        (0x01UL << CSC_OCLKCM_AUDIO_PROC_MANUAL_POS)
#define CSC_OCLKCM_PROCESS_MON_MANUAL_POS       (26)
#define CSC_OCLKCM_PROCESS_MON_MANUAL_BIT       (0x01UL << CSC_OCLKCM_PROCESS_MON_MANUAL_POS)
#define CSC_OCLKCM_RTC_WDG3_MANUAL_POS          (27)
#define CSC_OCLKCM_RTC_WDG3_MANUAL_BIT          (0x01UL << CSC_OCLKCM_RTC_WDG3_MANUAL_POS)
#define CSC_OCLKCM_26M_ASDMA_MANUAL_POS         (28)
#define CSC_OCLKCM_26M_ASDMA_MANUAL_BIT         (0x01UL << CSC_OCLKCM_26M_ASDMA_MANUAL_POS)
#define CSC_OCLKCM_BCK0_MANUAL_POS              (29)
#define CSC_OCLKCM_BCK0_MANUAL_BIT              (0x01UL << CSC_OCLKCM_BCK0_MANUAL_POS)
#define CSC_OCLKCM_BCK1_MANUAL_POS              (30)
#define CSC_OCLKCM_BCK1_MANUAL_BIT              (0x01UL << CSC_OCLKCM_BCK1_MANUAL_POS)
#define CSC_OCLKCM_SPDIF_MANUAL_POS             (31)
#define CSC_OCLKCM_SPDIF_MANUAL_BIT             (0x01UL << CSC_OCLKCM_SPDIF_MANUAL_POS)

__STATIC_INLINE uint32_t cpusysctrl_oclkcm_get()
{
    return AIC_CPUSYSCTRL->OCLKCM;
}

__STATIC_INLINE void cpusysctrl_oclkcm_set(uint32_t manual_mode)
{
    AIC_CPUSYSCTRL->OCLKCM = manual_mode;
}

/**
 * Address Offset: 0x05C
 * Register Name : CSC CACHE_BYPASS
 */

#define CSC_CACHEBP_BURST_INCR_ONLY_EN_POS      (2)
#define CSC_CACHEBP_BURST_INCR_ONLY_EN_BIT      (0x01UL << CSC_CACHEBP_BURST_INCR_ONLY_EN_POS)

__STATIC_INLINE uint8_t cpusysctrl_cachebp_burst_incr_only_en_getb(void)
{
    return (AIC_CPUSYSCTRL->CACHEBP & CSC_CACHEBP_BURST_INCR_ONLY_EN_BIT) >> CSC_CACHEBP_BURST_INCR_ONLY_EN_POS;
}

__STATIC_INLINE void cpusysctrl_cachebp_burst_incr_only_en_setb(void)
{
    AIC_CPUSYSCTRL->CACHEBP |=  CSC_CACHEBP_BURST_INCR_ONLY_EN_BIT;
}

__STATIC_INLINE void cpusysctrl_cachebp_burst_incr_only_en_clrb(void)
{
    AIC_CPUSYSCTRL->CACHEBP &= ~CSC_CACHEBP_BURST_INCR_ONLY_EN_BIT;
}

/**
 * Address Offset: 0x060
 * Register Name : CSC HCLK1_CTRL_MODE
 */

#define CSC_HCLK1CM_DSP_MANUAL_POS              (0)
#define CSC_HCLK1CM_DSP_MANUAL_BIT              (0x01UL << CSC_HCLK1CM_DSP_MANUAL_POS)
#define CSC_HCLK1CM_DSP_GATED_MANUAL_POS        (1)
#define CSC_HCLK1CM_DSP_GATED_MANUAL_BIT        (0x01UL << CSC_HCLK1CM_DSP_GATED_MANUAL_POS)
#define CSC_HCLK1CM_CAMERA_MANUAL_POS           (2)
#define CSC_HCLK1CM_CAMERA_MANUAL_BIT           (0x01UL << CSC_HCLK1CM_CAMERA_MANUAL_POS)
#define CSC_HCLK1CM_SPI_CAMERA_MANUAL_POS       (3)
#define CSC_HCLK1CM_SPI_CAMERA_MANUAL_BIT       (0x01UL << CSC_HCLK1CM_SPI_CAMERA_MANUAL_POS)
#define CSC_HCLK1CM_JPEG_ENC_MANUAL_POS         (4)
#define CSC_HCLK1CM_JPEG_ENC_MANUAL_BIT         (0x01UL << CSC_HCLK1CM_JPEG_ENC_MANUAL_POS)
#define CSC_HCLK1CM_BTROM_MANUAL_POS            (5)
#define CSC_HCLK1CM_BTROM_MANUAL_BIT            (0x01UL << CSC_HCLK1CM_BTROM_MANUAL_POS)
#define CSC_HCLK1CM_DSP_MATRIX_MANUAL_POS       (6)
#define CSC_HCLK1CM_DSP_MATRIX_MANUAL_BIT       (0x01UL << CSC_HCLK1CM_DSP_MATRIX_MANUAL_POS)
#define CSC_HCLK1CM_SRAM6_MANUAL_POS            (7)
#define CSC_HCLK1CM_SRAM6_MANUAL_BIT            (0x01UL << CSC_HCLK1CM_SRAM6_MANUAL_POS)
#define CSC_HCLK1CM_SDMMC_ALWAYS_MANUAL_POS     (8)
#define CSC_HCLK1CM_SDMMC_ALWAYS_MANUAL_BIT     (0x01UL << CSC_HCLK1CM_SDMMC_ALWAYS_MANUAL_POS)
#define CSC_HCLK1CM_SDMMC_MANUAL_POS            (9)
#define CSC_HCLK1CM_SDMMC_MANUAL_BIT            (0x01UL << CSC_HCLK1CM_SDMMC_MANUAL_POS)
#define CSC_HCLK1CM_CPUSB_MANUAL_POS            (10)
#define CSC_HCLK1CM_CPUSB_MANUAL_BIT            (0x01UL << CSC_HCLK1CM_CPUSB_MANUAL_POS)
#define CSC_HCLK1CM_CPUSB_GATED_MANUAL_POS      (11)
#define CSC_HCLK1CM_CPUSB_GATED_MANUAL_BIT      (0x01UL << CSC_HCLK1CM_CPUSB_GATED_MANUAL_POS)
#define CSC_HCLK1CM_SRAM5_LOW_MANUAL_POS        (12)
#define CSC_HCLK1CM_SRAM5_LOW_MANUAL_BIT        (0x01UL << CSC_HCLK1CM_SRAM5_LOW_MANUAL_POS)
#define CSC_HCLK1CM_SRAM5_HIGH_MANUAL_POS       (13)
#define CSC_HCLK1CM_SRAM5_HIGH_MANUAL_BIT       (0x01UL << CSC_HCLK1CM_SRAM5_HIGH_MANUAL_POS)
#define CSC_HCLK1CM_MM_MANUAL_POS               (14)
#define CSC_HCLK1CM_MM_MANUAL_BIT               (0x01UL << CSC_HCLK1CM_MM_MANUAL_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclk1cm_get()
{
    return AIC_CPUSYSCTRL->HCLK1CM;
}

__STATIC_INLINE void cpusysctrl_hclk1cm_set(uint32_t manual_mode)
{
    AIC_CPUSYSCTRL->HCLK1CM = manual_mode;
}

/**
 * Address Offset: 0x07C
 * Register Name : CSC PSRAM_MODE_SEL
 */

#define CSC_PSRMDSEL_UHSMD_POS          (0)
#define CSC_PSRMDSEL_UHSMD_BIT          (0x01UL << CSC_PSRMDSEL_UHSMD_POS)

__STATIC_INLINE uint8_t cpusysctrl_psrmdsel_uhsmd_getb(void)
{
    return (AIC_CPUSYSCTRL->PSRMDSEL & CSC_PSRMDSEL_UHSMD_BIT) >> CSC_PSRMDSEL_UHSMD_POS;
}

__STATIC_INLINE void cpusysctrl_psrmdsel_uhsmd_setb(void)
{
    AIC_CPUSYSCTRL->PSRMDSEL |=  CSC_PSRMDSEL_UHSMD_BIT;
}

__STATIC_INLINE void cpusysctrl_psrmdsel_uhsmd_clrb(void)
{
    AIC_CPUSYSCTRL->PSRMDSEL &= ~CSC_PSRMDSEL_UHSMD_BIT;
}

/**
 * Address Offset: 0x084
 * Register Name : CSC PCLK_DIV
 */

#define CSC_PCLKDIV_DENOM_LSB           (0)
#define CSC_PCLKDIV_DENOM_WIDTH         (8)
#define CSC_PCLKDIV_DENOM_MASK          (((0x01UL << CSC_PCLKDIV_DENOM_WIDTH) - 1) << CSC_PCLKDIV_DENOM_LSB)
#define CSC_PCLKDIV_UPDATE_POS          (8)
#define CSC_PCLKDIV_UPDATE_BIT          (0x01UL << CSC_PCLKDIV_UPDATE_POS)

__STATIC_INLINE uint8_t cpusysctrl_pclkdiv_denom_getf(void)
{
    return ((AIC_CPUSYSCTRL->PCLKDIV & CSC_PCLKDIV_DENOM_MASK) >> CSC_PCLKDIV_DENOM_LSB);
}

__STATIC_INLINE void cpusysctrl_pclkdiv_denom_setf(uint8_t div_denom)
{
    uint32_t local_val = AIC_CPUSYSCTRL->PCLKDIV & ~CSC_PCLKDIV_DENOM_MASK;
    AIC_CPUSYSCTRL->PCLKDIV = local_val | ((div_denom << CSC_PCLKDIV_DENOM_LSB) & CSC_PCLKDIV_DENOM_MASK) | CSC_PCLKDIV_UPDATE_BIT;
}

/**
 * Address Offset: 0x090
 * Register Name : CSC ULPI_CLK_DETECT
 */

#define CSC_ULPICD_CLKDETTH_LSB         (0)
#define CSC_ULPICD_CLKDETTH_WIDTH       (8)
#define CSC_ULPICD_CLKDETTH_MASK        (((0x01UL << CSC_ULPICD_CLKDETTH_WIDTH) - 1) << CSC_ULPICD_CLKDETTH_LSB)
#define CSC_ULPICD_CLKDETEN_POS         (8)
#define CSC_ULPICD_CLKDETEN_BIT         (0x01UL << CSC_ULPICD_CLKDETEN_POS)

__STATIC_INLINE uint8_t cpusysctrl_ulpicd_clkdetth_getf(void)
{
    return ((AIC_CPUSYSCTRL->ULPICD & CSC_ULPICD_CLKDETTH_MASK) >> CSC_ULPICD_CLKDETTH_LSB);
}

__STATIC_INLINE void cpusysctrl_ulpicd_clkdetth_setf(uint8_t clkdet_th)
{
    uint32_t local_val = AIC_CPUSYSCTRL->ULPICD & ~CSC_ULPICD_CLKDETTH_MASK;
    AIC_CPUSYSCTRL->ULPICD = local_val | ((clkdet_th << CSC_ULPICD_CLKDETTH_LSB) & CSC_ULPICD_CLKDETTH_MASK) | CSC_ULPICD_CLKDETEN_BIT;
}

/**
 * Address Offset: 0x094
 * Register Name : CSC ULPI_CLK_STATUS
 */

#define CSC_ULPICS_CLKST_POS            (0)
#define CSC_ULPICS_CLKST_BIT            (0x01UL << CSC_ULPICS_CLKST_POS)

__STATIC_INLINE uint32_t cpusysctrl_ulpics_get(void)
{
    return AIC_CPUSYSCTRL->ULPICS;
}

__STATIC_INLINE uint8_t cpusysctrl_ulpics_clkst_getf(void)
{
    return ((AIC_CPUSYSCTRL->ULPICS & CSC_ULPICS_CLKST_BIT) >> CSC_ULPICS_CLKST_POS);
}

/**
 * Address Offset: 0x100
 * Register Name : CSC HCLK_MANUAL_ENABLE (write 1 valid)
 */

#define CSC_HCLKME_CPUP_EN_POS                (0)
#define CSC_HCLKME_CPUP_EN_BIT                (0x01UL << CSC_HCLKME_CPUP_EN_POS)
#define CSC_HCLKME_CPUP_GATED_EN_POS          (1)
#define CSC_HCLKME_CPUP_GATED_EN_BIT          (0x01UL << CSC_HCLKME_CPUP_GATED_EN_POS)
#define CSC_HCLKME_CPUS_EN_POS                (2)
#define CSC_HCLKME_CPUS_EN_BIT                (0x01UL << CSC_HCLKME_CPUS_EN_POS)
#define CSC_HCLKME_CPUS_GATED_EN_POS          (3)
#define CSC_HCLKME_CPUS_GATED_EN_BIT          (0x01UL << CSC_HCLKME_CPUS_GATED_EN_POS)
#define CSC_HCLKME_ROM_EN_POS                 (4)
#define CSC_HCLKME_ROM_EN_BIT                 (0x01UL << CSC_HCLKME_ROM_EN_POS)
#define CSC_HCLKME_RAM0_EN_POS                (5)
#define CSC_HCLKME_RAM0_EN_BIT                (0x01UL << CSC_HCLKME_RAM0_EN_POS)
#define CSC_HCLKME_RAM1_EN_POS                (6)
#define CSC_HCLKME_RAM1_EN_BIT                (0x01UL << CSC_HCLKME_RAM1_EN_POS)
#define CSC_HCLKME_RAM2_EN_POS                (7)
#define CSC_HCLKME_RAM2_EN_BIT                (0x01UL << CSC_HCLKME_RAM2_EN_POS)
#define CSC_HCLKME_RAM3_EN_POS                (8)
#define CSC_HCLKME_RAM3_EN_BIT                (0x01UL << CSC_HCLKME_RAM3_EN_POS)
#define CSC_HCLKME_RAM4_EN_POS                (9)
#define CSC_HCLKME_RAM4_EN_BIT                (0x01UL << CSC_HCLKME_RAM4_EN_POS)
#define CSC_HCLKME_SYS_MATRIX_EN_POS          (10)
#define CSC_HCLKME_SYS_MATRIX_EN_BIT          (0x01UL << CSC_HCLKME_SYS_MATRIX_EN_POS)
#define CSC_HCLKME_AHB0_EN_POS                (11)
#define CSC_HCLKME_AHB0_EN_BIT                (0x01UL << CSC_HCLKME_AHB0_EN_POS)
#define CSC_HCLKME_AHB1_EN_POS                (12)
#define CSC_HCLKME_AHB1_EN_BIT                (0x01UL << CSC_HCLKME_AHB1_EN_POS)
#define CSC_HCLKME_APB0_EN_POS                (13)
#define CSC_HCLKME_APB0_EN_BIT                (0x01UL << CSC_HCLKME_APB0_EN_POS)
#define CSC_HCLKME_EXMEM_BUS_EN_POS           (14)
#define CSC_HCLKME_EXMEM_BUS_EN_BIT           (0x01UL << CSC_HCLKME_EXMEM_BUS_EN_POS)
#define CSC_HCLKME_CACHE0_EN_POS              (15)
#define CSC_HCLKME_CACHE0_EN_BIT              (0x01UL << CSC_HCLKME_CACHE0_EN_POS)
#define CSC_HCLKME_CACHE1_EN_POS              (16)
#define CSC_HCLKME_CACHE1_EN_BIT              (0x01UL << CSC_HCLKME_CACHE1_EN_POS)
#define CSC_HCLKME_DMA_EN_POS                 (17)
#define CSC_HCLKME_DMA_EN_BIT                 (0x01UL << CSC_HCLKME_DMA_EN_POS)
#define CSC_HCLKME_FLASH_EN_POS               (18)
#define CSC_HCLKME_FLASH_EN_BIT               (0x01UL << CSC_HCLKME_FLASH_EN_POS)
#define CSC_HCLKME_PSRAM_ALWAYS_EN_POS        (19)
#define CSC_HCLKME_PSRAM_ALWAYS_EN_BIT        (0x01UL << CSC_HCLKME_PSRAM_ALWAYS_EN_POS)
#define CSC_HCLKME_PSRAM_EN_POS               (20)
#define CSC_HCLKME_PSRAM_EN_BIT               (0x01UL << CSC_HCLKME_PSRAM_EN_POS)
#define CSC_HCLKME_PSRAM_REG_EN_POS           (21)
#define CSC_HCLKME_PSRAM_REG_EN_BIT           (0x01UL << CSC_HCLKME_PSRAM_REG_EN_POS)
#define CSC_HCLKME_TRAP_EN_POS                (22)
#define CSC_HCLKME_TRAP_EN_BIT                (0x01UL << CSC_HCLKME_TRAP_EN_POS)
#define CSC_HCLKME_UART0_EN_POS               (23)
#define CSC_HCLKME_UART0_EN_BIT               (0x01UL << CSC_HCLKME_UART0_EN_POS)
#define CSC_HCLKME_UART1_EN_POS               (24)
#define CSC_HCLKME_UART1_EN_BIT               (0x01UL << CSC_HCLKME_UART1_EN_POS)
#define CSC_HCLKME_UART2_EN_POS               (25)
#define CSC_HCLKME_UART2_EN_BIT               (0x01UL << CSC_HCLKME_UART2_EN_POS)
#define CSC_HCLKME_USBC_EN_POS                (26)
#define CSC_HCLKME_USBC_EN_BIT                (0x01UL << CSC_HCLKME_USBC_EN_POS)
#define CSC_HCLKME_VPC_EN_POS                 (27)
#define CSC_HCLKME_VPC_EN_BIT                 (0x01UL << CSC_HCLKME_VPC_EN_POS)
#define CSC_HCLKME_MAILBOX_EN_POS             (28)
#define CSC_HCLKME_MAILBOX_EN_BIT             (0x01UL << CSC_HCLKME_MAILBOX_EN_POS)
#define CSC_HCLKME_ASDMA_EN_POS               (29)
#define CSC_HCLKME_ASDMA_EN_BIT               (0x01UL << CSC_HCLKME_ASDMA_EN_POS)
#define CSC_HCLKME_SDIO_EN_POS                (30)
#define CSC_HCLKME_SDIO_EN_BIT                (0x01UL << CSC_HCLKME_SDIO_EN_POS)
#define CSC_HCLKME_RAM5_EN_POS                (31)
#define CSC_HCLKME_RAM5_EN_BIT                (0x01UL << CSC_HCLKME_RAM5_EN_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclkme_get()
{
    return AIC_CPUSYSCTRL->HCLKME;
}

__STATIC_INLINE void cpusysctrl_hclkme_set(uint32_t enable_bits)
{
    AIC_CPUSYSCTRL->HCLKME = enable_bits;
}

/**
 * Address Offset: 0x104
 * Register Name : CSC HCLK_MANUAL_DISABLE (write 1 valid)
 */

#define CSC_HCLKMD_CPUP_DIS_POS                (0)
#define CSC_HCLKMD_CPUP_DIS_BIT                (0x01UL << CSC_HCLKMD_CPUP_DIS_POS)
#define CSC_HCLKMD_CPUP_GATED_DIS_POS          (1)
#define CSC_HCLKMD_CPUP_GATED_DIS_BIT          (0x01UL << CSC_HCLKMD_CPUP_GATED_DIS_POS)
#define CSC_HCLKMD_CPUS_DIS_POS                (2)
#define CSC_HCLKMD_CPUS_DIS_BIT                (0x01UL << CSC_HCLKMD_CPUS_DIS_POS)
#define CSC_HCLKMD_CPUS_GATED_DIS_POS          (3)
#define CSC_HCLKMD_CPUS_GATED_DIS_BIT          (0x01UL << CSC_HCLKMD_CPUS_GATED_DIS_POS)
#define CSC_HCLKMD_ROM_DIS_POS                 (4)
#define CSC_HCLKMD_ROM_DIS_BIT                 (0x01UL << CSC_HCLKMD_ROM_DIS_POS)
#define CSC_HCLKMD_RAM0_DIS_POS                (5)
#define CSC_HCLKMD_RAM0_DIS_BIT                (0x01UL << CSC_HCLKMD_RAM0_DIS_POS)
#define CSC_HCLKMD_RAM1_DIS_POS                (6)
#define CSC_HCLKMD_RAM1_DIS_BIT                (0x01UL << CSC_HCLKMD_RAM1_DIS_POS)
#define CSC_HCLKMD_RAM2_DIS_POS                (7)
#define CSC_HCLKMD_RAM2_DIS_BIT                (0x01UL << CSC_HCLKMD_RAM2_DIS_POS)
#define CSC_HCLKMD_RAM3_DIS_POS                (8)
#define CSC_HCLKMD_RAM3_DIS_BIT                (0x01UL << CSC_HCLKMD_RAM3_DIS_POS)
#define CSC_HCLKMD_RAM4_DIS_POS                (9)
#define CSC_HCLKMD_RAM4_DIS_BIT                (0x01UL << CSC_HCLKMD_RAM4_DIS_POS)
#define CSC_HCLKMD_SYS_MATRIX_DIS_POS          (10)
#define CSC_HCLKMD_SYS_MATRIX_DIS_BIT          (0x01UL << CSC_HCLKMD_SYS_MATRIX_DIS_POS)
#define CSC_HCLKMD_AHB0_DIS_POS                (11)
#define CSC_HCLKMD_AHB0_DIS_BIT                (0x01UL << CSC_HCLKMD_AHB0_DIS_POS)
#define CSC_HCLKMD_AHB1_DIS_POS                (12)
#define CSC_HCLKMD_AHB1_DIS_BIT                (0x01UL << CSC_HCLKMD_AHB1_DIS_POS)
#define CSC_HCLKMD_APB0_DIS_POS                (13)
#define CSC_HCLKMD_APB0_DIS_BIT                (0x01UL << CSC_HCLKMD_APB0_DIS_POS)
#define CSC_HCLKMD_EXMEM_BUS_DIS_POS           (14)
#define CSC_HCLKMD_EXMEM_BUS_DIS_BIT           (0x01UL << CSC_HCLKMD_EXMEM_BUS_DIS_POS)
#define CSC_HCLKMD_CACHE0_DIS_POS              (15)
#define CSC_HCLKMD_CACHE0_DIS_BIT              (0x01UL << CSC_HCLKMD_CACHE0_DIS_POS)
#define CSC_HCLKMD_CACHE1_DIS_POS              (16)
#define CSC_HCLKMD_CACHE1_DIS_BIT              (0x01UL << CSC_HCLKMD_CACHE1_DIS_POS)
#define CSC_HCLKMD_DMA_DIS_POS                 (17)
#define CSC_HCLKMD_DMA_DIS_BIT                 (0x01UL << CSC_HCLKMD_DMA_DIS_POS)
#define CSC_HCLKMD_FLASH_DIS_POS               (18)
#define CSC_HCLKMD_FLASH_DIS_BIT               (0x01UL << CSC_HCLKMD_FLASH_DIS_POS)
#define CSC_HCLKMD_PSRAM_ALWAYS_DIS_POS        (19)
#define CSC_HCLKMD_PSRAM_ALWAYS_DIS_BIT        (0x01UL << CSC_HCLKMD_PSRAM_ALWAYS_DIS_POS)
#define CSC_HCLKMD_PSRAM_DIS_POS               (20)
#define CSC_HCLKMD_PSRAM_DIS_BIT               (0x01UL << CSC_HCLKMD_PSRAM_DIS_POS)
#define CSC_HCLKMD_PSRAM_REG_DIS_POS           (21)
#define CSC_HCLKMD_PSRAM_REG_DIS_BIT           (0x01UL << CSC_HCLKMD_PSRAM_REG_DIS_POS)
#define CSC_HCLKMD_TRAP_DIS_POS                (22)
#define CSC_HCLKMD_TRAP_DIS_BIT                (0x01UL << CSC_HCLKMD_TRAP_DIS_POS)
#define CSC_HCLKMD_UART0_DIS_POS               (23)
#define CSC_HCLKMD_UART0_DIS_BIT               (0x01UL << CSC_HCLKMD_UART0_DIS_POS)
#define CSC_HCLKMD_UART1_DIS_POS               (24)
#define CSC_HCLKMD_UART1_DIS_BIT               (0x01UL << CSC_HCLKMD_UART1_DIS_POS)
#define CSC_HCLKMD_UART2_DIS_POS               (25)
#define CSC_HCLKMD_UART2_DIS_BIT               (0x01UL << CSC_HCLKMD_UART2_DIS_POS)
#define CSC_HCLKMD_USBC_DIS_POS                (26)
#define CSC_HCLKMD_USBC_DIS_BIT                (0x01UL << CSC_HCLKMD_USBC_DIS_POS)
#define CSC_HCLKMD_VPC_DIS_POS                 (27)
#define CSC_HCLKMD_VPC_DIS_BIT                 (0x01UL << CSC_HCLKMD_VPC_DIS_POS)
#define CSC_HCLKMD_MAILBOX_DIS_POS             (28)
#define CSC_HCLKMD_MAILBOX_DIS_BIT             (0x01UL << CSC_HCLKMD_MAILBOX_DIS_POS)
#define CSC_HCLKMD_ASDMA_DIS_POS               (29)
#define CSC_HCLKMD_ASDMA_DIS_BIT               (0x01UL << CSC_HCLKMD_ASDMA_DIS_POS)
#define CSC_HCLKMD_SDIO_DIS_POS                (30)
#define CSC_HCLKMD_SDIO_DIS_BIT                (0x01UL << CSC_HCLKMD_SDIO_DIS_POS)
#define CSC_HCLKMD_RAM5_DIS_POS                (31)
#define CSC_HCLKMD_RAM5_DIS_BIT                (0x01UL << CSC_HCLKMD_RAM5_DIS_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclkmd_get()
{
    return AIC_CPUSYSCTRL->HCLKMD;
}

__STATIC_INLINE void cpusysctrl_hclkmd_set(uint32_t disable_bits)
{
    AIC_CPUSYSCTRL->HCLKMD = disable_bits;
}

/**
 * Address Offset: 0x108
 * Register Name : CSC PCLK_MANUAL_ENABLE (write 1 valid)
 */

#define CSC_PCLKME_CPU_SYSCTRL_EN_POS        (0)
#define CSC_PCLKME_CPU_SYSCTRL_EN_BIT        (0x01UL << CSC_PCLKME_CPU_SYSCTRL_EN_POS)
#define CSC_PCLKME_WDG0_EN_POS               (1)
#define CSC_PCLKME_WDG0_EN_BIT               (0x01UL << CSC_PCLKME_WDG0_EN_POS)
#define CSC_PCLKME_WDG1_EN_POS               (2)
#define CSC_PCLKME_WDG1_EN_BIT               (0x01UL << CSC_PCLKME_WDG1_EN_POS)
#define CSC_PCLKME_WDG2_EN_POS               (3)
#define CSC_PCLKME_WDG2_EN_BIT               (0x01UL << CSC_PCLKME_WDG2_EN_POS)
#define CSC_PCLKME_TIMER0_EN_POS             (4)
#define CSC_PCLKME_TIMER0_EN_BIT             (0x01UL << CSC_PCLKME_TIMER0_EN_POS)
#define CSC_PCLKME_TIMER1_EN_POS             (5)
#define CSC_PCLKME_TIMER1_EN_BIT             (0x01UL << CSC_PCLKME_TIMER1_EN_POS)
#define CSC_PCLKME_SPINLOCK_EN_POS           (6)
#define CSC_PCLKME_SPINLOCK_EN_BIT           (0x01UL << CSC_PCLKME_SPINLOCK_EN_POS)
#define CSC_PCLKME_SPI_EN_POS                (7)
#define CSC_PCLKME_SPI_EN_BIT                (0x01UL << CSC_PCLKME_SPI_EN_POS)
#define CSC_PCLKME_PWM_EN_POS                (8)
#define CSC_PCLKME_PWM_EN_BIT                (0x01UL << CSC_PCLKME_PWM_EN_POS)
#define CSC_PCLKME_I2CM_EN_POS               (9)
#define CSC_PCLKME_I2CM_EN_BIT               (0x01UL << CSC_PCLKME_I2CM_EN_POS)
#define CSC_PCLKME_TRNG_EN_POS               (10)
#define CSC_PCLKME_TRNG_EN_BIT               (0x01UL << CSC_PCLKME_TRNG_EN_POS)
#define CSC_PCLKME_WDG3_EN_POS               (11)
#define CSC_PCLKME_WDG3_EN_BIT               (0x01UL << CSC_PCLKME_WDG3_EN_POS)
#define CSC_PCLKME_PROCESS_MON_EN_POS        (12)
#define CSC_PCLKME_PROCESS_MON_EN_BIT        (0x01UL << CSC_PCLKME_PROCESS_MON_EN_POS)
#define CSC_PCLKME_ANALOG_REG0_EN_POS        (13)
#define CSC_PCLKME_ANALOG_REG0_EN_BIT        (0x01UL << CSC_PCLKME_ANALOG_REG0_EN_POS)

__STATIC_INLINE uint32_t cpusysctrl_pclkme_get()
{
    return AIC_CPUSYSCTRL->PCLKME;
}

__STATIC_INLINE void cpusysctrl_pclkme_set(uint32_t enable_bits)
{
    AIC_CPUSYSCTRL->PCLKME = enable_bits;
}

/**
 * Address Offset: 0x10C
 * Register Name : CSC PCLK_MANUAL_DISABLE (write 1 valid)
 */

#define CSC_PCLKMD_CPU_SYSCTRL_DIS_POS        (0)
#define CSC_PCLKMD_CPU_SYSCTRL_DIS_BIT        (0x01UL << CSC_PCLKMD_CPU_SYSCTRL_DIS_POS)
#define CSC_PCLKMD_WDG0_DIS_POS               (1)
#define CSC_PCLKMD_WDG0_DIS_BIT               (0x01UL << CSC_PCLKMD_WDG0_DIS_POS)
#define CSC_PCLKMD_WDG1_DIS_POS               (2)
#define CSC_PCLKMD_WDG1_DIS_BIT               (0x01UL << CSC_PCLKMD_WDG1_DIS_POS)
#define CSC_PCLKMD_WDG2_DIS_POS               (3)
#define CSC_PCLKMD_WDG2_DIS_BIT               (0x01UL << CSC_PCLKMD_WDG2_DIS_POS)
#define CSC_PCLKMD_TIMER0_DIS_POS             (4)
#define CSC_PCLKMD_TIMER0_DIS_BIT             (0x01UL << CSC_PCLKMD_TIMER0_DIS_POS)
#define CSC_PCLKMD_TIMER1_DIS_POS             (5)
#define CSC_PCLKMD_TIMER1_DIS_BIT             (0x01UL << CSC_PCLKMD_TIMER1_DIS_POS)
#define CSC_PCLKMD_SPINLOCK_DIS_POS           (6)
#define CSC_PCLKMD_SPINLOCK_DIS_BIT           (0x01UL << CSC_PCLKMD_SPINLOCK_DIS_POS)
#define CSC_PCLKMD_SPI_DIS_POS                (7)
#define CSC_PCLKMD_SPI_DIS_BIT                (0x01UL << CSC_PCLKMD_SPI_DIS_POS)
#define CSC_PCLKMD_PWM_DIS_POS                (8)
#define CSC_PCLKMD_PWM_DIS_BIT                (0x01UL << CSC_PCLKMD_PWM_DIS_POS)
#define CSC_PCLKMD_I2CM_DIS_POS               (9)
#define CSC_PCLKMD_I2CM_DIS_BIT               (0x01UL << CSC_PCLKMD_I2CM_DIS_POS)
#define CSC_PCLKMD_TRNG_DIS_POS               (10)
#define CSC_PCLKMD_TRNG_DIS_BIT               (0x01UL << CSC_PCLKMD_TRNG_DIS_POS)
#define CSC_PCLKMD_WDG3_DIS_POS               (11)
#define CSC_PCLKMD_WDG3_DIS_BIT               (0x01UL << CSC_PCLKMD_WDG3_DIS_POS)
#define CSC_PCLKMD_PROCESS_MON_DIS_POS        (12)
#define CSC_PCLKMD_PROCESS_MON_DIS_BIT        (0x01UL << CSC_PCLKMD_PROCESS_MON_DIS_POS)
#define CSC_PCLKMD_ANALOG_REG0_DIS_POS        (13)
#define CSC_PCLKMD_ANALOG_REG0_DIS_BIT        (0x01UL << CSC_PCLKMD_ANALOG_REG0_DIS_POS)

__STATIC_INLINE uint32_t cpusysctrl_pclkmd_get()
{
    return AIC_CPUSYSCTRL->PCLKMD;
}

__STATIC_INLINE void cpusysctrl_pclkmd_set(uint32_t disable_bits)
{
    AIC_CPUSYSCTRL->PCLKMD = disable_bits;
}

/**
 * Address Offset: 0x110
 * Register Name : CSC OCLK_MANUAL_ENABLE (write 1 valid)
 */

#define CSC_OCLKME_OPI_2X_ALWAYS_EN_POS        (0)
#define CSC_OCLKME_OPI_2X_ALWAYS_EN_BIT        (0x01UL << CSC_OCLKME_OPI_2X_ALWAYS_EN_POS)
#define CSC_OCLKME_OPI_2X_EN_POS               (1)
#define CSC_OCLKME_OPI_2X_EN_BIT               (0x01UL << CSC_OCLKME_OPI_2X_EN_POS)
#define CSC_OCLKME_SDMMC_EN_POS                (2)
#define CSC_OCLKME_SDMMC_EN_BIT                (0x01UL << CSC_OCLKME_SDMMC_EN_POS)
#define CSC_OCLKME_ASDMA_EN_POS                (3)
#define CSC_OCLKME_ASDMA_EN_BIT                (0x01UL << CSC_OCLKME_ASDMA_EN_POS)
#define CSC_OCLKME_FLASH_EN_POS                (4)
#define CSC_OCLKME_FLASH_EN_BIT                (0x01UL << CSC_OCLKME_FLASH_EN_POS)
#define CSC_OCLKME_TIMER00_EN_POS              (5)
#define CSC_OCLKME_TIMER00_EN_BIT              (0x01UL << CSC_OCLKME_TIMER00_EN_POS)
#define CSC_OCLKME_TIMER01_EN_POS              (6)
#define CSC_OCLKME_TIMER01_EN_BIT              (0x01UL << CSC_OCLKME_TIMER01_EN_POS)
#define CSC_OCLKME_TIMER10_EN_POS              (7)
#define CSC_OCLKME_TIMER10_EN_BIT              (0x01UL << CSC_OCLKME_TIMER10_EN_POS)
#define CSC_OCLKME_TIMER11_EN_POS              (8)
#define CSC_OCLKME_TIMER11_EN_BIT              (0x01UL << CSC_OCLKME_TIMER11_EN_POS)
#define CSC_OCLKME_SPI_EN_POS                  (9)
#define CSC_OCLKME_SPI_EN_BIT                  (0x01UL << CSC_OCLKME_SPI_EN_POS)
#define CSC_OCLKME_UART0_EN_POS                (10)
#define CSC_OCLKME_UART0_EN_BIT                (0x01UL << CSC_OCLKME_UART0_EN_POS)
#define CSC_OCLKME_UART1_EN_POS                (11)
#define CSC_OCLKME_UART1_EN_BIT                (0x01UL << CSC_OCLKME_UART1_EN_POS)
#define CSC_OCLKME_UART2_EN_POS                (12)
#define CSC_OCLKME_UART2_EN_BIT                (0x01UL << CSC_OCLKME_UART2_EN_POS)
#define CSC_OCLKME_ULPI_EN_POS                 (13)
#define CSC_OCLKME_ULPI_EN_BIT                 (0x01UL << CSC_OCLKME_ULPI_EN_POS)
#define CSC_OCLKME_SDIO_EN_POS                 (14)
#define CSC_OCLKME_SDIO_EN_BIT                 (0x01UL << CSC_OCLKME_SDIO_EN_POS)
#define CSC_OCLKME_PWM_EN_POS                  (15)
#define CSC_OCLKME_PWM_EN_BIT                  (0x01UL << CSC_OCLKME_PWM_EN_POS)
#define CSC_OCLKME_TIMER02_EN_POS              (16)
#define CSC_OCLKME_TIMER02_EN_BIT              (0x01UL << CSC_OCLKME_TIMER02_EN_POS)
#define CSC_OCLKME_TIMER12_EN_POS              (17)
#define CSC_OCLKME_TIMER12_EN_BIT              (0x01UL << CSC_OCLKME_TIMER12_EN_POS)
#define CSC_OCLKME_RTC_ALWAYS_EN_POS           (18)
#define CSC_OCLKME_RTC_ALWAYS_EN_BIT           (0x01UL << CSC_OCLKME_RTC_ALWAYS_EN_POS)
#define CSC_OCLKME_RTC_WDG0_EN_POS             (19)
#define CSC_OCLKME_RTC_WDG0_EN_BIT             (0x01UL << CSC_OCLKME_RTC_WDG0_EN_POS)
#define CSC_OCLKME_RTC_WDG1_EN_POS             (20)
#define CSC_OCLKME_RTC_WDG1_EN_BIT             (0x01UL << CSC_OCLKME_RTC_WDG1_EN_POS)
#define CSC_OCLKME_RTC_WDG2_EN_POS             (21)
#define CSC_OCLKME_RTC_WDG2_EN_BIT             (0x01UL << CSC_OCLKME_RTC_WDG2_EN_POS)
#define CSC_OCLKME_DDR_2X_EN_POS               (22)
#define CSC_OCLKME_DDR_2X_EN_BIT               (0x01UL << CSC_OCLKME_DDR_2X_EN_POS)
#define CSC_OCLKME_DDR_2X_ALWAYS_EN_POS        (23)
#define CSC_OCLKME_DDR_2X_ALWAYS_EN_BIT        (0x01UL << CSC_OCLKME_DDR_2X_ALWAYS_EN_POS)
#define CSC_OCLKME_CAMERA_REF_EN_POS           (24)
#define CSC_OCLKME_CAMERA_REF_EN_BIT           (0x01UL << CSC_OCLKME_CAMERA_REF_EN_POS)
#define CSC_OCLKME_AUDIO_PROC_EN_POS           (25)
#define CSC_OCLKME_AUDIO_PROC_EN_BIT           (0x01UL << CSC_OCLKME_AUDIO_PROC_EN_POS)
#define CSC_OCLKME_RTC_WDG3_EN_POS             (26)
#define CSC_OCLKME_RTC_WDG3_EN_BIT             (0x01UL << CSC_OCLKME_RTC_WDG3_EN_POS)
#define CSC_OCLKME_PROCESS_MON_EN_POS          (27)
#define CSC_OCLKME_PROCESS_MON_EN_BIT          (0x01UL << CSC_OCLKME_PROCESS_MON_EN_POS)
#define CSC_OCLKME_26M_ASDMA_EN_POS            (28)
#define CSC_OCLKME_26M_ASDMA_EN_BIT            (0x01UL << CSC_OCLKME_26M_ASDMA_EN_POS)
#define CSC_OCLKME_BCK0_EN_POS                 (29)
#define CSC_OCLKME_BCK0_EN_BIT                 (0x01UL << CSC_OCLKME_BCK0_EN_POS)
#define CSC_OCLKME_BCK1_EN_POS                 (30)
#define CSC_OCLKME_BCK1_EN_BIT                 (0x01UL << CSC_OCLKME_BCK1_EN_POS)
#define CSC_OCLKME_SPDIF_EN_POS                (31)
#define CSC_OCLKME_SPDIF_EN_BIT                (0x01UL << CSC_OCLKME_SPDIF_EN_POS)

__STATIC_INLINE uint32_t cpusysctrl_oclkme_get()
{
    return AIC_CPUSYSCTRL->OCLKME;
}

__STATIC_INLINE void cpusysctrl_oclkme_set(uint32_t enable_bits)
{
    AIC_CPUSYSCTRL->OCLKME = enable_bits;
}

/**
 * Address Offset: 0x114
 * Register Name : CSC OCLK_MANUAL_DISABLE (write 1 valid)
 */

#define CSC_OCLKMD_OPI_2X_ALWAYS_DIS_POS        (0)
#define CSC_OCLKMD_OPI_2X_ALWAYS_DIS_BIT        (0x01UL << CSC_OCLKMD_OPI_2X_ALWAYS_DIS_POS)
#define CSC_OCLKMD_OPI_2X_DIS_POS               (1)
#define CSC_OCLKMD_OPI_2X_DIS_BIT               (0x01UL << CSC_OCLKMD_OPI_2X_DIS_POS)
#define CSC_OCLKMD_SDMMC_DIS_POS                (2)
#define CSC_OCLKMD_SDMMC_DIS_BIT                (0x01UL << CSC_OCLKMD_SDMMC_DIS_POS)
#define CSC_OCLKMD_ASDMA_DIS_POS                (3)
#define CSC_OCLKMD_ASDMA_DIS_BIT                (0x01UL << CSC_OCLKMD_ASDMA_DIS_POS)
#define CSC_OCLKMD_FLASH_DIS_POS                (4)
#define CSC_OCLKMD_FLASH_DIS_BIT                (0x01UL << CSC_OCLKMD_FLASH_DIS_POS)
#define CSC_OCLKMD_TIMER00_DIS_POS              (5)
#define CSC_OCLKMD_TIMER00_DIS_BIT              (0x01UL << CSC_OCLKMD_TIMER00_DIS_POS)
#define CSC_OCLKMD_TIMER01_DIS_POS              (6)
#define CSC_OCLKMD_TIMER01_DIS_BIT              (0x01UL << CSC_OCLKMD_TIMER01_DIS_POS)
#define CSC_OCLKMD_TIMER10_DIS_POS              (7)
#define CSC_OCLKMD_TIMER10_DIS_BIT              (0x01UL << CSC_OCLKMD_TIMER10_DIS_POS)
#define CSC_OCLKMD_TIMER11_DIS_POS              (8)
#define CSC_OCLKMD_TIMER11_DIS_BIT              (0x01UL << CSC_OCLKMD_TIMER11_DIS_POS)
#define CSC_OCLKMD_SPI_DIS_POS                  (9)
#define CSC_OCLKMD_SPI_DIS_BIT                  (0x01UL << CSC_OCLKMD_SPI_DIS_POS)
#define CSC_OCLKMD_UART0_DIS_POS                (10)
#define CSC_OCLKMD_UART0_DIS_BIT                (0x01UL << CSC_OCLKMD_UART0_DIS_POS)
#define CSC_OCLKMD_UART1_DIS_POS                (11)
#define CSC_OCLKMD_UART1_DIS_BIT                (0x01UL << CSC_OCLKMD_UART1_DIS_POS)
#define CSC_OCLKMD_UART2_DIS_POS                (12)
#define CSC_OCLKMD_UART2_DIS_BIT                (0x01UL << CSC_OCLKMD_UART2_DIS_POS)
#define CSC_OCLKMD_ULPI_DIS_POS                 (13)
#define CSC_OCLKMD_ULPI_DIS_BIT                 (0x01UL << CSC_OCLKMD_ULPI_DIS_POS)
#define CSC_OCLKMD_SDIO_DIS_POS                 (14)
#define CSC_OCLKMD_SDIO_DIS_BIT                 (0x01UL << CSC_OCLKMD_SDIO_DIS_POS)
#define CSC_OCLKMD_PWM_DIS_POS                  (15)
#define CSC_OCLKMD_PWM_DIS_BIT                  (0x01UL << CSC_OCLKMD_PWM_DIS_POS)
#define CSC_OCLKMD_TIMER02_DIS_POS              (16)
#define CSC_OCLKMD_TIMER02_DIS_BIT              (0x01UL << CSC_OCLKMD_TIMER02_DIS_POS)
#define CSC_OCLKMD_TIMER12_DIS_POS              (17)
#define CSC_OCLKMD_TIMER12_DIS_BIT              (0x01UL << CSC_OCLKMD_TIMER12_DIS_POS)
#define CSC_OCLKMD_RTC_ALWAYS_DIS_POS           (18)
#define CSC_OCLKMD_RTC_ALWAYS_DIS_BIT           (0x01UL << CSC_OCLKMD_RTC_ALWAYS_DIS_POS)
#define CSC_OCLKMD_RTC_WDG0_DIS_POS             (19)
#define CSC_OCLKMD_RTC_WDG0_DIS_BIT             (0x01UL << CSC_OCLKMD_RTC_WDG0_DIS_POS)
#define CSC_OCLKMD_RTC_WDG1_DIS_POS             (20)
#define CSC_OCLKMD_RTC_WDG1_DIS_BIT             (0x01UL << CSC_OCLKMD_RTC_WDG1_DIS_POS)
#define CSC_OCLKMD_RTC_WDG2_DIS_POS             (21)
#define CSC_OCLKMD_RTC_WDG2_DIS_BIT             (0x01UL << CSC_OCLKMD_RTC_WDG2_DIS_POS)
#define CSC_OCLKMD_DDR_2X_DIS_POS               (22)
#define CSC_OCLKMD_DDR_2X_DIS_BIT               (0x01UL << CSC_OCLKMD_DDR_2X_DIS_POS)
#define CSC_OCLKMD_DDR_2X_ALWAYS_DIS_POS        (23)
#define CSC_OCLKMD_DDR_2X_ALWAYS_DIS_BIT        (0x01UL << CSC_OCLKMD_DDR_2X_ALWAYS_DIS_POS)
#define CSC_OCLKMD_CAMERA_REF_DIS_POS           (24)
#define CSC_OCLKMD_CAMERA_REF_DIS_BIT           (0x01UL << CSC_OCLKMD_CAMERA_REF_DIS_POS)
#define CSC_OCLKMD_AUDIO_PROC_DIS_POS           (25)
#define CSC_OCLKMD_AUDIO_PROC_DIS_BIT           (0x01UL << CSC_OCLKMD_AUDIO_PROC_DIS_POS)
#define CSC_OCLKMD_RTC_WDG3_DIS_POS             (26)
#define CSC_OCLKMD_RTC_WDG3_DIS_BIT             (0x01UL << CSC_OCLKMD_RTC_WDG3_DIS_POS)
#define CSC_OCLKMD_PROCESS_MON_DIS_POS          (27)
#define CSC_OCLKMD_PROCESS_MON_DIS_BIT          (0x01UL << CSC_OCLKMD_PROCESS_MON_DIS_POS)
#define CSC_OCLKMD_26M_ASDMA_DIS_POS            (28)
#define CSC_OCLKMD_26M_ASDMA_DIS_BIT            (0x01UL << CSC_OCLKMD_26M_ASDMA_DIS_POS)
#define CSC_OCLKMD_BCK0_DIS_POS                 (29)
#define CSC_OCLKMD_BCK0_DIS_BIT                 (0x01UL << CSC_OCLKMD_BCK0_DIS_POS)
#define CSC_OCLKMD_BCK1_DIS_POS                 (30)
#define CSC_OCLKMD_BCK1_DIS_BIT                 (0x01UL << CSC_OCLKMD_BCK1_DIS_POS)
#define CSC_OCLKMD_SPDIF_DIS_POS                (31)
#define CSC_OCLKMD_SPDIF_DIS_BIT                (0x01UL << CSC_OCLKMD_SPDIF_DIS_POS)

__STATIC_INLINE uint32_t cpusysctrl_oclkmd_get()
{
    return AIC_CPUSYSCTRL->OCLKMD;
}

__STATIC_INLINE void cpusysctrl_oclkmd_set(uint32_t disable_bits)
{
    AIC_CPUSYSCTRL->OCLKMD = disable_bits;
}

/**
 * Address Offset: 0x118
 * Register Name : CSC HCLK_SOFT_RESETn_SET (write 1 valid)
 */

#define CSC_HCLKRS_CPUPSET_POS          (0)
#define CSC_HCLKRS_CPUPSET_BIT          (0x01UL << CSC_HCLKRS_CPUPSET_POS)
#define CSC_HCLKRS_ROMSET_POS           (2)
#define CSC_HCLKRS_ROMSET_BIT           (0x01UL << CSC_HCLKRS_ROMSET_POS)
#define CSC_HCLKRS_SRAM0SET_POS         (3)
#define CSC_HCLKRS_SRAM0SET_BIT         (0x01UL << CSC_HCLKRS_SRAM0SET_POS)
#define CSC_HCLKRS_SRAM1SET_POS         (4)
#define CSC_HCLKRS_SRAM1SET_BIT         (0x01UL << CSC_HCLKRS_SRAM1SET_POS)
#define CSC_HCLKRS_SRAM2SET_POS         (5)
#define CSC_HCLKRS_SRAM2SET_BIT         (0x01UL << CSC_HCLKRS_SRAM2SET_POS)
#define CSC_HCLKRS_SRAM3SET_POS         (6)
#define CSC_HCLKRS_SRAM3SET_BIT         (0x01UL << CSC_HCLKRS_SRAM3SET_POS)
#define CSC_HCLKRS_SRAM4SET_POS         (7)
#define CSC_HCLKRS_SRAM4SET_BIT         (0x01UL << CSC_HCLKRS_SRAM4SET_POS)
#define CSC_HCLKRS_SRAM5SET_POS         (8)
#define CSC_HCLKRS_SRAM5SET_BIT         (0x01UL << CSC_HCLKRS_SRAM5SET_POS)
#define CSC_HCLKRS_AHB0DECSET_POS       (9)
#define CSC_HCLKRS_AHB0DECSET_BIT       (0x01UL << CSC_HCLKRS_AHB0DECSET_POS)
#define CSC_HCLKRS_AHB1DECSET_POS       (10)
#define CSC_HCLKRS_AHB1DECSET_BIT       (0x01UL << CSC_HCLKRS_AHB1DECSET_POS)
#define CSC_HCLKRS_APB0SET_POS          (11)
#define CSC_HCLKRS_APB0SET_BIT          (0x01UL << CSC_HCLKRS_APB0SET_POS)
#define CSC_HCLKRS_FLASHSET_POS         (12)
#define CSC_HCLKRS_FLASHSET_BIT         (0x01UL << CSC_HCLKRS_FLASHSET_POS)
#define CSC_HCLKRS_DMASET_POS           (13)
#define CSC_HCLKRS_DMASET_BIT           (0x01UL << CSC_HCLKRS_DMASET_POS)
#define CSC_HCLKRS_EXMEMBUSSET_POS      (14)
#define CSC_HCLKRS_EXMEMBUSSET_BIT      (0x01UL << CSC_HCLKRS_EXMEMBUSSET_POS)
#define CSC_HCLKRS_CACHE0SET_POS        (15)
#define CSC_HCLKRS_CACHE0SET_BIT        (0x01UL << CSC_HCLKRS_CACHE0SET_POS)
#define CSC_HCLKRS_CACHE1SET_POS        (16)
#define CSC_HCLKRS_CACHE1SET_BIT        (0x01UL << CSC_HCLKRS_CACHE1SET_POS)
#define CSC_HCLKRS_PSRAMSET_POS         (17)
#define CSC_HCLKRS_PSRAMSET_BIT         (0x01UL << CSC_HCLKRS_PSRAMSET_POS)
#define CSC_HCLKRS_PSRAMREGSET_POS      (18)
#define CSC_HCLKRS_PSRAMREGSET_BIT      (0x01UL << CSC_HCLKRS_PSRAMREGSET_POS)
#define CSC_HCLKRS_TRAPSET_POS          (19)
#define CSC_HCLKRS_TRAPSET_BIT          (0x01UL << CSC_HCLKRS_TRAPSET_POS)
#define CSC_HCLKRS_UART0SET_POS         (20)
#define CSC_HCLKRS_UART0SET_BIT         (0x01UL << CSC_HCLKRS_UART0SET_POS)
#define CSC_HCLKRS_UART1SET_POS         (21)
#define CSC_HCLKRS_UART1SET_BIT         (0x01UL << CSC_HCLKRS_UART1SET_POS)
#define CSC_HCLKRS_UART2SET_POS         (22)
#define CSC_HCLKRS_UART2SET_BIT         (0x01UL << CSC_HCLKRS_UART2SET_POS)
#define CSC_HCLKRS_USBCSET_POS          (23)
#define CSC_HCLKRS_USBCSET_BIT          (0x01UL << CSC_HCLKRS_USBCSET_POS)
#define CSC_HCLKRS_VPCSET_POS           (24)
#define CSC_HCLKRS_VPCSET_BIT           (0x01UL << CSC_HCLKRS_VPCSET_POS)
#define CSC_HCLKRS_MAILBOXSET_POS       (25)
#define CSC_HCLKRS_MAILBOXSET_BIT       (0x01UL << CSC_HCLKRS_MAILBOXSET_POS)
#define CSC_HCLKRS_ASDMASET_POS         (26)
#define CSC_HCLKRS_ASDMASET_BIT         (0x01UL << CSC_HCLKRS_ASDMASET_POS)
#define CSC_HCLKRS_SDIOSET_POS          (27)
#define CSC_HCLKRS_SDIOSET_BIT          (0x01UL << CSC_HCLKRS_SDIOSET_POS)
#define CSC_HCLKRS_CAMERASET_POS        (29)
#define CSC_HCLKRS_CAMERASET_BIT        (0x01UL << CSC_HCLKRS_CAMERASET_POS)
#define CSC_HCLKRS_SRAM6SET_POS         (30)
#define CSC_HCLKRS_SRAM6SET_BIT         (0x01UL << CSC_HCLKRS_SRAM6SET_POS)
#define CSC_HCLKRS_JPEGENCSET_POS       (31)
#define CSC_HCLKRS_JPEGENCSET_BIT       (0x01UL << CSC_HCLKRS_JPEGENCSET_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclkrs_get()
{
    return AIC_CPUSYSCTRL->HCLKRS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_set(uint32_t reset_bits)
{
    AIC_CPUSYSCTRL->HCLKRS = reset_bits;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_cpupset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_CPUPSET_BIT) >> CSC_HCLKRS_CPUPSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_cpupset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_CPUPSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_romset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_ROMSET_BIT) >> CSC_HCLKRS_ROMSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_romset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_ROMSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sram0set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SRAM0SET_BIT) >> CSC_HCLKRS_SRAM0SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sram0set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SRAM0SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sram1set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SRAM1SET_BIT) >> CSC_HCLKRS_SRAM1SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sram1set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SRAM1SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sram2set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SRAM2SET_BIT) >> CSC_HCLKRS_SRAM2SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sram2set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SRAM2SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sram3set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SRAM3SET_BIT) >> CSC_HCLKRS_SRAM3SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sram3set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SRAM3SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sram4set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SRAM4SET_BIT) >> CSC_HCLKRS_SRAM4SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sram4set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SRAM4SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sram5set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SRAM5SET_BIT) >> CSC_HCLKRS_SRAM5SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sram5set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SRAM5SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_ahb0decset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_AHB0DECSET_BIT) >> CSC_HCLKRS_AHB0DECSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_ahb0decset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_AHB0DECSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_ahb1decset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_AHB1DECSET_BIT) >> CSC_HCLKRS_AHB1DECSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_ahb1decset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_AHB1DECSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_apb0set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_APB0SET_BIT) >> CSC_HCLKRS_APB0SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_apb0set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_APB0SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_flashset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_FLASHSET_BIT) >> CSC_HCLKRS_FLASHSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_flashset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_FLASHSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_dmaset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_DMASET_BIT) >> CSC_HCLKRS_DMASET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_dmaset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_DMASET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_exmembusset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_EXMEMBUSSET_BIT) >> CSC_HCLKRS_EXMEMBUSSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_exmembusset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_EXMEMBUSSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_cache0set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_CACHE0SET_BIT) >> CSC_HCLKRS_CACHE0SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_cache0set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_CACHE0SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_cache1set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_CACHE1SET_BIT) >> CSC_HCLKRS_CACHE1SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_cache1set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_CACHE1SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_psramset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_PSRAMSET_BIT) >> CSC_HCLKRS_PSRAMSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_psramset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_PSRAMSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_psramregset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_PSRAMREGSET_BIT) >> CSC_HCLKRS_PSRAMREGSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_psramregset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_PSRAMREGSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_trapset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_TRAPSET_BIT) >> CSC_HCLKRS_TRAPSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_trapset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_TRAPSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_uart0set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_UART0SET_BIT) >> CSC_HCLKRS_UART0SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_uart0set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_UART0SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_uart1set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_UART1SET_BIT) >> CSC_HCLKRS_UART1SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_uart1set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_UART1SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_uart2set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_UART2SET_BIT) >> CSC_HCLKRS_UART2SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_uart2set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_UART2SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_usbcset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_USBCSET_BIT) >> CSC_HCLKRS_USBCSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_usbcset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_USBCSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_vpcset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_VPCSET_BIT) >> CSC_HCLKRS_VPCSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_vpcset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_VPCSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_mailboxset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_MAILBOXSET_BIT) >> CSC_HCLKRS_MAILBOXSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_mailboxset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_MAILBOXSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_asdmaset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_ASDMASET_BIT) >> CSC_HCLKRS_ASDMASET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_asdmaset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_ASDMASET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sdioset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SDIOSET_BIT) >> CSC_HCLKRS_SDIOSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sdioset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SDIOSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_cameraset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_CAMERASET_BIT) >> CSC_HCLKRS_CAMERASET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_cameraset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_CAMERASET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_sram6set_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_SRAM6SET_BIT) >> CSC_HCLKRS_SRAM6SET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_sram6set_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_SRAM6SET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrs_jpegencset_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRS & CSC_HCLKRS_JPEGENCSET_BIT) >> CSC_HCLKRS_JPEGENCSET_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrs_jpegencset_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRS = CSC_HCLKRS_JPEGENCSET_BIT;
}

/**
 * Address Offset: 0x11C
 * Register Name : CSC HCLK_SOFT_RESETn_CLEAR (write 1 valid)
 */

#define CSC_HCLKRC_CPUPCLR_POS          (0)
#define CSC_HCLKRC_CPUPCLR_BIT          (0x01UL << CSC_HCLKRC_CPUPCLR_POS)
#define CSC_HCLKRC_ROMCLR_POS           (2)
#define CSC_HCLKRC_ROMCLR_BIT           (0x01UL << CSC_HCLKRC_ROMCLR_POS)
#define CSC_HCLKRC_SRAM0CLR_POS         (3)
#define CSC_HCLKRC_SRAM0CLR_BIT         (0x01UL << CSC_HCLKRC_SRAM0CLR_POS)
#define CSC_HCLKRC_SRAM1CLR_POS         (4)
#define CSC_HCLKRC_SRAM1CLR_BIT         (0x01UL << CSC_HCLKRC_SRAM1CLR_POS)
#define CSC_HCLKRC_SRAM2CLR_POS         (5)
#define CSC_HCLKRC_SRAM2CLR_BIT         (0x01UL << CSC_HCLKRC_SRAM2CLR_POS)
#define CSC_HCLKRC_SRAM3CLR_POS         (6)
#define CSC_HCLKRC_SRAM3CLR_BIT         (0x01UL << CSC_HCLKRC_SRAM3CLR_POS)
#define CSC_HCLKRC_SRAM4CLR_POS         (7)
#define CSC_HCLKRC_SRAM4CLR_BIT         (0x01UL << CSC_HCLKRC_SRAM4CLR_POS)
#define CSC_HCLKRC_SRAM5CLR_POS         (8)
#define CSC_HCLKRC_SRAM5CLR_BIT         (0x01UL << CSC_HCLKRC_SRAM5CLR_POS)
#define CSC_HCLKRC_AHB0DECCLR_POS       (9)
#define CSC_HCLKRC_AHB0DECCLR_BIT       (0x01UL << CSC_HCLKRC_AHB0DECCLR_POS)
#define CSC_HCLKRC_AHB1DECCLR_POS       (10)
#define CSC_HCLKRC_AHB1DECCLR_BIT       (0x01UL << CSC_HCLKRC_AHB1DECCLR_POS)
#define CSC_HCLKRC_APB0CLR_POS          (11)
#define CSC_HCLKRC_APB0CLR_BIT          (0x01UL << CSC_HCLKRC_APB0CLR_POS)
#define CSC_HCLKRC_FLASHCLR_POS         (12)
#define CSC_HCLKRC_FLASHCLR_BIT         (0x01UL << CSC_HCLKRC_FLASHCLR_POS)
#define CSC_HCLKRC_DMACLR_POS           (13)
#define CSC_HCLKRC_DMACLR_BIT           (0x01UL << CSC_HCLKRC_DMACLR_POS)
#define CSC_HCLKRC_EXMEMBUSCLR_POS      (14)
#define CSC_HCLKRC_EXMEMBUSCLR_BIT      (0x01UL << CSC_HCLKRC_EXMEMBUSCLR_POS)
#define CSC_HCLKRC_CACHE0CLR_POS        (15)
#define CSC_HCLKRC_CACHE0CLR_BIT        (0x01UL << CSC_HCLKRC_CACHE0CLR_POS)
#define CSC_HCLKRC_CACHE1CLR_POS        (16)
#define CSC_HCLKRC_CACHE1CLR_BIT        (0x01UL << CSC_HCLKRC_CACHE1CLR_POS)
#define CSC_HCLKRC_PSRAMCLR_POS         (17)
#define CSC_HCLKRC_PSRAMCLR_BIT         (0x01UL << CSC_HCLKRC_PSRAMCLR_POS)
#define CSC_HCLKRC_PSRAMREGCLR_POS      (18)
#define CSC_HCLKRC_PSRAMREGCLR_BIT      (0x01UL << CSC_HCLKRC_PSRAMREGCLR_POS)
#define CSC_HCLKRC_TRAPCLR_POS          (19)
#define CSC_HCLKRC_TRAPCLR_BIT          (0x01UL << CSC_HCLKRC_TRAPCLR_POS)
#define CSC_HCLKRC_UART0CLR_POS         (20)
#define CSC_HCLKRC_UART0CLR_BIT         (0x01UL << CSC_HCLKRC_UART0CLR_POS)
#define CSC_HCLKRC_UART1CLR_POS         (21)
#define CSC_HCLKRC_UART1CLR_BIT         (0x01UL << CSC_HCLKRC_UART1CLR_POS)
#define CSC_HCLKRC_UART2CLR_POS         (22)
#define CSC_HCLKRC_UART2CLR_BIT         (0x01UL << CSC_HCLKRC_UART2CLR_POS)
#define CSC_HCLKRC_USBCCLR_POS          (23)
#define CSC_HCLKRC_USBCCLR_BIT          (0x01UL << CSC_HCLKRC_USBCCLR_POS)
#define CSC_HCLKRC_VPCCLR_POS           (24)
#define CSC_HCLKRC_VPCCLR_BIT           (0x01UL << CSC_HCLKRC_VPCCLR_POS)
#define CSC_HCLKRC_MAILBOXCLR_POS       (25)
#define CSC_HCLKRC_MAILBOXCLR_BIT       (0x01UL << CSC_HCLKRC_MAILBOXCLR_POS)
#define CSC_HCLKRC_ASDMACLR_POS         (26)
#define CSC_HCLKRC_ASDMACLR_BIT         (0x01UL << CSC_HCLKRC_ASDMACLR_POS)
#define CSC_HCLKRC_SDIOCLR_POS          (27)
#define CSC_HCLKRC_SDIOCLR_BIT          (0x01UL << CSC_HCLKRC_SDIOCLR_POS)
#define CSC_HCLKRC_CAMERACLR_POS        (29)
#define CSC_HCLKRC_CAMERACLR_BIT        (0x01UL << CSC_HCLKRC_CAMERACLR_POS)
#define CSC_HCLKRC_SRAM6CLR_POS         (30)
#define CSC_HCLKRC_SRAM6CLR_BIT         (0x01UL << CSC_HCLKRC_SRAM6CLR_POS)
#define CSC_HCLKRC_JPEGENCCLR_POS       (31)
#define CSC_HCLKRC_JPEGENCCLR_BIT       (0x01UL << CSC_HCLKRC_JPEGENCCLR_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclkrc_get()
{
    return AIC_CPUSYSCTRL->HCLKRC;
}

__STATIC_INLINE void cpusysctrl_hclkrc_set(uint32_t reset_bits)
{
    AIC_CPUSYSCTRL->HCLKRC = reset_bits;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_cpupclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_CPUPCLR_BIT) >> CSC_HCLKRC_CPUPCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_cpupclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_CPUPCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_romclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_ROMCLR_BIT) >> CSC_HCLKRC_ROMCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_romclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_ROMCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sram0clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SRAM0CLR_BIT) >> CSC_HCLKRC_SRAM0CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sram0clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SRAM0CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sram1clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SRAM1CLR_BIT) >> CSC_HCLKRC_SRAM1CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sram1clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SRAM1CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sram2clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SRAM2CLR_BIT) >> CSC_HCLKRC_SRAM2CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sram2clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SRAM2CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sram3clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SRAM3CLR_BIT) >> CSC_HCLKRC_SRAM3CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sram3clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SRAM3CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sram4clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SRAM4CLR_BIT) >> CSC_HCLKRC_SRAM4CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sram4clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SRAM4CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sram5clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SRAM5CLR_BIT) >> CSC_HCLKRC_SRAM5CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sram5clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SRAM5CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_ahb0decclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_AHB0DECCLR_BIT) >> CSC_HCLKRC_AHB0DECCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_ahb0decclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_AHB0DECCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_ahb1decclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_AHB1DECCLR_BIT) >> CSC_HCLKRC_AHB1DECCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_ahb1decclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_AHB1DECCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_apb0clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_APB0CLR_BIT) >> CSC_HCLKRC_APB0CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_apb0clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_APB0CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_flashclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_FLASHCLR_BIT) >> CSC_HCLKRC_FLASHCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_flashclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_FLASHCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_dmaclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_DMACLR_BIT) >> CSC_HCLKRC_DMACLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_dmaclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_DMACLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_exmembusclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_EXMEMBUSCLR_BIT) >> CSC_HCLKRC_EXMEMBUSCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_exmembusclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_EXMEMBUSCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_cache0clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_CACHE0CLR_BIT) >> CSC_HCLKRC_CACHE0CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_cache0clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_CACHE0CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_cache1clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_CACHE1CLR_BIT) >> CSC_HCLKRC_CACHE1CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_cache1clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_CACHE1CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_psramclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_PSRAMCLR_BIT) >> CSC_HCLKRC_PSRAMCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_psramclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_PSRAMCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_psramregclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_PSRAMREGCLR_BIT) >> CSC_HCLKRC_PSRAMREGCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_psramregclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_PSRAMREGCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_trapclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_TRAPCLR_BIT) >> CSC_HCLKRC_TRAPCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_trapclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_TRAPCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_uart0clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_UART0CLR_BIT) >> CSC_HCLKRC_UART0CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_uart0clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_UART0CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_uart1clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_UART1CLR_BIT) >> CSC_HCLKRC_UART1CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_uart1clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_UART1CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_uart2clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_UART2CLR_BIT) >> CSC_HCLKRC_UART2CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_uart2clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_UART2CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_usbcclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_USBCCLR_BIT) >> CSC_HCLKRC_USBCCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_usbcclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_USBCCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_vpcclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_VPCCLR_BIT) >> CSC_HCLKRC_VPCCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_vpcclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_VPCCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_mailboxclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_MAILBOXCLR_BIT) >> CSC_HCLKRC_MAILBOXCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_mailboxclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_MAILBOXCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_asdmaclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_ASDMACLR_BIT) >> CSC_HCLKRC_ASDMACLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_asdmaclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_ASDMACLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sdioclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SDIOCLR_BIT) >> CSC_HCLKRC_SDIOCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sdioclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SDIOCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_cameraclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_CAMERACLR_BIT) >> CSC_HCLKRC_CAMERACLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_cameraclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_CAMERACLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_sram6clr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_SRAM6CLR_BIT) >> CSC_HCLKRC_SRAM6CLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_sram6clr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_SRAM6CLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_hclkrc_jpegencclr_getb(void)
{
    return (AIC_CPUSYSCTRL->HCLKRC & CSC_HCLKRC_JPEGENCCLR_BIT) >> CSC_HCLKRC_JPEGENCCLR_POS;
}

__STATIC_INLINE void cpusysctrl_hclkrc_jpegencclr_setb(void)
{
    AIC_CPUSYSCTRL->HCLKRC = CSC_HCLKRC_JPEGENCCLR_BIT;
}

/**
 * Address Offset: 0x120
 * Register Name : CSC PCLK_SOFT_RESETn_SET (write 1 valid)
 */

#define CSC_PCLKRS_CPUSYSCTRLSET_POS    (0)
#define CSC_PCLKRS_CPUSYSCTRLSET_BIT    (0x01UL << CSC_PCLKRS_CPUSYSCTRLSET_POS)

__STATIC_INLINE uint32_t cpusysctrl_pclkrs_get()
{
    return AIC_CPUSYSCTRL->PCLKRS;
}

__STATIC_INLINE void cpusysctrl_pclkrs_set(uint32_t reset_bits)
{
    AIC_CPUSYSCTRL->PCLKRS = reset_bits;
}

__STATIC_INLINE uint8_t cpusysctrl_pclkrs_cpusysctrlset_getb(void)
{
    return (AIC_CPUSYSCTRL->PCLKRS & CSC_PCLKRS_CPUSYSCTRLSET_BIT) >> CSC_PCLKRS_CPUSYSCTRLSET_POS;
}

__STATIC_INLINE void cpusysctrl_pclkrs_cpusysctrlset_setb(void)
{
    AIC_CPUSYSCTRL->PCLKRS = CSC_PCLKRS_CPUSYSCTRLSET_BIT;
}

/**
 * Address Offset: 0x124
 * Register Name : CSC PCLK_SOFT_RESETn_CLEAR (write 1 valid)
 */

#define CSC_PCLKRC_CPUSYSCTRLCLR_POS    (0)
#define CSC_PCLKRC_CPUSYSCTRLCLR_BIT    (0x01UL << CSC_PCLKRC_CPUSYSCTRLCLR_POS)

__STATIC_INLINE uint32_t cpusysctrl_pclkrc_get()
{
    return AIC_CPUSYSCTRL->PCLKRC;
}

__STATIC_INLINE void cpusysctrl_pclkrc_set(uint32_t reset_bits)
{
    AIC_CPUSYSCTRL->PCLKRC = reset_bits;
}

__STATIC_INLINE uint8_t cpusysctrl_pclkrc_cpusysctrlclr_getb(void)
{
    return (AIC_CPUSYSCTRL->PCLKRC & CSC_PCLKRC_CPUSYSCTRLCLR_BIT) >> CSC_PCLKRC_CPUSYSCTRLCLR_POS;
}

__STATIC_INLINE void cpusysctrl_pclkrc_cpusysctrlclr_setb(void)
{
    AIC_CPUSYSCTRL->PCLKRC = CSC_PCLKRC_CPUSYSCTRLCLR_BIT;
}

/**
 * Address Offset: 0x128
 * Register Name : CSC OTHERS_SOFT_RESETn_SET (write 1 valid)
 */

#define CSC_OCLKRS_SDIOSET_POS          (0)
#define CSC_OCLKRS_SDIOSET_BIT          (0x01UL << CSC_OCLKRS_SDIOSET_POS)
#define CSC_OCLKRS_ASDMASET_POS         (1)
#define CSC_OCLKRS_ASDMASET_BIT         (0x01UL << CSC_OCLKRS_ASDMASET_POS)
#define CSC_OCLKRS_ULPISET_POS          (10)
#define CSC_OCLKRS_ULPISET_BIT          (0x01UL << CSC_OCLKRS_ULPISET_POS)

__STATIC_INLINE uint32_t cpusysctrl_oclkrs_get()
{
    return AIC_CPUSYSCTRL->OCLKRS;
}

__STATIC_INLINE void cpusysctrl_oclkrs_set(uint32_t reset_bits)
{
    AIC_CPUSYSCTRL->OCLKRS = reset_bits;
}

__STATIC_INLINE uint8_t cpusysctrl_oclkrs_sdioset_getb(void)
{
    return (AIC_CPUSYSCTRL->OCLKRS & CSC_OCLKRS_SDIOSET_BIT) >> CSC_OCLKRS_SDIOSET_POS;
}

__STATIC_INLINE void cpusysctrl_oclkrs_sdioset_setb(void)
{
    AIC_CPUSYSCTRL->OCLKRS = CSC_OCLKRS_SDIOSET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_oclkrs_asdmaset_getb(void)
{
    return (AIC_CPUSYSCTRL->OCLKRS & CSC_OCLKRS_ASDMASET_BIT) >> CSC_OCLKRS_ASDMASET_POS;
}

__STATIC_INLINE void cpusysctrl_oclkrs_asdmaset_setb(void)
{
    AIC_CPUSYSCTRL->OCLKRS = CSC_OCLKRS_ASDMASET_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_oclkrs_ulpiset_getb(void)
{
    return (AIC_CPUSYSCTRL->OCLKRS & CSC_OCLKRS_ULPISET_BIT) >> CSC_OCLKRS_ULPISET_POS;
}

__STATIC_INLINE void cpusysctrl_oclkrs_ulpiset_setb(void)
{
    AIC_CPUSYSCTRL->OCLKRS = CSC_OCLKRS_ULPISET_BIT;
}

/**
 * Address Offset: 0x12C
 * Register Name : CSC OTHERS_SOFT_RESETn_CLEAR (write 1 valid)
 */

#define CSC_OCLKRC_SDIOCLR_POS          (0)
#define CSC_OCLKRC_SDIOCLR_BIT          (0x01UL << CSC_OCLKRC_SDIOCLR_POS)
#define CSC_OCLKRC_ASDMACLR_POS         (1)
#define CSC_OCLKRC_ASDMACLR_BIT         (0x01UL << CSC_OCLKRC_ASDMACLR_POS)
#define CSC_OCLKRC_ULPICLR_POS          (10)
#define CSC_OCLKRC_ULPICLR_BIT          (0x01UL << CSC_OCLKRC_ULPICLR_POS)

__STATIC_INLINE uint32_t cpusysctrl_oclkrc_get()
{
    return AIC_CPUSYSCTRL->OCLKRC;
}

__STATIC_INLINE void cpusysctrl_oclkrc_set(uint32_t reset_bits)
{
    AIC_CPUSYSCTRL->OCLKRC = reset_bits;
}

__STATIC_INLINE uint8_t cpusysctrl_oclkrc_sdioclr_getb(void)
{
    return (AIC_CPUSYSCTRL->OCLKRC & CSC_OCLKRC_SDIOCLR_BIT) >> CSC_OCLKRC_SDIOCLR_POS;
}

__STATIC_INLINE void cpusysctrl_oclkrc_sdioclr_setb(void)
{
    AIC_CPUSYSCTRL->OCLKRC = CSC_OCLKRC_SDIOCLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_oclkrc_asdmaclr_getb(void)
{
    return (AIC_CPUSYSCTRL->OCLKRC & CSC_OCLKRC_ASDMACLR_BIT) >> CSC_OCLKRC_ASDMACLR_POS;
}

__STATIC_INLINE void cpusysctrl_oclkrc_asdmaclr_setb(void)
{
    AIC_CPUSYSCTRL->OCLKRC = CSC_OCLKRC_ASDMACLR_BIT;
}

__STATIC_INLINE uint8_t cpusysctrl_oclkrc_ulpiclr_getb(void)
{
    return (AIC_CPUSYSCTRL->OCLKRC & CSC_OCLKRC_ULPICLR_BIT) >> CSC_OCLKRC_ULPICLR_POS;
}

__STATIC_INLINE void cpusysctrl_oclkrc_ulpiclr_setb(void)
{
    AIC_CPUSYSCTRL->OCLKRC = CSC_OCLKRC_ULPICLR_BIT;
}

/**
 * Address Offset: 0x130
 * Register Name : CSC HCLK1_MANUAL_ENABLE (write 1 valid)
 */

#define CSC_HCLK1ME_DSP_EN_POS                 (0)
#define CSC_HCLK1ME_DSP_EN_BIT                 (0x01UL << CSC_HCLK1ME_DSP_EN_POS)
#define CSC_HCLK1ME_DSP_GATED_EN_POS           (1)
#define CSC_HCLK1ME_DSP_GATED_EN_BIT           (0x01UL << CSC_HCLK1ME_DSP_GATED_EN_POS)
#define CSC_HCLK1ME_CAMERA_EN_POS              (2)
#define CSC_HCLK1ME_CAMERA_EN_BIT              (0x01UL << CSC_HCLK1ME_CAMERA_EN_POS)
#define CSC_HCLK1ME_SPI_CAMERA_EN_POS          (3)
#define CSC_HCLK1ME_SPI_CAMERA_EN_BIT          (0x01UL << CSC_HCLK1ME_SPI_CAMERA_EN_POS)
#define CSC_HCLK1ME_JPEG_ENC_EN_POS            (4)
#define CSC_HCLK1ME_JPEG_ENC_EN_BIT            (0x01UL << CSC_HCLK1ME_JPEG_ENC_EN_POS)
#define CSC_HCLK1ME_BTROM_EN_POS               (5)
#define CSC_HCLK1ME_BTROM_EN_BIT               (0x01UL << CSC_HCLK1ME_BTROM_EN_POS)
#define CSC_HCLK1ME_DSP_MATRIX_EN_POS          (6)
#define CSC_HCLK1ME_DSP_MATRIX_EN_BIT          (0x01UL << CSC_HCLK1ME_DSP_MATRIX_EN_POS)
#define CSC_HCLK1ME_SRAM6_EN_POS               (7)
#define CSC_HCLK1ME_SRAM6_EN_BIT               (0x01UL << CSC_HCLK1ME_SRAM6_EN_POS)
#define CSC_HCLK1ME_SDMMC_ALWAYS_EN_POS        (8)
#define CSC_HCLK1ME_SDMMC_ALWAYS_EN_BIT        (0x01UL << CSC_HCLK1ME_SDMMC_ALWAYS_EN_POS)
#define CSC_HCLK1ME_SDMMC_EN_POS               (9)
#define CSC_HCLK1ME_SDMMC_EN_BIT               (0x01UL << CSC_HCLK1ME_SDMMC_EN_POS)
#define CSC_HCLK1ME_CPUSB_EN_POS               (10)
#define CSC_HCLK1ME_CPUSB_EN_BIT               (0x01UL << CSC_HCLK1ME_CPUSB_EN_POS)
#define CSC_HCLK1ME_CPUSB_GATED_EN_POS         (11)
#define CSC_HCLK1ME_CPUSB_GATED_EN_BIT         (0x01UL << CSC_HCLK1ME_CPUSB_GATED_EN_POS)
#define CSC_HCLK1ME_SRAM5_LOW_EN_POS           (12)
#define CSC_HCLK1ME_SRAM5_LOW_EN_BIT           (0x01UL << CSC_HCLK1ME_SRAM5_LOW_EN_POS)
#define CSC_HCLK1ME_SRAM5_HIGH_EN_POS          (13)
#define CSC_HCLK1ME_SRAM5_HIGH_EN_BIT          (0x01UL << CSC_HCLK1ME_SRAM5_HIGH_EN_POS)
#define CSC_HCLK1ME_MM_EN_POS                  (14)
#define CSC_HCLK1ME_MM_EN_BIT                  (0x01UL << CSC_HCLK1ME_MM_EN_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclk1me_get()
{
    return AIC_CPUSYSCTRL->HCLK1ME;
}

__STATIC_INLINE void cpusysctrl_hclk1me_set(uint32_t enable_bits)
{
    AIC_CPUSYSCTRL->HCLK1ME = enable_bits;
}

/**
 * Address Offset: 0x134
 * Register Name : CSC HCLK1_MANUAL_DISABLE (write 1 valid)
 */

#define CSC_HCLK1MD_DSP_DIS_POS                 (0)
#define CSC_HCLK1MD_DSP_DIS_BIT                 (0x01UL << CSC_HCLK1MD_DSP_DIS_POS)
#define CSC_HCLK1MD_DSP_GATED_DIS_POS           (1)
#define CSC_HCLK1MD_DSP_GATED_DIS_BIT           (0x01UL << CSC_HCLK1MD_DSP_GATED_DIS_POS)
#define CSC_HCLK1MD_CAMERA_DIS_POS              (2)
#define CSC_HCLK1MD_CAMERA_DIS_BIT              (0x01UL << CSC_HCLK1MD_CAMERA_DIS_POS)
#define CSC_HCLK1MD_SPI_CAMERA_DIS_POS          (3)
#define CSC_HCLK1MD_SPI_CAMERA_DIS_BIT          (0x01UL << CSC_HCLK1MD_SPI_CAMERA_DIS_POS)
#define CSC_HCLK1MD_JPEG_ENC_DIS_POS            (4)
#define CSC_HCLK1MD_JPEG_ENC_DIS_BIT            (0x01UL << CSC_HCLK1MD_JPEG_ENC_DIS_POS)
#define CSC_HCLK1MD_BTROM_DIS_POS               (5)
#define CSC_HCLK1MD_BTROM_DIS_BIT               (0x01UL << CSC_HCLK1MD_BTROM_DIS_POS)
#define CSC_HCLK1MD_DSP_MATRIX_DIS_POS          (6)
#define CSC_HCLK1MD_DSP_MATRIX_DIS_BIT          (0x01UL << CSC_HCLK1MD_DSP_MATRIX_DIS_POS)
#define CSC_HCLK1MD_SRAM6_DIS_POS               (7)
#define CSC_HCLK1MD_SRAM6_DIS_BIT               (0x01UL << CSC_HCLK1MD_SRAM6_DIS_POS)
#define CSC_HCLK1MD_SDMMC_ALWAYS_DIS_POS        (8)
#define CSC_HCLK1MD_SDMMC_ALWAYS_DIS_BIT        (0x01UL << CSC_HCLK1MD_SDMMC_ALWAYS_DIS_POS)
#define CSC_HCLK1MD_SDMMC_DIS_POS               (9)
#define CSC_HCLK1MD_SDMMC_DIS_BIT               (0x01UL << CSC_HCLK1MD_SDMMC_DIS_POS)
#define CSC_HCLK1MD_CPUSB_DIS_POS               (10)
#define CSC_HCLK1MD_CPUSB_DIS_BIT               (0x01UL << CSC_HCLK1MD_CPUSB_DIS_POS)
#define CSC_HCLK1MD_CPUSB_GATED_DIS_POS         (11)
#define CSC_HCLK1MD_CPUSB_GATED_DIS_BIT         (0x01UL << CSC_HCLK1MD_CPUSB_GATED_DIS_POS)
#define CSC_HCLK1MD_SRAM5_LOW_DIS_POS           (12)
#define CSC_HCLK1MD_SRAM5_LOW_DIS_BIT           (0x01UL << CSC_HCLK1MD_SRAM5_LOW_DIS_POS)
#define CSC_HCLK1MD_SRAM5_HIGH_DIS_POS          (13)
#define CSC_HCLK1MD_SRAM5_HIGH_DIS_BIT          (0x01UL << CSC_HCLK1MD_SRAM5_HIGH_DIS_POS)
#define CSC_HCLK1MD_MM_DIS_POS                  (14)
#define CSC_HCLK1MD_MM_DIS_BIT                  (0x01UL << CSC_HCLK1MD_MM_DIS_POS)

__STATIC_INLINE uint32_t cpusysctrl_hclk1md_get()
{
    return AIC_CPUSYSCTRL->HCLK1MD;
}

__STATIC_INLINE void cpusysctrl_hclk1md_set(uint32_t disable_bits)
{
    AIC_CPUSYSCTRL->HCLK1MD = disable_bits;
}

/**
 * Address Offset: 0x000
 * Register Name : PC CPUSYS
 */

#define PC_CPUSYS_AWAKE_SRC_LSB         (0)
#define PC_CPUSYS_AWAKE_SRC_WIDTH       (10)
#define PC_CPUSYS_AWAKE_SRC_MASK        (((0x01UL << PC_CPUSYS_AWAKE_SRC_WIDTH) - 1) << PC_CPUSYS_AWAKE_SRC_LSB)
#define PC_CPUSYS_SLEEP_SRC_LSB         (10)
#define PC_CPUSYS_SLEEP_SRC_WIDTH       (2)
#define PC_CPUSYS_SLEEP_SRC_MASK        (((0x01UL << PC_CPUSYS_SLEEP_SRC_WIDTH) - 1) << PC_CPUSYS_SLEEP_SRC_LSB)
#define PC_CPUSYS_SLEEP_SRC_WIFI_POS    (10)
#define PC_CPUSYS_SLEEP_SRC_WIFI_BIT    (0x01UL << PC_CPUSYS_SLEEP_SRC_WIFI_POS)
#define PC_CPUSYS_SLEEP_SRC_BT_POS      (11)
#define PC_CPUSYS_SLEEP_SRC_BT_BIT      (0x01UL << PC_CPUSYS_SLEEP_SRC_BT_POS)
#define PC_CPUSYS_SLEEP_SOFT_REQ_POS    (12)
#define PC_CPUSYS_SLEEP_SOFT_REQ_BIT    (0x01UL << PC_CPUSYS_SLEEP_SOFT_REQ_POS)
#define PC_CPUSYS_SLEEP_REQVLDCLR_POS   (13)
#define PC_CPUSYS_SLEEP_REQVLDCLR_BIT   (0x01UL << PC_CPUSYS_SLEEP_REQVLDCLR_POS)
#define PC_CPUSYS_HWEN_PON_POS          (15)
#define PC_CPUSYS_HWEN_PON_BIT          (0x01UL << PC_CPUSYS_HWEN_PON_POS)
#define PC_CPUSYS_HWEN_POFF_POS         (16)
#define PC_CPUSYS_HWEN_POFF_BIT         (0x01UL << PC_CPUSYS_HWEN_POFF_POS)
#define PC_CPUSYS_PON_POS               (17)
#define PC_CPUSYS_PON_BIT               (0x01UL << PC_CPUSYS_PON_POS)
#define PC_CPUSYS_POFF_POS              (18)
#define PC_CPUSYS_POFF_BIT              (0x01UL << PC_CPUSYS_POFF_POS)
#define PC_CPUSYS_PWRSYS_TMR_POFF_POS   (19)
#define PC_CPUSYS_PWRSYS_TMR_POFF_BIT   (0x01UL << PC_CPUSYS_PWRSYS_TMR_POFF_POS)
#define PC_CPUSYS_PWRSYS_PON_POS        (20)
#define PC_CPUSYS_PWRSYS_PON_BIT        (0x01UL << PC_CPUSYS_PWRSYS_PON_POS)
#define PC_CPUSYS_PWRSYS_POFF_POS       (21)
#define PC_CPUSYS_PWRSYS_POFF_BIT       (0x01UL << PC_CPUSYS_PWRSYS_POFF_POS)
#define PC_CPUSYS_AWAKE_SOFT_REQ_POS    (22)
#define PC_CPUSYS_AWAKE_SOFT_REQ_BIT    (0x01UL << PC_CPUSYS_AWAKE_SOFT_REQ_POS)
#define PC_CPUSYS_AWAKE_REQVLDCLR_POS   (23)
#define PC_CPUSYS_AWAKE_REQVLDCLR_BIT   (0x01UL << PC_CPUSYS_AWAKE_REQVLDCLR_POS)

__STATIC_INLINE uint32_t pwrctrl_cpusys_get(void)
{
    return AIC_PWRCTRL->CPUSYS;
}

__STATIC_INLINE void pwrctrl_cpusys_set(uint32_t reg_val)
{
    AIC_PWRCTRL->CPUSYS = reg_val;
}

__STATIC_INLINE uint16_t pwrctrl_cpusys_awake_src_getf(void)
{
    return ((AIC_PWRCTRL->CPUSYS & PC_CPUSYS_AWAKE_SRC_MASK) >> PC_CPUSYS_AWAKE_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_cpusys_awake_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->CPUSYS & ~PC_CPUSYS_AWAKE_SRC_MASK;
    AIC_PWRCTRL->CPUSYS = local_val | ((awake_src << PC_CPUSYS_AWAKE_SRC_LSB) & PC_CPUSYS_AWAKE_SRC_MASK);
}

__STATIC_INLINE uint16_t pwrctrl_cpusys_sleep_src_getf(void)
{
    return ((AIC_PWRCTRL->CPUSYS & PC_CPUSYS_SLEEP_SRC_MASK) >> PC_CPUSYS_SLEEP_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_cpusys_sleep_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->CPUSYS & ~PC_CPUSYS_SLEEP_SRC_MASK;
    AIC_PWRCTRL->CPUSYS = local_val | ((awake_src << PC_CPUSYS_SLEEP_SRC_LSB) & PC_CPUSYS_SLEEP_SRC_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_sleep_src_wifi_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_SLEEP_SRC_WIFI_BIT) >> PC_CPUSYS_SLEEP_SRC_WIFI_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_sleep_src_wifi_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_sleep_src_wifi_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_sleep_src_bt_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_SLEEP_SRC_BT_BIT) >> PC_CPUSYS_SLEEP_SRC_BT_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_sleep_src_bt_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_sleep_src_bt_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_sleep_soft_req_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_SLEEP_SOFT_REQ_BIT) >> PC_CPUSYS_SLEEP_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_sleep_soft_req_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_SLEEP_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_sleep_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_SLEEP_REQVLDCLR_BIT) >> PC_CPUSYS_SLEEP_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_sleep_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_SLEEP_REQVLDCLR_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_hwen_pon_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_HWEN_PON_BIT) >> PC_CPUSYS_HWEN_PON_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_hwen_pon_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_HWEN_PON_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_hwen_pon_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_HWEN_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_hwen_poff_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_HWEN_POFF_BIT) >> PC_CPUSYS_HWEN_POFF_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_hwen_poff_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_HWEN_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_hwen_poff_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_HWEN_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_pon_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_PON_BIT) >> PC_CPUSYS_PON_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_pon_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_PON_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_pon_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_poff_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_POFF_BIT) >> PC_CPUSYS_POFF_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_poff_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_poff_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_pwrsys_timer_poff_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_PWRSYS_TMR_POFF_BIT) >> PC_CPUSYS_PWRSYS_TMR_POFF_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_pwrsys_timer_poff_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_pwrsys_timer_poff_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_pwrsys_pon_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_PWRSYS_PON_BIT) >> PC_CPUSYS_PWRSYS_PON_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_pwrsys_pon_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_PWRSYS_PON_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_pwrsys_pon_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_PWRSYS_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_pwrsys_poff_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_PWRSYS_POFF_BIT) >> PC_CPUSYS_PWRSYS_POFF_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_pwrsys_poff_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_PWRSYS_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_cpusys_pwrsys_poff_clrb(void)
{
    AIC_PWRCTRL->CPUSYS &= ~PC_CPUSYS_PWRSYS_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_awake_soft_req_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_AWAKE_SOFT_REQ_BIT) >> PC_CPUSYS_AWAKE_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_awake_soft_req_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_AWAKE_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_cpusys_awake_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->CPUSYS & PC_CPUSYS_AWAKE_REQVLDCLR_BIT) >> PC_CPUSYS_AWAKE_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_cpusys_awake_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->CPUSYS |=  PC_CPUSYS_AWAKE_REQVLDCLR_BIT;
}

/**
 * Address Offset: 0x004
 * Register Name : PC BTCORE
 */

#define PC_BTCORE_AWAKE_SRC_LSB         (0)
#define PC_BTCORE_AWAKE_SRC_WIDTH       (10)
#define PC_BTCORE_AWAKE_SRC_MASK        (((0x01UL << PC_BTCORE_AWAKE_SRC_WIDTH) - 1) << PC_BTCORE_AWAKE_SRC_LSB)
#define PC_BTCORE_SLEEP_SRC_LSB         (10)
#define PC_BTCORE_SLEEP_SRC_WIDTH       (2)
#define PC_BTCORE_SLEEP_SRC_MASK        (((0x01UL << PC_BTCORE_SLEEP_SRC_WIDTH) - 1) << PC_BTCORE_SLEEP_SRC_LSB)
#define PC_BTCORE_SLEEP_SRC_WIFI_POS    (10)
#define PC_BTCORE_SLEEP_SRC_WIFI_BIT    (0x01UL << PC_BTCORE_SLEEP_SRC_WIFI_POS)
#define PC_BTCORE_SLEEP_SRC_BT_POS      (11)
#define PC_BTCORE_SLEEP_SRC_BT_BIT      (0x01UL << PC_BTCORE_SLEEP_SRC_BT_POS)
#define PC_BTCORE_SLEEP_SOFT_REQ_POS    (12)
#define PC_BTCORE_SLEEP_SOFT_REQ_BIT    (0x01UL << PC_BTCORE_SLEEP_SOFT_REQ_POS)
#define PC_BTCORE_SLEEP_REQVLDCLR_POS   (13)
#define PC_BTCORE_SLEEP_REQVLDCLR_BIT   (0x01UL << PC_BTCORE_SLEEP_REQVLDCLR_POS)
#define PC_BTCORE_HWEN_PON_POS          (15)
#define PC_BTCORE_HWEN_PON_BIT          (0x01UL << PC_BTCORE_HWEN_PON_POS)
#define PC_BTCORE_HWEN_POFF_POS         (16)
#define PC_BTCORE_HWEN_POFF_BIT         (0x01UL << PC_BTCORE_HWEN_POFF_POS)
#define PC_BTCORE_PON_POS               (17)
#define PC_BTCORE_PON_BIT               (0x01UL << PC_BTCORE_PON_POS)
#define PC_BTCORE_POFF_POS              (18)
#define PC_BTCORE_POFF_BIT              (0x01UL << PC_BTCORE_POFF_POS)
#define PC_BTCORE_PWRSYS_TMR_POFF_POS   (19)
#define PC_BTCORE_PWRSYS_TMR_POFF_BIT   (0x01UL << PC_BTCORE_PWRSYS_TMR_POFF_POS)
#define PC_BTCORE_PWRSYS_PON_POS        (20)
#define PC_BTCORE_PWRSYS_PON_BIT        (0x01UL << PC_BTCORE_PWRSYS_PON_POS)
#define PC_BTCORE_PWRSYS_POFF_POS       (21)
#define PC_BTCORE_PWRSYS_POFF_BIT       (0x01UL << PC_BTCORE_PWRSYS_POFF_POS)
#define PC_BTCORE_AWAKE_SOFT_REQ_POS    (22)
#define PC_BTCORE_AWAKE_SOFT_REQ_BIT    (0x01UL << PC_BTCORE_AWAKE_SOFT_REQ_POS)
#define PC_BTCORE_AWAKE_REQVLDCLR_POS   (23)
#define PC_BTCORE_AWAKE_REQVLDCLR_BIT   (0x01UL << PC_BTCORE_AWAKE_REQVLDCLR_POS)
#define PC_BTCORE_AWAKE_SOFTREQBT_POS   (24)
#define PC_BTCORE_AWAKE_SOFTREQBT_BIT   (0x01UL << PC_BTCORE_AWAKE_SOFTREQBT_POS)

__STATIC_INLINE uint32_t pwrctrl_btcore_get(void)
{
    return AIC_PWRCTRL->BTCORE;
}

__STATIC_INLINE void pwrctrl_btcore_set(uint32_t reg_val)
{
    AIC_PWRCTRL->BTCORE = reg_val;
}

__STATIC_INLINE uint16_t pwrctrl_btcore_awake_src_getf(void)
{
    return ((AIC_PWRCTRL->BTCORE & PC_BTCORE_AWAKE_SRC_MASK) >> PC_BTCORE_AWAKE_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_btcore_awake_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->BTCORE & ~PC_BTCORE_AWAKE_SRC_MASK;
    AIC_PWRCTRL->BTCORE = local_val | ((awake_src << PC_BTCORE_AWAKE_SRC_LSB) & PC_BTCORE_AWAKE_SRC_MASK);
}

__STATIC_INLINE uint16_t pwrctrl_btcore_sleep_src_getf(void)
{
    return ((AIC_PWRCTRL->BTCORE & PC_BTCORE_SLEEP_SRC_MASK) >> PC_BTCORE_SLEEP_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_btcore_sleep_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->BTCORE & ~PC_BTCORE_SLEEP_SRC_MASK;
    AIC_PWRCTRL->BTCORE = local_val | ((awake_src << PC_BTCORE_SLEEP_SRC_LSB) & PC_BTCORE_SLEEP_SRC_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_btcore_sleep_src_wifi_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_SLEEP_SRC_WIFI_BIT) >> PC_BTCORE_SLEEP_SRC_WIFI_POS;
}

__STATIC_INLINE void pwrctrl_btcore_sleep_src_wifi_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_sleep_src_wifi_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_sleep_src_bt_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_SLEEP_SRC_BT_BIT) >> PC_BTCORE_SLEEP_SRC_BT_POS;
}

__STATIC_INLINE void pwrctrl_btcore_sleep_src_bt_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_sleep_src_bt_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_sleep_soft_req_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_SLEEP_SOFT_REQ_BIT) >> PC_BTCORE_SLEEP_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_btcore_sleep_soft_req_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_SLEEP_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_sleep_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_SLEEP_REQVLDCLR_BIT) >> PC_BTCORE_SLEEP_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_btcore_sleep_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_SLEEP_REQVLDCLR_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_hwen_pon_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_HWEN_PON_BIT) >> PC_BTCORE_HWEN_PON_POS;
}

__STATIC_INLINE void pwrctrl_btcore_hwen_pon_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_HWEN_PON_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_hwen_pon_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_HWEN_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_hwen_poff_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_HWEN_POFF_BIT) >> PC_BTCORE_HWEN_POFF_POS;
}

__STATIC_INLINE void pwrctrl_btcore_hwen_poff_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_HWEN_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_hwen_poff_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_HWEN_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_pon_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_PON_BIT) >> PC_BTCORE_PON_POS;
}

__STATIC_INLINE void pwrctrl_btcore_pon_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_PON_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_pon_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_poff_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_POFF_BIT) >> PC_BTCORE_POFF_POS;
}

__STATIC_INLINE void pwrctrl_btcore_poff_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_poff_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_pwrsys_timer_poff_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_PWRSYS_TMR_POFF_BIT) >> PC_BTCORE_PWRSYS_TMR_POFF_POS;
}

__STATIC_INLINE void pwrctrl_btcore_pwrsys_timer_poff_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_pwrsys_timer_poff_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_pwrsys_pon_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_PWRSYS_PON_BIT) >> PC_BTCORE_PWRSYS_PON_POS;
}

__STATIC_INLINE void pwrctrl_btcore_pwrsys_pon_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_PWRSYS_PON_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_pwrsys_pon_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_PWRSYS_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_pwrsys_poff_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_PWRSYS_POFF_BIT) >> PC_BTCORE_PWRSYS_POFF_POS;
}

__STATIC_INLINE void pwrctrl_btcore_pwrsys_poff_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_PWRSYS_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_pwrsys_poff_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_PWRSYS_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_awake_soft_req_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_AWAKE_SOFT_REQ_BIT) >> PC_BTCORE_AWAKE_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_btcore_awake_soft_req_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_AWAKE_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_awake_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_AWAKE_REQVLDCLR_BIT) >> PC_BTCORE_AWAKE_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_btcore_awake_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_AWAKE_REQVLDCLR_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_btcore_awake_soft_req_to_bt_getb(void)
{
    return (AIC_PWRCTRL->BTCORE & PC_BTCORE_AWAKE_SOFTREQBT_BIT) >> PC_BTCORE_AWAKE_SOFTREQBT_POS;
}

__STATIC_INLINE void pwrctrl_btcore_awake_soft_req_to_bt_setb(void)
{
    AIC_PWRCTRL->BTCORE |=  PC_BTCORE_AWAKE_SOFTREQBT_BIT;
}

__STATIC_INLINE void pwrctrl_btcore_awake_soft_req_to_bt_clrb(void)
{
    AIC_PWRCTRL->BTCORE &= ~PC_BTCORE_AWAKE_SOFTREQBT_BIT;
}

/**
 * Address Offset: 0x008
 * Register Name : PC WIFICORE
 */

#define PC_WIFICORE_AWAKE_SRC_LSB       (0)
#define PC_WIFICORE_AWAKE_SRC_WIDTH     (10)
#define PC_WIFICORE_AWAKE_SRC_MASK      (((0x01UL << PC_WIFICORE_AWAKE_SRC_WIDTH) - 1) << PC_WIFICORE_AWAKE_SRC_LSB)
#define PC_WIFICORE_SLEEP_SRC_LSB       (10)
#define PC_WIFICORE_SLEEP_SRC_WIDTH     (2)
#define PC_WIFICORE_SLEEP_SRC_MASK      (((0x01UL << PC_WIFICORE_SLEEP_SRC_WIDTH) - 1) << PC_WIFICORE_SLEEP_SRC_LSB)
#define PC_WIFICORE_SLEEP_SRC_WIFI_POS  (10)
#define PC_WIFICORE_SLEEP_SRC_WIFI_BIT  (0x01UL << PC_WIFICORE_SLEEP_SRC_WIFI_POS)
#define PC_WIFICORE_SLEEP_SRC_BT_POS    (11)
#define PC_WIFICORE_SLEEP_SRC_BT_BIT    (0x01UL << PC_WIFICORE_SLEEP_SRC_BT_POS)
#define PC_WIFICORE_SLEEP_SOFT_REQ_POS  (12)
#define PC_WIFICORE_SLEEP_SOFT_REQ_BIT  (0x01UL << PC_WIFICORE_SLEEP_SOFT_REQ_POS)
#define PC_WIFICORE_SLEEP_REQVLDCLR_POS (13)
#define PC_WIFICORE_SLEEP_REQVLDCLR_BIT (0x01UL << PC_WIFICORE_SLEEP_REQVLDCLR_POS)
#define PC_WIFICORE_HWEN_PON_POS        (15)
#define PC_WIFICORE_HWEN_PON_BIT        (0x01UL << PC_WIFICORE_HWEN_PON_POS)
#define PC_WIFICORE_HWEN_POFF_POS       (16)
#define PC_WIFICORE_HWEN_POFF_BIT       (0x01UL << PC_WIFICORE_HWEN_POFF_POS)
#define PC_WIFICORE_PON_POS             (17)
#define PC_WIFICORE_PON_BIT             (0x01UL << PC_WIFICORE_PON_POS)
#define PC_WIFICORE_POFF_POS            (18)
#define PC_WIFICORE_POFF_BIT            (0x01UL << PC_WIFICORE_POFF_POS)
#define PC_WIFICORE_PWRSYS_TMR_POFF_POS (19)
#define PC_WIFICORE_PWRSYS_TMR_POFF_BIT (0x01UL << PC_WIFICORE_PWRSYS_TMR_POFF_POS)
#define PC_WIFICORE_PWRSYS_PON_POS      (20)
#define PC_WIFICORE_PWRSYS_PON_BIT      (0x01UL << PC_WIFICORE_PWRSYS_PON_POS)
#define PC_WIFICORE_PWRSYS_POFF_POS     (21)
#define PC_WIFICORE_PWRSYS_POFF_BIT     (0x01UL << PC_WIFICORE_PWRSYS_POFF_POS)
#define PC_WIFICORE_AWAKE_SOFT_REQ_POS  (22)
#define PC_WIFICORE_AWAKE_SOFT_REQ_BIT  (0x01UL << PC_WIFICORE_AWAKE_SOFT_REQ_POS)
#define PC_WIFICORE_AWAKE_REQVLDCLR_POS (23)
#define PC_WIFICORE_AWAKE_REQVLDCLR_BIT (0x01UL << PC_WIFICORE_AWAKE_REQVLDCLR_POS)
#define PC_WIFICORE_AWAKE_SOFTREQWF_POS (24)
#define PC_WIFICORE_AWAKE_SOFTREQWF_BIT (0x01UL << PC_WIFICORE_AWAKE_SOFTREQWF_POS)

__STATIC_INLINE uint32_t pwrctrl_wificore_get(void)
{
    return AIC_PWRCTRL->WIFICORE;
}

__STATIC_INLINE void pwrctrl_wificore_set(uint32_t reg_val)
{
    AIC_PWRCTRL->WIFICORE = reg_val;
}

__STATIC_INLINE uint16_t pwrctrl_wificore_awake_src_getf(void)
{
    return ((AIC_PWRCTRL->WIFICORE & PC_WIFICORE_AWAKE_SRC_MASK) >> PC_WIFICORE_AWAKE_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_wificore_awake_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->WIFICORE & ~PC_WIFICORE_AWAKE_SRC_MASK;
    AIC_PWRCTRL->WIFICORE = local_val | ((awake_src << PC_WIFICORE_AWAKE_SRC_LSB) & PC_WIFICORE_AWAKE_SRC_MASK);
}

__STATIC_INLINE uint16_t pwrctrl_wificore_sleep_src_getf(void)
{
    return ((AIC_PWRCTRL->WIFICORE & PC_WIFICORE_SLEEP_SRC_MASK) >> PC_WIFICORE_SLEEP_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_wificore_sleep_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->WIFICORE & ~PC_WIFICORE_SLEEP_SRC_MASK;
    AIC_PWRCTRL->WIFICORE = local_val | ((awake_src << PC_WIFICORE_SLEEP_SRC_LSB) & PC_WIFICORE_SLEEP_SRC_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_wificore_sleep_src_wifi_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_SLEEP_SRC_WIFI_BIT) >> PC_WIFICORE_SLEEP_SRC_WIFI_POS;
}

__STATIC_INLINE void pwrctrl_wificore_sleep_src_wifi_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_sleep_src_wifi_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_sleep_src_bt_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_SLEEP_SRC_BT_BIT) >> PC_WIFICORE_SLEEP_SRC_BT_POS;
}

__STATIC_INLINE void pwrctrl_wificore_sleep_src_bt_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_sleep_src_bt_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_sleep_soft_req_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_SLEEP_SOFT_REQ_BIT) >> PC_WIFICORE_SLEEP_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_wificore_sleep_soft_req_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_SLEEP_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_sleep_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_SLEEP_REQVLDCLR_BIT) >> PC_WIFICORE_SLEEP_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_wificore_sleep_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_SLEEP_REQVLDCLR_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_hwen_pon_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_HWEN_PON_BIT) >> PC_WIFICORE_HWEN_PON_POS;
}

__STATIC_INLINE void pwrctrl_wificore_hwen_pon_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_HWEN_PON_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_hwen_pon_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_HWEN_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_hwen_poff_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_HWEN_POFF_BIT) >> PC_WIFICORE_HWEN_POFF_POS;
}

__STATIC_INLINE void pwrctrl_wificore_hwen_poff_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_HWEN_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_hwen_poff_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_HWEN_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_pon_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_PON_BIT) >> PC_WIFICORE_PON_POS;
}

__STATIC_INLINE void pwrctrl_wificore_pon_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_PON_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_pon_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_poff_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_POFF_BIT) >> PC_WIFICORE_POFF_POS;
}

__STATIC_INLINE void pwrctrl_wificore_poff_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_poff_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_pwrsys_timer_poff_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_PWRSYS_TMR_POFF_BIT) >> PC_WIFICORE_PWRSYS_TMR_POFF_POS;
}

__STATIC_INLINE void pwrctrl_wificore_pwrsys_timer_poff_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_pwrsys_timer_poff_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_pwrsys_pon_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_PWRSYS_PON_BIT) >> PC_WIFICORE_PWRSYS_PON_POS;
}

__STATIC_INLINE void pwrctrl_wificore_pwrsys_pon_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_PWRSYS_PON_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_pwrsys_pon_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_PWRSYS_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_pwrsys_poff_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_PWRSYS_POFF_BIT) >> PC_WIFICORE_PWRSYS_POFF_POS;
}

__STATIC_INLINE void pwrctrl_wificore_pwrsys_poff_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_PWRSYS_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_pwrsys_poff_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_PWRSYS_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_awake_soft_req_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_AWAKE_SOFT_REQ_BIT) >> PC_WIFICORE_AWAKE_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_wificore_awake_soft_req_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_AWAKE_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_awake_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_AWAKE_REQVLDCLR_BIT) >> PC_WIFICORE_AWAKE_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_wificore_awake_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_AWAKE_REQVLDCLR_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_wificore_awake_soft_req_to_wifi_getb(void)
{
    return (AIC_PWRCTRL->WIFICORE & PC_WIFICORE_AWAKE_SOFTREQWF_BIT) >> PC_WIFICORE_AWAKE_SOFTREQWF_POS;
}

__STATIC_INLINE void pwrctrl_wificore_awake_soft_req_to_wifi_setb(void)
{
    AIC_PWRCTRL->WIFICORE |=  PC_WIFICORE_AWAKE_SOFTREQWF_BIT;
}

__STATIC_INLINE void pwrctrl_wificore_awake_soft_req_to_wifi_clrb(void)
{
    AIC_PWRCTRL->WIFICORE &= ~PC_WIFICORE_AWAKE_SOFTREQWF_BIT;
}

/**
 * Address Offset: 0x010
 * Register Name : PC PWRSYS CTRL
 */

#define PC_PWRSYS_DEJITTER_LSB              (0)
#define PC_PWRSYS_DEJITTER_WIDTH            (16)
#define PC_PWRSYS_DEJITTER_MASK             (((0x01UL << PC_PWRSYS_DEJITTER_WIDTH) - 1) << PC_PWRSYS_DEJITTER_LSB)
#define PC_PWRSYS_PON_SOFT_POS              (16)
#define PC_PWRSYS_PON_SOFT_BIT              (0x01UL << PC_PWRSYS_PON_SOFT_POS)
#define PC_PWRSYS_PON_SOFT_EN_POS           (17)
#define PC_PWRSYS_PON_SOFT_EN_BIT           (0x01UL << PC_PWRSYS_PON_SOFT_EN_POS)
#define PC_PWRSYS_PU_PLL_SOFT_POS           (18)
#define PC_PWRSYS_PU_PLL_SOFT_BIT           (0x01UL << PC_PWRSYS_PU_PLL_SOFT_POS)
#define PC_PWRSYS_PU_PLL_SOFT_EN_POS        (19)
#define PC_PWRSYS_PU_PLL_SOFT_EN_BIT        (0x01UL << PC_PWRSYS_PU_PLL_SOFT_EN_POS)
#define PC_PWRSYS_CHIP_SLP_SOFT_POS         (20)
#define PC_PWRSYS_CHIP_SLP_SOFT_BIT         (0x01UL << PC_PWRSYS_CHIP_SLP_SOFT_POS)
#define PC_PWRSYS_CHIP_SLP_SOFT_EN_POS      (21)
#define PC_PWRSYS_CHIP_SLP_SOFT_EN_BIT      (0x01UL << PC_PWRSYS_CHIP_SLP_SOFT_EN_POS)
#define PC_PWRSYS_CG_PLL_SOFT_POS           (22)
#define PC_PWRSYS_CG_PLL_SOFT_BIT           (0x01UL << PC_PWRSYS_CG_PLL_SOFT_POS)
#define PC_PWRSYS_CG_PLL_SOFT_EN_POS        (23)
#define PC_PWRSYS_CG_PLL_SOFT_EN_BIT        (0x01UL << PC_PWRSYS_CG_PLL_SOFT_EN_POS)
#define PC_PWRSYS_CLK32K52M_SEL_SOFT_POS    (24)
#define PC_PWRSYS_CLK32K52M_SEL_SOFT_BIT    (0x01UL << PC_PWRSYS_CLK32K52M_SEL_SOFT_POS)
#define PC_PWRSYS_CLK32K52M_SEL_SOFT_EN_POS (25)
#define PC_PWRSYS_CLK32K52M_SEL_SOFT_EN_BIT (0x01UL << PC_PWRSYS_CLK32K52M_SEL_SOFT_EN_POS)
#define PC_PWRSYS_CLK32K52M_SW_EN_POS       (26)
#define PC_PWRSYS_CLK32K52M_SW_EN_BIT       (0x01UL << PC_PWRSYS_CLK32K52M_SW_EN_POS)
#define PC_PWRSYS_POFF_HW_EN_POS            (27)
#define PC_PWRSYS_POFF_HW_EN_BIT            (0x01UL << PC_PWRSYS_POFF_HW_EN_POS)
#define PC_PWRSYS_XTAL_PD_EN_POS            (28)
#define PC_PWRSYS_XTAL_PD_EN_BIT            (0x01UL << PC_PWRSYS_XTAL_PD_EN_POS)
#define PC_PWRSYS_PU_XTAL_SOFT_POS          (29)
#define PC_PWRSYS_PU_XTAL_SOFT_BIT          (0x01UL << PC_PWRSYS_PU_XTAL_SOFT_POS)
#define PC_PWRSYS_PU_XTAL_SOFT_EN_POS       (30)
#define PC_PWRSYS_PU_XTAL_SOFT_EN_BIT       (0x01UL << PC_PWRSYS_PU_XTAL_SOFT_EN_POS)
#define PC_PWRSYS_CHIP_SLP_HW_EN_POS        (31)
#define PC_PWRSYS_CHIP_SLP_HW_EN_BIT        (0x01UL << PC_PWRSYS_CHIP_SLP_HW_EN_POS)

__STATIC_INLINE uint8_t pwrctrl_pwrsys_chip_slp_hw_en_getb(void)
{
    return (AIC_PWRCTRL->PWRSYS & PC_PWRSYS_CHIP_SLP_HW_EN_BIT) >> PC_PWRSYS_CHIP_SLP_HW_EN_POS;
}

__STATIC_INLINE void pwrctrl_pwrsys_chip_slp_hw_en_setb(void)
{
    AIC_PWRCTRL->PWRSYS |=  PC_PWRSYS_CHIP_SLP_HW_EN_BIT;
}

__STATIC_INLINE void pwrctrl_pwrsys_chip_slp_hw_en_clrb(void)
{
    AIC_PWRCTRL->PWRSYS &= ~PC_PWRSYS_CHIP_SLP_HW_EN_BIT;
}

/**
 * Address Offset: 0x01C
 * Register Name : PC CTRL DELAY1
 */

#define PC_CTRLDLY1_PRE_DELAY_LSB           (0)
#define PC_CTRLDLY1_PRE_DELAY_WIDTH         (16)
#define PC_CTRLDLY1_PRE_DELAY_MASK          (((0x01UL << PC_CTRLDLY1_PRE_DELAY_WIDTH) - 1) << PC_CTRLDLY1_PRE_DELAY_LSB)
#define PC_CTRLDLY1_DELAY_LSB               (16)
#define PC_CTRLDLY1_DELAY_WIDTH             (16)
#define PC_CTRLDLY1_DELAY_MASK              (((0x01UL << PC_CTRLDLY1_DELAY_WIDTH) - 1) << PC_CTRLDLY1_DELAY_LSB)

__STATIC_INLINE uint16_t pwrctrl_ctrldly1_pre_delay_getf(void)
{
    return ((AIC_PWRCTRL->CTRLDLY[0] & PC_CTRLDLY1_PRE_DELAY_MASK) >> PC_CTRLDLY1_PRE_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_ctrldly1_pre_delay_setf(uint16_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->CTRLDLY[0] & ~PC_CTRLDLY1_PRE_DELAY_MASK;
    AIC_PWRCTRL->CTRLDLY[0] = local_val | ((delay << PC_CTRLDLY1_PRE_DELAY_LSB) & PC_CTRLDLY1_PRE_DELAY_MASK);
}

__STATIC_INLINE uint16_t pwrctrl_ctrldly1_delay_getf(void)
{
    return ((AIC_PWRCTRL->CTRLDLY[0] & PC_CTRLDLY1_DELAY_MASK) >> PC_CTRLDLY1_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_ctrldly1_delay_setf(uint16_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->CTRLDLY[0] & ~PC_CTRLDLY1_DELAY_MASK;
    AIC_PWRCTRL->CTRLDLY[0] = local_val | ((delay << PC_CTRLDLY1_DELAY_LSB) & PC_CTRLDLY1_DELAY_MASK);
}

/**
 * Address Offset: 0x020
 * Register Name : PC CTRL DELAY2
 */

#define PC_CTRLDLY2_STATE_DELAY_LSB         (0)
#define PC_CTRLDLY2_STATE_DELAY_WIDTH       (8)
#define PC_CTRLDLY2_STATE_DELAY_MASK        (((0x01UL << PC_CTRLDLY2_STATE_DELAY_WIDTH) - 1) << PC_CTRLDLY2_STATE_DELAY_LSB)
#define PC_CTRLDLY2_XTAL_CLOSE_DELAY_LSB    (8)
#define PC_CTRLDLY2_XTAL_CLOSE_DELAY_WIDTH  (8)
#define PC_CTRLDLY2_XTAL_CLOSE_DELAY_MASK   (((0x01UL << PC_CTRLDLY2_XTAL_CLOSE_DELAY_WIDTH) - 1) << PC_CTRLDLY2_XTAL_CLOSE_DELAY_LSB)
#define PC_CTRLDLY2_XTAL_OPEN_DELAY_LSB     (16)
#define PC_CTRLDLY2_XTAL_OPEN_DELAY_WIDTH   (8)
#define PC_CTRLDLY2_XTAL_OPEN_DELAY_MASK    (((0x01UL << PC_CTRLDLY2_XTAL_OPEN_DELAY_WIDTH) - 1) << PC_CTRLDLY2_XTAL_OPEN_DELAY_LSB)
#define PC_CTRLDLY2_PUPD_XTAL_DELAY_LSB     (24)
#define PC_CTRLDLY2_PUPD_XTAL_DELAY_WIDTH   (8)
#define PC_CTRLDLY2_PUPD_XTAL_DELAY_MASK    (((0x01UL << PC_CTRLDLY2_PUPD_XTAL_DELAY_WIDTH) - 1) << PC_CTRLDLY2_PUPD_XTAL_DELAY_LSB)

__STATIC_INLINE uint8_t pwrctrl_ctrldly2_state_delay_getf(void)
{
    return ((AIC_PWRCTRL->CTRLDLY[1] & PC_CTRLDLY2_STATE_DELAY_MASK) >> PC_CTRLDLY2_STATE_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_ctrldly2_state_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->CTRLDLY[1] & ~PC_CTRLDLY2_STATE_DELAY_MASK;
    AIC_PWRCTRL->CTRLDLY[1] = local_val | ((delay << PC_CTRLDLY2_STATE_DELAY_LSB) & PC_CTRLDLY2_STATE_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_ctrldly2_xtal_close_delay_getf(void)
{
    return ((AIC_PWRCTRL->CTRLDLY[1] & PC_CTRLDLY2_XTAL_CLOSE_DELAY_MASK) >> PC_CTRLDLY2_XTAL_CLOSE_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_ctrldly2_xtal_close_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->CTRLDLY[1] & ~PC_CTRLDLY2_XTAL_CLOSE_DELAY_MASK;
    AIC_PWRCTRL->CTRLDLY[1] = local_val | ((delay << PC_CTRLDLY2_XTAL_CLOSE_DELAY_LSB) & PC_CTRLDLY2_XTAL_CLOSE_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_ctrldly2_xtal_open_delay_getf(void)
{
    return ((AIC_PWRCTRL->CTRLDLY[1] & PC_CTRLDLY2_XTAL_OPEN_DELAY_MASK) >> PC_CTRLDLY2_XTAL_OPEN_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_ctrldly2_xtal_open_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->CTRLDLY[1] & ~PC_CTRLDLY2_XTAL_OPEN_DELAY_MASK;
    AIC_PWRCTRL->CTRLDLY[1] = local_val | ((delay << PC_CTRLDLY2_XTAL_OPEN_DELAY_LSB) & PC_CTRLDLY2_XTAL_OPEN_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_ctrldly2_pupd_xtal_delay_getf(void)
{
    return ((AIC_PWRCTRL->CTRLDLY[1] & PC_CTRLDLY2_PUPD_XTAL_DELAY_MASK) >> PC_CTRLDLY2_PUPD_XTAL_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_ctrldly2_pupd_xtal_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->CTRLDLY[1] & ~PC_CTRLDLY2_PUPD_XTAL_DELAY_MASK;
    AIC_PWRCTRL->CTRLDLY[1] = local_val | ((delay << PC_CTRLDLY2_PUPD_XTAL_DELAY_LSB) & PC_CTRLDLY2_PUPD_XTAL_DELAY_MASK);
}

/**
 * Address Offset: 0x024
 * Register Name : PC SYS DELAY1
 */

#define PC_SYSDLY1_DP_OPEN_DELAY_LSB        (0)
#define PC_SYSDLY1_DP_OPEN_DELAY_WIDTH      (8)
#define PC_SYSDLY1_DP_OPEN_DELAY_MASK       (((0x01UL << PC_SYSDLY1_DP_OPEN_DELAY_WIDTH) - 1) << PC_SYSDLY1_DP_OPEN_DELAY_LSB)
#define PC_SYSDLY1_DP_CLOSE_DELAY_LSB       (8)
#define PC_SYSDLY1_DP_CLOSE_DELAY_WIDTH     (8)
#define PC_SYSDLY1_DP_CLOSE_DELAY_MASK      (((0x01UL << PC_SYSDLY1_DP_CLOSE_DELAY_WIDTH) - 1) << PC_SYSDLY1_DP_CLOSE_DELAY_LSB)
#define PC_SYSDLY1_CG_OPEN_DELAY_LSB        (16)
#define PC_SYSDLY1_CG_OPEN_DELAY_WIDTH      (8)
#define PC_SYSDLY1_CG_OPEN_DELAY_MASK       (((0x01UL << PC_SYSDLY1_CG_OPEN_DELAY_WIDTH) - 1) << PC_SYSDLY1_CG_OPEN_DELAY_LSB)
#define PC_SYSDLY1_CG_CLOSE_DELAY_LSB       (24)
#define PC_SYSDLY1_CG_CLOSE_DELAY_WIDTH     (8)
#define PC_SYSDLY1_CG_CLOSE_DELAY_MASK      (((0x01UL << PC_SYSDLY1_CG_CLOSE_DELAY_WIDTH) - 1) << PC_SYSDLY1_CG_CLOSE_DELAY_LSB)

__STATIC_INLINE uint8_t pwrctrl_sysdly1_dp_open_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[0] & PC_SYSDLY1_DP_OPEN_DELAY_MASK) >> PC_SYSDLY1_DP_OPEN_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly1_dp_open_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[0] & ~PC_SYSDLY1_DP_OPEN_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[0] = local_val | ((delay << PC_SYSDLY1_DP_OPEN_DELAY_LSB) & PC_SYSDLY1_DP_OPEN_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_sysdly1_dp_close_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[0] & PC_SYSDLY1_DP_CLOSE_DELAY_MASK) >> PC_SYSDLY1_DP_CLOSE_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly1_dp_close_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[0] & ~PC_SYSDLY1_DP_CLOSE_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[0] = local_val | ((delay << PC_SYSDLY1_DP_CLOSE_DELAY_LSB) & PC_SYSDLY1_DP_CLOSE_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_sysdly1_cg_open_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[0] & PC_SYSDLY1_CG_OPEN_DELAY_MASK) >> PC_SYSDLY1_CG_OPEN_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly1_cg_open_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[0] & ~PC_SYSDLY1_CG_OPEN_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[0] = local_val | ((delay << PC_SYSDLY1_CG_OPEN_DELAY_LSB) & PC_SYSDLY1_CG_OPEN_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_sysdly1_cg_close_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[0] & PC_SYSDLY1_CG_CLOSE_DELAY_MASK) >> PC_SYSDLY1_CG_CLOSE_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly1_cg_close_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[0] & ~PC_SYSDLY1_CG_CLOSE_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[0] = local_val | ((delay << PC_SYSDLY1_CG_CLOSE_DELAY_LSB) & PC_SYSDLY1_CG_CLOSE_DELAY_MASK);
}

/**
 * Address Offset: 0x028
 * Register Name : PC SYS DELAY2
 */

#define PC_SYSDLY2_PWR_OPEN_DELAY_LSB       (0)
#define PC_SYSDLY2_PWR_OPEN_DELAY_WIDTH     (8)
#define PC_SYSDLY2_PWR_OPEN_DELAY_MASK      (((0x01UL << PC_SYSDLY2_PWR_OPEN_DELAY_WIDTH) - 1) << PC_SYSDLY2_PWR_OPEN_DELAY_LSB)
#define PC_SYSDLY2_PWR_CLOSE_DELAY_LSB      (8)
#define PC_SYSDLY2_PWR_CLOSE_DELAY_WIDTH    (8)
#define PC_SYSDLY2_PWR_CLOSE_DELAY_MASK     (((0x01UL << PC_SYSDLY2_PWR_CLOSE_DELAY_WIDTH) - 1) << PC_SYSDLY2_PWR_CLOSE_DELAY_LSB)
#define PC_SYSDLY2_PLL_OPEN_DELAY_LSB       (16)
#define PC_SYSDLY2_PLL_OPEN_DELAY_WIDTH     (8)
#define PC_SYSDLY2_PLL_OPEN_DELAY_MASK      (((0x01UL << PC_SYSDLY2_PLL_OPEN_DELAY_WIDTH) - 1) << PC_SYSDLY2_PLL_OPEN_DELAY_LSB)
#define PC_SYSDLY2_PLL_CLOSE_DELAY_LSB      (24)
#define PC_SYSDLY2_PLL_CLOSE_DELAY_WIDTH    (8)
#define PC_SYSDLY2_PLL_CLOSE_DELAY_MASK     (((0x01UL << PC_SYSDLY2_PLL_CLOSE_DELAY_WIDTH) - 1) << PC_SYSDLY2_PLL_CLOSE_DELAY_LSB)

__STATIC_INLINE uint8_t pwrctrl_sysdly2_pwr_open_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[1] & PC_SYSDLY2_PWR_OPEN_DELAY_MASK) >> PC_SYSDLY2_PWR_OPEN_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly2_pwr_open_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[1] & ~PC_SYSDLY2_PWR_OPEN_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[1] = local_val | ((delay << PC_SYSDLY2_PWR_OPEN_DELAY_LSB) & PC_SYSDLY2_PWR_OPEN_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_sysdly2_pwr_close_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[1] & PC_SYSDLY2_PWR_CLOSE_DELAY_MASK) >> PC_SYSDLY2_PWR_CLOSE_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly2_pwr_close_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[1] & ~PC_SYSDLY2_PWR_CLOSE_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[1] = local_val | ((delay << PC_SYSDLY2_PWR_CLOSE_DELAY_LSB) & PC_SYSDLY2_PWR_CLOSE_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_sysdly2_pll_open_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[1] & PC_SYSDLY2_PLL_OPEN_DELAY_MASK) >> PC_SYSDLY2_PLL_OPEN_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly2_pll_open_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[1] & ~PC_SYSDLY2_PLL_OPEN_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[1] = local_val | ((delay << PC_SYSDLY2_PLL_OPEN_DELAY_LSB) & PC_SYSDLY2_PLL_OPEN_DELAY_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_sysdly2_pll_close_delay_getf(void)
{
    return ((AIC_PWRCTRL->SYSDLY[1] & PC_SYSDLY2_PLL_CLOSE_DELAY_MASK) >> PC_SYSDLY2_PLL_CLOSE_DELAY_LSB);
}

__STATIC_INLINE void pwrctrl_sysdly2_pll_close_delay_setf(uint8_t delay)
{
    uint32_t local_val = AIC_PWRCTRL->SYSDLY[1] & ~PC_SYSDLY2_PLL_CLOSE_DELAY_MASK;
    AIC_PWRCTRL->SYSDLY[1] = local_val | ((delay << PC_SYSDLY2_PLL_CLOSE_DELAY_LSB) & PC_SYSDLY2_PLL_CLOSE_DELAY_MASK);
}

/**
 * Address Offset: 0x030
 * Register Name : PC STATE1
 */

#define PC_STATE1_PONSTAB_WIFICORE_POS      (1)
#define PC_STATE1_PONSTAB_WIFICORE_BIT      (0x01UL << PC_STATE1_PONSTAB_WIFICORE_POS)
#define PC_STATE1_PONSTAB_BTCORE_POS        (2)
#define PC_STATE1_PONSTAB_BTCORE_BIT        (0x01UL << PC_STATE1_PONSTAB_BTCORE_POS)
#define PC_STATE1_PONSTAB_CPUSYS_POS        (3)
#define PC_STATE1_PONSTAB_CPUSYS_BIT        (0x01UL << PC_STATE1_PONSTAB_CPUSYS_POS)
#define PC_STATE1_POFFSTAB_WIFICORE_POS     (5)
#define PC_STATE1_POFFSTAB_WIFICORE_BIT     (0x01UL << PC_STATE1_POFFSTAB_WIFICORE_POS)
#define PC_STATE1_POFFSTAB_BTCORE_POS       (6)
#define PC_STATE1_POFFSTAB_BTCORE_BIT       (0x01UL << PC_STATE1_POFFSTAB_BTCORE_POS)
#define PC_STATE1_POFFSTAB_CPUSYS_POS       (7)
#define PC_STATE1_POFFSTAB_CPUSYS_BIT       (0x01UL << PC_STATE1_POFFSTAB_CPUSYS_POS)
#define PC_STATE1_STATE_WIFICORE_LSB        (8)
#define PC_STATE1_STATE_WIFICORE_WIDTH      (4)
#define PC_STATE1_STATE_WIFICORE_MASK       (((0x01UL << PC_STATE1_STATE_WIFICORE_WIDTH) - 1) << PC_STATE1_STATE_WIFICORE_LSB)
#define PC_STATE1_STATE_BTCORE_LSB          (12)
#define PC_STATE1_STATE_BTCORE_WIDTH        (4)
#define PC_STATE1_STATE_BTCORE_MASK         (((0x01UL << PC_STATE1_STATE_BTCORE_WIDTH) - 1) << PC_STATE1_STATE_BTCORE_LSB)
#define PC_STATE1_STATE_CPUSYS_LSB          (16)
#define PC_STATE1_STATE_CPUSYS_WIDTH        (4)
#define PC_STATE1_STATE_CPUSYS_MASK         (((0x01UL << PC_STATE1_STATE_CPUSYS_WIDTH) - 1) << PC_STATE1_STATE_CPUSYS_LSB)
#define PC_STATE1_CURSTATE_WIFICORE_LSB     (20)
#define PC_STATE1_CURSTATE_WIFICORE_WIDTH   (2)
#define PC_STATE1_CURSTATE_WIFICORE_MASK    (((0x01UL << PC_STATE1_CURSTATE_WIFICORE_WIDTH) - 1) << PC_STATE1_CURSTATE_WIFICORE_LSB)
#define PC_STATE1_CURSTATE_BTCORE_LSB       (22)
#define PC_STATE1_CURSTATE_BTCORE_WIDTH     (2)
#define PC_STATE1_CURSTATE_BTCORE_MASK      (((0x01UL << PC_STATE1_CURSTATE_BTCORE_WIDTH) - 1) << PC_STATE1_CURSTATE_BTCORE_LSB)
#define PC_STATE1_CURSTATE_CPUSYS_LSB       (24)
#define PC_STATE1_CURSTATE_CPUSYS_WIDTH     (2)
#define PC_STATE1_CURSTATE_CPUSYS_MASK      (((0x01UL << PC_STATE1_CURSTATE_CPUSYS_WIDTH) - 1) << PC_STATE1_CURSTATE_CPUSYS_LSB)
#define PC_STATE1_CURSTATE_PWRSYS_LSB       (26)
#define PC_STATE1_CURSTATE_PWRSYS_WIDTH     (4)
#define PC_STATE1_CURSTATE_PWRSYS_MASK      (((0x01UL << PC_STATE1_CURSTATE_PWRSYS_WIDTH) - 1) << PC_STATE1_CURSTATE_PWRSYS_LSB)
#define PC_STATE1_CURSTATE_VCORESYS_LSB     (30)
#define PC_STATE1_CURSTATE_VCORESYS_WIDTH   (2)
#define PC_STATE1_CURSTATE_VCORESYS_MASK    (((0x01UL << PC_STATE1_CURSTATE_VCORESYS_WIDTH) - 1) << PC_STATE1_CURSTATE_VCORESYS_LSB)

__STATIC_INLINE uint8_t pwrctrl_state1_pon_stable_wificore_getb(void)
{
    return (AIC_PWRCTRL->STATE[0] & PC_STATE1_PONSTAB_WIFICORE_BIT) >> PC_STATE1_PONSTAB_WIFICORE_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state1_pon_stable_btcore_getb(void)
{
    return (AIC_PWRCTRL->STATE[0] & PC_STATE1_PONSTAB_BTCORE_BIT) >> PC_STATE1_PONSTAB_BTCORE_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state1_pon_stable_cpusys_getb(void)
{
    return (AIC_PWRCTRL->STATE[0] & PC_STATE1_PONSTAB_CPUSYS_BIT) >> PC_STATE1_PONSTAB_CPUSYS_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state1_poff_stable_wificore_getb(void)
{
    return (AIC_PWRCTRL->STATE[0] & PC_STATE1_POFFSTAB_WIFICORE_BIT) >> PC_STATE1_POFFSTAB_WIFICORE_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state1_poff_stable_btcore_getb(void)
{
    return (AIC_PWRCTRL->STATE[0] & PC_STATE1_POFFSTAB_BTCORE_BIT) >> PC_STATE1_POFFSTAB_BTCORE_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state1_poff_stable_cpusys_getb(void)
{
    return (AIC_PWRCTRL->STATE[0] & PC_STATE1_POFFSTAB_CPUSYS_BIT) >> PC_STATE1_POFFSTAB_CPUSYS_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state1_state_wificore_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_STATE_WIFICORE_MASK) >> PC_STATE1_STATE_WIFICORE_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state1_state_btcore_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_STATE_BTCORE_MASK) >> PC_STATE1_STATE_BTCORE_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state1_state_cpusys_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_STATE_CPUSYS_MASK) >> PC_STATE1_STATE_CPUSYS_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state1_curstate_wificore_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_CURSTATE_WIFICORE_MASK) >> PC_STATE1_CURSTATE_WIFICORE_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state1_curstate_btcore_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_CURSTATE_BTCORE_MASK) >> PC_STATE1_CURSTATE_BTCORE_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state1_curstate_cpusys_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_CURSTATE_CPUSYS_MASK) >> PC_STATE1_CURSTATE_CPUSYS_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state1_curstate_pwrsys_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_CURSTATE_PWRSYS_MASK) >> PC_STATE1_CURSTATE_PWRSYS_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state1_curstate_vcoresys_getf(void)
{
    return ((AIC_PWRCTRL->STATE[0] & PC_STATE1_CURSTATE_VCORESYS_MASK) >> PC_STATE1_CURSTATE_VCORESYS_LSB);
}

/**
 * Address Offset: 0x034
 * Register Name : PC STATE2
 */

#define PC_STATE2_PONSTAB_VCORESYS_POS  (0)
#define PC_STATE2_PONSTAB_VCORESYS_BIT  (0x01UL << PC_STATE2_PONSTAB_VCORESYS_POS)
#define PC_STATE2_PONSTAB_AONRAM1_POS   (1)
#define PC_STATE2_PONSTAB_AONRAM1_BIT   (0x01UL << PC_STATE2_PONSTAB_AONRAM1_POS)
#define PC_STATE2_PONSTAB_AONRAM2_POS   (2)
#define PC_STATE2_PONSTAB_AONRAM2_BIT   (0x01UL << PC_STATE2_PONSTAB_AONRAM2_POS)
#define PC_STATE2_PONSTAB_MMSYS_POS     (3)
#define PC_STATE2_PONSTAB_MMSYS_BIT     (0x01UL << PC_STATE2_PONSTAB_MMSYS_POS)
#define PC_STATE2_POFFSTAB_VCORESYS_POS (4)
#define PC_STATE2_POFFSTAB_VCORESYS_BIT (0x01UL << PC_STATE2_POFFSTAB_VCORESYS_POS)
#define PC_STATE2_POFFSTAB_AONRAM1_POS  (5)
#define PC_STATE2_POFFSTAB_AONRAM1_BIT  (0x01UL << PC_STATE2_POFFSTAB_AONRAM1_POS)
#define PC_STATE2_POFFSTAB_AONRAM2_POS  (6)
#define PC_STATE2_POFFSTAB_AONRAM2_BIT  (0x01UL << PC_STATE2_POFFSTAB_AONRAM2_POS)
#define PC_STATE2_POFFSTAB_MMSYS_POS    (7)
#define PC_STATE2_POFFSTAB_MMSYS_BIT    (0x01UL << PC_STATE2_POFFSTAB_MMSYS_POS)
#define PC_STATE2_STATE_AONRAM1_LSB     (8)
#define PC_STATE2_STATE_AONRAM1_WIDTH   (4)
#define PC_STATE2_STATE_AONRAM1_MASK    (((0x01UL << PC_STATE2_STATE_AONRAM1_WIDTH) - 1) << PC_STATE2_STATE_AONRAM1_LSB)
#define PC_STATE2_STATE_AONRAM2_LSB     (12)
#define PC_STATE2_STATE_AONRAM2_WIDTH   (4)
#define PC_STATE2_STATE_AONRAM2_MASK    (((0x01UL << PC_STATE2_STATE_AONRAM2_WIDTH) - 1) << PC_STATE2_STATE_AONRAM2_LSB)
#define PC_STATE2_STATE_MMSYS_LSB       (16)
#define PC_STATE2_STATE_MMSYS_WIDTH     (4)
#define PC_STATE2_STATE_MMSYS_MASK      (((0x01UL << PC_STATE2_STATE_MMSYS_WIDTH) - 1) << PC_STATE2_STATE_MMSYS_LSB)
#define PC_STATE2_STATE_VCORESYS_LSB    (20)
#define PC_STATE2_STATE_VCORESYS_WIDTH  (4)
#define PC_STATE2_STATE_VCORESYS_MASK   (((0x01UL << PC_STATE2_STATE_VCORESYS_WIDTH) - 1) << PC_STATE2_STATE_VCORESYS_LSB)

__STATIC_INLINE uint8_t pwrctrl_state2_pon_stable_vcoresys_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_PONSTAB_VCORESYS_BIT) >> PC_STATE2_PONSTAB_VCORESYS_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_pon_stable_aonram1_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_PONSTAB_AONRAM1_BIT) >> PC_STATE2_PONSTAB_AONRAM1_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_pon_stable_aonram2_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_PONSTAB_AONRAM2_BIT) >> PC_STATE2_PONSTAB_AONRAM2_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_pon_stable_mmsys_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_PONSTAB_MMSYS_BIT) >> PC_STATE2_PONSTAB_MMSYS_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_poff_stable_vcoresys_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_POFFSTAB_VCORESYS_BIT) >> PC_STATE2_POFFSTAB_VCORESYS_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_poff_stable_aonram1_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_POFFSTAB_AONRAM1_BIT) >> PC_STATE2_POFFSTAB_AONRAM1_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_poff_stable_aonram2_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_POFFSTAB_AONRAM2_BIT) >> PC_STATE2_POFFSTAB_AONRAM2_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_poff_stable_mmsys_getb(void)
{
    return (AIC_PWRCTRL->STATE[1] & PC_STATE2_POFFSTAB_MMSYS_BIT) >> PC_STATE2_POFFSTAB_MMSYS_POS;
}

__STATIC_INLINE uint8_t pwrctrl_state2_state_aonram1_getf(void)
{
    return ((AIC_PWRCTRL->STATE[1] & PC_STATE2_STATE_AONRAM1_MASK) >> PC_STATE2_STATE_AONRAM1_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state2_state_aonram2_getf(void)
{
    return ((AIC_PWRCTRL->STATE[1] & PC_STATE2_STATE_AONRAM2_MASK) >> PC_STATE2_STATE_AONRAM2_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state2_state_mmsys_getf(void)
{
    return ((AIC_PWRCTRL->STATE[1] & PC_STATE2_STATE_MMSYS_MASK) >> PC_STATE2_STATE_MMSYS_LSB);
}

__STATIC_INLINE uint8_t pwrctrl_state2_state_vcoresys_getf(void)
{
    return ((AIC_PWRCTRL->STATE[1] & PC_STATE2_STATE_VCORESYS_MASK) >> PC_STATE2_STATE_VCORESYS_LSB);
}

/**
 * Address Offset: 0x038
 * Register Name : PC SOFTMD1
 */

#define PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_LSB      (0)
#define PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_WIDTH    (6)
#define PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_MASK     (((0x01UL << PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_WIDTH) - 1) << PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_LSB)
#define PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_LSB      (6)
#define PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_WIDTH    (6)
#define PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_MASK     (((0x01UL << PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_WIDTH) - 1) << PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_LSB)
#define PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_LSB    (12)
#define PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_WIDTH  (6)
#define PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_MASK   (((0x01UL << PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_WIDTH) - 1) << PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_LSB)
#define PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_LSB     (18)
#define PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_WIDTH   (6)
#define PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_MASK    (((0x01UL << PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_WIDTH) - 1) << PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_LSB)
#define PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_LSB     (24)
#define PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_WIDTH   (6)
#define PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_MASK    (((0x01UL << PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_WIDTH) - 1) << PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_LSB)

__STATIC_INLINE uint8_t pwrctrl_softmd1_cpusys_pwrctrl_soft_getf(void)
{
    return ((AIC_PWRCTRL->SOFTMD1 & PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_MASK) >> PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_LSB);
}

__STATIC_INLINE void pwrctrl_softmd1_cpusys_pwrctrl_soft_setf(uint8_t pwrctrl_soft)
{
    uint32_t local_val = AIC_PWRCTRL->SOFTMD1 & ~PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_MASK;
    AIC_PWRCTRL->SOFTMD1 = local_val | ((pwrctrl_soft << PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_LSB) & PC_SOFTMD1_CPUSYS_PWRCTRL_SOFT_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_softmd1_btcore_pwrctrl_soft_getf(void)
{
    return ((AIC_PWRCTRL->SOFTMD1 & PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_MASK) >> PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_LSB);
}

__STATIC_INLINE void pwrctrl_softmd1_btcore_pwrctrl_soft_setf(uint8_t pwrctrl_soft)
{
    uint32_t local_val = AIC_PWRCTRL->SOFTMD1 & ~PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_MASK;
    AIC_PWRCTRL->SOFTMD1 = local_val | ((pwrctrl_soft << PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_LSB) & PC_SOFTMD1_BTCORE_PWRCTRL_SOFT_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_softmd1_wificore_pwrctrl_soft_getf(void)
{
    return ((AIC_PWRCTRL->SOFTMD1 & PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_MASK) >> PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_LSB);
}

__STATIC_INLINE void pwrctrl_softmd1_wificore_pwrctrl_soft_setf(uint8_t pwrctrl_soft)
{
    uint32_t local_val = AIC_PWRCTRL->SOFTMD1 & ~PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_MASK;
    AIC_PWRCTRL->SOFTMD1 = local_val | ((pwrctrl_soft << PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_LSB) & PC_SOFTMD1_WIFICORE_PWRCTRL_SOFT_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_softmd1_aonram1_pwrctrl_soft_getf(void)
{
    return ((AIC_PWRCTRL->SOFTMD1 & PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_MASK) >> PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_LSB);
}

__STATIC_INLINE void pwrctrl_softmd1_aonram1_pwrctrl_soft_setf(uint8_t pwrctrl_soft)
{
    uint32_t local_val = AIC_PWRCTRL->SOFTMD1 & ~PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_MASK;
    AIC_PWRCTRL->SOFTMD1 = local_val | ((pwrctrl_soft << PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_LSB) & PC_SOFTMD1_AONRAM1_PWRCTRL_SOFT_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_softmd1_aonram2_pwrctrl_soft_getf(void)
{
    return ((AIC_PWRCTRL->SOFTMD1 & PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_MASK) >> PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_LSB);
}

__STATIC_INLINE void pwrctrl_softmd1_aonram2_pwrctrl_soft_setf(uint8_t pwrctrl_soft)
{
    uint32_t local_val = AIC_PWRCTRL->SOFTMD1 & ~PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_MASK;
    AIC_PWRCTRL->SOFTMD1 = local_val | ((pwrctrl_soft << PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_LSB) & PC_SOFTMD1_AONRAM2_PWRCTRL_SOFT_MASK);
}

/**
 * Address Offset: 0x044
 * Register Name : PC IRQCTRL
 */

#define PC_IRQCTRL_CLR_AWAKE_STATE_WIFI_POS     (0)
#define PC_IRQCTRL_CLR_AWAKE_STATE_WIFI_BIT     (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_WIFI_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_BT_POS       (1)
#define PC_IRQCTRL_CLR_AWAKE_STATE_BT_BIT       (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_BT_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_GPIO_POS     (2)
#define PC_IRQCTRL_CLR_AWAKE_STATE_GPIO_BIT     (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_GPIO_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_TMR2_POS     (3)
#define PC_IRQCTRL_CLR_AWAKE_STATE_TMR2_BIT     (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_TMR2_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_C0_POS       (4)
#define PC_IRQCTRL_CLR_AWAKE_STATE_C0_BIT       (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_C0_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_C1_POS       (5)
#define PC_IRQCTRL_CLR_AWAKE_STATE_C1_BIT       (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_C1_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_BTCPU_POS    (6)
#define PC_IRQCTRL_CLR_AWAKE_STATE_BTCPU_BIT    (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_BTCPU_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_WIFICPU_POS  (7)
#define PC_IRQCTRL_CLR_AWAKE_STATE_WIFICPU_BIT  (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_WIFICPU_POS)
#define PC_IRQCTRL_CLR_AWAKE_STATE_PMIC_POS     (8)
#define PC_IRQCTRL_CLR_AWAKE_STATE_PMIC_BIT     (0x01UL << PC_IRQCTRL_CLR_AWAKE_STATE_PMIC_POS)
#define PC_IRQCTRL_CLR_SLEEP_STATE_DIGTOP_POS   (10)
#define PC_IRQCTRL_CLR_SLEEP_STATE_DIGTOP_BIT   (0x01UL << PC_IRQCTRL_CLR_SLEEP_STATE_DIGTOP_POS)
#define PC_IRQCTRL_CLR_SLEEP_STATE_CPUSYS_POS   (11)
#define PC_IRQCTRL_CLR_SLEEP_STATE_CPUSYS_BIT   (0x01UL << PC_IRQCTRL_CLR_SLEEP_STATE_CPUSYS_POS)
#define PC_IRQCTRL_CLR_SLEEP_STATE_BTSYS_POS    (12)
#define PC_IRQCTRL_CLR_SLEEP_STATE_BTSYS_BIT    (0x01UL << PC_IRQCTRL_CLR_SLEEP_STATE_BTSYS_POS)
#define PC_IRQCTRL_CLR_SLEEP_STATE_WIFISYS_POS  (13)
#define PC_IRQCTRL_CLR_SLEEP_STATE_WIFISYS_BIT  (0x01UL << PC_IRQCTRL_CLR_SLEEP_STATE_WIFISYS_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_WIFI_POS     (16)
#define PC_IRQCTRL_MSK_AWAKE_STATE_WIFI_BIT     (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_WIFI_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_BT_POS       (17)
#define PC_IRQCTRL_MSK_AWAKE_STATE_BT_BIT       (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_BT_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_GPIO_POS     (18)
#define PC_IRQCTRL_MSK_AWAKE_STATE_GPIO_BIT     (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_GPIO_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_TMR2_POS     (19)
#define PC_IRQCTRL_MSK_AWAKE_STATE_TMR2_BIT     (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_TMR2_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_C0_POS       (20)
#define PC_IRQCTRL_MSK_AWAKE_STATE_C0_BIT       (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_C0_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_C1_POS       (21)
#define PC_IRQCTRL_MSK_AWAKE_STATE_C1_BIT       (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_C1_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_BTCPU_POS    (22)
#define PC_IRQCTRL_MSK_AWAKE_STATE_BTCPU_BIT    (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_BTCPU_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_WIFICPU_POS  (23)
#define PC_IRQCTRL_MSK_AWAKE_STATE_WIFICPU_BIT  (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_WIFICPU_POS)
#define PC_IRQCTRL_MSK_AWAKE_STATE_PMIC_POS     (24)
#define PC_IRQCTRL_MSK_AWAKE_STATE_PMIC_BIT     (0x01UL << PC_IRQCTRL_MSK_AWAKE_STATE_PMIC_POS)
#define PC_IRQCTRL_MSK_SLEEP_STATE_DIGTOP_POS   (26)
#define PC_IRQCTRL_MSK_SLEEP_STATE_DIGTOP_BIT   (0x01UL << PC_IRQCTRL_MSK_SLEEP_STATE_DIGTOP_POS)
#define PC_IRQCTRL_MSK_SLEEP_STATE_CPUSYS_POS   (27)
#define PC_IRQCTRL_MSK_SLEEP_STATE_CPUSYS_BIT   (0x01UL << PC_IRQCTRL_MSK_SLEEP_STATE_CPUSYS_POS)
#define PC_IRQCTRL_MSK_SLEEP_STATE_BTSYS_POS    (28)
#define PC_IRQCTRL_MSK_SLEEP_STATE_BTSYS_BIT    (0x01UL << PC_IRQCTRL_MSK_SLEEP_STATE_BTSYS_POS)
#define PC_IRQCTRL_MSK_SLEEP_STATE_WIFISYS_POS  (29)
#define PC_IRQCTRL_MSK_SLEEP_STATE_WIFISYS_BIT  (0x01UL << PC_IRQCTRL_MSK_SLEEP_STATE_WIFISYS_POS)
#define PC_IRQCTRL_PWR_CTRL_IRQ_EN_POS          (31)
#define PC_IRQCTRL_PWR_CTRL_IRQ_EN_BIT          (0x01UL << PC_IRQCTRL_PWR_CTRL_IRQ_EN_POS)

__STATIC_INLINE uint32_t pwrctrl_irqctrl_get(void)
{
    return AIC_PWRCTRL->IRQCTRL;
}

__STATIC_INLINE void pwrctrl_irqctrl_set(uint32_t reg_val)
{
    AIC_PWRCTRL->IRQCTRL = reg_val;
}

/**
 * Address Offset: 0x048
 * Register Name : PC IRQSTATUS
 */

#define PC_IRQSTATUS_RAW_AWAKE_STATE_WIFI_POS       (0)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_WIFI_BIT       (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_WIFI_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_BT_POS         (1)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_BT_BIT         (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_BT_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_GPIO_POS       (2)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_GPIO_BIT       (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_GPIO_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_TMR2_POS       (3)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_TMR2_BIT       (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_TMR2_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_C0_POS         (4)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_C0_BIT         (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_C0_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_C1_POS         (5)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_C1_BIT         (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_C1_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_BTCPU_POS      (6)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_BTCPU_BIT      (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_BTCPU_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_WIFICPU_POS    (7)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_WIFICPU_BIT    (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_WIFICPU_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_PMIC_POS       (8)
#define PC_IRQSTATUS_RAW_AWAKE_STATE_PMIC_BIT       (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATE_PMIC_POS)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_DIGTOP_POS     (10)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_DIGTOP_BIT     (0x01UL << PC_IRQSTATUS_RAW_SLEEP_STATE_DIGTOP_POS)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_CPUSYS_POS     (11)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_CPUSYS_BIT     (0x01UL << PC_IRQSTATUS_RAW_SLEEP_STATE_CPUSYS_POS)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_BTSYS_POS      (12)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_BTSYS_BIT      (0x01UL << PC_IRQSTATUS_RAW_SLEEP_STATE_BTSYS_POS)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_WIFISYS_POS    (13)
#define PC_IRQSTATUS_RAW_SLEEP_STATE_WIFISYS_BIT    (0x01UL << PC_IRQSTATUS_RAW_SLEEP_STATE_WIFISYS_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_VCORESYS_POS  (14)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_VCORESYS_BIT  (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATUS_VCORESYS_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_CPUSYS_POS    (15)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_CPUSYS_BIT    (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATUS_CPUSYS_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_WIFI_POS       (16)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_WIFI_BIT       (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_WIFI_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_BT_POS         (17)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_BT_BIT         (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_BT_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_GPIO_POS       (18)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_GPIO_BIT       (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_GPIO_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_TMR2_POS       (19)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_TMR2_BIT       (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_TMR2_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_C0_POS         (20)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_C0_BIT         (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_C0_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_C1_POS         (21)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_C1_BIT         (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_C1_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_BTCPU_POS      (22)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_BTCPU_BIT      (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_BTCPU_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_WIFICPU_POS    (23)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_WIFICPU_BIT    (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_WIFICPU_POS)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_PMIC_POS       (24)
#define PC_IRQSTATUS_MSK_AWAKE_STATE_PMIC_BIT       (0x01UL << PC_IRQSTATUS_MSK_AWAKE_STATE_PMIC_POS)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_DIGTOP_POS     (26)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_DIGTOP_BIT     (0x01UL << PC_IRQSTATUS_MSK_SLEEP_STATE_DIGTOP_POS)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_CPUSYS_POS     (27)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_CPUSYS_BIT     (0x01UL << PC_IRQSTATUS_MSK_SLEEP_STATE_CPUSYS_POS)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_BTSYS_POS      (28)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_BTSYS_BIT      (0x01UL << PC_IRQSTATUS_MSK_SLEEP_STATE_BTSYS_POS)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_WIFISYS_POS    (29)
#define PC_IRQSTATUS_MSK_SLEEP_STATE_WIFISYS_BIT    (0x01UL << PC_IRQSTATUS_MSK_SLEEP_STATE_WIFISYS_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_BTCORE_POS    (30)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_BTCORE_BIT    (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATUS_BTCORE_POS)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_WIFICORE_POS  (31)
#define PC_IRQSTATUS_RAW_AWAKE_STATUS_WIFICORE_BIT  (0x01UL << PC_IRQSTATUS_RAW_AWAKE_STATUS_WIFICORE_POS)

__STATIC_INLINE uint32_t pwrctrl_irqstatus_get(void)
{
    return AIC_PWRCTRL->IRQSTATUS;
}

__STATIC_INLINE void pwrctrl_irqstatus_set(uint32_t reg_val)
{
    AIC_PWRCTRL->IRQSTATUS = reg_val;
}

/**
 * Address Offset: 0x04C
 * Register Name : PC MMSYS
 */

#define PC_MMSYS_PON_POS                (17)
#define PC_MMSYS_PON_BIT                (0x01UL << PC_MMSYS_PON_POS)
#define PC_MMSYS_POFF_POS               (18)
#define PC_MMSYS_POFF_BIT               (0x01UL << PC_MMSYS_POFF_POS)

__STATIC_INLINE uint8_t pwrctrl_mmsys_pon_getb(void)
{
    return (AIC_PWRCTRL->MMSYS & PC_MMSYS_PON_BIT) >> PC_MMSYS_PON_POS;
}

__STATIC_INLINE void pwrctrl_mmsys_pon_setb(void)
{
    AIC_PWRCTRL->MMSYS |=  PC_MMSYS_PON_BIT;
}

__STATIC_INLINE void pwrctrl_mmsys_pon_clrb(void)
{
    AIC_PWRCTRL->MMSYS &= ~PC_MMSYS_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_mmsys_poff_getb(void)
{
    return (AIC_PWRCTRL->MMSYS & PC_MMSYS_POFF_BIT) >> PC_MMSYS_POFF_POS;
}

__STATIC_INLINE void pwrctrl_mmsys_poff_setb(void)
{
    AIC_PWRCTRL->MMSYS |=  PC_MMSYS_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_mmsys_poff_clrb(void)
{
    AIC_PWRCTRL->MMSYS &= ~PC_MMSYS_POFF_BIT;
}

/**
 * Address Offset: 0x050
 * Register Name : PC SOFTMD2
 */

#define PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_LSB       (0)
#define PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_WIDTH     (6)
#define PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_MASK      (((0x01UL << PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_WIDTH) - 1) << PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_LSB)
#define PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_LSB    (6)
#define PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_WIDTH  (6)
#define PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_MASK   (((0x01UL << PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_WIDTH) - 1) << PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_LSB)
#define PC_SOFTMD2_SLP_MODE_SEL_AONRAM1_POS     (12)
#define PC_SOFTMD2_SLP_MODE_SEL_AONRAM1_BIT     (0x01UL << PC_SOFTMD2_SLP_MODE_SEL_AONRAM1_POS)
#define PC_SOFTMD2_SLP_MODE_SEL_AONRAM2_POS     (13)
#define PC_SOFTMD2_SLP_MODE_SEL_AONRAM2_BIT     (0x01UL << PC_SOFTMD2_SLP_MODE_SEL_AONRAM2_POS)
#define PC_SOFTMD2_SLP_MODE_SEL_BTCORE_POS      (14)
#define PC_SOFTMD2_SLP_MODE_SEL_BTCORE_BIT      (0x01UL << PC_SOFTMD2_SLP_MODE_SEL_BTCORE_POS)
#define PC_SOFTMD2_SLP_MODE_SEL_CPUSYS_POS      (15)
#define PC_SOFTMD2_SLP_MODE_SEL_CPUSYS_BIT      (0x01UL << PC_SOFTMD2_SLP_MODE_SEL_CPUSYS_POS)
#define PC_SOFTMD2_SLP_MODE_SEL_MMSYS_POS       (16)
#define PC_SOFTMD2_SLP_MODE_SEL_MMSYS_BIT       (0x01UL << PC_SOFTMD2_SLP_MODE_SEL_MMSYS_POS)
#define PC_SOFTMD2_SLP_MODE_SEL_VCORESYS_POS    (17)
#define PC_SOFTMD2_SLP_MODE_SEL_VCORESYS_BIT    (0x01UL << PC_SOFTMD2_SLP_MODE_SEL_VCORESYS_POS)
#define PC_SOFTMD2_SLP_MODE_SEL_WIFICORE_POS    (18)
#define PC_SOFTMD2_SLP_MODE_SEL_WIFICORE_BIT    (0x01UL << PC_SOFTMD2_SLP_MODE_SEL_WIFICORE_POS)

__STATIC_INLINE uint8_t pwrctrl_softmd2_mmsys_pwrctrl_soft_getf(void)
{
    return ((AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_MASK) >> PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_LSB);
}

__STATIC_INLINE void pwrctrl_softmd2_mmsys_pwrctrl_soft_setf(uint8_t pwrctrl_soft)
{
    uint32_t local_val = AIC_PWRCTRL->SOFTMD2 & ~PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_MASK;
    AIC_PWRCTRL->SOFTMD2 = local_val | ((pwrctrl_soft << PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_LSB) & PC_SOFTMD2_MMSYS_PWRCTRL_SOFT_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_vcoresys_pwrctrl_soft_getf(void)
{
    return ((AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_MASK) >> PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_LSB);
}

__STATIC_INLINE void pwrctrl_softmd2_vcoresys_pwrctrl_soft_setf(uint8_t pwrctrl_soft)
{
    uint32_t local_val = AIC_PWRCTRL->SOFTMD2 & ~PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_MASK;
    AIC_PWRCTRL->SOFTMD2 = local_val | ((pwrctrl_soft << PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_LSB) & PC_SOFTMD2_VCORESYS_PWRCTRL_SOFT_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_slp_mode_sel_aonram1_getb(void)
{
    return (AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_SLP_MODE_SEL_AONRAM1_BIT) >> PC_SOFTMD2_SLP_MODE_SEL_AONRAM1_POS;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_aonram1_setb(void)
{
    AIC_PWRCTRL->SOFTMD2 |=  PC_SOFTMD2_SLP_MODE_SEL_AONRAM1_BIT;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_aonram1_clrb(void)
{
    AIC_PWRCTRL->SOFTMD2 &= ~PC_SOFTMD2_SLP_MODE_SEL_AONRAM1_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_slp_mode_sel_aonram2_getb(void)
{
    return (AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_SLP_MODE_SEL_AONRAM2_BIT) >> PC_SOFTMD2_SLP_MODE_SEL_AONRAM2_POS;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_aonram2_setb(void)
{
    AIC_PWRCTRL->SOFTMD2 |=  PC_SOFTMD2_SLP_MODE_SEL_AONRAM2_BIT;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_aonram2_clrb(void)
{
    AIC_PWRCTRL->SOFTMD2 &= ~PC_SOFTMD2_SLP_MODE_SEL_AONRAM2_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_slp_mode_sel_btcore_getb(void)
{
    return (AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_SLP_MODE_SEL_BTCORE_BIT) >> PC_SOFTMD2_SLP_MODE_SEL_BTCORE_POS;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_btcore_setb(void)
{
    AIC_PWRCTRL->SOFTMD2 |=  PC_SOFTMD2_SLP_MODE_SEL_BTCORE_BIT;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_btcore_clrb(void)
{
    AIC_PWRCTRL->SOFTMD2 &= ~PC_SOFTMD2_SLP_MODE_SEL_BTCORE_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_slp_mode_sel_cpusys_getb(void)
{
    return (AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_SLP_MODE_SEL_CPUSYS_BIT) >> PC_SOFTMD2_SLP_MODE_SEL_CPUSYS_POS;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_cpusys_setb(void)
{
    AIC_PWRCTRL->SOFTMD2 |=  PC_SOFTMD2_SLP_MODE_SEL_CPUSYS_BIT;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_cpusys_clrb(void)
{
    AIC_PWRCTRL->SOFTMD2 &= ~PC_SOFTMD2_SLP_MODE_SEL_CPUSYS_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_slp_mode_sel_mmsys_getb(void)
{
    return (AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_SLP_MODE_SEL_MMSYS_BIT) >> PC_SOFTMD2_SLP_MODE_SEL_MMSYS_POS;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_mmsys_setb(void)
{
    AIC_PWRCTRL->SOFTMD2 |=  PC_SOFTMD2_SLP_MODE_SEL_MMSYS_BIT;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_mmsys_clrb(void)
{
    AIC_PWRCTRL->SOFTMD2 &= ~PC_SOFTMD2_SLP_MODE_SEL_MMSYS_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_slp_mode_sel_vcoresys_getb(void)
{
    return (AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_SLP_MODE_SEL_VCORESYS_BIT) >> PC_SOFTMD2_SLP_MODE_SEL_VCORESYS_POS;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_vcoresys_setb(void)
{
    AIC_PWRCTRL->SOFTMD2 |=  PC_SOFTMD2_SLP_MODE_SEL_VCORESYS_BIT;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_vcoresys_clrb(void)
{
    AIC_PWRCTRL->SOFTMD2 &= ~PC_SOFTMD2_SLP_MODE_SEL_VCORESYS_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_softmd2_slp_mode_sel_wificore_getb(void)
{
    return (AIC_PWRCTRL->SOFTMD2 & PC_SOFTMD2_SLP_MODE_SEL_WIFICORE_BIT) >> PC_SOFTMD2_SLP_MODE_SEL_WIFICORE_POS;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_wificore_setb(void)
{
    AIC_PWRCTRL->SOFTMD2 |=  PC_SOFTMD2_SLP_MODE_SEL_WIFICORE_BIT;
}

__STATIC_INLINE void pwrctrl_softmd2_slp_mode_sel_wificore_clrb(void)
{
    AIC_PWRCTRL->SOFTMD2 &= ~PC_SOFTMD2_SLP_MODE_SEL_WIFICORE_BIT;
}

/**
 * Address Offset: 0x054
 * Register Name : PC VCORESYS
 */

#define PC_VCORESYS_AWAKE_SRC_LSB       (0)
#define PC_VCORESYS_AWAKE_SRC_WIDTH     (10)
#define PC_VCORESYS_AWAKE_SRC_MASK      (((0x01UL << PC_VCORESYS_AWAKE_SRC_WIDTH) - 1) << PC_VCORESYS_AWAKE_SRC_LSB)
#define PC_VCORESYS_SLEEP_SRC_LSB       (10)
#define PC_VCORESYS_SLEEP_SRC_WIDTH     (2)
#define PC_VCORESYS_SLEEP_SRC_MASK      (((0x01UL << PC_VCORESYS_SLEEP_SRC_WIDTH) - 1) << PC_VCORESYS_SLEEP_SRC_LSB)
#define PC_VCORESYS_SLEEP_SRC_WIFI_POS  (10)
#define PC_VCORESYS_SLEEP_SRC_WIFI_BIT  (0x01UL << PC_VCORESYS_SLEEP_SRC_WIFI_POS)
#define PC_VCORESYS_SLEEP_SRC_BT_POS    (11)
#define PC_VCORESYS_SLEEP_SRC_BT_BIT    (0x01UL << PC_VCORESYS_SLEEP_SRC_BT_POS)
#define PC_VCORESYS_SLEEP_SOFT_REQ_POS  (12)
#define PC_VCORESYS_SLEEP_SOFT_REQ_BIT  (0x01UL << PC_VCORESYS_SLEEP_SOFT_REQ_POS)
#define PC_VCORESYS_SLEEP_REQVLDCLR_POS (13)
#define PC_VCORESYS_SLEEP_REQVLDCLR_BIT (0x01UL << PC_VCORESYS_SLEEP_REQVLDCLR_POS)
#define PC_VCORESYS_HWEN_PON_POS        (15)
#define PC_VCORESYS_HWEN_PON_BIT        (0x01UL << PC_VCORESYS_HWEN_PON_POS)
#define PC_VCORESYS_HWEN_POFF_POS       (16)
#define PC_VCORESYS_HWEN_POFF_BIT       (0x01UL << PC_VCORESYS_HWEN_POFF_POS)
#define PC_VCORESYS_PON_POS             (17)
#define PC_VCORESYS_PON_BIT             (0x01UL << PC_VCORESYS_PON_POS)
#define PC_VCORESYS_POFF_POS            (18)
#define PC_VCORESYS_POFF_BIT            (0x01UL << PC_VCORESYS_POFF_POS)
#define PC_VCORESYS_PWRSYS_TMR_POFF_POS (19)
#define PC_VCORESYS_PWRSYS_TMR_POFF_BIT (0x01UL << PC_VCORESYS_PWRSYS_TMR_POFF_POS)
#define PC_VCORESYS_PWRSYS_PON_POS      (20)
#define PC_VCORESYS_PWRSYS_PON_BIT      (0x01UL << PC_VCORESYS_PWRSYS_PON_POS)
#define PC_VCORESYS_PWRSYS_POFF_POS     (21)
#define PC_VCORESYS_PWRSYS_POFF_BIT     (0x01UL << PC_VCORESYS_PWRSYS_POFF_POS)
#define PC_VCORESYS_AWAKE_SOFT_REQ_POS  (22)
#define PC_VCORESYS_AWAKE_SOFT_REQ_BIT  (0x01UL << PC_VCORESYS_AWAKE_SOFT_REQ_POS)
#define PC_VCORESYS_AWAKE_REQVLDCLR_POS (23)
#define PC_VCORESYS_AWAKE_REQVLDCLR_BIT (0x01UL << PC_VCORESYS_AWAKE_REQVLDCLR_POS)

__STATIC_INLINE uint32_t pwrctrl_vcoresys_get(void)
{
    return AIC_PWRCTRL->VCORESYS;
}

__STATIC_INLINE void pwrctrl_vcoresys_set(uint32_t reg_val)
{
    AIC_PWRCTRL->VCORESYS = reg_val;
}

__STATIC_INLINE uint16_t pwrctrl_vcoresys_awake_src_getf(void)
{
    return ((AIC_PWRCTRL->VCORESYS & PC_VCORESYS_AWAKE_SRC_MASK) >> PC_VCORESYS_AWAKE_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_vcoresys_awake_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->VCORESYS & ~PC_VCORESYS_AWAKE_SRC_MASK;
    AIC_PWRCTRL->VCORESYS = local_val | ((awake_src << PC_VCORESYS_AWAKE_SRC_LSB) & PC_VCORESYS_AWAKE_SRC_MASK);
}

__STATIC_INLINE uint16_t pwrctrl_vcoresys_sleep_src_getf(void)
{
    return ((AIC_PWRCTRL->VCORESYS & PC_VCORESYS_SLEEP_SRC_MASK) >> PC_VCORESYS_SLEEP_SRC_LSB);
}

__STATIC_INLINE void pwrctrl_vcoresys_sleep_src_setf(uint16_t awake_src)
{
    uint32_t local_val = AIC_PWRCTRL->VCORESYS & ~PC_VCORESYS_SLEEP_SRC_MASK;
    AIC_PWRCTRL->VCORESYS = local_val | ((awake_src << PC_VCORESYS_SLEEP_SRC_LSB) & PC_VCORESYS_SLEEP_SRC_MASK);
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_sleep_src_wifi_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_SLEEP_SRC_WIFI_BIT) >> PC_VCORESYS_SLEEP_SRC_WIFI_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_sleep_src_wifi_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_sleep_src_wifi_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_SLEEP_SRC_WIFI_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_sleep_src_bt_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_SLEEP_SRC_BT_BIT) >> PC_VCORESYS_SLEEP_SRC_BT_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_sleep_src_bt_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_sleep_src_bt_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_SLEEP_SRC_BT_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_sleep_soft_req_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_SLEEP_SOFT_REQ_BIT) >> PC_VCORESYS_SLEEP_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_sleep_soft_req_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_SLEEP_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_sleep_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_SLEEP_REQVLDCLR_BIT) >> PC_VCORESYS_SLEEP_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_sleep_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_SLEEP_REQVLDCLR_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_hwen_pon_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_HWEN_PON_BIT) >> PC_VCORESYS_HWEN_PON_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_hwen_pon_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_HWEN_PON_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_hwen_pon_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_HWEN_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_hwen_poff_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_HWEN_POFF_BIT) >> PC_VCORESYS_HWEN_POFF_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_hwen_poff_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_HWEN_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_hwen_poff_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_HWEN_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_pon_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_PON_BIT) >> PC_VCORESYS_PON_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_pon_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_PON_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_pon_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_poff_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_POFF_BIT) >> PC_VCORESYS_POFF_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_poff_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_poff_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_pwrsys_timer_poff_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_PWRSYS_TMR_POFF_BIT) >> PC_VCORESYS_PWRSYS_TMR_POFF_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_pwrsys_timer_poff_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_pwrsys_timer_poff_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_PWRSYS_TMR_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_pwrsys_pon_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_PWRSYS_PON_BIT) >> PC_VCORESYS_PWRSYS_PON_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_pwrsys_pon_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_PWRSYS_PON_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_pwrsys_pon_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_PWRSYS_PON_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_pwrsys_poff_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_PWRSYS_POFF_BIT) >> PC_VCORESYS_PWRSYS_POFF_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_pwrsys_poff_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_PWRSYS_POFF_BIT;
}

__STATIC_INLINE void pwrctrl_vcoresys_pwrsys_poff_clrb(void)
{
    AIC_PWRCTRL->VCORESYS &= ~PC_VCORESYS_PWRSYS_POFF_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_awake_soft_req_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_AWAKE_SOFT_REQ_BIT) >> PC_VCORESYS_AWAKE_SOFT_REQ_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_awake_soft_req_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_AWAKE_SOFT_REQ_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_vcoresys_awake_req_vld_clr_getb(void)
{
    return (AIC_PWRCTRL->VCORESYS & PC_VCORESYS_AWAKE_REQVLDCLR_BIT) >> PC_VCORESYS_AWAKE_REQVLDCLR_POS;
}

__STATIC_INLINE void pwrctrl_vcoresys_awake_req_vld_clr_setb(void)
{
    AIC_PWRCTRL->VCORESYS |=  PC_VCORESYS_AWAKE_REQVLDCLR_BIT;
}

/**
 * Address Offset: 0x05C
 * Register Name : PC PWRMD
 */

#define PC_PWRMD_CPUSYS_SW_RECORD_LSB   (0)
#define PC_PWRMD_CPUSYS_SW_RECORD_WIDTH (2)
#define PC_PWRMD_CPUSYS_SW_RECORD_MASK  (((0x01UL << PC_PWRMD_CPUSYS_SW_RECORD_WIDTH) - 1) << PC_PWRMD_CPUSYS_SW_RECORD_LSB)
#define PC_PWRMD_FLASH_SMPLDLY_LSB      (2)
#define PC_PWRMD_FLASH_SMPLDLY_WIDTH    (3)
#define PC_PWRMD_FLASH_SMPLDLY_MASK     (((0x01UL << PC_PWRMD_FLASH_SMPLDLY_WIDTH) - 1) << PC_PWRMD_FLASH_SMPLDLY_LSB)
#define PC_PWRMD_FLASH_CLKSEL_FAST_POS  (5)
#define PC_PWRMD_FLASH_CLKSEL_FAST_BIT  (0x01UL << PC_PWRMD_FLASH_CLKSEL_FAST_POS)
#define PC_PWRMD_FLASH_CLKDIV_LSB       (6)
#define PC_PWRMD_FLASH_CLKDIV_WIDTH     (8)
#define PC_PWRMD_FLASH_CLKDIV_MASK      (((0x01UL << PC_PWRMD_FLASH_CLKDIV_WIDTH) - 1) << PC_PWRMD_FLASH_CLKDIV_LSB)
#define PC_PWRMD_UPDATE_POS             (31)
#define PC_PWRMD_UPDATE_BIT             (0x01UL << PC_PWRMD_UPDATE_POS)

__STATIC_INLINE uint32_t pwrctrl_pwrmd_cpusys_sw_record_getf(void)
{
    return ((AIC_PWRCTRL->PWRMD & PC_PWRMD_CPUSYS_SW_RECORD_MASK) >> PC_PWRMD_CPUSYS_SW_RECORD_LSB);
}

__STATIC_INLINE void pwrctrl_pwrmd_cpusys_sw_record_setf(uint32_t mode)
{
    uint32_t local_val = AIC_PWRCTRL->PWRMD & ~PC_PWRMD_CPUSYS_SW_RECORD_MASK;
    AIC_PWRCTRL->PWRMD = local_val | ((mode << PC_PWRMD_CPUSYS_SW_RECORD_LSB) & PC_PWRMD_CPUSYS_SW_RECORD_MASK) | PC_PWRMD_UPDATE_BIT;
}

__STATIC_INLINE uint8_t pwrctrl_pwrmd_flash_clksel_fast_getb(void)
{
    return (AIC_PWRCTRL->PWRMD & PC_PWRMD_FLASH_CLKSEL_FAST_BIT) >> PC_PWRMD_FLASH_CLKSEL_FAST_POS;
}

__STATIC_INLINE void pwrctrl_pwrmd_flash_clksel_fast_setb(void)
{
    AIC_PWRCTRL->PWRMD |=  PC_PWRMD_FLASH_CLKSEL_FAST_BIT;
}

__STATIC_INLINE void pwrctrl_pwrmd_flash_clksel_fast_clrb(void)
{
    AIC_PWRCTRL->PWRMD &= ~PC_PWRMD_FLASH_CLKSEL_FAST_BIT;
}

__STATIC_INLINE uint32_t pwrctrl_pwrmd_flash_clkdiv_smpldly_getf(void)
{
    return ((AIC_PWRCTRL->PWRMD & (PC_PWRMD_FLASH_CLKDIV_MASK | PC_PWRMD_FLASH_SMPLDLY_MASK)) >> PC_PWRMD_FLASH_SMPLDLY_LSB);
}

__STATIC_INLINE void pwrctrl_pwrmd_flash_clkdiv_smpldly_setf(uint32_t div_dly)
{
    uint32_t local_val = AIC_PWRCTRL->PWRMD & ~(PC_PWRMD_FLASH_CLKDIV_MASK | PC_PWRMD_FLASH_SMPLDLY_MASK);
    AIC_PWRCTRL->PWRMD = local_val | ((div_dly << PC_PWRMD_FLASH_SMPLDLY_LSB) & (PC_PWRMD_FLASH_CLKDIV_MASK | PC_PWRMD_FLASH_SMPLDLY_MASK));
}

#endif // _REG_SYSCTRL_H_
