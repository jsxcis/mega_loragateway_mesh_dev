void sendToMesh(String outgoing, byte destination)
{
  digitalWrite(LORA_SEND, HIGH);
  //uint8_t data[] = "Hello World!";
  uint8_t data[XCIS_RH_MESH_MAX_MESSAGE_LEN];
  outgoing.toCharArray((char*)data,sizeof(data));
  // Dont put this on the stack:
  uint8_t buf[XCIS_RH_MESH_MAX_MESSAGE_LEN];
  Serial.print("sendToMesh():");
  Serial.println(outgoing);
    
  // Send a message to a rf22_mesh_server
  // A route to the destination will be automatically discovered.
  
  if (manager->sendtoWait(data, sizeof(data), destination) == RH_ROUTER_ERROR_NONE)
  {
    /*
    // It has been reliably delivered to the next node.
    // Now wait for a reply from the ultimate server
    uint8_t len = sizeof(buf);
    uint8_t from;    
    if (manager->recvfromAckTimeout(buf, &len, 3000, &from))
    {
      Serial.print("got reply from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
    }
    else
    {
      Serial.println("No reply, 1,2,3 running?");
    }
    */
  }
  else
  {
     //Serial.println("sendtoWait failed. Are the intermediate mesh servers running?");
  }
  digitalWrite(LORA_SEND, LOW);
}
