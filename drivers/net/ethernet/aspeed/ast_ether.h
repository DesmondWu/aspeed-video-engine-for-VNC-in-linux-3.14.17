#ifndef _AST_ETHER_H_
#define _AST_ETHER_H_

#ifdef CONFIG_SPX_FEATURE_GLOBAL_NIC_COUNT
#define AST_ETHER_MAX_NUM       CONFIG_SPX_FEATURE_GLOBAL_NIC_COUNT
#else
#define AST_ETHER_MAX_NUM		2
#endif
#define AST_ETHER_USE_NUM		AST_ETHER_MAX_NUM

#define AST_ETHER_REG_BASE1		0x1E660000
#define AST_ETHER_REG_BASE2		0x1E680000
#define AST_ETHER_REG_BASE3     0x1E670000
#define AST_ETHER_REG_BASE4     0x1E690000

#define AST_ETHER_IRQ1			2
#define AST_ETHER_IRQ2			3
#define AST_ETHER_IRQ3         23
#define AST_ETHER_IRQ4         24

#define AST_ETHER_IO_REG_SIZE	SZ_64K

#define NUM_MAIN_STATS		23
#define ETH_GSTRING_LEN		32
/*---------------------------------------------------------------------------*/

/* registers offset */
#define AST_ETHER_ISR			0x00 /* interrups status register */
#define AST_ETHER_IER			0x04 /* interrupt enable register */
#define AST_ETHER_MAC_MADR		0x08 /* MAC address (Most significant) */
#define AST_ETHER_MAC_LADR		0x0c /* MAC address (Least significant) */
#define AST_ETHER_MAHT0			0x10 /* Multicast Address Hash Table 0 register */
#define AST_ETHER_MAHT1			0x14 /* Multicast Address Hash Table 1 register */
#define AST_ETHER_TXPD			0x18 /* Transmit Poll Demand register */
#define AST_ETHER_RXPD			0x1c /* Receive Poll Demand register */
#define AST_ETHER_TXR_BADR		0x20 /* Transmit Ring Base Address register */
#define AST_ETHER_RXR_BADR		0x24 /* Receive Ring Base Address register */
#define AST_ETHER_HPTXPD		0x28 /* High Performance Transmit Poll Demand register */
#define AST_ETHER_HPTXR_BADR	0x2c /* High Performance Transmit Ring Base Address register */
#define AST_ETHER_ITC			0x30 /* interrupt timer control register */
#define AST_ETHER_APTC			0x34 /* Automatic Polling Timer control register */
#define AST_ETHER_DBLAC			0x38 /* DMA Burst Length and Arbitration control register */
#define AST_ETHER_DMAFIFOS		0x3c /* DMA/FIFO state register */
#define AST_ETHER_FEAR			0x44 /* Fearture register */
#define AST_ETHER_TPAFCR		0x48 /* Transmit priority arbitration and FIFO control register */
#define AST_ETHER_RBSR			0x4c /* Receive Buffer Size register */
#define AST_ETHER_MACCR			0x50 /* MAC control register */
#define AST_ETHER_MACSR			0x54 /* MAC status register */
#define AST_ETHER_TEST_MODE		0x58 /* test mode register */
#define AST_ETHER_PHYCR			0x60 /* PHY control register */
#define AST_ETHER_PHYDATA		0x64 /* PHY Data register */
#define AST_ETHER_FCR			0x68 /* Flow Control register */
#define AST_ETHER_BPR			0x6c /* back pressure register */
#define AST_ETHER_PWRTC			0x70 /* Power control register */

/* bits of interrupt status/enable register */
#define ISR_HPTXBUF_UNAVA			0x00000400
#define ISR_PHYSTS_CHG				0x00000200 /* PHY link status change */
#define ISR_AHB_ERR					0x00000100
#define ISR_TPKT_LOST				0x00000080 /* collision / excessive collision / under-run */
#define ISR_NPTXBUF_UNAVA			0x00000040
#define ISR_TPKT2F					0x00000020 /* data from buffer to FIFO */
#define ISR_TPKT2E					0x00000010 /* data from FIFO to ethernet */
#define ISR_RPKT_LOST				0x00000008 /* Rx FIFO full */
#define ISR_RXBUF_UNAVA				0x00000004
#define ISR_RPKT2F					0x00000002 /* data from ethernet to FIFO */
#define ISR_RPKT2B					0x00000001 /* data from FIFO to buffer */

