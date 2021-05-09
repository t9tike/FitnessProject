void Menu(){  //menu funktio
  if (once == 1){ //kirjoittaa näytön kerran
    tft.fillScreen(BLACK);  //täyttää näytön mustalla
    tft.setTextColor(GREEN, BLACK); //asettaa tekstin vihreäksi ja tekstin taustan mustaksi
    Kello();  //kutsuu kellon
    tft.setTextSize(3); //tekstin koko
  
    tft.drawRect(0,30,WIDTH,40,CYAN); //piirtää laatikon
    tft.setCursor(10,40);
    tft.print("HYPPY");
  
    tft.drawRect(0,70,WIDTH,40,CYAN);
    tft.setCursor(10,80);
    tft.print("VATSALIHAS");
    
    tft.drawRect(0,110,WIDTH,40,CYAN);
    tft.setCursor(10,120);
    tft.print("PUNNERRUS");
  
    tft.drawRect(0,150,WIDTH,40,CYAN);
    tft.setCursor(10,160);
    tft.print("KYYKKY");
  
    tft.drawRect(0,190,WIDTH,40,CYAN);
    tft.setCursor(10,200);
    tft.print("KALORIT");
  
    tft.drawRect(0,230,WIDTH,40,CYAN);
    tft.setCursor(10,240);
    tft.print("K\x8eYTT\x8eJ\x8e");
  
    tft.drawRect(0,270,WIDTH,40,CYAN);
    tft.setCursor(10,280);
    tft.print("VAIKEUSASTE"); // setti kertoimen määritys
    
    once = 0;
  }

  Kello();
  
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > ts.pressureThreshhold){ //painalluksen voimakkuus > painetunnistus
    p.x = map(p.x, TS_MAXX, TS_MINX, 0, WIDTH); //ottaa pikselikoordinaatin x:lle
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, HEIGHT);  //ottaa pikselikoordinaatin y:lle
    
    if (p.x>0 && p.x<WIDTH && p.y>30 && p.y<70){ //jos X akseli suurempi kuin 0 ja pienempi kuin näytön maksimi leveys. Y suurempi kuin 30 ja pienempi kuin 70
      once = 1;
      laskuri = 0;
      setti = 1;
      tft.fillScreen(BLACK);
      tft.setTextSize(3);
      tft.setCursor(10, 60);
      tft.print("Hyppy");
      tavoitenum = 1;
      Hyppy();
    }

    if (p.x>0 && p.x<WIDTH && p.y>70 && p.y<110){
      once = 1;
      laskuri = 0;
      setti = 1;
      tft.fillScreen(BLACK);
      tft.setTextSize(3);
      tft.setCursor(10, 60);
      tft.print("Vatsalihas");
      tavoitenum = 2;
      Vatsalihas();
    }

    if (p.x>0 && p.x<WIDTH && p.y>110 && p.y<150){
      once = 1;
      laskuri = 0;
      setti = 1;
      tft.fillScreen(BLACK);
      tft.setTextSize(3);
      tft.setCursor(10, 60);
      tft.print("Punnerrus");
      tavoitenum = 3;
      Punnerrus();
    }
      
    if (p.x>0 && p.x<WIDTH && p.y>150 && p.y<190){
      once = 1;
      laskuri = 0;
      setti = 1;
      tft.fillScreen(BLACK);
      tft.setTextSize(3);
      tft.setCursor(10, 60);
      tft.print("Kyykky");
      tavoitenum = 4;
      Kyykky();
    }
    
    if (p.x>0 && p.x<WIDTH && p.y>190 && p.y<230){
      once = 1;
      laskuri = 0;
      setti = 1;
      tft.fillScreen(BLACK);
      tft.setTextSize(3);
      tft.setCursor(10, 60);
      tft.print("Kalori");
      Kalori();
    }
      
    if (p.x>0 && p.x<WIDTH && p.y>230 && p.y<270){
      once = 1;
      Users();
    }

    if (p.x>0 && p.x<WIDTH && p.y>270 && p.y<310){
      once = 1;
      Vaikeustaso();
    }
  }
}
