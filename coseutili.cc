\t //è un tab

//fixed e scientific
cout.precision(10); //numero tra parentesi sono le cifre significative che voglio

//così è come stampo con il fixed
cout << fixed;  //da usare insieme a precisione, stampa con le cifre significative che gli ho detto
cout << ... << endl;

//così è come stampo con il scientific
cout << scientific; //stampa in notazione scientifica
cout << ... << endl;

char nomevariabile[20] //tra parentesi metto il numero di caratteri

string nomevariabile //non ho un numero di caratteri contato, mi prende anche i numeri

\n //vado a capo



//come stampare dati su file
#include <fstream>
fstream foutuput; //foutput è il nome che do alla variabile
foutput.open("risultato.dat", ios::out); //risultato.dat è il nome del file
if (foutput.good()) //controllo che funzioni e gli faccio stampare, altrimenti gli faccio dare errore
    {
      foutput << cognome << ", " << nome
	      << " è registrato con numero matricola "
	      << matricola << ".\n";  
    }
  else
    cout << "Errore: file is not good!" << endl;

  foutput.close(); //chiudo il file




//come leggere dati da file
#include <fstream>
fstream finput;
finput.open("myinput.dat", ios::in);

// check if file exists
if (!finput.good())
    {
      cout << "Cannot open myinput.dat" << endl;
      return -1;
    }

// read from file
finput >> nome;
finput >> cognome;
finput >> matricola;

// close input file
finput.close();


//per dire che una cosa è vera negli if devi mettere due uguali, per dire che è diversa !=

//se devo mettere tre condizioni in un if, faccio la prima if, la seconda else if, la terza else



//funzione switch
  switch(matricola)
    {
    case 123456:
      cout << "Sono io" << endl;
      break;

    default:
      cout << "Matricola non trovata" << endl;
    }



//cicli while e do while

  // ciclo while
  int counter = 0;
  while(counter < 5)
    {
      cout << "Hello World while index = " << counter << endl;
      counter++;
    }

  // ciclo do/while
  counter = 0;
  do {
    cout << "Hello World do/while index = " << counter << endl;
    counter++;
  }
  while(counter < 5);
  

//for infinito e eof per leggere dati da file
  double num;
  double sum = 0.0, n = 0.0;  
  for (;;)
    {
      f >> num;
      if (f.eof()) break;
      sum += num;
      n++;
    }
  f.close();



//dichiarare array statico
double v[5] = {2, 5, 10, 20, 50};


//dichiare array dinamico
  double *v = new double[5];
  v[0] = 2;
  v[1] = 5;
  v[2] = 10;
  v[3] = 20;
  v[4] = 50;

  delete[] v; //ricordati di cancellare il vettore



//massimo
int max_array(const int a[], int n)
{
  double max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}


//minimo
int min_array(const int a[], int n)
{
  double min = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] < min)
      min = a[i];
  return min;
}


//massimo e minimo 
void min_max_array(const int a[], int n, int &min, int &max)
{
  max = max_array(a, n);
  min = min_array(a, n);
}



//leggere dati da file quando ho più di una colonna
  for (int i = 0; i < N; i++)
    {
      f >> spazio >> tempo;
      v[i] = spazio / tempo;
    }
  
  f.close();



//selection sort (ordine crescente)
void sort_array(int a[], int n)
{
  for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++)
      if (a[i] > a[j])
      {
        const int dep = a[i];
        a[i] = a[j];
        a[j] = dep;
      }
}


//funzione print
void print_array(const int a[], int n)
{
  cout << "Contenuto array:" << endl;
  for (int i = 0; i < n; i++)
    cout << "index = " << i << ", value = " << a[i] << endl;
}



//funzione scambia (reference)
void scambia(double &a, double &b)
{
  const double dep = a;
  a = b;
  b = dep;
}


//funzione scambia(puntatori)
void scambia2(double *a, double *b)
{
  double dep = *b;
  *b = *a;
  *a = dep;
}



//ROBE SUI PUNTATORI (LEGGERE BENE)

// creazione variabile e puntatore
  double x = 5.5;
  double *p = NULL;

  // punto 2: stampare su terminale
  cout << "x = " << x << endl; //stampa valore x
  cout << "&x= " << &x << endl; //stampa numero celletta x
  cout << "p = " << p << endl; //stampa valore p (null vuol dire zero)
  cout << "&p= " << &p << endl; //stampa numero celletta p

  // punto 3: assegnare &x a p
  p = &x; //p è puntatore, deve PUNTARE a qualcosa per assumere il suo valore
  cout << "p  = " << p << endl; //stampa numero celletta p (che adesso è uguale a quello di x)
  cout << "*p = " << *p << endl; //stampa valore p

  // punto 4: chiedere un nuovo double
  cout << "Introdurre un double: ";
  cin >> *p;

  // controllare il nuovo valore di x (modificato tramite *p)
  cout << "x = " << x << endl; //stampa il valore

  // creare un array di puntatori n=2
  int n = 10;
  double *v = new double[10];
  for (int i = 0; i < n; i++)
    cout << "&v[" << i << "] = " << &v[i] << endl; //stampa cellette
  delete[] v;