/* bits of interrupt timer control register */
#define ITCR_TXINT_TIME_SEL			0x00008000
#define ITCR_TXINT_THR_SHIFT		12
#define ITCR_TXINT_THR_MASK			0x00007000
#define ITCR_TXINT_CNT_SHIFT		8
#define ITCR_TXINT_CNT_MASK			0x00000F00
#define ITCR_RXINT_TIME_SEL			0x00000080
#define ITCR_RXINT_THR_SHIFT		4
#define ITCR_RXINT_THR_MASK			0x00000070
#define ITCR_RXINT_CNT_SHIFT		0
#define ITCR_RXINT_CNT_MASK			0x0000000F

/* bits of automatic polling timer control register */
#define APTC_TXPOLL_TIME_SEL		0x00001000
#define APTC_TXPOLL_CNT_SHIFT		8
#define APTC_TXPOLL_CNT_MASK		0x00000F00
#define APTC_RXPOLL_TIME_SEL		0x00000010
#define APTC_RXPOLL_CNT_SHIFT		0
#define APTC_RXPOLL_CNT_MASK		0x0000000F

/* bits of feature register */
#define FEAR_TFIFO_RSIZE_SHIFT		3
#define FEAR_TFIFO_RSIZE_MASK		0x00000038
#define FEAR_RFIFO_RSIZE_SHIFT		0
#define FEAR_RFIFO_RSIZE_MASK		0x00000007

/* bits of transmit priority arbitration and FIFO control register */
#define FPAFCR_TFIFO_SIZE_SHIFT		27
#define FPAFCR_TFIFO_SIZE_MASK		0x38000000
#define FPAFCR_RFIFO_SIZE_SHIFT		24
#define FPAFCR_RFIFO_SIZE_MASK		0x07000000

/* bits of receive buffer size register */
#define RBSR_MASK					0x00003ff8 /* bits[13:3], 8-byte alignment */

/* bits of MAC control register */
#define MACCR_SW_RST				0x80000000 /* software reset */
#define MACCR_SPEED_100				0x00080000 /* Speed mode */
#define MACCR_DISCARD_CRCERR		0x00040000
#define MACCR_RX_BROADPKT_EN		0x00020000 /* Receiving all broadcast packet */
#define MACCR_RX_MULTIPKT_EN		0x00010000 /* receiving all multicast packet */
#define MACCR_RX_HT_EN				0x00008000 /* enable multicast hast table */
#define MACCR_RX_ALLADR				0x00004000 /* Destination address of incoming packet is not checked */
#define MACCR_JUMBO_LF				0x00002000 /* Jumbo Long Frame */
#define MACCR_RX_RUNT				0x00001000 /* Store incoming packet even its length is les than 64 byte */
#define MACCR_CRC_APD				0x00000400 /* Append crc to transmit packet */
#define MACCR_GMAC_MODE				0x00000200 /* 1000 Mpbs mode */
#define MACCR_FULLDUP				0x00000100 /* full duplex */
#define MACCR_ENRX_IN_HALFTX		0x00000080
#define MACCR_PHY_LINK				0x00000040
#define MACCR_HPTXR_EN				0x00000020
#define MACCR_REMOVE_VLAN			0x00000010
#define MACCR_RXMAC_EN				0x00000008 /* receiver enable */
#define MACCR_TXMAC_EN				0x00000004 /* transmitter enable */
#define MACCR_RXDMA_EN				0x00000002 /* enable DMA receiving channel */
#define MACCR_TXDMA_EN				0x00000001 /* enable DMA transmitting channel */

