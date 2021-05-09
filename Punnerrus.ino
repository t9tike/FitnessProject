void Punnerrus(){  //punnerrus ohjelma
  GUI();
  while (true){
    Kello();
    if (setti != 0){  //jos eri kuin 0
      Kulma();  //kutsuu kulmafunktion
      
      if (kulmaX > 17){
        laskuri++;
        kalori = kalori + 7;
        tft.setTextColor(GREEN, BLACK);
        tft.setTextSize(8);
        
        if (laskuri < 10) tft.setCursor(64, 195);
        
        else if (laskuri >= 10) tft.setCursor(14, 195);
        
        tft.print(laskuri);
        
        while (kulmaX > 15){ //jos kulma pienempi kuin nolla
          Kello();          //kutsuu kelloa
          Kulma();          //kutsuu kulmaa
          Return2();        //kutsuu return2
          Setti();          //kutsuu settiä
          if (once == 1) return;
        }
      }
    }
    Return2();
    Setti();
    if (once == 1) return;
  }
}
