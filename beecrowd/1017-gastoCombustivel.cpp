#include <iostream>
 
using namespace std;
 
int main() {
 
    int tempo, velocidadeMedia;
    
    cin >> tempo >> velocidadeMedia;
    
    printf("%.3f\n", (float) tempo*velocidadeMedia/12);
 
    return 0;
}