/* bits of PHY control register */
#define PHYCR_WRITE					0x08000000
#define PHYCR_READ					0x04000000
#define PHYCR_REGAD_SHIFT			21
#define PHYCR_REGAD_MASK			0x03E00000
#define PHYCR_PHYAD_SHIFT			16
#define PHYCR_PHYAD_MASK			0x001F0000
#define PHYCR_MDC_CYCTHR_SHIFT		0
#define PHYCR_MDC_CYCTHR_MASK		0x0000001F

/*---------------------------------------------------------------------------*/

/* PHY OUI */
#define MARVELL_88E1111_OUI		0x005043
#define BROADCOM_BCM5221_OUI	0x001018
#define BROADCOM_BCM5241_OUI	0x0050EF
#define BROADCOM_BCM5461_OUI    0x000818
#define BROADCOM_BCM54612E_OUI  0x00D897
#define BROADCOM_BCM5421_OUI    0x180361
#define REALTEK_RTL82X1X_OUI	0x000732
#define MICREL_KSZ80X1_OUI		0x000885

/* PHY model name */
#define BCM54610_MODEL_NAME     0x16

/* addresses of PHY common registers */
#define PHY_COM_REG_ADDR_CONTROL 0
#define PHY_COM_REG_ADDR_STATUS 1
#define PHY_COM_REG_ADDR_ID_HI 2
#define PHY_COM_REG_ADDR_ID_LO 3

/* PHY basic controler register - Register 0 */
#define PHY_COM_REG_CONTROL_SPEED		0x2000 /* bit 13 */
#define PHY_COM_REG_CONTROL_RE_AUTO		0x0200 /* bit 9 */
#define PHY_COM_REG_CONTROL_DUPLEX		0x0100 /* bit 8 */

/* PHY basic status register - Register 1 */
#define PHY_COM_REG_STATUS_AUTO_OK		0x0020
#define PHY_COM_REG_STATUS_LINK			0x0004

/* addresses of Marvell 88E1111 PHY specific registers */
#define MARVELL_88E1111_REG_ADDR_PHY_STATUS 17
#define MARVELL_88E1111_REG_ADDR_INTR_CTRL 18
#define MARVELL_88E1111_REG_ADDR_INTR_STATUS 19

/* Bits of Marvell 88E1111 PHY Specific Status Register - Page 0, Register 17 */
#define MARVELL_88E1111_REG_PHY_STATUS_RESOLVED			0x0800
#define MARVELL_88E1111_REG_PHY_STATUS_SPEED_MASK		0xC000
#define MARVELL_88E1111_REG_PHY_STATUS_DUPLEX_MASK		0x2000

/* addresses of Broadcom BCM5221 PHY specific registers */
#define BROADCOM_BCM5221_REG_ADDR_AUX_CTRL_STAT		0x18

/* addresses of Broadcom BCM54610 PHY specific registers */
#define BROADCOM_BCM54610_REG_ADDR_AUX_CTRL_STAT    0x19


/* Bits of Broadcom BCM5221 Auxiliary Control/Status Register - Register 0x18 */
#define BROADCOM_BCM5221_REG_AUX_CTRL_STAT_SPEED	0x0002
#define BROADCOM_BCM5221_REG_AUX_CTRL_STAT_DEPLEX	0x0001

/* Bits of Broadcom BCM4610 Auxiliary Control/Status Register - Register 0x19 */
#define  BROADCOM_BCM54610_REG_AUX_CTRL_STAT_FULL_1000   0x0700
#define  BROADCOM_BCM54610_REG_AUX_CTRL_STAT_HALF_1000   0x0600
#define  BROADCOM_BCM54610_REG_AUX_CTRL_STAT_FULL_100    0x0500
#define  BROADCOM_BCM54610_REG_AUX_CTRL_STAT_HALF_100    0x0300
#define  BROADCOM_BCM54610_REG_AUX_CTRL_STAT_FULL_10     0x0200
#define  BROADCOM_BCM54610_REG_AUX_CTRL_STAT_HALF_10     0x0100


/* addresses of Realtek RTL8211B PHY specific status register */
#define REALTEK_RTL8211B_REG_ADDR_PHY_STAT		0x11

