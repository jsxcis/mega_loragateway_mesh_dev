void processCommand(String command)
{
  String dest_string;
  byte destination = 0x00;
  String messageType;
  
  Serial.print("processCommand:");
  Serial.println(command);
  
  dest_string = command.substring(0,2);

  messageType = command.substring(3,10);

  Serial.print("Message type is :");
  Serial.println(messageType);

  if (messageType == "REQUEST")
  {
     //Serial.print("Destination as string:");
    //Serial.println(dest_string);

    destination = dest_string.toInt();

    //Serial.print("Destination as byte:");
    //Serial.println(destination,HEX);
    //sendLoraMessage(command,destination);
    sendToMesh(command,destination);
  }
  else if (messageType == "INFO")
  {
    Serial.println(command);
  }
}
