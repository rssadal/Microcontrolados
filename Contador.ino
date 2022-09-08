unsigned long myTime=0;
unsigned long currentMillis, previousMillis; 
unsigned long interval=1;
unsigned long timer_segmentos;
int estado_segmentos, temp_unid, temp_dez, timer_contagem;


void setup() {
  // put your setup code here, to run once:
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

int disp_seg[10][7] ={
{ 1, 1, 1, 1, 1, 1, 0},
{ 0, 1, 1, 0, 0, 0, 0},
{ 1, 1, 0, 1, 1, 0, 1},
{ 1, 1, 1, 1, 0, 0, 1},
{ 0, 1, 1, 0, 0, 1, 1},
{ 1, 0, 1, 1, 0, 1, 1},
{ 1, 0, 1, 1, 1, 1, 1},
{ 1, 1, 1, 0, 0, 0, 0},
{ 1, 1, 1, 1, 1, 1, 1},
{ 1, 1, 1, 0, 0, 1, 1}
};


void base_tempo (){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
//    Serial.println(myTime++); // prints time since program started
    if (timer_segmentos != 0){
      timer_segmentos--;
    }
     if (timer_contagem!=0){
      timer_contagem--;
    }
  }
}

void tic_display(){
  switch(estado_segmentos){
      case 0:
        estado_segmentos = 1;
        break;
      case 1:  
        if(timer_segmentos == 0){
          timer_segmentos = 20;
          digitalWrite(0, disp_seg[temp_unid][1]);  
          digitalWrite(0, disp_seg[temp_unid][0]);
          digitalWrite(0, disp_seg[temp_unid][5]);
          digitalWrite(0, disp_seg[temp_unid][6]);
          digitalWrite(0, disp_seg[temp_unid][3]);
          digitalWrite(0, disp_seg[temp_unid][4]);
          digitalWrite(0, disp_seg[temp_unid][2]);
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);   
           estado_segmentos = 2;
        }
        
        break;
      case 2:
        if(timer_segmentos == 0){
            timer_segmentos = 20;
            digitalWrite(0, disp_seg[temp_dez][1]);  
            digitalWrite(0, disp_seg[temp_dez][0]);
            digitalWrite(0, disp_seg[temp_dez][5]);
            digitalWrite(0, disp_seg[temp_dez][6]);
            digitalWrite(0, disp_seg[temp_dez][3]);
            digitalWrite(0, disp_seg[temp_dez][4]);
            digitalWrite(0, disp_seg[temp_dez][2]);
            digitalWrite(7, LOW);
            digitalWrite(8, HIGH);  
            estado_segmentos = 1;
        }
        
      break;
  } 
}

void tic_contagem(){
  if(timer_contagem==0){
    timer_contagem=1000;
    temp_unid++;
    if(temp_unid==10){
      temp_dez++;
      temp_unid=0;
      if(temp_dez==10){
        temp_dez=0;
      }
    }
  }
}

void loop() {
  base_tempo();
  tic_display();
  tic_contagem();
}