/* addresses of Realtek RTL8211F PHY specific status register */
#define REALTEK_RTL8211F_REG_ADDR_PHY_STAT		0x1A

/* Bits of ealtek RTL8211B PHY specific status register - Register 0x11 */
#define REALTEK_RTL8211B_REG_ADDR_PHY_STS_SPEED_MASK		0xC000 /* bits[15:14] */
#define REALTEK_RTL8211B_REG_ADDR_PHY_STS_SPEED_SHIFT		14
#define REALTEK_RTL8211B_REG_ADDR_PHY_STS_DEPLEX			0x2000 /* bit 13 */

/* Bits of ealtek RTL8211F PHY specific status register - Register 0x1A */
#define REALTEK_RTL8211F_REG_ADDR_PHY_STS_SPEED_MASK		0x0030 
#define REALTEK_RTL8211F_REG_ADDR_PHY_STS_SPEED_SHIFT		4
#define REALTEK_RTL8211F_REG_ADDR_PHY_STS_DEPLEX			0x0008 

#define MICREL_KSZ8031_REG_STATUS		0x1E
#define MICREL_KSZ8041_REG_STATUS		0x1F
#define MICREL_KSZ9031_REG_STATUS		0x1F

#define MICREL_KSZ8031_REG_STATUS_MASK			0x0007 /* bits[2:0] */
#define MICREL_KSZ8041_REG_STATUS_MASK			0x001C /* bits[4:2] */
#define MICREL_KSZ8041_REG_STATUS_SHIFT			2
#define MICREL_KSZ8041_REG_STATUS_FULL_100		0x0006 /* 110 */
#define MICREL_KSZ8041_REG_STATUS_FULL_10		0x0005 /* 101 */
#define MICREL_KSZ8041_REG_STATUS_HALF_100		0x0002 /* 010 */
#define MICREL_KSZ8041_REG_STATUS_HALF_10		0x0001 /* 001 */

/* these valuse are the same for almost every PHY */
#define PHY_DUPLEX_HALF		0x00
#define PHY_DUPLEX_FULL		0x01

#define PHY_SPEED_10M		0x00
#define PHY_SPEED_100M		0x01
#define PHY_SPEED_1000M		0x02

/*---------------------------------------------------------------------------*/

/* bits of Tx descriptor */
#define TX_DESC_TXDMA_OWN		0x80000000	/* TX Own Bit */
#define TX_DESC_EDOTR			0x40000000	/* TX End Of Ring */
#define TX_DESC_FTS				0x20000000	/* TX First Descriptor Segment */
#define TX_DESC_LTS				0x10000000	/* TX Last Descriptor Segment */
#define TX_DESC_CRC_ERR			0x00080000	/* Tx CRC error */
#define TX_DESC_TXBUF_SIZE		0x00003fff	/* Tx buffer size in byte */

#define TX_DESC_TXIC        	0x80000000	/* TX interrupt on completion */
#define TX_DESC_TX2FIC			0x40000000	/* TX to FIFO interrupt on completion */
#define TX_DESC_IPCS_EN			0x00080000	/* TX IP checksum offlad enable */
#define TX_DESC_UDPCS_EN		0x00040000	/* TX UDP checksum offlad enable */
#define TX_DESC_TCPCS_EN		0x00020000	/* Tx TCP checksum offlad enable */

/* bits of Rx descriptor */
#define RX_DESC_RXPKT_RDY		0x80000000	/* RX Own Bit */
#define RX_DESC_EDORR			0x40000000	/* RX End Of Ring */
#define RX_DESC_FRS				0x20000000	/* RX First Descriptor Segment */
#define RX_DESC_LRS				0x10000000	/* RX Last Descriptor Segment */
#define RX_DESC_FIFO_FULL		0x00800000
#define RX_DESC_RX_ODD_NB		0x00400000
#define RX_DESC_RUNT			0x00200000	/* runt packet */
#define RX_DESC_FTL				0x00100000	/* frame too long */
#define RX_DESC_CRC_ERR			0x00080000	/* CRC error */
#define RX_DESC_RX_ERR			0x00040000	/* RX error */
#define RX_DESC_BROADCAST		0x00020000	/* broadcast frame */
#define RX_DESC_MULTICAST		0x00010000	/* multicast frame */
#define RX_DESC_VDBC			0x00003fff

