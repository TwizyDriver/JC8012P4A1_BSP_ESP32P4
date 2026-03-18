/*******************************************************************************
Created by profi-max (Oleg Linnik) 2026
https://profimaxblog.ru
https://github.com/profi-max

*******************************************************************************/

#include "esp_log.h"
#include "esp_err.h"
#include "nvs.h"
#include "nvs_flash.h"
#include <string.h>
#include <inttypes.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "esp_idf_version.h"

#include "esp_hosted.h"
#include "esp_netif.h"
#include "esp_wifi_remote.h" 

#define WIFI_MAX_RETRY_NUM 10

// Your wifi credentials
wifi_config_t wifi_config = {
    .sta = {
        .ssid = "YOUR_SSID",
        .password = "YOUR_PASSWORD",
    },
};

const char *TAG = "app_main";

static int s_retry_num = 0;

static bool wifi_connected = false;
static uint32_t wifi_ip_addr = 0;
//===========================================================================================================
static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT) {
        switch (event_id) {
        case WIFI_EVENT_STA_START:
            ESP_ERROR_CHECK(esp_wifi_connect());
            ESP_LOGI(TAG, "Started connection");
            wifi_connected = false;
            break;
        case WIFI_EVENT_STA_DISCONNECTED:
            wifi_connected = false;
            if (s_retry_num < WIFI_MAX_RETRY_NUM) {
                esp_wifi_connect();
                s_retry_num++;
                ESP_LOGI(TAG, "retry to connect to the AP");
            } else {
                ESP_LOGI(TAG, "Connect to the AP fails");
             }
            break;
        case WIFI_EVENT_STA_CONNECTED:
             wifi_connected = true;
            ESP_LOGI(TAG, "Successfully connected to the AP ssid : %s ", wifi_config.sta.ssid);
            break;
        default:
            break;
        }
    }
    if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
        wifi_ip_addr = event->ip_info.ip.addr;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        s_retry_num = 0;
    }
}
//===========================================================================================================

void app_main(void)
{
    esp_err_t ret;
    char bda_str[18] = {0};

    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    esp_hosted_init();

    // initialise connection to co-processor
    esp_hosted_connect_to_slave();


     // initialise NET interface
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL));

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    
    // Starts Wi-Fi 
    if(esp_wifi_start() ==  ESP_OK) {
        ESP_LOGI(TAG, "Wi-Fi starts on ESP32-P4 using external ESP32-C6");
    }

    // Main application loop...
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
        ESP_LOGI(TAG, "Application running...");
        if (wifi_connected) {
            //  do something
        }
    }
}
//===========================================================================================================

