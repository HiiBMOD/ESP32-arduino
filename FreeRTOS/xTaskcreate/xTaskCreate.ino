
void setup() {
  Serial.begin(115200);

  xTaskCreate(t1_Main, "t1_Main", 10000, NULL, configMAX_PRIORITIES/2, NULL); 
  xTaskCreate(t2_Main, "t2_Main", 10000, NULL, configMAX_PRIORITIES/2, NULL); 


  while (1);

}

void t1_Main(void *arg) { 
  while (1) {
      Serial.printf("A %d\n",i);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void t2_Main(void *arg) {
  while (1) {
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      Serial.printf(" B%d\n",j); 
   
    
  }
}

void loop() {
  Serial.println("loop task on");
  //no use
}