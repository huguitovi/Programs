//Initializing LED Pin
#define PWMX 2  //se usa el PWMX y PWMY PARA EL GIRO (esta decisión es concensuada) 
#define PWMY 3
#define PWMZ 4
 
#define sentidoAX1  22
#define sentidoBX1  23
#define sentidoAX2  24
#define sentidoBX2  25

#define sentidoAY1  28
#define sentidoBY1  29
#define sentidoAY2  30
#define sentidoBY2  31

#define sentidoAZ0  34
#define sentidoBZ0  35

//pote 1 x,y  | pote2 z,w
#define Xmin 271  //ok
#define Xmed 527
#define Xumbral 50  //real 25
#define Xmax 736 //ok 

#define Ymin 0
#define Ymed 386
#define Yumbral 140 //real 126
#define Ymax 1024 //ok

#define Zmin 312
#define Zmed 480
#define Zumbral 70 //real 50
#define Zmax 796

#define Wmin 0
#define Wmed 646
#define Wumbral 220 //real 209
#define Wmax 1024

boolean Xon = false;  
boolean Yon = false; 
boolean Zon = false; 
boolean Won = false; //chequeo por motores compartidos

void setup() {

  pinMode(PWMX, OUTPUT);
  pinMode(PWMY, OUTPUT);
  pinMode(PWMZ, OUTPUT);
  
  pinMode(sentidoAX1,OUTPUT);
  pinMode(sentidoBX1,OUTPUT);
  pinMode(sentidoAX2,OUTPUT);
  pinMode(sentidoBX2,OUTPUT);
  
  pinMode(sentidoAY1,OUTPUT);
  pinMode(sentidoBY1,OUTPUT);
  pinMode(sentidoAY2,OUTPUT);
  pinMode(sentidoBY2,OUTPUT);
  
  pinMode(sentidoAZ0,OUTPUT);
  pinMode(sentidoBZ0,OUTPUT);
  
  Serial.begin(9600);
}

