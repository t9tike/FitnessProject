void setup(){ //arduinon alku
  tft.reset();  //resetoi näytön
  Serial.begin(9600);
  uint16_t ID = tft.readID(); //lukee näytön id:n
  if (ID == 0xD3) ID = 0x9481;  //
  tft.begin(ID);  //aloittaa näytön
  tft.setRotation(2);
  Kello();
  SD.begin(10, 11, 12, 13); //"aloittaa" muistikortin
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
}

void loop(){  //arduinon loppi
  if (user == 7) Users(); // jos käyttäjää ei ole valittu, valitse käyttäjä
  Menu(); //kutsuu menu funktion
  Kulma();
  Kiihtyvyys();
}
