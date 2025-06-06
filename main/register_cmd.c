#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_console.h"
#include "argtable3/argtable3.h"
#include "esp_now_hub.h"
#include "register_cmd.h"
#include "nvs_flash.h"

static struct {
    struct arg_str *state; // "on" or "off"
    struct arg_end *end;
} light_args;

static int control_light(int argc, char **argv)
{
    int nerrors = arg_parse(argc, argv, (void **) &light_args);
    if (nerrors != 0) {
        arg_print_errors(stderr, light_args.end, argv[0]);
        return 1;
    }

    const char *state = light_args.state->sval[0];

    if (strcmp(state, "on") == 0) {
        espnow_send_light_state(true);
        ESP_LOGI("TAG", "Send light state ON");
    } else if (strcmp(state, "off") == 0) {
        espnow_send_light_state(false);
        ESP_LOGI("TAG", "Send light state OFF");
    } else {
        printf("Invalid command. Use 'on' or 'off'.\n");
    }
    return 0;
}

void register_control_light_commands(void)
{
    light_args.state = arg_str1(NULL, NULL, "<state for light>", "Light state: 'on' or 'off'");
    light_args.end = arg_end(1);
    /* Register custom commands here */
    esp_console_cmd_t light_cmd = {
        .command = "light",
        .help = "Control light state",
        .hint = NULL,
        .func = &control_light,
        .argtable = &light_args
    };

    ESP_ERROR_CHECK( esp_console_cmd_register(&light_cmd) );
}

static struct {
    struct arg_int *kp;
    struct arg_int *ki;
    struct arg_int *kd;
    struct arg_end *end;
} pid_args;

static int set_pid(int argc, char **argv)
{
    int nerrors = arg_parse(argc, argv, (void **) &pid_args);
    if (nerrors != 0) {
        arg_print_errors(stderr, pid_args.end, argv[0]);
        return 1;
    }

    int kp = pid_args.kp->ival[0];
    int ki = pid_args.ki->ival[0];
    int kd = pid_args.kd->ival[0];

    printf("PID parameters set: Kp=%d, Ki=%d, Kd=%d\n", kp, ki, kd);
    return 0;
}

void register_pid_command(void)
{
    pid_args.kp = arg_int1(NULL, NULL, "<kp>", "Proportional gain");
    pid_args.ki = arg_int1(NULL, NULL, "<ki>", "Integral gain");
    pid_args.kd = arg_int1(NULL, NULL, "<kd>", "Derivative gain");
    pid_args.end = arg_end(3);

    const esp_console_cmd_t pid_cmd = {
        .command = "pid",
        .help = "Set PID parameters",
        .hint = NULL,
        .func = &set_pid,
        .argtable = &pid_args
    };

    ESP_ERROR_CHECK( esp_console_cmd_register(&pid_cmd) );
}

static int reset_app(int argc, char **argv)
{
    ESP_LOGI("TAG", "Reset application and erase nvs...");
    nvs_flash_erase();
    esp_restart();
    return 0;
}

void register_reset_app_command(void)
{
    const esp_console_cmd_t restart_cmd = {
        .command = "reset",
        .help = "Reset the application",
        .hint = NULL,
        .func = &reset_app,
        .argtable = NULL
    };

    ESP_ERROR_CHECK( esp_console_cmd_register(&restart_cmd) );
}