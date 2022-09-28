#include "mu_test.h"
#include <fstream>
#include "sensors_manager.hpp"

BEGIN_TEST(sensor_manager)

    std::ifstream configFile("../../configFile/sensor_config.txt");
    home::SensorsManager sensorManager(configFile);
 
   char c =  '+';
   while(std::cin >> c)
   {
       switch (c)
       {
           case 'q': 
                sensorManager.stop();
                goto exit_loop;
                break;       
       }
   }
    exit_loop:
	ASSERT_PASS();

END_TEST


BEGIN_SUITE(sensor_manager)

    TEST(sensor_manager)

END_SUITE
