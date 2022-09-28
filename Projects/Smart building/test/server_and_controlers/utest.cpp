#include "mu_test.h"
#include <iostream>
#include <unistd.h>
#include "log.hpp"
#include "server_manager.hpp"

BEGIN_TEST(server_and_controlers)

    std::ofstream logPath("../../log/log.txt", std::ios::app);
    std::ifstream configFile("../../configFile/controler_config.txt");
    home::ServerManager server("0.0.0.0", 5555, logPath, configFile);

    char c = '+';
    while (std::cin >> c)
    {
        switch (c)
        { 
            case 'q':
                server.stop();
                goto exit_loop;
                break;
        }
    }
    exit_loop : 
	ASSERT_PASS();

END_TEST


BEGIN_SUITE(server_and_controlers)

    TEST(server_and_controlers)

END_SUITE
