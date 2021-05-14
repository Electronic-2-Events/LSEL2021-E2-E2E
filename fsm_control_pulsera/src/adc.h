#ifndef ADC_H
#define ADC_H

#include <stdint.h>

  void saadc_init(void);
  void saadc_sampling_event_enable(void);
  void saadc_sampling_event_init(void);

  uint16_t ldrvalue;

#endif
