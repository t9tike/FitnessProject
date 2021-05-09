void Vatsalihas(){  //vatsalihas ohjelma
  GUI();
  while (true){ 
    Kello();
    if (setti != 0){
      Kulma();
      
      if (kulmaZ > 12){ //jos kulma Z isompi kuin 10
        laskuri++;
        kalori = kalori + 9;  //lisää poltetun kalorimäärän kalorilaskuriin
        tft.setTextColor(GREEN, BLACK); //asettaa tekstin värin ja tekstin taustavärin
        tft.setTextSize(8); //asettaa tekstin koon
        
        if (laskuri < 10) tft.setCursor(64, 195);
        
        else if (laskuri >= 10) tft.setCursor(14, 195);
        
        tft.print(laskuri);
        
        while (kulmaZ > 5){ //jatkaa kulman laskemista jos kulma Z on pienempi kuin 0
          Kello();
          Kulma();
          Return2();
          Setti();
          if (once == 1) return;  //jos once on 1 palaa
        }
      }
    }
    Return2();
    Setti();
    if (once == 1) return;
  }
}
