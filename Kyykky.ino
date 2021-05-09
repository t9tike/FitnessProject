void Kyykky(){  //kyykky ohjelma
  GUI();

  while (true){ 
    Kello();

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    
    distance = pulseIn(echo, HIGH);
    
    cm = distance*0.034/2;
    
    if (cm < 80){
      laskuri++;
      kalori = kalori + 8;
      
      while (cm < 120){
        Kello();
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);
        distance = pulseIn(echo, HIGH);
        
        cm = distance*0.034/2;
        
        Return2();
        Setti();
        if (once == 1) return;
      }
    }
    
    if (laskuri < 10) tft.setCursor(64, 195);
    else if (laskuri >= 10) tft.setCursor(14, 195);
    tft.setTextColor(GREEN, BLACK);
    tft.setTextSize(8);
    tft.print(laskuri);
    
    Return2();
    Setti();
    if (once == 1) return;
  }
}
