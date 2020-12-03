#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

void szukaj_podciagu(int t[], int n)
{
//deklaracja zmiennych i przypisanie wartosci
	int* tempArray;
	int zero = 0;
	int jeden = 0;
	int patternzero = 0;
	int patternjeden = 0;
	int max = 0;
	int znalezione = 0;
	int i, j;

fstream z;
//otwarcie pliku,w ktorym zapisywane sa podciagi
z.open("WYNIKI.txt",ios::out);

//obliczamy ilosc zer i jedynek w tablicy
	for (i = 0; i < n; i++)
	{
		if (t[i] == 0)
			zero++;
		else
			jeden++;
	}

//obliczamy maksymalna dlugosc ciagu
	if (zero < jeden)
		max = zero * 2;
	if (jeden < zero)
		max = jeden * 2;
	if (jeden == zero)
		max = jeden * 2;

//tworzenie tablicy
	tempArray = new int[max];

//przeszukujemy tablice wejsciowa
	while (max > 0)
	{
		for (i = 0; i <= n - max; i++)
		{
			patternzero = 0;
			patternjeden = 0;
			for (j = 0 + i; j <max + i; j++)
			{
				if (t[j] == 0)
				{
					patternzero++;
					tempArray[j - i] = 0;
				}
				else
				{
					patternjeden++;
					tempArray[j - i] = 1;
				}
			}
			if (patternjeden == patternzero)
			{
				cout<<"Najdluzszy podciag to: "<<endl;
				for (j = 0; j < max; j++)
                {
				cout<<tempArray[j];
				}
				cout<<"\n";

				z<<"Najdluzszy podciag to: "<<endl;

				for (j = 0; j < max; j++)
				{
					z<<tempArray[j];
					znalezione++;
				}
				z<<"\n";
			}

			patternzero = 0;
			patternjeden = 0;
		}
		if (znalezione > 0)
        {
			delete[] tempArray;
			break;
		}
		max--;
	}
	if (znalezione == 0)
    delete[] tempArray;
	z.close();


}

void test_1()
{
	cout<<"Test 1"<<endl<<endl;
//deklaracja stalej tablicy
	int a[2]={0,1};
	cout<<"A[] = ";
	for(int i = 0; i<2;i++) cout<<a[i]<<" ";
	cout<<endl;
	szukaj_podciagu(a,2);
	cout<<endl;

}


int main ()
{
	cout<<"1 - Pseudolosowe"<<endl<<endl;
	cout<<"2 - Test1"<<endl<<endl;

	 int sposob;
	 cout<<"Wybierz sposob dzialania programu: ";
	 cin>>sposob;

//stworzenie  menu
	 switch (sposob)
	{

	case 1:
    {

    int i,n;
    int *t;
	cout<<"Podaj rozmiar tablicy: "; //podajemy rozmiar tablicy dynamicznej
	cin>>n;
	t=new int[n];
		srand((unsigned)time(NULL));

//Wypelnienie tablicy 0 lub 1
        for(int i=0;i<n;i++)
        {
            t[i]= (rand()%2);
            cout<<t[i]<<" ";
        }
            cout<<endl;

    szukaj_podciagu(t,n);
    delete [] t;
    break;
    }

	case 2: test_1();
	break;

	}

    return 0;
}
