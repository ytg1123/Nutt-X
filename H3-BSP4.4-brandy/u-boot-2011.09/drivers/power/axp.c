/*
 * (C) Copyright 2007-2013
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Jerry Wang <wangflord@allwinnertech.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <common.h>
#include <power.h>
#if defined(CONFIG_SUNXI_AXP22)
#  include <power/axp22_reg.h>
#endif
#if defined(CONFIG_SUNXI_AXP20)
#  include <power/axp20_reg.h>
#endif
#include "axp.h"
#include <pmu.h>
#include "sys_config.h"

DECLARE_GLOBAL_DATA_PTR;

sunxi_axp_dev_t  *sunxi_axp_dev[SUNXI_AXP_DEV_MAX] = {(void *)(-1)};

extern int axp22_probe(void);
extern int axp20_probe(void);
extern int axp15_probe(void);
extern int axp809_probe(void);
extern int axp806_probe(void);
extern int axp81_probe(void);
extern int axp808_probe(void);
extern int power_rich_probe(void);
extern int power_oz_probe(void);

int __plat_get_chip_id(void)
{
       return -1;
}

int plat_get_chip_id(void)
       __attribute__((weak, alias("__plat_get_chip_id")));

int axp_probe_power_id(char *name)
{
	if(!strcmp("axp22x", name))
	{
		return PMU_TYPE_22X;
	}
	else if(!strcmp("axp15x", name))
	{
		return PMU_TYPE_15X;
	}
	else if(!strcmp("axp20x", name))
	{
		return PMU_TYPE_22X;
	}
	else if(!strcmp("axp809", name))
	{
		return PMU_TYPE_20X;
	}
	else if(!strcmp("axp806", name))
	{
		return PMU_TYPE_806;
	}
	else if(!strcmp("axp81x", name))
	{
		return PMU_TYPE_81X;
	}
	else if(!strcmp("axp808", name))
	{
		return PMU_TYPE_808;
	}
	else if(!strcmp("poweroz", name))
	{
		return POWER_TYPE_OZ;
	}
	else if(!strcmp("powerrich", name))
	{
		return POWER_TYPE_RICH;
	}

	printf("no power %s\n", name);
	return -1;
}


static int axp_fetch_pmu_id(int *main_pmu_id, int *slave_pmu_id)
{
	int ret = 0;
	ret = script_parser_fetch("power_sply", "pmu_id", main_pmu_id, 1);
	if(ret)
	{
		printf("not set main pmu id\n");
		return -1;
	}

	ret = script_parser_fetch("slave_power_sply", "pmu_id", slave_pmu_id, 1);
	if(ret)
	{
		printf("not set slave pmu id\n");
		return -2;
	}
	return 0;
}

static int axp_probe_type(int main_pmu_id, int slave_pmu_id)
{
		int ret = 0;
		printf("use pmu by pmu_id from sys_config.fex\n");
		switch(main_pmu_id)
		{
			case PMU_TYPE_22X:
#if defined(CONFIG_SUNXI_AXP22)
				if(axp22_probe())
				{
					printf("probe axp22x failed\n");
				}
				else
				{
					/* pmu type AXP22X */
					tick_printf("PMU: AXP22x found\n");
					ret ++;
				}
				sunxi_axp_dev[0] = &sunxi_axp_22;
				sunxi_axp_dev[PMU_TYPE_22X] = &sunxi_axp_22;
#endif
				break;
			case PMU_TYPE_20X:
#if defined(CONFIG_SUNXI_AXP20)
				if(axp20_probe())
				{
					printf("probe axp20x failed\n");
				}
				else
				{
					/* pmu type AXP22X */
					tick_printf("PMU: AXP20x found\n");
					ret ++;
				}
				sunxi_axp_dev[0] = &sunxi_axp_20;
				sunxi_axp_dev[PMU_TYPE_20X] = &sunxi_axp_20;
#endif
				break;
			case PMU_TYPE_15X:
#if defined(CONFIG_SUNXI_AXP15)
				if(axp15_probe())
				{
					printf("probe axp15 failed\n");
				}
				else
				{
					/* pmu type AXP15X */
					tick_printf("PMU: AXP15x found\n");
					ret ++;
				}
				sunxi_axp_dev[0] = &sunxi_axp_15;
				sunxi_axp_dev[PMU_TYPE_15X] = &sunxi_axp_15;
#endif
				break;
			case PMU_TYPE_809:
#if defined(CONFIG_SUNXI_AXP809)
				if(axp809_probe())
				{
					printf("probe axp809 failed\n");
				}
				else
				{
					/* pmu type AXP809 */
					tick_printf("PMU: AXP809 found\n");
					ret ++;
				}
				sunxi_axp_dev[0] = &sunxi_axp_809;
				sunxi_axp_dev[PMU_TYPE_809] = &sunxi_axp_809;
