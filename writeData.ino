void writeData(String data)
{

  Serial.print("Gateway returning:");
  Serial.println(data);
  writeString(data);
  //Serial3.print(data);
}
