#include "weather_utils.h"

#include "limits.h"
#include "array_helpers.h"



int temp_minima_hist(WeatherTable a) {
  int all_time_lowest_temp = INT_MAX;

  for (unsigned int year = 0u; year < YEARS; year++) {
    for (month_t month = january; month <= december; month++) {
      for (unsigned int day = 0u; day < DAYS; day++) {
        if (a[year][month][day]._min_temp < all_time_lowest_temp) {
          all_time_lowest_temp = a[year][month][day]._min_temp;
        }
      }
    }
  };

  return all_time_lowest_temp;
}








void may_temp_año(WeatherTable a, int output[YEARS]) {
  int yearly_highest_temp = INT_MIN;

  for (unsigned int year = 0u; year < YEARS; year++) {
    for (month_t month = january; month <= december; month++) {
      for (unsigned int day = 0u; day < DAYS; day++) {
        if (a[year][month][day]._max_temp > yearly_highest_temp) {
          yearly_highest_temp = a[year][month][day]._max_temp;
        };
      }
    }
    output[year] = yearly_highest_temp;
  }
}








void mes_mas_precip(WeatherTable a, int output[YEARS]) {

  for (unsigned int year = 0u; year < YEARS; year++) {

    month_t mes_que_me_interesa = january;
    unsigned int mayor_precip_SF = 0u;
        for (month_t month = january; month <= december; month++) {


        unsigned int sum_precip = 0u;
            for (unsigned int day = 0u; day < DAYS; day++) {

                sum_precip = sum_precip + a[year][month][day]._rainfall;
            }
            if (sum_precip >= mayor_precip_SF) {
                mayor_precip_SF = sum_precip;
                mes_que_me_interesa = month + 1;
            }
        }
    output[year] = mes_que_me_interesa;

  }
}
