//Primera secuencia 
int secuencia1 [] = {7,8,9,10,11};

//Segunda secuencia
int secuencia2 [] = {9,8,11,10,7,8,9};

//Tercera secuencia
int secuencia3 [] = {7,9,11,10,8,7,9,11,10,8};

//Variabres de pulsadores
int lectura = 0;
int estadoanterior = 0;

//Registro pulsaciones del usuario
int ingreso [10];
int cuenta = 0;

//Asigna los procesos que se ejecutan
int estado = 0;

//Pines de los botones
int BotonRojo = 2;
int BotonVerde = 3;
int BotonAmarillo = 4;
int BotonAzul = 5;
int BotonNaranja = 6;

//Pines de los leds
int LedRojo = 7;
int LedVerde = 8;
int LedAmarillo = 9;
int LedAzul = 10;
int LedNaranja = 11;

//pin del piezo
int Piezo = 12;

//Asigna los pines de led como salidas
void InicioLed ()
{
  for(int i = 7;i <= 11;i++)
  {
    pinMode(i, OUTPUT);
  }
}

//Asigna los pines de los botones como entradas
void InicioBoton ()
{
  for(int i = 2;i <= 6;i++)
  {
    pinMode(i, INPUT);
  }
}

//Se encarga de revisar si algun boton esta siendo pulsado
void LecturaBotones ()
{
  // lectura boton rojo
  lectura = digitalRead( BotonRojo);
  if(lectura != estadoanterior)
  {
    if(lectura == HIGH)
    {
      Serial.println("Rojo");
      ingreso [cuenta] = 7;
      cuenta++;
    }
    delay(100);
  }
  estadoanterior = lectura;
  
  //lectura boton verde
  lectura = digitalRead( BotonVerde);
  if(lectura != estadoanterior)
  {
    if(lectura == HIGH)
    {
      Serial.println("Verde");
      ingreso [cuenta] = 8;
      cuenta++;
    }
    delay(100);
  }
  estadoanterior = lectura;
  
  //lectura boton amarillo
  lectura = digitalRead( BotonAmarillo);
  if(lectura != estadoanterior)
  {
    if(lectura == HIGH)
    {
      Serial.println("Amarillo");
      ingreso [cuenta] = 9;
      cuenta++;
    }
    delay(100);
  }
  estadoanterior = lectura;
  
  //lectura boton azul
  lectura = digitalRead( BotonAzul);
  if(lectura != estadoanterior)
  {
    if(lectura == HIGH)
    {
      Serial.println("Azul");
      ingreso [cuenta] = 10;
      cuenta++;
    }
    delay(100);
  }
  estadoanterior = lectura;
  
  //lectura boton naranja
  lectura = digitalRead( BotonNaranja);
  if(lectura != estadoanterior)
  {
    if(lectura == HIGH)
    {
      Serial.println("Naranja");
      ingreso[cuenta] = 11;
      cuenta++;
    }
    delay(100);
  }
  estadoanterior = lectura;
}

//limpia el vector ingreso
void LimpiarIngreso()
{
  for(int i = 0; i < 10 ; i++)
  {
    ingreso [i] = 0;
  }
  cuenta = 0;
}

//Genera una alarma con el Piezo
void alarma()
{
    tone(Piezo, 523.25);
    delay (2000);
    noTone(Piezo);
}

//Muestra la primera secuencia de leds
void Ronda1 ()
{
  for (int i = 0;i < 5 ;i++)
  {
    digitalWrite(secuencia1 [i] , HIGH);
    delay (500);
    digitalWrite(secuencia1 [i] , LOW);
    delay(1000);
  }
  estado = 1;
}

//Muestra la segunda secuencia de leds
void Ronda2 ()
{
  for (int i = 0;i < 7 ;i++)
  {
    digitalWrite(secuencia2 [i] , HIGH);
    delay (400);
    digitalWrite(secuencia2 [i] , LOW);
    delay(800);
  }
  estado = 3;
}

//Muestra la tercera secuencia de leds
void Ronda3 ()
{
  for (int i = 0;i < 10 ;i++)
  {
    digitalWrite(secuencia3 [i] , HIGH);
    delay (300);
    digitalWrite(secuencia3 [i] , LOW);
    delay(500);
  }
  estado = 5;
}

