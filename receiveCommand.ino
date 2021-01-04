bool receiveCommand(String &req)
{
    // listen for communication from the ESP8266
    while(Serial3.available() > 0) // Don't read unless there you know there is data
    {
      if(index < 19) // One less than the size of the array
      {
          inChar = Serial3.read(); // Read a character
          inData[index] = inChar; // Store it
          index++; // Increment where to write next
          inData[index] = '\0'; // Null terminate the string
      }
    } 
    if (index >=19)
    { 
      //Serial.print(String(inData));
      req = inData;
      //Serial3.write("Hello\n");
      index = 0;
      return true;
    }
    return false;
}
