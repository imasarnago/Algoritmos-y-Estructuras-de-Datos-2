#ifndef WEATHER_UTILS
#define WEATHER_UTILS

#include "array_helpers.h"



/*Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad de Córdoba
según los datos del arreglo*/

int temp_minima_hist (WeatherTable array);

/*Un “procedimiento” que registre para cada año entre 1980 y 2016 la mayor temperatura máxima
registrada durante ese año. El procedimiento debe tomar como parámetro un arreglo que almacenará los resultados obtenidos*/

void may_temp_año (WeatherTable a, int output[YEARS]);

/*Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en
que se registró la mayor cantidad mensual de precipitaciones.*/

void mes_mas_precip (WeatherTable a, int arr_prec [YEARS]);

#endif