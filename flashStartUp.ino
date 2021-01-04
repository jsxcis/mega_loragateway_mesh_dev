void flashStartUp()
{

  digitalWrite(LORA_SEND, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LORA_SEND, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  digitalWrite(LORA_RECV, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LORA_RECV, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  digitalWrite(LORA_SEND, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LORA_SEND, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
}       
