/*
 *  Copyright (C) 2008 STMicroelectronics
 *  Copyright (C) 2009 ST-Ericsson.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef ASM_ARCH_IRQS_H
#define ASM_ARCH_IRQS_H

#include <mach/hardware.h>
#include <linux/gpio.h>

/* Shared Peripheral Interrupt (SHPI) */
#define IRQ_SHPI_START			32

/*
 * MTU0 preserved for now until plat-nomadik is taught not to use it.  Don't
 * add any other IRQs here, use the irqs-dbx500.h files.
 */
#define IRQ_MTU0			(IRQ_SHPI_START + 4)

#define GIC_PPI_START			29
#define IRQ_LOCALTIMER			29
#define IRQ_LOCALWDOG			30

/*********************************************************************/

#define DBX500_NR_INTERNAL_IRQS	(IRQ_SHPI_START + 224)

/* After chip-specific IRQ numbers we have the GPIO ones */
#define NOMADIK_GPIO_TO_IRQ(gpio)	((gpio) + DBX500_NR_INTERNAL_IRQS)
#define NOMADIK_IRQ_TO_GPIO(irq)	((irq) - DBX500_NR_INTERNAL_IRQS)

#define GPIO_TO_IRQ			NOMADIK_GPIO_TO_IRQ
#define IRQ_TO_GPIO			NOMADIK_IRQ_TO_GPIO
#define IRQ_GPIO_END			NOMADIK_GPIO_TO_IRQ(NOMADIK_NR_GPIO)

#define IRQ_SOC_START			IRQ_GPIO_END
/* This will be overridden by SoC-specific irq headers */
#define IRQ_SOC_END			IRQ_SOC_START

#define IRQ_BOARD_START			IRQ_SOC_END
/* This will be overridden by board-specific irq headers */
#define IRQ_BOARD_END			IRQ_BOARD_START

#include <mach/irqs-db8500.h>
#include <mach/irqs-db9540.h>
#include <mach/irqs-db8540.h>

#ifdef CONFIG_MACH_UX500
#include <mach/irqs-board-mop500.h>
#else
#include <mach/irqs-board-semc.h>
#endif

#ifndef NR_IRQS
#define NR_IRQS			IRQ_BOARD_END
#endif

#endif /* ASM_ARCH_IRQS_H */