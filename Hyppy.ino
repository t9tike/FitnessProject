void Hyppy(){ //hyppy ohjelma
  GUI();  //graafinen alkuasetus
    
  while (true){ //looppi hypylle
    //Kello();  //kutsuu kellofunktion
    Kulma();
    Kiihtyvyys();
    
    if (setti != 0){
      
      if (kiihtyvyys > 5){ //jos kiihtyvyys yli 14
        laskuri++;  //lisää yhden laskuriin
        kalori = kalori + 16; //lisää liikkeen kalorin
        tft.setTextColor(GREEN, BLACK);
        tft.setTextSize(8);
        
        if (laskuri < 10) tft.setCursor(64, 195); //tulostaa laskurin näytölle
        
        else if (laskuri >= 10) tft.setCursor(14, 195); //jos laskuri yli 10 vaihtaa kohtaa johon tulostaa
        
        tft.print(laskuri);
        delay(600);
      }
    }
    Return2();
    Setti();
    if (once == 1) return;
  }
}