#endif
				break;
			case PMU_TYPE_806:
#if defined(CONFIG_SUNXI_AXP806)
				if(axp806_probe())
				{
					printf("probe axp806 failed\n");
				}
				else
				{
					/* pmu type AXP806 */
					tick_printf("PMU: AXP806 found\n");
					ret ++;
				}
				sunxi_axp_dev[0] = &sunxi_axp_806;
				sunxi_axp_dev[PMU_TYPE_806] = &sunxi_axp_806;
#endif
				break;
			 case PMU_TYPE_808:
#if defined(CONFIG_SUNXI_AXP808)
				if(axp808_probe())
				{
					printf("probe axp808 failed\n");
				}
				else
				{
					/* pmu type AXP808 */
					tick_printf("PMU: AXP808 found\n");
					ret ++;
				}
				sunxi_axp_dev[0] = &sunxi_axp_808;
				sunxi_axp_dev[PMU_TYPE_808] = &sunxi_axp_808;
#endif
				break;
			case PMU_TYPE_81X:
#if defined(CONFIG_SUNXI_AXP81X)
				if(axp81_probe())
				{
					printf("probe axp81x failed\n");
				}
				else
				{
					/* pmu type AXP81x */
					tick_printf("PMU: AXP81x found\n");
					ret ++;
				}
				sunxi_axp_dev[0] = &sunxi_axp_81;
				sunxi_axp_dev[PMU_TYPE_81X] = &sunxi_axp_81;
#endif
				break;
			default:
				tick_printf("main pmu id is valid\n");
				break;
		}
		switch(slave_pmu_id)
		{
			case PMU_TYPE_22X:
#if defined(CONFIG_SUNXI_AXP22)
				if(axp22_probe())
				{
					printf("probe axp22x failed\n");
				}
				else
				{
					/* pmu type AXP22X */
					tick_printf("PMU: AXP22x found\n");
					ret ++;
				}
				sunxi_axp_dev[PMU_TYPE_22X] = &sunxi_axp_22;
#endif
				break;
			case PMU_TYPE_20X:
#if defined(CONFIG_SUNXI_AXP20)
				if(axp20_probe())
				{
					printf("probe axp20x failed\n");
				}
				else
				{
					/* pmu type AXP22X */
					tick_printf("PMU: AXP20x found\n");
					ret ++;
				}
				sunxi_axp_dev[PMU_TYPE_20X] = &sunxi_axp_20;
#endif
				break;
			case PMU_TYPE_15X:
#if defined(CONFIG_SUNXI_AXP15)
				if(axp15_probe())
				{
					printf("probe axp15 failed\n");
				}
				else
				{
					/* pmu type AXP15X */
					tick_printf("PMU: AXP15x found\n");
					ret ++;
				}
				sunxi_axp_dev[PMU_TYPE_15X] = &sunxi_axp_15;
#endif
				break;
			case PMU_TYPE_809:
#if defined(CONFIG_SUNXI_AXP809)
				if(axp809_probe())
				{
					printf("probe axp809 failed\n");
				}
				else
				{
					/* pmu type AXP809 */
					tick_printf("PMU: AXP809 found\n");
					ret ++;
				}
				sunxi_axp_dev[PMU_TYPE_809] = &sunxi_axp_809;
#endif
				break;
			case PMU_TYPE_806:
#if defined(CONFIG_SUNXI_AXP806)
				if(axp806_probe())
				{
					printf("probe axp806 failed\n");
				}
				else
				{
					/* pmu type AXP806 */
					tick_printf("PMU: AXP806 found\n");
					ret ++;
				}
				sunxi_axp_dev[PMU_TYPE_806] = &sunxi_axp_806;
#endif
				break;
			 case PMU_TYPE_808:
#if defined(CONFIG_SUNXI_AXP808)
				if(axp808_probe())
				{
					printf("probe axp808 failed\n");
				}
				else
				{
					/* pmu type AXP808 */
					tick_printf("PMU: AXP808 found\n");
					ret ++;
				}
				sunxi_axp_dev[PMU_TYPE_808] = &sunxi_axp_808;
#endif
				break;
			case PMU_TYPE_81X:
#if defined(CONFIG_SUNXI_AXP81X)
				if(axp81_probe())
				{
					printf("probe axp81x failed\n");
				}
				else
				{
					/* pmu type AXP81x */
					tick_printf("PMU: AXP81x found\n");
					ret ++;
				}
				sunxi_axp_dev[PMU_TYPE_81X] = &sunxi_axp_81;
#endif
				break;
			case POWER_TYPE_OZ:
#if defined(CONFIG_SUNXI_POWEROZ)
				if(power_oz_probe())
				{
					printf("probe oz failed\n");
				}
				else
				{
					/* pmu type poewr oz */
					tick_printf("power: oz found\n");
					ret ++;
				}
#endif
				break;
			case POWER_TYPE_RICH:
#if defined(CONFIG_SUNXI_POWEROZ)
				if(power_rich_probe())
				{
					printf("probe rich failed\n");
				}
				else
				{
					/* pmu type poewr oz */
					tick_printf("power: rich found\n");
					ret ++;
				}
#endif
				break;
			default:
				tick_printf("slave pmu id is valid\n");
				break;
		}
		return ret;
}

