#include "Copter.h"
#include "AP_HAL/AnalogIn.h"
#include "DataFlash/DataFlash.h"
#include "GCS_MAVLink/GCS.h"

AP_HAL::AnalogSource *adc_source;

const uint8_t pin=14;

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up

    adc_source = hal.analogin->channel(pin);

}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
    float value = adc_source->voltage_latest();
    DataFlash_Class::instance()->Log_Write("ADC",
                                       "TimeUS,Value",  
                                       "Qf",
                                        AP_HAL::micros64(),
                                       (double)value);
    gcs().send_text(MAV_SEVERITY_INFO, "adc value: %5.3f", (double)value);
}
#endif

#ifdef USERHOOK_AUXSWITCH
void Copter::userhook_auxSwitch1(uint8_t ch_flag)
{
    // put your aux switch #1 handler here (CHx_OPT = 47)
}

void Copter::userhook_auxSwitch2(uint8_t ch_flag)
{
    // put your aux switch #2 handler here (CHx_OPT = 48)
}

void Copter::userhook_auxSwitch3(uint8_t ch_flag)
{
    // put your aux switch #3 handler here (CHx_OPT = 49)
}
#endif
