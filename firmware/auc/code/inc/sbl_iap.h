/*
 * @brief
 *
 * @note
 * Author: Mikeqin Fengling.Qin@gmail.com
 *
 * @par
 * This is free and unencumbered software released into the public domain.
 * For details see the UNLICENSE file at the root of the source tree.
 */
#ifndef  _SBL_IAP_H
#define  _SBL_IAP_H

#define FLASH_BUF_SIZE		256
#define SECTOR_0_START_ADDR	0
#define SECTOR_SIZE			4096
#define MAX_USER_SECTOR		8
#define CCLK				48000/* 48,000 KHz for IAP call */

#define APP_START_ADDR		0x4000
#define APP_END_ADDR		0x8000
#define RAM_START_ADDR		0x10000000
#define NVIC_TABLE_LEN		0x200

extern unsigned char g_flash_buf[FLASH_BUF_SIZE];

enum iap_cmd_code {
	PREPARE_SECTOR_FOR_WRITE=50,
	COPY_RAM_TO_FLASH=51,
	ERASE_SECTOR=52,
	BLANK_CHECK_SECTOR=53,
	READ_PART_ID=54,
	READ_BOOT_VER=55,
	COMPARE=56,
	REINVOKE_ISP=57,
	READ_UID=58
};

int iap_readserialid(char *dna);
void reinvokeisp(void);
int write_updata_flag(void);

#endif /* _SBL_IAP_H */
