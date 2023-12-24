#ifndef __CHELPER_STM_H__
#define __CHELPER_STM_H__

#include <cHelper_GEN.h>

    typedef struct {
        GPIO_TypeDef* port;
        uint32_t pin;
    }   GPIO_HandleTypeDef;

    typedef struct {
        SPI_HandleTypeDef* spi;
        GPIO_HandleTypeDef* cs;
        GPIO_HandleTypeDef* rs;
    }   SpiConf;

    void HAL_GPIO_HiPin(GPIO_HandleTypeDef* gpio);
    void HAL_GPIO_LoPin(GPIO_HandleTypeDef* gpio);
    void HAL_GPIO_ToggPin(GPIO_HandleTypeDef* gpio);
    void HAL_GPIO_TrigPin(GPIO_HandleTypeDef* gpio, uint32_t milliseconds);

#endif
