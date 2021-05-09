void Vaikeustaso(){  //ohjelmien vaikeustasojen säätäminen
  if (once == 1){ //kirjoittaa näytön kerran
    tft.fillScreen(BLACK);  //täyttää näytön mustalla
    tft.setTextColor(GREEN, BLACK); //asettaa tekstin vihreäksi ja tekstin taustan mustaksi
    Kello();  //kutsuu kellon
    tft.setTextSize(2); //tekstin koko
  
    tft.drawRect(0,30,140,40,CYAN); //piirtää laatikon
    tft.setCursor(10,40);
    tft.print("HYPPY");
  
    tft.drawRect(0,70,140,40,CYAN);
    tft.setCursor(10,80);
    tft.print("VATSALIHAS");
    
    tft.drawRect(0,110,140,40,CYAN);
    tft.setCursor(10,120);
    tft.print("PUNNERRUS");
  
    tft.drawRect(0,150,140,40,CYAN);
    tft.setCursor(10,160);
    tft.print("KYYKKY");


    tft.drawRect(155,35,25,25,CYAN);
    tft.setCursor(160,40);
    tft.print("1");
    
    tft.drawRect(185,35,25,25,CYAN);
    tft.setCursor(190,40);
    tft.print("2");
    
    tft.drawRect(215,35,25,25,CYAN);
    tft.setCursor(220,40);
    tft.print("3");
    


    tft.drawRect(155,75,25,25,CYAN);
    tft.setCursor(160,80);
    tft.print("1");
    
    tft.drawRect(185,75,25,25,CYAN);
    tft.setCursor(190,80);
    tft.print("2");
    
    tft.drawRect(215,75,25,25,CYAN);
    tft.setCursor(220,80);
    tft.print("3");



    tft.drawRect(155,115,25,25,CYAN);
    tft.setCursor(160,120);
    tft.print("1");

    tft.drawRect(185,115,25,25,CYAN);
    tft.setCursor(190,120);
    tft.print("2");

    tft.drawRect(215,115,25,25,CYAN);
    tft.setCursor(220,120);
    tft.print("3");

    

    tft.drawRect(155,155,25,25,CYAN);
    tft.setCursor(160,160);
    tft.print("1");

    tft.drawRect(185,155,25,25,CYAN);
    tft.setCursor(190,160);
    tft.print("2");

    tft.drawRect(215,155,25,25,CYAN);
    tft.setCursor(220,160);
    tft.print("3");

    tft.drawRect(0,272,240,40,CYAN);
    tft.setTextSize(3);
    tft.setCursor(80,280);
    tft.print("PALAA");
    
    once = 0;
  }

  Kello();
  while (true){
    tft.setTextSize(3);
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
  
    if (p.z > ts.pressureThreshhold){ //painalluksen voimakkuus > painetunnistus
      p.x = map(p.x, TS_MAXX, TS_MINX, 0, WIDTH); //ottaa pikselikoordinaatin x:lle
      p.y = map(p.y, TS_MAXY, TS_MINY, 0, HEIGHT);  //ottaa pikselikoordinaatin y:lle
      
      if (p.x>155 && p.x<180 && p.y>35 && p.y<60){ 
        tavoitehyppy = 2;
        tft.setCursor(120,230);
        tft.print(tavoitehyppy);
      }
      if (p.x>185 && p.x<210 && p.y>35 && p.y<60){
        
        tavoitehyppy = 5;
        tft.setCursor(120,230);
        tft.print(tavoitehyppy);
      }
      if (p.x>215 && p.x<240 && p.y>35 && p.y<60){
        
        tavoitehyppy = 9;
        tft.setCursor(120,230);
        tft.print(tavoitehyppy);
      }
      if (p.x>155 && p.x<180 && p.y>75 && p.y<100){ 
  
        tavoitevatsa = 2;
        tft.setCursor(120,230);
        tft.print(tavoitevatsa);
      }
      if (p.x>185 && p.x<210 && p.y>75 && p.y<100){
        
        tavoitevatsa = 5;
        tft.setCursor(120,230);
        tft.print(tavoitevatsa);
      }
      if (p.x>215 && p.x<240 && p.y>75 && p.y<100){
        
        tavoitevatsa = 9;
        tft.setCursor(120,230);
        tft.print(tavoitevatsa);
      }
      if (p.x>155 && p.x<180 && p.y>115 && p.y<140){ 
       tavoitepunnerrus = 2;
       tft.setCursor(120,230);
       tft.print(tavoitepunnerrus);
      }
  
      if (p.x>185 && p.x<210 && p.y>115 && p.y<140){
        
       tavoitepunnerrus = 5;
       tft.setCursor(120,230);
       tft.print(tavoitepunnerrus);
      }
  
      if (p.x>215 && p.x<240 && p.y>115 && p.y<140){
        
       tavoitepunnerrus = 9;
       tft.setCursor(120,230);
       tft.print(tavoitepunnerrus);
      }
       if (p.x>155 && p.x<180 && p.y>155 && p.y<180){ 
  
       tavoitekyykky = 2;
       tft.setCursor(120,230);
       tft.print(tavoitekyykky);
      }
      if (p.x>185 && p.x<210 && p.y>155 && p.y<180){
        
       tavoitekyykky = 5;
       tft.setCursor(120,230);
       tft.print(tavoitekyykky);
      }
      if (p.x>215 && p.x<240 && p.y>155 && p.y<180){
        
       tavoitekyykky = 9;
       tft.setCursor(120,230);
       tft.print(tavoitekyykky);
      }
      if (p.x>0 && p.x<WIDTH && p.y>280 && p.y<HEIGHT){
       once = 1;
       return;
      }
    }
  }
}