void tipodemaniobra(int X,int Y,int Z,int W){ //eje: x=1; y=2; z=3, giro = 4 sentido          1=adelante/horario ; -1=atras/antihorario ;
//configuro el sentido de rotacion de los motores segun el eje y sentido
boolean entroxoy = false;
int Xmap,Ymap,Zmap,Wmap;

  //mapeo de valores
  if(X>Xmed+Xumbral){  //x+
    
      Xmap = round(((X-(Xmed+Xumbral))/(float)(Xmax-(Xmed+Xumbral)))*215);   
      Serial.print("Xmap+ = ");
      Serial.println(Xmap);
      digitalWrite(sentidoAX1, HIGH); 
      digitalWrite(sentidoBX1, LOW);
      digitalWrite(sentidoAX2, HIGH); 
      digitalWrite(sentidoBX2, LOW);
      Xon = true;
      
  }else if(X<Xmed-Xumbral){  // X-
      
      Xmap = round(((X-(Xmed-Xumbral))/(float)(Xmin-(Xmed-Xumbral)))*215); 
      Serial.print("Xmap- = ");
      Serial.println(Xmap);
      digitalWrite(sentidoAX1, LOW);
      digitalWrite(sentidoBX1, HIGH);
      digitalWrite(sentidoAX2, LOW); 
      digitalWrite(sentidoBX2, HIGH);
      Xon = true;
      
  }else{   // no va: if(X<(Xmed+Xumbral) || X>(Xmed-Xumbral)){  //si x se encuentra cercano al cero
      Xon = false;
      if(Won == false) analogWrite(PWMX, 0); //Won es global, por tanto queda del loop anterior
      Xmap = 0; //para test
  }

  if(Xon){

    if(Xmap > 215) Xmap = 215;  
    if(Xmap <= 0) Xmap = 0;  
    analogWrite(PWMX, Xmap + 40);  
  }

  if(Y>Ymed+Yumbral){  //Y+
    
      Ymap = round(((Y-(Ymed+Yumbral))/(float)(Ymax-(Ymed+Yumbral)))*215);  
      Serial.print("Ymap+ = ");
      Serial.println(Ymap);
      digitalWrite(sentidoAY1, HIGH); 
      digitalWrite(sentidoBY1, LOW);
      digitalWrite(sentidoAY2, HIGH); 
      digitalWrite(sentidoBY2, LOW);
      Yon = true;
      
  }else if(Y<Ymed-Yumbral){  // X-

      Ymap = round(((Y-(Ymed-Yumbral))/(float)(Ymin-(Ymed-Yumbral)))*215); 
      Serial.print("Ymap- = ");
      Serial.println(Ymap);
      digitalWrite(sentidoAY1, LOW);
      digitalWrite(sentidoBY1, HIGH);
      digitalWrite(sentidoAY2, LOW); 
      digitalWrite(sentidoBY2, HIGH);
      Yon = true;

  }else{  //si Y se encuentra cercano al cero
      Yon = false;
      if(Won == false) analogWrite(PWMY, 0);
      Ymap = 0; 
  }

  if(Yon){

    if(Ymap > 215) Ymap = 215; 
    if(Ymap <= 0) Ymap = 0;  
    analogWrite(PWMY, Ymap + 40);  
  }

  if(Z>Zmed+Zumbral){  //Z+
    
      Zmap = round(((Z-(Zmed+Zumbral))/(float)(Zmax-(Zmed+Zumbral)))*215);  
      Serial.print("Zmap+ = ");
      Serial.println(Zmap);
      digitalWrite(sentidoAZ0, HIGH);
      digitalWrite(sentidoBZ0, LOW);
      Zon = true;
 
  }else if(Z<Zmed-Zumbral){  // Z-
      
      Zmap = round(((Z-(Zmed-Zumbral))/(float)(Zmin-(Zmed-Zumbral)))*215); 
      Serial.print("Zmap- = ");
      Serial.println(Zmap);
      digitalWrite(sentidoAZ0, LOW);
      digitalWrite(sentidoBZ0, HIGH);
      Zon = true;
      
  }else{  //si z se encuentra cercano al cero
    
      Zon = false;
      analogWrite(PWMZ, 0);
  }

  if(Zon){

    if(Zmap > 215) Zmap = 215; 
    if(Zmap <= 0) Zmap = 0;  
    analogWrite(PWMZ, Zmap + 40);  
  }

  if(!(Xon && Yon)){ //W - si alguna de las dos tralsaciones está apagada (sino no hay rotacion)
    
    if(W>Wmed+Wumbral){  //W+ giro horario
       
        Wmap = round(((W-(Wmed+Wumbral))/(float)(Wmax-(Wmed+Wumbral)))*215);  
        Serial.print("Wmap+ = ");
        Serial.println(Wmap);
        if(Xon == false){ //si no estoy usando X entonces configuro para girar horario
          digitalWrite(sentidoAX1, HIGH);
          digitalWrite(sentidoBX1, LOW);
          digitalWrite(sentidoAX2, LOW); 
          digitalWrite(sentidoBX2, HIGH);
        }
        if(Yon == false){ //si no estoy usando Y entonces configuro para girar horario
          digitalWrite(sentidoAY1, HIGH);
          digitalWrite(sentidoBY1, LOW);
          digitalWrite(sentidoAY2, LOW); 
          digitalWrite(sentidoBY2, HIGH);
        }
        Won = true;
        
    }else if(W<Wmed-Wumbral){  // X-
        
        Wmap = round(((W-(Wmed-Wumbral))/(float)(Wmin-(Wmed-Wumbral)))*215); 
        Serial.print("Wmap- = ");
        Serial.println(Wmap);

        if(Xon == false){   //si no estoy usando X entonces configuro para girar antihorario
          digitalWrite(sentidoAX1, LOW);
          digitalWrite(sentidoBX1, HIGH);
          digitalWrite(sentidoAX2, HIGH); 
          digitalWrite(sentidoBX2, LOW);
        }
        if(Yon == false){ //si no estoy usando Y entonces configuro para girar antihorario
          digitalWrite(sentidoAY1, LOW);
          digitalWrite(sentidoBY1, HIGH);
          digitalWrite(sentidoAY2, HIGH); 
          digitalWrite(sentidoBY2, LOW);
        }
  
        Won = true;
        
    }else{   //si W se encuentra cercano al cero
        
        Won = false;
        if(Xon == false) analogWrite(PWMX, 0); //Won es global, por tanto queda del loop anterior
        if(Yon == false) analogWrite(PWMY, 0);
        Xmap = 0; //para test
    }
  
    if(Won){
    
        if(Wmap > 215) Wmap = 215; 
        if(Wmap <= 0) Wmap = 0;  
        if(Xon == false) analogWrite(PWMX, Wmap + 40); //si no se activa queda el de la tralsacion 
        if(Yon == false) analogWrite(PWMY, Wmap + 40); // ""  idem
     }
    
  }else{
    Serial.println("no entró a W"); //para test
  }

}

void loop(){ //eje: x=1; y=2; z=3, giro = 4 sentido; 1=adelante/horario ; -1=atras/antihorario ; visto desde techo de carpa 

  //CONVERSION DE TEXTO A VARIABLES DE CONTROL
  boolean msjok= true;
  char payload[13] = "527100320900/"; //"123456789666/";
  
  Serial.println(payload);
  
    for(int i = 0;i <= 11;i++){
      if(!isDigit(payload[i])){
        Serial.print("Error, no es numérico = "); //funciona la validacion
        Serial.println(payload[i]);
        msjok = false;
      }
    }
    if(payload[12] != '/'){
      Serial.print("Error de fin de comando = "); 
      msjok = false;
    }

    if(msjok){
     
      int X = (payload[0]- '0')*100 + (payload[1]- '0')*10 + (payload[2]- '0')*1;
      int Y = (payload[3]- '0')*100 + (payload[4]- '0')*10 + (payload[5]- '0')*1;
      int Z = (payload[6]- '0')*100 + (payload[7]- '0')*10 + (payload[8]- '0')*1;
      int W = (payload[9]- '0')*100 + (payload[10]- '0')*10 + (payload[11]- '0')*1;
      Serial.println("Separacion de char a int"); 
      Serial.println(X);
      Serial.println(Y);
      Serial.println(Z);
      Serial.println(W);
  
      tipodemaniobra(X,Y,Z,W);
    }
    delay(5000); //solo para poder ver el monitor
}
