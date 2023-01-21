#include <sstream>
#include <string>
using namespace std;

struct netpacket{
int time; // timestamp del pacchetto
double db; // qualita' del pacchetto
char data; // carattere del messaggio
};

netpacket *load_data(string const &filename, int &ntot);
void print_and_save(stringstream &ss);
void filtra(netpacket *m, netpacket *a, netpacket *b, int ntot);
void store_corrupt(netpacket *m, int ntot);
void sort_by_timestamp(netpacket *m, int ntot);
void print_data(netpacket *m, int ntot, stringstream &sout);
void print_description(netpacket *m, int ntot, stringstream &sout);
void print_message1(netpacket *m, int ntot, stringstream &sout);
void store_message(netpacket *m, int ntot);