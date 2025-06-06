#include <stdio.h>
#include"esp_now_hub.h"

extern void app_rainmaker_start(void);
extern void app_console_start(void);

void app_main(void)
{
    app_rainmaker_start();
    app_espnow_start();
    app_console_start();
}
