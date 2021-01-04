String onReceive(int packetSize) {
  if (packetSize == 0) return "";          // if there's no packet, return
  digitalWrite(LORA_RECV, HIGH);
  // read packet header bytes:
 /*
  int recipient = LoRa.read();          // recipient address
  byte sender = LoRa.read();            // sender address
  byte incomingMsgId = LoRa.read();     // incoming msg ID
  byte incomingLength = LoRa.read();    // incoming msg length
 
  */
  String incoming = "";
  /*
  while (LoRa.available()) {
    incoming += (char)LoRa.read();
  }


  if (incomingLength != incoming.length()) {   // check length for error
    Serial.println("error: message length does not match length");
    return "";                             // skip rest of function
  }

  // if the recipient isn't this device or broadcast,
  if (recipient != localAddress && recipient != 0xFF) {
    Serial.println("This message is not for me.");
    return "";                             // skip rest of function
  }
  digitalWrite(LED_BUILTIN, HIGH);
 
  // if message is for this device, or broadcast, print details:
  //Serial.println("Received from: 0x" + String(sender, HEX));
  //Serial.println("Sent to: 0x" + String(recipient, HEX));
  //Serial.println("Message ID: " + String(incomingMsgId));
  //Serial.println("Message length: " + String(incomingLength));
  Serial.println("Message: " + incoming);
  //Serial.println("RSSI: " + String(LoRa.packetRssi()));
  //Serial.println("Snr: " + String(LoRa.packetSnr()));
  //Serial.println();
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LORA_RECV, LOW);
  */
  return incoming;
}