#define RX_DESC_IPCS_FAIL		0x08000000	/* RX IP checksum offlad failure */
#define RX_DESC_UDPCS_FAIL		0x04000000	/* RX UDP checksum offlad failure */
#define RX_DESC_TCPCS_FAIL		0x02000000	/* Rx TCP checksum offlad failure */

#define RX_DESC_PROTL_TYPE_MASK			0x00300000
#define RX_DESC_PROTL_TYPE_UNKNOWN		0x00000000
#define RX_DESC_PROTL_TYPE_IP			0x00100000
#define RX_DESC_PROTL_TYPE_TCP			0x00200000
#define RX_DESC_PROTL_TYPE_UDP			0x00300000

/*---------------------------------------------------------------------------*/
#if defined(CONFIG_SOC_AST2500)
#define MAX_MTU_SIZE	(2052 - 18) //Jumbo frame payload
#elif defined(CONFIG_SOC_AST2400)
#define MAX_MTU_SIZE	(9216 - 18)
#endif

/* the length of buffer length has to be a power of two */
#define RX_DES_NUM		64
#define RX_BUF_SIZE		1536

#define TX_DES_NUM		32
#define TX_BUF_SIZE		1536
#define VLAN_PROTOCOL           0x8100

struct ast_eth_desc {
	volatile u32 status;
	u32 vlan;
	u32 reserved;
	u32 buffer;
};

#define AST_PHY_STATUS_CHECK_INTERVAL		3 /* for PHY without interrupt */
#define AST_BC_CHECK_INTERVAL			2 	

/* store this information for the driver.. */
struct ast_ether_priv {
	struct net_device_stats stats;
	
	spinlock_t lock;
	spinlock_t mii_lock;
	
	/* virtual address of allocated descriptor */
	struct ast_eth_desc *tx_desc;
	struct ast_eth_desc *rx_desc;

	/* bus address of allocated descriptor */
	dma_addr_t tx_desc_dma;
	dma_addr_t rx_desc_dma;
	
	struct sk_buff *tx_skbuff[TX_DES_NUM]; /* The saved address of a sent-in-place packet/buffer, for skfree(). */
	struct sk_buff *rx_skbuff[RX_DES_NUM]; /* The addresses of receive-in-place skbuffs. */

	/* streaming DMA mapping of socket buffer */
	dma_addr_t tx_skb_dma[TX_DES_NUM];
	dma_addr_t rx_skb_dma[RX_DES_NUM];

	unsigned int cur_tx, cur_rx; /* The next free ring entry */
	unsigned int dirty_tx, dirty_rx; /* The ring entries to be free()ed. */
	
	u32 maccr; /* saved value of MAC control register */

	u32 phy_oui;
	u8 phy_model;
	u8 phy_rev;
	u8 link_state;
	u8 idx; /*Net Device Index*/
    
    u32 supports_gmii : 1; /* are GMII registers supported? */
    
	struct timer_list timer; /* status check timer for PHY without interrupt */
#ifdef CONFIG_ASTMAC100_NAPI
       struct net_device *dev;
       struct napi_struct napi;
#endif
	u8 phy_addr;
};

#ifdef BROADCAST_BLACKLIST
struct ast_bc{
	unsigned long bc_count;
	bool bc_ctr;
	bool trans_busy_1;
	bool trans_busy_2;
	struct timer_list timer;
};
#endif
#define AST_PAUSE_FR_ENABLE 1 

extern void ast_ether_get_mac_addr(unsigned char *mac_addr);
extern int ast_ether_eeprom_read(unsigned int offset, unsigned char *buffer, unsigned int cnt);
 
#endif  /* _AST_ETHER_H_ */
