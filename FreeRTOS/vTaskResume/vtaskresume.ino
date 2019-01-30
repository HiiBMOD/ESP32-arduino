xTaskHandle xHandle;

void setup() {
  Serial.begin(115200);

  xTaskCreate(t1_Main, "t1_Main", 10000, NULL, configMAX_PRIORITIES/2, &xHandle); //�׽�ũ1,�켱����1
  xTaskCreate(t2_Main, "t2_Main", 10000, NULL, configMAX_PRIORITIES/2, NULL); //�׽�ũ2,�켱����1


  while (1);

}

void t1_Main(void *arg) { //�׽�ũ1 �Լ�
  while (1) {
    for (int i = 0; i < 10; i++) {
      vTaskDelay(500 / portTICK_PERIOD_MS);
      Serial.printf("A %d\n",i);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      if (i == 5)
        vTaskSuspend(xHandle);
    }
    Serial.println("T1_Main Task Quit");
    vTaskDelete(NULL);
  }
}

void t2_Main(void *arg) { //�׽�ũ2 �Լ�
  while (1) {
    for (int j = 0; j < 10; j++) {
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      Serial.printf(" B%d\n",j); 
      vTaskDelay(500 / portTICK_PERIOD_MS);
      
    }
    vTaskResume(xHandle);
    Serial.println("T2_Main Task Quit");
    vTaskDelete(NULL);
    
  }
}

void loop() {
  Serial.println("loop task on");
  //no use
}