 // cores running each tasks 
static const BaseType_t app1_cpu = 1;
static const BaseType_t app2_cpu = 1;
static const BaseType_t app3_cpu = 1;
static const BaseType_t app4_cpu = 1;

// Pins
static const int led_pin1 = LED_BUILTIN;
static const int led_pin2 = 32;
static const int led_pin3 = 33;
static const int led_pin4 = 25;


// Our task: blink an LED 1
void toggleLED1(void *parameter) {
  while(1) {
    digitalWrite(led_pin1, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin1, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

// Our task: blink an LED 2
void toggleLED2(void *parameter) {
  while(1) {
    digitalWrite(led_pin2, HIGH);
    vTaskDelay(400 / portTICK_PERIOD_MS);
    digitalWrite(led_pin2, LOW);
    vTaskDelay(400 / portTICK_PERIOD_MS);
  }
}

// Our task: blink an LED 3
void toggleLED3(void *parameter) {
  while(1) {
    digitalWrite(led_pin3, HIGH);
    vTaskDelay(400 / portTICK_PERIOD_MS);
    digitalWrite(led_pin3, LOW);
    vTaskDelay(400 / portTICK_PERIOD_MS);
  }
}

// Our task: blink an LED 4
void toggleLED4(void *parameter) {
  while(1) {
    digitalWrite(led_pin4, HIGH);
    vTaskDelay(400 / portTICK_PERIOD_MS);
    digitalWrite(led_pin4, LOW);
    vTaskDelay(400 / portTICK_PERIOD_MS);
  }
}

void setup() {

  // Configure pin
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);


  // Task to run forever
  xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
              toggleLED1,    // Function to be called
              "Toggle LED 1", // Name of task
              1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
              NULL,         // Parameter to pass to function
              1,            // Task priority (0 to configMAX_PRIORITIES - 1)
              NULL,         // Task handle
              app1_cpu);     // Run on one core for demo purposes (ESP32 only)

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in
  // main after setting up your tasks.
  
  // Task to run forever
  xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
              toggleLED2,    // Function to be called
              "Toggle LED 2", // Name of task
              1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
              NULL,         // Parameter to pass to function
              1,            // Task priority (0 to configMAX_PRIORITIES - 1)
              NULL,         // Task handle
              app2_cpu);     // Run on one core for demo purposes (ESP32 only)

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in
  // main after setting up your tasks.

  // Task to run forever
  xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
              toggleLED3,    // Function to be called
              "Toggle LED 3", // Name of task
              1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
              NULL,         // Parameter to pass to function
              1,            // Task priority (0 to configMAX_PRIORITIES - 1)
              NULL,         // Task handle
              app3_cpu);     // Run on one core for demo purposes (ESP32 only)

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in
  // main after setting up your tasks.

  // Task to run forever
  xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
              toggleLED4,    // Function to be called
              "Toggle LED 4", // Name of task
              1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
              NULL,         // Parameter to pass to function
              1,            // Task priority (0 to configMAX_PRIORITIES - 1)
              NULL,         // Task handle
              app4_cpu);     // Run on one core for demo purposes (ESP32 only)

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in
  // main after setting up your tasks.



}

void loop() {
  // Do nothing
  ;
  // setup() and loop() run in their own task with priority 1 in core 1
  // on ESP32
}