//Verifica que la primera secuencia ingresada sea correcta
int Revicion1 ()
{
  if (secuencia1[0] == ingreso[0])
  {
    if (secuencia1[1] == ingreso[1])
    {
      if (secuencia1[2] == ingreso[2])
      {
        if (secuencia1[3] == ingreso[3])
      {
          if (secuencia1[4] == ingreso[4])
        {
            Serial.println("ganoooooooooooooo");
            estado = 2;
            LimpiarIngreso();
            return 0;
        }
      }
      }
    }
  }
  return 1;
}

//Verifica que la segunda secuencia ingresada sea correcta
int Revicion2 ()
{
  if (secuencia1[0] == ingreso[0])
  {
    if (secuencia1[1] == ingreso[1])
    {
      if (secuencia1[2] == ingreso[2])
      {
        if (secuencia1[3] == ingreso[3])
      {
          if (secuencia1[4] == ingreso[4])
        {
            if (secuencia1[5] == ingreso[5])
            {
              if (secuencia1[6] == ingreso[6])
              {
                Serial.println("ganoooooooooooooo");
                estado = 4;
                LimpiarIngreso();
                return 0;
              }
            }
        }
      }
      }
    }
  }
  return 1;
}

//Verifica que la tercera secuencia ingresada sea correcta
int Revicion3 ()
{
  if (secuencia1[0] == ingreso[0])
  {
    if (secuencia1[1] == ingreso[1])
    {
      if (secuencia1[2] == ingreso[2])
      {
        if (secuencia1[3] == ingreso[3])
      {
          if (secuencia1[4] == ingreso[4])
        {
            if (secuencia1[5] == ingreso[5])
            {
              if (secuencia1[6] == ingreso[6])
              {
                if (secuencia1[7] == ingreso[7])
                {
                  if (secuencia1[8] == ingreso[8])
                  {
                    if (secuencia1[9] == ingreso[9])
                    {
                      Serial.println("ganoooooooooooooo");
                      estado = 6;
                      LimpiarIngreso();
                      return 0;
                    }
                  }
                }
              }
            }
        }
      }
      }
    }
  }
  return 1;
}

//resetea el ingreso si te equivocas en la primera ronda
void Reset1 ()
{
  if (Revicion1 () == 1)
  {
    if(cuenta == 5)
    {
      estado = 0;
      alarma();
      LimpiarIngreso();
    }
  }
}

//resetea el ingreso si te equivocas en la segunda ronda
void Reset2 ()
{
  if (Revicion2 () == 1)
  {
    if(cuenta == 7)
    {
      estado = 0;
      alarma();
      LimpiarIngreso();
    }
  }
}

//resetea el ingreso si te equivocas en la tercera ronda
void Reset3 ()
{
  if (Revicion3 ()== 1)
  {
    if(cuenta == 10)
    {
      estado = 0;
      alarma();
      LimpiarIngreso();
    }
  }
}

//Muestra la primera secuencia y despues verifica
void Nivel1()
{
  if (estado == 0)
  {
    Serial.println("+++ Ronda 1 ejecutando +++");
    Ronda1 ();
  }
  if (estado == 1)
  {
    LecturaBotones ();
    Revicion1 ();
    Reset1 ();
  }
}

//Muestra la segunda secuencia y despues verifica
void Nivel2()
{
  if (estado == 2)
  {
    Serial.println("+++Ronda 2 ejecutando +++");
    Ronda2 ();
  }
  if (estado == 3)
  {
    LecturaBotones ();
    Revicion2 ();
    Reset2 ();
  }
}

//Muestra la tercera secuencia y despues verifica
void Nivel3()
{
  if (estado == 4)
  {
    Serial.println("+++Ronda 3 ejecutando +++");
    Ronda3 ();
  }
  if (estado == 5)
  {
    LecturaBotones ();
    Revicion3 ();
    Reset3 ();
  }
}

void setup()
{
  //Inicio Pantalla serial
  Serial.begin(9600);
  
  InicioLed ();
  InicioBoton ();
}
void loop ()
{ 
  Nivel1();
  Nivel2();
  Nivel3();
}