/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_probe(void)
{
	int ret = 0;
	int pmu_main_id = (int)-1;
	int pmu_slave_id = (int)-1;
	memset(sunxi_axp_dev, 0, SUNXI_AXP_DEV_MAX * 4);
	if(axp_fetch_pmu_id(&pmu_main_id, &pmu_slave_id) != (-1)) //must has one pmu
	{
		gd->power_main_id = pmu_main_id;
		gd->power_slave_id = pmu_slave_id;
		if(axp_probe_type(pmu_main_id, pmu_slave_id) > 0)
		{
			ret++;
		}
	}
	else
	{
#if defined(CONFIG_SUNXI_AXP22)
	if(axp22_probe())
	{
		printf("probe axp22x failed\n");
	}
	else
	{
		/* pmu type AXP22X */
		tick_printf("PMU: AXP22x found\n");
		ret ++;
		gd->power_main_id = PMU_TYPE_22X;
	}
	sunxi_axp_dev[PMU_TYPE_22X] = &sunxi_axp_22;
#if (CONFIG_SUNXI_AXP_MAIN == PMU_TYPE_22X)
	sunxi_axp_dev[0] = &sunxi_axp_22;
#endif
#endif

#if defined(CONFIG_SUNXI_AXP20)
	if(axp20_probe())
	{
		printf("probe axp20x failed\n");
	}
	else
	{
		/* pmu type AXP22X */
		tick_printf("PMU: AXP20x found\n");
		ret ++;
		gd->power_main_id = PMU_TYPE_20X;
	}
	sunxi_axp_dev[PMU_TYPE_20X] = &sunxi_axp_20;
#if (CONFIG_SUNXI_AXP_MAIN == PMU_TYPE_20X)
	sunxi_axp_dev[0] = &sunxi_axp_20;
#endif
#endif

#if defined(CONFIG_SUNXI_AXP15)
	if(axp15_probe())
	{
		printf("probe axp15 failed\n");
	}
	else
	{
		/* pmu type AXP15X */
		tick_printf("PMU: AXP15x found\n");
		ret ++;
		gd->power_main_id = PMU_TYPE_15X;
	}
	sunxi_axp_dev[PMU_TYPE_15X] = &sunxi_axp_15;
#if (CONFIG_SUNXI_AXP_MAIN == PMU_TYPE_15X)
	sunxi_axp_dev[0] = &sunxi_axp_15;
#endif
#endif

#if defined(CONFIG_SUNXI_AXP809)
	if(axp809_probe())
	{
		printf("probe axp809 failed\n");
	}
	else
	{
		/* pmu type AXP809 */
		tick_printf("PMU: AXP809 found\n");
		ret ++;
		gd->power_main_id = PMU_TYPE_809;
	}
	sunxi_axp_dev[PMU_TYPE_809] = &sunxi_axp_809;
#if (CONFIG_SUNXI_AXP_MAIN == PMU_TYPE_809)
	sunxi_axp_dev[0] = &sunxi_axp_809;
#endif
#endif

#if defined(CONFIG_SUNXI_AXP806)
	if(axp806_probe())
	{
		printf("probe axp806 failed\n");
	}
	else
	{
		/* pmu type AXP806 */
		tick_printf("PMU: AXP806 found\n");
		ret ++;
		gd->power_main_id = PMU_TYPE_806;
	}
	sunxi_axp_dev[PMU_TYPE_806] = &sunxi_axp_806;
#if (CONFIG_SUNXI_AXP_MAIN == PMU_TYPE_806)
	sunxi_axp_dev[0] = &sunxi_axp_806;
#endif
#endif

#if defined(CONFIG_SUNXI_AXP81X)
    if(axp81_probe())
    {
        printf("probe axp81X failed\n");
    }
    else
    {
        /* pmu type AXP81X */
        tick_printf("PMU: AXP81X found\n");
        ret ++;
		gd->power_main_id = PMU_TYPE_81X;
    }
    sunxi_axp_dev[PMU_TYPE_81X] = &sunxi_axp_81;
#if (CONFIG_SUNXI_AXP_MAIN == PMU_TYPE_81X)
        sunxi_axp_dev[0] = &sunxi_axp_81;
#endif
#endif
	}
	if(!ret)
	{
		sunxi_axp_dev[0] = &sunxi_axp_null;
	}

	return ret;
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
int axp_reinit(void)
{
	int i;

	for(i=0;i<SUNXI_AXP_DEV_MAX;i++)
	{
		if((sunxi_axp_dev[i] != NULL) && (sunxi_axp_dev[i] != (void *)(-1)))
		{
			sunxi_axp_dev[i] = (sunxi_axp_dev_t *)((uint)sunxi_axp_dev[i] + gd->reloc_off);
		}
	}

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_get_power_vol_level(void)
{
	return gd->power_step_level;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_probe_startup_cause(void)
{
	int ret = -1;
	int buffer_value;
	int status;
	int poweron_reason, next_action = 0;

	buffer_value = sunxi_axp_dev[0]->probe_pre_sys_mode();
	debug("axp buffer %x\n", buffer_value);
	if(buffer_value < 0)
	{
		return -1;
	}
    if(buffer_value == PMU_PRE_SYS_MODE)//????????????????????????????????????????????
    {
    	tick_printf("pre sys mode\n");
    	return -1;
    }
    else if(buffer_value == PMU_PRE_BOOT_MODE)//??????????????boot standby??????????????????????boot standby
	{
		tick_printf("pre boot mode\n");
		status = sunxi_axp_dev[0]->probe_power_status();
    	if(status == AXP_VBUS_EXIST)	//only vbus exist
    	{
    		return AXP_VBUS_EXIST;
    	}
    	else if(status == AXP_DCIN_EXIST)	//dc exist(dont care wether vbus exist)
    	{
    		return AXP_DCIN_EXIST;
    	}
		return AXP_VBUS_DCIN_NOT_EXIST;  // return if dont have external power supply
	}
	else if(buffer_value == PMU_PRE_FASTBOOT_MODE)
	{
		tick_printf("pre fastboot mode\n");
		return -1;
	}
	//???? ??????????????????????????????????????
	poweron_reason = sunxi_axp_dev[0]->probe_this_poweron_cause();
	if(poweron_reason == AXP_POWER_ON_BY_POWER_KEY)
	{
		tick_printf("key trigger\n");
		next_action = PMU_PRE_SYS_MODE;
		ret = 0;
	}
	else if(poweron_reason == AXP_POWER_ON_BY_POWER_TRIGGER)
	{
		tick_printf("power trigger\n");
		next_action = PMU_PRE_SYS_MODE;
    	ret = 1;
	}
	//????????????????????
	sunxi_axp_dev[0]->set_next_sys_mode(next_action);

    return ret;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????axp_probe_startup_check_factory_mode
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??????????????????????????????????????????????????USB??????????????????????????????????????????????
*
*
************************************************************************************************************
*/
int axp_probe_factory_mode(void)
{
	int buffer_value, status;
	int poweron_reason;

	buffer_value = sunxi_axp_dev[0]->probe_pre_sys_mode();

	if(buffer_value == PMU_PRE_FACTORY_MODE)	//factory mode: need the power key and dc or vbus
	{
		printf("factory mode detect\n");
		status = sunxi_axp_dev[0]->probe_power_status();
		if(status > 0)  //has the dc or vbus
		{
			//???? ??????????????????????????????????????
			poweron_reason = sunxi_axp_dev[0]->probe_this_poweron_cause();
			if(poweron_reason == AXP_POWER_ON_BY_POWER_KEY)
			{
				//set the system next powerom status as 0x0e(the system mode)
				printf("factory mode release\n");
				sunxi_axp_dev[0]->set_next_sys_mode(PMU_PRE_SYS_MODE);
			}
			else
			{
				printf("factory mode: try to poweroff without power key\n");
				axp_set_hardware_poweron_vol();  //poweroff
				axp_set_power_off();
				for(;;);
			}
		}
		else
		{
			printf("factory mode: try to poweroff without power in\n");
			axp_set_hardware_poweroff_vol();  //poweroff
			axp_set_power_off();
			for(;;);
		}
	}

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_hardware_poweron_vol(void) //??????????????PMU??????????????2.9V
{
	int vol_value = 0;

	if(script_parser_fetch("pmu_para", "pmu_pwron_vol", &vol_value, 1))
	{
		puts("set power on vol to default\n");
	}

	return sunxi_axp_dev[0]->set_power_onoff_vol(vol_value, 1);
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_hardware_poweroff_vol(void) //??????????????PMU??????????????????3.3V
{
	int vol_value = 0;

	if(script_parser_fetch("pmu_para", "pmu_pwroff_vol", &vol_value, 1))
	{
		puts("set power off vol to default\n");
	}

	return sunxi_axp_dev[0]->set_power_onoff_vol(vol_value, 0);
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_set_power_off(void)
{
	return sunxi_axp_dev[0]->set_power_off();
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_next_poweron_status(int value)
{
	return sunxi_axp_dev[0]->set_next_sys_mode(value);
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_probe_pre_sys_mode(void)
{
	return sunxi_axp_dev[0]->probe_pre_sys_mode();
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_power_get_dcin_battery_exist(int *dcin_exist, int *battery_exist)
{
	*dcin_exist    = sunxi_axp_dev[0]->probe_power_status();
	*battery_exist = sunxi_axp_dev[0]->probe_battery_exist();

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????						axp_probe_power_source
*
*    ??????????void
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_probe_power_source(void)
{
	int status = 0;
	status = sunxi_axp_dev[0]->probe_power_status();
	if(status == AXP_VBUS_EXIST)
		return 1;
	else if(status == AXP_DCIN_EXIST)
		return 2;
	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_probe_battery_vol(void)
{
	return sunxi_axp_dev[0]->probe_battery_vol();
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_probe_rest_battery_capacity(void)
{
	return sunxi_axp_dev[0]->probe_battery_ratio();
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_probe_key(void)
{
	return sunxi_axp_dev[0]->probe_key();
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_probe_charge_current(void)
{
	return sunxi_axp_dev[0]->probe_charge_current();
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_set_charge_current(int current)
{
	return sunxi_axp_dev[0]->set_charge_current(current);
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int  axp_set_charge_control(void)
{
	return sunxi_axp_dev[0]->set_charge_control();
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_vbus_limit_dc(void)
{
	sunxi_axp_dev[0]->set_vbus_vol_limit(gd->limit_vol);
	sunxi_axp_dev[0]->set_vbus_cur_limit(gd->limit_cur);

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_vbus_limit_pc(void)
{
	sunxi_axp_dev[0]->set_vbus_vol_limit(gd->limit_pcvol);
	sunxi_axp_dev[0]->set_vbus_cur_limit(gd->limit_pccur);

	return 0;
}

/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_all_limit(void)
{
	int usbvol_limit = 0;
	int usbcur_limit = 0;

	script_parser_fetch(PMU_SCRIPT_NAME, "pmu_usbvol_limit", &usbvol_limit, 1);
	script_parser_fetch(PMU_SCRIPT_NAME, "pmu_usbcur_limit", &usbcur_limit, 1);
	script_parser_fetch(PMU_SCRIPT_NAME, "pmu_usbvol", (int *)&gd->limit_vol, 1);
	script_parser_fetch(PMU_SCRIPT_NAME, "pmu_usbcur", (int *)&gd->limit_cur, 1);
	script_parser_fetch(PMU_SCRIPT_NAME, "pmu_usbvol_pc", (int *)&gd->limit_pcvol, 1);
	script_parser_fetch(PMU_SCRIPT_NAME, "pmu_usbcur_pc", (int *)&gd->limit_pccur, 1);
#ifdef DEBUG
	printf("usbvol_limit = %d, limit_vol = %d\n", usbvol_limit, gd->limit_vol);
	printf("usbcur_limit = %d, limit_cur = %d\n", usbcur_limit, gd->limit_cur);
#endif
	if(!usbvol_limit)
	{
		gd->limit_vol = 0;

	}
	if(!usbcur_limit)
	{
		gd->limit_cur = 0;
	}

	axp_set_vbus_limit_pc();

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_suspend_chgcur(void)
{
	return sunxi_axp_dev[0]->set_charge_current(gd->pmu_suspend_chgcur);
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_runtime_chgcur(void)
{
	return sunxi_axp_dev[0]->set_charge_current(gd->pmu_runtime_chgcur);
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_charge_vol_limit(void)
{
	int ret1;
	int ret2;

	ret1 = script_parser_fetch(PMU_SCRIPT_NAME, "pmu_runtime_chgcur", (int *)&gd->pmu_runtime_chgcur, 1);
	ret2 = script_parser_fetch(PMU_SCRIPT_NAME, "pmu_suspend_chgcur", (int *)&gd->pmu_suspend_chgcur, 1);

	if(ret1)
	{
		gd->pmu_runtime_chgcur = 600;
	}
	if(ret2)
	{
		gd->pmu_suspend_chgcur = 1500;
	}
#if DEBUG
	printf("pmu_runtime_chgcur=%d\n", gd->pmu_runtime_chgcur);
	printf("pmu_suspend_chgcur=%d\n", gd->pmu_suspend_chgcur);
#endif
	axp_set_suspend_chgcur();

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_set_power_supply_output(void)
{
	int  ret, onoff;
	uint power_supply_hd;
	char power_name[16];
	int  power_vol, power_index = 0;
	int  power_vol_d;

if (gd->power_main_id == PMU_TYPE_20X)
{
#if defined(CONFIG_SUNXI_SUN7I)
    power_supply_hd = script_parser_fetch_subkey_start("target");
#else
    power_supply_hd = script_parser_fetch_subkey_start("power_sply");
#endif
}
else if (gd->power_main_id == PMU_TYPE_15X)
{
    power_supply_hd = script_parser_fetch_subkey_start("axp15_para");
}
else if (gd->power_main_id == PMU_TYPE_81X)
{
#if (defined(CONFIG_ARCH_SUN8IW6) && defined(CONFIG_ARCH_HOMELET))
	int  chipid;
	//0x18:axp_818, 0x13:axp_813 0x03:axp_803 0x0: key not burn
	chipid = plat_get_chip_id();
	if(chipid == 0x03)
	{
		power_supply_hd = script_parser_fetch_subkey_start("power_sply_ext");
	}
	else
	{
		power_supply_hd = script_parser_fetch_subkey_start("power_sply");
	
	}
#endif
}
else
{
	power_supply_hd = script_parser_fetch_subkey_start("power_sply");
}
    if(!power_supply_hd)
    {
        printf("unable to set power supply\n");

		return -1;
	}
	do
	{
		memset(power_name, 0, 16);
		ret = script_parser_fetch_subkey_next(power_supply_hd, power_name, &power_vol, &power_index);
		if(ret < 0)
		{
			printf("find power_sply to end\n");

            return 0;
        }

        onoff = -1;
        power_vol_d = 0;
#if defined(CONFIG_SUNXI_AXP_CONFIG_ONOFF)
        if(power_vol > 10000)
        {
            onoff = 1;
            power_vol_d = power_vol%10000;
        }
        else if(power_vol >= 0)
        {
        	onoff = 0;
        	power_vol_d = power_vol;
        }
#else
        if(power_vol > 0 )
        {
            onoff = 1;
            power_vol_d = power_vol;
        }
        else if(power_vol == 0)
        {
        	onoff = 0;
        }
#endif
#if defined(CONFIG_SUNXI_AXP_CONFIG_ONOFF)
		printf("%s = %d, onoff=%d\n", power_name, power_vol_d, onoff);
#else
        printf("%s = %d\n", power_name, power_vol_d);
#endif
        if(sunxi_axp_dev[0]->set_supply_status_byname(power_name, power_vol_d, onoff))
        {
            printf("axp set %s to %d failed\n", power_name, power_vol_d);
        }
    }
    while(1);

    return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_slave_set_power_supply_output(void)
{
	int  ret, onoff;
	uint slave_power_sply;
	char power_name[16];
	int  power_vol, power_index = 0;
	int  index = -1;
	int  i;
	int  power_vol_d;

    slave_power_sply = script_parser_fetch_subkey_start("slave_power_sply");
    if(!slave_power_sply)
    {
        printf("unable to set slave power supply\n");

		return -1;
	}

    for(i=1;i<SUNXI_AXP_DEV_MAX;i++)
    {
        if(sunxi_axp_dev[i] != NULL)
        {
            if(strcmp(sunxi_axp_dev[0]->pmu_name, sunxi_axp_dev[i]->pmu_name))
            {
                index = i;

                break;
            }
        }
    }
    if(index == -1)
    {
        printf("unable to find slave pmu\n");

        return -1;
    }
    printf("slave power\n");
	do
	{
		memset(power_name, 0, 16);
		ret = script_parser_fetch_subkey_next(slave_power_sply, power_name, &power_vol, &power_index);
		if(ret < 0)
		{
			printf("find slave power sply to end\n");

            return 0;
        }

        onoff = -1;
        power_vol_d = 0;
        if(power_vol > 10000)
        {
            onoff = 1;
            power_vol_d = power_vol%10000;
        }
#if defined(CONFIG_SUNXI_AXP_CONFIG_ONOFF)
        else if(power_vol > 0)
        {
        	onoff = 0;
        	power_vol_d = power_vol;
        }
#endif
        else if(power_vol == 0)
        {
        	onoff = 0;
        }
#if defined(CONFIG_SUNXI_AXP_CONFIG_ONOFF)
		printf("%s = %d, onoff=%d\n", power_name, power_vol_d, onoff);
#else
        printf("%s = %d\n", power_name, power_vol_d);
#endif
        if(sunxi_axp_dev[index]->set_supply_status_byname(power_name, power_vol_d, onoff))
        {
            printf("axp set %s to %d failed\n", power_name, power_vol_d);
        }
    }
    while(1);

    return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_probe_power_supply_condition(void)
{
	int   dcin_exist, bat_vol;
	int   ratio;
	int   safe_vol, ret;

	//??????????????????????
	dcin_exist = sunxi_axp_dev[0]->probe_power_status();

#ifdef DEBUG
    printf("dcin_exist = %x\n", dcin_exist);
#endif
	bat_vol = sunxi_axp_dev[0]->probe_battery_vol();
	ret = script_parser_fetch(PMU_SCRIPT_NAME, "pmu_safe_vol", &safe_vol, 1);
	if((ret) || (safe_vol < 3000))
	{
		safe_vol = 3500;
	}
	ratio = sunxi_axp_dev[0]->probe_battery_ratio();
	if(ratio < 1)
	{
		sunxi_axp_dev[0]->set_coulombmeter_onoff(0);
		sunxi_axp_dev[0]->set_coulombmeter_onoff(1);
	}
	printf("bat_vol=%d, ratio=%d\n", bat_vol, ratio);
	if(ratio < 1)   //????????????
	{
		if(dcin_exist)
		{
			//??????????????????????????
			if(bat_vol < safe_vol)		//??????????????????????????????
			{
				gd->power_step_level = BATTERY_RATIO_TOO_LOW_WITH_DCIN_VOL_TOO_LOW;
			}
			else	//????????????????????????????????????????????????????????????
			{
				gd->power_step_level = BATTERY_RATIO_TOO_LOW_WITH_DCIN;
			}
		}
		else
		{
			//????????????????????????????
			gd->power_step_level = BATTERY_RATIO_TOO_LOW_WITHOUT_DCIN;
		}
	}
	else
	{
		gd->power_step_level = BATTERY_RATIO_ENOUGH;
	}

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
static __u8 power_int_value[8];

int axp_int_enable(__u8 *value)
{
	sunxi_axp_dev[0]->probe_int_enable(power_int_value);
	sunxi_axp_dev[0]->set_int_enable(value);
	//??????cpu??????????
	//*(volatile unsigned int *)(0x01f00c00 + 0x10) |= 1;
	//*(volatile unsigned int *)(0x01f00c00 + 0x40) |= 1;

	return 0;
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_int_disable(void)
{
	//*(volatile unsigned int *)(0x01f00c00 + 0x10) |= 1;
	//*(volatile unsigned int *)(0x01f00c00 + 0x40) &= ~1;
	return sunxi_axp_dev[0]->set_int_enable(power_int_value);
}
/*
************************************************************************************************************
*
*                                             function
*
*    ??????????
*
*    ??????????
*
*    ??????  ??
*
*    ????    ??
*
*
************************************************************************************************************
*/
int axp_int_query(__u8 *addr)
{
	int ret;

	ret = sunxi_axp_dev[0]->probe_int_pending(addr);
	//*(volatile unsigned int *)(0x01f00c00 + 0x10) |= 1;

	return ret;
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :  ????pmu_type = 0, ??????????PMU
*                     ??????????????????????????????pmu
*                     ??????????????????????????
*
************************************************************************************************************
*/
int axp_set_supply_status(int pmu_type, int vol_name, int vol_value, int onoff)
{
	//??????????????????
	return sunxi_axp_dev[pmu_type]->set_supply_status(vol_name, vol_value, onoff);
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
int axp_set_supply_status_byname(char *pmu_type, char *vol_type, int vol_value, int onoff)
{
	//??????????????????
	int   i;

	for(i=1;i<SUNXI_AXP_DEV_MAX;i++)
	{
		if(sunxi_axp_dev[i] != NULL)
		{
			if(!strcmp(sunxi_axp_dev[i]->pmu_name, pmu_type))
			{
				return sunxi_axp_dev[i]->set_supply_status_byname(vol_type, vol_value, onoff);
			}
		}
	}

	return -1;
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
int axp_probe_supply_status(int pmu_type, int vol_name, int vol_value)
{
	//??????????????????
	return sunxi_axp_dev[pmu_type]->probe_supply_status(vol_name, 0, 0);
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
int axp_probe_supply_status_byname(char *pmu_type, char *vol_type)
{
	//??????????????????
	int   i;

	for(i=1;i<SUNXI_AXP_DEV_MAX;i++)
	{
		if(sunxi_axp_dev[i] != NULL)
		{
			if(!strcmp(sunxi_axp_dev[i]->pmu_name, pmu_type))
			{
				return sunxi_axp_dev[i]->probe_supply_status_byname(vol_type);
			}
		}
	}

	return -1;
}

//example string  :    "axp81x_dcdc6 vdd-sys vdd-usb0-09 vdd-hdmi-09"
static int find_regulator_str(const char* src, const char* des)
{
    int i,len_src, len_des ;
    int token_index;
    len_src = strlen(src);
    len_des = strlen(des);

    if(len_des > len_src) return 0;

    token_index = 0;
    for(i =0 ; i < len_src+1; i++)
    {
        if(src[i]==' ' || src[i] == '\t' || src[i] == '\0')
        {
            if(i-token_index == len_des)
            {
                if(memcmp(src+token_index,des,len_des) == 0)
                {
                    return 1;
                }
            }
            token_index = i+1;
        }
    }
    return 0;
}

int axp_set_supply_status_byregulator(const char* id, int onoff)
{
    char main_key[32];
    char pmu_type[32];
    char vol_type[32];
    char sub_key_name[32];
    char sub_key_value[256];
    int main_hd = 0;
    unsigned int i = 0, j = 0, index = 0;
    int ldo_count = 0;
    int find_flag = 0;
    int ret = 0;

#if (defined(CONFIG_ARCH_SUN8IW6) && defined(CONFIG_ARCH_HOMELET))
    static int chipid = -2; //use static variable for read once

    if(chipid == -2)
    {
        //just read once
    	chipid = plat_get_chip_id();
    }

    //0x18:axp_818, 0x13:axp_813 0x03:axp_803 0x0: key not burn
    if(chipid == -1)  //default, platform not implement function plat_get_chip_id
    {
    	printf("axp chipid not care,use default regulator tree\n");
    	i = 1;
    }
    else if(chipid == 0x03)
    {
    	printf("use extend  regulator tree\n");
    	i = 2;
    }
    else
    {
    	printf("use default regulator tree\n");
    	i = 1;
    }

   for(i = 1; i <= 1; i++)
   {
#else
   for(i = 1; i <= 2; i++)
   {
#endif
        sprintf(main_key,"pmu%d_regu", i);

        main_hd = script_parser_fetch(main_key,"regulator_count",&ldo_count, 1);
        if(main_hd != 0)
        {
            //printf("unable to get ldo_count  from [%s] \n",main_key);
    		break;
    	}
        for(index = 1; index <= ldo_count; index++)
        {
            sprintf(sub_key_name, "regulator%d", index);
            main_hd = script_parser_fetch(main_key,sub_key_name,(int*)(sub_key_value), sizeof(sub_key_value)/sizeof(int));
            if(main_hd != 0)
            {
                //printf("unable to get subkey %s from [%s]\n",sub_key_name, main_key);
        		break;
        	}
            if(find_regulator_str(sub_key_value, id))
            {
                find_flag = 1;
                break;
            }

        }
        if(find_flag)
            break;
    }

    if(!find_flag)
    {
        printf("unable to find regulator %s from [pmu1_regu] or [pmu2_regu] \n",id);
        return -1;
    }

    //example :    ldo6      = "axp81x_dcdc6 vdd-sys vdd-usb0-09 vdd-hdmi-09"
    memset(pmu_type, 0, sizeof(pmu_type));
    memset(vol_type, 0, sizeof(vol_type));
    //get pmu type
    for(j = 0,i =0; i < strlen(sub_key_value); i++)
    {
        if(sub_key_value[i] == '_')
        {
            i++;
            break;
        }
        pmu_type[j++] = sub_key_value[i];
    }
    //get vol type
    j = 0;
    for(; i < strlen(sub_key_value); i++)
    {
        if(sub_key_value[i] == ' ')
        {
            break;
        }
        vol_type[j++]= sub_key_value[i];
    }

    //para vol = 0  indcate not set vol,only open or close  voltage switch
    ret = axp_set_supply_status_byname(pmu_type,vol_type,0, onoff);
    if(ret != 0)
    {
         printf("error: supply regelator %s=id, pmu_type=%s_%s onoff=%d fail\n", id,pmu_type,vol_type,onoff );
    }
    return ret;
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
static int current_pmu = -1;
int axp_probe_supply_pmu_name(char *axpname)
{
	int i = 0;
	if(axpname == NULL)
	{
		return -1;
	}
	for(i=1;i<SUNXI_AXP_DEV_MAX;i++)
	{
		if((sunxi_axp_dev[i] != NULL) && (current_pmu < i))
		{
			current_pmu = i;
			strcpy(axpname, sunxi_axp_dev[i]->pmu_name);
			return 0;
		}
	}
	return -1;

}

int axp_probe_vbus_cur_limit(void)
{
    return sunxi_axp_dev[0]->probe_vbus_cur_limit();
}


