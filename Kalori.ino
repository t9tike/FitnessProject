void Kalori(){  //kaloreitten laskemiseen
  if (once == 1){
    Kello();  //kutsuu kellon
    if (user == 0) Fitness = SD.open("USER0");
    else if (user == 1) Fitness = SD.open("USER1");
    else if (user == 2) Fitness = SD.open("USER2");
    else if (user == 3) Fitness = SD.open("USER3");
    else if (user == 4) Fitness = SD.open("USER4");
    else if (user == 5) Fitness = SD.open("USER5");
    else if (user == 6) Fitness = SD.open("USER6");

    while (Fitness.available()) { // muistikortti on saatavilla
      kalori3[SDnumero] = Fitness.read();
      kalori2 = kalori2 * 10 + kalori3[SDnumero] - '0';
      SDnumero++;
    }

    SDnumero = 0;
    kalori4 = kalori + kalori2;

    Fitness.close();
    
    if (user == 0) SD.remove("USER0");
    else if (user == 1) SD.remove("USER1");
    else if (user == 2) SD.remove("USER2");
    else if (user == 3) SD.remove("USER3");
    else if (user == 4) SD.remove("USER4");
    else if (user == 5) SD.remove("USER5");
    else if (user == 6) SD.remove("USER6");

    if (user == 0) Fitness = SD.open("USER0", FILE_WRITE);
    else if (user == 1) Fitness = SD.open("USER1", FILE_WRITE);
    else if (user == 2) Fitness = SD.open("USER2", FILE_WRITE);
    else if (user == 3) Fitness = SD.open("USER3", FILE_WRITE);
    else if (user == 4) Fitness = SD.open("USER4", FILE_WRITE);
    else if (user == 5) Fitness = SD.open("USER5", FILE_WRITE);
    else if (user == 6) Fitness = SD.open("USER6", FILE_WRITE);
    
    Fitness.print(kalori4);
    Fitness.close();
    
    tft.setTextSize(9);
    tft.setCursor(10, 170);
    tft.print(kalori4);

    kalori = 0;
    kalori2 = 0;
    
    once = 0;
  }
  
  while (true){ 
    Kello();
    Return();
    if (once == 1) return;  //paluu
  }
}
